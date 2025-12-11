#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include "DatabaseManager.h"

class QTableView;
class QPushButton;
class QLineEdit;
class QTabWidget;
class QSpinBox;
class QComboBox;

/**
 * @brief Ventana principal: vista de tabla, formulario rápido y controles.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onAdd();
    void onUpdate();
    void onDelete();
    void onExportCsv();
    void onSearch(const QString &text);
    void onDbError(const QString &msg);
    void onRegisterSale(); // Slot para ventas

private:
    void setupUi();
    void setupInventoryTab(QWidget *tab);
    void setupSalesTab(QWidget *tab);
    void setupModel();
    void refreshSalesModel();

    DatabaseManager m_dbManager;
    QSqlTableModel *m_model = nullptr;
    QSqlQueryModel *m_salesModel = nullptr;

    // Inventory Widgets
    QTableView *m_table = nullptr;
    QLineEdit *m_nameEdit = nullptr;
    QLineEdit *m_typeEdit = nullptr;
    QLineEdit *m_quantityEdit = nullptr;
    QLineEdit *m_priceEdit = nullptr;
    QLineEdit *m_locationEdit = nullptr;
    QLineEdit *m_dateEdit = nullptr;

    // Sales Widgets
    QLineEdit *m_saleSearch = nullptr;
    QComboBox *m_saleProductCombo = nullptr;
    QSpinBox *m_saleQtySpin = nullptr;
    QTableView *m_salesTable = nullptr;
};

#endif // MAINWINDOW_H
