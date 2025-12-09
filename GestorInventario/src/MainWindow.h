#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "DatabaseManager.h"

class QTableView;
class QPushButton;
class QLineEdit;

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

private:
    void setupUi();
    void setupModel();

    DatabaseManager m_dbManager;
    QSqlTableModel *m_model = nullptr; // Qt tomará ownership si le damos parent
    QTableView *m_table = nullptr;
    QLineEdit *m_nameEdit = nullptr;
    QLineEdit *m_typeEdit = nullptr;
    QLineEdit *m_quantityEdit = nullptr;
    QLineEdit *m_locationEdit = nullptr;
    QLineEdit *m_dateEdit = nullptr;
};

#endif // MAINWINDOW_H
