#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the register button click signal to the slot
    connect(ui->register_2, &QPushButton::clicked, this, &MainWindow::on_register_2_clicked);
    connect(ui->commandLinkButton, &QPushButton::clicked, this, &MainWindow::on_commandLinkButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    APITicket api(*db);

    QString userName , password;
    userName = ui->user->text();
    password = ui->password->text();

    if(api.login(userName.toStdString(),password.toStdString())){
        QMessageBox::information(this, "Success", "Welcome Login succes");

    }else{
        QMessageBox::information(this, "Failed", "User or Password are wrong");
    }

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
        APITicket api(*db);

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


void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

