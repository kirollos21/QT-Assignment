#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "booksdialog.h"

#include <QMessageBox>
#include <QList>
#include <QString>
#include "User.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->errorLabel->setVisible(false);
    ui->passwordField->setEchoMode(QLineEdit::Password);

    User user1("ahmed", "pass1", 1, 100.00, QList<QString>());
    User user2("kiro", "pass2", 1, 200.00, QList<QString>());
    users.append(user1);
    users.append(user2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signInButton_clicked()
{
    ui->errorLabel->setVisible(false);

    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();
    
    for (int i = 0; i < users.length(); i++) {
        if (users[i].getUsername() == username) {
            if (users[i].getPassword() == password) {
                ui->IDLabel->setText(QString::number(users[i].getId()));
                ui->balanceLabel->setText(QString::number(users[i].getBalance()));

                BooksDialog *booksDialog = new BooksDialog(this, &users[i]);
                booksDialog->setModal(true);
                booksDialog->exec();
                ui->balanceLabel->setText(QString::number(users[i].getBalance()));
                return;

                ui->errorLabel->setVisible(false);
                return;
            } else {
                ui->errorLabel->setText("Incorrect password");
                ui->errorLabel->setVisible(true);
                return;
            }
        }
    }

    ui->errorLabel->setText("User not found");
    ui->errorLabel->setVisible(true);
}
