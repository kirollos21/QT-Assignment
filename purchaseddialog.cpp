#include "purchaseddialog.h"
#include "ui_purchaseddialog.h"

PurchasedDialog::PurchasedDialog(QWidget *parent, QList<QString> *p) :
    QDialog(parent),
    ui(new Ui::PurchasedDialog),
    pur_books(*p)
{
    ui->setupUi(this);
    for (int i=0; i<pur_books.capacity(); i++)
    {
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+ "Book name : " + pur_books[i] + "\n");
    }
}

PurchasedDialog::~PurchasedDialog()
{
    delete ui;
}
