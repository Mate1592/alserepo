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
    // m_model es hijo de la ventana y se destruirá automáticamente
}

void MainWindow::setupUi() {
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Controles de búsqueda
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(new QLabel("Buscar:"));
    QLineEdit *search = new QLineEdit();
    connect(search, &QLineEdit::textChanged, this, &MainWindow::onSearch);
    searchLayout->addWidget(search);
    mainLayout->addLayout(searchLayout);

    // Tabla
    m_table = new QTableView(central);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(m_table);

    // Formulario sencillo
    QHBoxLayout *form = new QHBoxLayout();
    m_nameEdit = new QLineEdit(); m_nameEdit->setPlaceholderText("Nombre");
    m_typeEdit = new QLineEdit(); m_typeEdit->setPlaceholderText("Tipo");
    m_quantityEdit = new QLineEdit(); m_quantityEdit->setPlaceholderText("Cantidad");
    m_locationEdit = new QLineEdit(); m_locationEdit->setPlaceholderText("Ubicación");
    m_dateEdit = new QLineEdit(); m_dateEdit->setPlaceholderText("Fecha compra (YYYY-MM-DD)");

    form->addWidget(m_nameEdit);
    form->addWidget(m_typeEdit);
    form->addWidget(m_quantityEdit);
    form->addWidget(m_locationEdit);
    form->addWidget(m_dateEdit);
    mainLayout->addLayout(form);

    // Botones
    QHBoxLayout *buttons = new QHBoxLayout();
    QPushButton *addBtn = new QPushButton("Agregar");
    QPushButton *updBtn = new QPushButton("Actualizar");
    QPushButton *delBtn = new QPushButton("Eliminar");
    QPushButton *expBtn = new QPushButton("Exportar CSV");

    buttons->addWidget(addBtn);
    buttons->addWidget(updBtn);
    buttons->addWidget(delBtn);
    buttons->addWidget(expBtn);
    mainLayout->addLayout(buttons);

    connect(addBtn, &QPushButton::clicked, this, &MainWindow::onAdd);
    connect(updBtn, &QPushButton::clicked, this, &MainWindow::onUpdate);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::onDelete);
    connect(expBtn, &QPushButton::clicked, this, &MainWindow::onExportCsv);

    setCentralWidget(central);
    setWindowTitle("Gestor de Inventario");
    resize(800, 480);
}

void MainWindow::setupModel() {
    // Usamos QSqlTableModel para ligarlo directamente a la tabla SQLite
    m_model = new QSqlTableModel(this, m_dbManager.database());
    m_model->setTable("components");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    // Encabezados
    m_model->setHeaderData(0, Qt::Horizontal, "ID");
    m_model->setHeaderData(1, Qt::Horizontal, "Nombre");
    m_model->setHeaderData(2, Qt::Horizontal, "Tipo");
    m_model->setHeaderData(3, Qt::Horizontal, "Cantidad");
    m_model->setHeaderData(4, Qt::Horizontal, "Ubicación");
    m_model->setHeaderData(5, Qt::Horizontal, "Fecha compra");
    m_table->setModel(m_model);

    for (int c=0; c<m_model->columnCount(); ++c)
        m_table->resizeColumnToContents(c);
}

void MainWindow::onAdd() {
    // Validación básica
    bool ok;
    int qty = m_quantityEdit->text().toInt(&ok);
    if (!ok) qty = 0;

    Component c(-1, m_nameEdit->text(), m_typeEdit->text(), qty,
                m_locationEdit->text(), m_dateEdit->text());

    if (!m_dbManager.insertComponent(c)) {
        QMessageBox::warning(this, "Error", "No se pudo insertar componente");
        return;
    }
    m_model->select();
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

    Component c(id, m_nameEdit->text(), m_typeEdit->text(), qty,
                m_locationEdit->text(), m_dateEdit->text());

    if (!m_dbManager.updateComponent(c)) {
        QMessageBox::warning(this, "Error", "No se pudo actualizar componente");
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

    if (!m_dbManager.deleteComponent(id)) {
        QMessageBox::warning(this, "Error", "No se pudo eliminar componente");
        return;
    }
    m_model->select();
}

void MainWindow::onExportCsv() {
    QList<Component> list;
    if (!m_dbManager.fetchAll(list)) {
        QMessageBox::warning(this, "Error", "No se pudo leer datos para exportar");
        return;
    }
    QString fname = QFileDialog::getSaveFileName(this, "Guardar CSV", "inventario.csv", "CSV Files (*.csv)");
    if (fname.isEmpty()) return;

    if (!ReportGenerator::exportCsv(fname, list)) {
        QMessageBox::warning(this, "Error", "No se pudo crear archivo CSV");
    } else {
        QMessageBox::information(this, "Exportado", "CSV creado correctamente");
    }
}

void MainWindow::onSearch(const QString &text) {
    if (!m_model) return;
    // Filtrado sencillo buscando en name y type
    QString filter = QString("name LIKE '%%1%' OR type LIKE '%%1%'").arg(text);
    m_model->setFilter(filter);
    m_model->select();
}

void MainWindow::onDbError(const QString &msg) {
    QMessageBox::warning(this, "Database Error", msg);
}
