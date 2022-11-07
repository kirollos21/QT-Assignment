#ifndef PURCHASEDDIALOG_H
#define PURCHASEDDIALOG_H

#include <QDialog>

namespace Ui {
class PurchasedDialog;
}

class PurchasedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PurchasedDialog(QWidget *parent = nullptr, QList<QString> *p = nullptr);
    ~PurchasedDialog();

private:
    Ui::PurchasedDialog *ui;
    QList<QString> pur_books;
};

#endif // PURCHASEDDIALOG_H
