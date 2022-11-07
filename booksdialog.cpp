#include "booksdialog.h"
#include "ui_booksdialog.h"
#include "purchaseddialog.h"

BooksDialog::BooksDialog(QWidget *parent, User *user) :
    QDialog(parent),
    ui(new Ui::BooksDialog),
    user(user)    
{
    ui->setupUi(this);
    ui->IDLabel->setText(QString::number(user->getId()));
    ui->balanceLabel->setText(QString::number(user->getBalance()));

    books.append("Choose a book");
    books.append("Java");
    books.append("C++");
    books.append("Algorithms");
    books.append("Calculas 3");

    for (int i = 0; i < books.length(); i++) {
        ui->booksCombo->addItem(books[i]);
    }

    prices.append(0);
    prices.append(120.00);
    prices.append(110.00);
    prices.append(250.00);
    prices.append(90.00);

}

BooksDialog::~BooksDialog()
{
    delete ui;
}

void BooksDialog::on_booksCombo_currentIndexChanged(int index)
{
    if(prices.length() > index) {
        ui->priceLabel->setText("Book Price ::: "+QString::number(prices[index]));
    }
    ind = index;
}


void BooksDialog::on_pushButton_5_clicked()
{
    double new_balance = QString(ui->textEdit->toPlainText()).toDouble();
    if(new_balance >= 0)
    {
    user->setBalance(user->getBalance()+new_balance);
    ui->balanceLabel->setText(QString::number(user->getBalance()));
    }
    else
    {
        ui->textEdit->setText("Can't enter -ve value");
    }
}


void BooksDialog::on_pushButton_4_clicked()
{
    if (ui->booksCombo->currentText() == "Choose a book")
    {
        ui->priceLabel->setText("Choose a book first");
    }
    else if(prices[ind] > user->getBalance())
    {
        ui->priceLabel->setText("Recharge your balance first");
    }
    else
    {
        ui->priceLabel->setText("Book Purchased");
        user->setBalance(user->getBalance() - prices[ind]);
        ui->balanceLabel->setText(QString::number(user->getBalance()));
        pur_books.append(books[ind]);
    }
}


void BooksDialog::on_pushButton_6_clicked()
{
    PurchasedDialog purchases(this, &pur_books);
    purchases.setModal(true);
    purchases.exec();
}

