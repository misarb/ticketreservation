#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database/database.hpp"

#include "api/api.hpp"
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();
    void on_register_2_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    Database* db = Database::getInstance("dbname=my_db user=postgres password=admin");
    // APITicket api(*db);
   // API api(*db);
};
#endif // MAINWINDOW_H
