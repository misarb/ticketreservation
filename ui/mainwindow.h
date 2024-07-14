#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../database/database.hpp"

#include "../api/api.hpp"
#include "../utils/EventModel.h"
#include <QString>
#include <QMessageBox>
#include <QListView>

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
    void loadEvents();
    ~MainWindow();

private slots:
    void on_login_clicked();
    void on_register_2_clicked();
    void on_pushButton_clicked();
    void on_commandLinkButton_clicked();    
    // void on_EventView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::MainWindow *ui;
    Database* db = Database::getInstance("dbname=my_db user=postgres password=admin");
    QListView *listView;
    EventModel *model;

    APITicket api;

};
#endif // MAINWINDOW_H
