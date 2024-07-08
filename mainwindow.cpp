#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "database/database.hpp"

#include "api/api.hpp"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the register button click signal to the slot
    connect(ui->register_2, &QPushButton::clicked, this, &MainWindow::on_register_2_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{

}


void MainWindow::on_register_2_clicked()
{

    // // Create an instance of LoginDialog
    // loginDialog loginDialog;

    // // Show the LoginDialog
    // loginDialog.exec();
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_clicked()
{
    QString userName, email, password;
    userName = ui->userName->text();
    email = ui->email->text();
    password = ui->password_2->text();

    try {
        Database db("dbname=my_db user=postgres password=admin");
        API api(db);

        // Register a new user
        if (api.register_user(userName.toStdString(), email.toStdString(), password.toStdString())) {
            QMessageBox::information(this, "Success", "User registered successfully");
        } else {
            QMessageBox::warning(this, "Failure", "Failed to register user");
        }
        // db.get_connection().disconnect();

        // Inform the user that database operations are completed successfully
        QMessageBox::information(this, "Info", "Database operations completed successfully");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }

}

