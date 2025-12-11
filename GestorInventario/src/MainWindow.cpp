#include "MainWindow.h"
#include "ReportGenerator.h"
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlError>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Abrir BD en el directorio actual
    if (!m_dbManager.openDatabase("inventory.db")) {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos.");
    }
    if (!m_dbManager.initSchema()) {
        QMessageBox::critical(this, "Error", "No se pudo inicializar el esquema.");
    }
    connect(&m_dbManager, &DatabaseManager::errorOccurred, this, &MainWindow::onDbError);
    setupUi();
    setupModel();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUi() {
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // --- Styling with QSS (Shop Theme) ---
    // Dark modern theme with teal accents
    QString qss = R"(
        QMainWindow {
            background-color: #2b2b2b;
        }
        QWidget {
            color: #ffffff;
            font-family: 'Segoe UI', sans-serif;
            font-size: 14px;
        }
        QTableView {
            background-color: #3c3c3c;
            alternate-background-color: #353535;
            selection-background-color: #00796b;
            selection-color: #ffffff;
            gridline-color: #555555;
            border: 1px solid #555555;
            border-radius: 4px;
        }
        QHeaderView::section {
            background-color: #424242;
            color: #ffffff;
            padding: 4px;
            border: 1px solid #555555;
        }
        QLineEdit {
            background-color: #424242;
            border: 1px solid #555555;
            border-radius: 4px;
            padding: 6px;
            color: #ffffff;
        }
        QLineEdit:focus {
            border: 1px solid #00796b;
        }
        QPushButton {
            background-color: #00796b;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 8px 16px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #009688;
        }
        QPushButton:pressed {
            background-color: #004d40;
        }
        QLabel {
            font-weight: bold;
            color: #b2dfdb;
        }
    )";
    this->setStyleSheet(qss);

    // Controles de búsqueda
    QHBoxLayout *searchLayout = new QHBoxLayout();
    QLabel *searchLabel = new QLabel("🔎 Buscar Producto:");
    searchLayout->addWidget(searchLabel);
    QLineEdit *search = new QLineEdit();
    search->setPlaceholderText("Escribe nombre o tipo...");
    connect(search, &QLineEdit::textChanged, this, &MainWindow::onSearch);
    searchLayout->addWidget(search);
    mainLayout->addLayout(searchLayout);

    // Tabla
    m_table = new QTableView(central);
    m_table->setAlternatingRowColors(true);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(m_table);

    // Formulario de edición
    QLabel *formLabel = new QLabel("📝 Detalles del Producto");
    formLabel->setStyleSheet("font-size: 16px; margin-top: 10px; margin-bottom: 5px; color: #80cbc4;");
    mainLayout->addWidget(formLabel);

    QHBoxLayout *formRow1 = new QHBoxLayout();
    m_nameEdit = new QLineEdit(); m_nameEdit->setPlaceholderText("Nombre del producto");
    m_typeEdit = new QLineEdit(); m_typeEdit->setPlaceholderText("Categoría / Tipo");
    m_quantityEdit = new QLineEdit(); m_quantityEdit->setPlaceholderText("Stock");

    // Validadores simples
    // m_quantityEdit->setValidator(new QIntValidator(0, 999999, this)); // requires include QIntValidator

    formRow1->addWidget(m_nameEdit, 2);
    formRow1->addWidget(m_typeEdit, 2);
    formRow1->addWidget(m_quantityEdit, 1);
    mainLayout->addLayout(formRow1);

    QHBoxLayout *formRow2 = new QHBoxLayout();
    m_priceEdit = new QLineEdit(); m_priceEdit->setPlaceholderText("Precio Unitario ($)");
    m_locationEdit = new QLineEdit(); m_locationEdit->setPlaceholderText("Ubicación en almacén");
    m_dateEdit = new QLineEdit(); m_dateEdit->setPlaceholderText("Fecha (YYYY-MM-DD)");

    formRow2->addWidget(m_priceEdit, 1);
    formRow2->addWidget(m_locationEdit, 2);
    formRow2->addWidget(m_dateEdit, 2);
    mainLayout->addLayout(formRow2);

    // Botones de acción
    QHBoxLayout *buttons = new QHBoxLayout();
    buttons->setContentsMargins(0, 10, 0, 0);

    QPushButton *addBtn = new QPushButton("➕ Agregar");
    QPushButton *updBtn = new QPushButton("✏️ Actualizar");
    QPushButton *delBtn = new QPushButton("🗑️ Eliminar");
    QPushButton *expBtn = new QPushButton("📄 Exportar CSV");

    // Estilos específicos para botones
    delBtn->setStyleSheet("background-color: #c62828;"); // Red for delete
    delBtn->setStyleSheet("QPushButton:hover { background-color: #e53935; }");

    buttons->addWidget(addBtn);
    buttons->addWidget(updBtn);
    buttons->addWidget(delBtn);
    buttons->addStretch(); // Espacio flexible
    buttons->addWidget(expBtn);
    mainLayout->addLayout(buttons);

    connect(addBtn, &QPushButton::clicked, this, &MainWindow::onAdd);
    connect(updBtn, &QPushButton::clicked, this, &MainWindow::onUpdate);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::onDelete);
    connect(expBtn, &QPushButton::clicked, this, &MainWindow::onExportCsv);

    setCentralWidget(central);
    setWindowTitle("Gestor de Tienda v2.0");
    resize(900, 600);
}

void MainWindow::setupModel() {
    m_model = new QSqlTableModel(this, m_dbManager.database());
    m_model->setTable("components");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    // Encabezados amigables
    m_model->setHeaderData(0, Qt::Horizontal, "ID");
    m_model->setHeaderData(1, Qt::Horizontal, "Producto");
    m_model->setHeaderData(2, Qt::Horizontal, "Categoría");
    m_model->setHeaderData(3, Qt::Horizontal, "Stock");
    m_model->setHeaderData(4, Qt::Horizontal, "Ubicación");
    m_model->setHeaderData(5, Qt::Horizontal, "Fecha Ingreso");
    // El precio es la columna 6 ahora
    m_model->setHeaderData(6, Qt::Horizontal, "Precio ($)");

    m_table->setModel(m_model);
}

void MainWindow::onAdd() {
    bool ok;
    int qty = m_quantityEdit->text().toInt(&ok);
    if (!ok) qty = 0;

    double price = m_priceEdit->text().toDouble(&ok);
    if (!ok) price = 0.0;

    Component c(-1, m_nameEdit->text(), m_typeEdit->text(), qty,
                m_locationEdit->text(), m_dateEdit->text(), price);

    if (!m_dbManager.insertComponent(c)) {
        QMessageBox::warning(this, "Error", "No se pudo insertar producto");
        return;
    }
    m_model->select(); // Refrescar tabla

    // Limpiar campos
    m_nameEdit->clear();
    m_typeEdit->clear();
    m_quantityEdit->clear();
    m_priceEdit->clear();
    m_locationEdit->clear();
}

void MainWindow::onUpdate() {
    auto sel = m_table->selectionModel();
    if (!sel->hasSelection()) {
        QMessageBox::information(this, "Info", "Seleccione una fila para actualizar");
        return;
    }
    int row = sel->selectedRows().first().row();
    int id = m_model->data(m_model->index(row,0)).toInt();

    bool ok;
    int qty = m_quantityEdit->text().toInt(&ok);
    if (!ok) qty = 0;

    double price = m_priceEdit->text().toDouble(&ok);
    if (!ok) price = 0.0;

    Component c(id, m_nameEdit->text(), m_typeEdit->text(), qty,
                m_locationEdit->text(), m_dateEdit->text(), price);

    if (!m_dbManager.updateComponent(c)) {
        QMessageBox::warning(this, "Error", "No se pudo actualizar producto");
        return;
    }
    m_model->select();
}

void MainWindow::onDelete() {
    auto sel = m_table->selectionModel();
    if (!sel->hasSelection()) {
        QMessageBox::information(this, "Info", "Seleccione una fila para eliminar");
        return;
    }
    int row = sel->selectedRows().first().row();
    int id = m_model->data(m_model->index(row,0)).toInt();

    if (QMessageBox::question(this, "Confirmar", "¿Seguro que desea eliminar este producto?",
                              QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        if (!m_dbManager.deleteComponent(id)) {
            QMessageBox::warning(this, "Error", "No se pudo eliminar producto");
            return;
        }
        m_model->select();
    }
}

void MainWindow::onExportCsv() {
    QList<Component> list;
    if (!m_dbManager.fetchAll(list)) {
        QMessageBox::warning(this, "Error", "No se pudo leer datos");
        return;
    }
    QString fname = QFileDialog::getSaveFileName(this, "Guardar Reporte", "inventario.csv", "CSV Files (*.csv)");
    if (fname.isEmpty()) return;

    if (!ReportGenerator::exportCsv(fname, list)) {
        QMessageBox::warning(this, "Error", "No se pudo crear archivo CSV");
    } else {
        QMessageBox::information(this, "Éxito", "Reporte generado correctamente");
    }
}

void MainWindow::onSearch(const QString &text) {
    if (!m_model) return;
    QString filter = QString("name LIKE '%%1%' OR type LIKE '%%1%'").arg(text);
    m_model->setFilter(filter);
    m_model->select();
}

void MainWindow::onDbError(const QString &msg) {
    QMessageBox::warning(this, "Database Error", msg);
}
