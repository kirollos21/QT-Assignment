#ifndef BOOKSDIALOG_H
#define BOOKSDIALOG_H

#include <QDialog>
#include "User.h"

namespace Ui {
class BooksDialog;
}

class BooksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BooksDialog(QWidget *parent = nullptr , User *user = nullptr);
    ~BooksDialog();

private slots:
    void on_booksCombo_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::BooksDialog *ui;
    User *user;
    // make list for avaliable books
    QList<QString> books;
    QList<QString> pur_books;
    QList<double> prices;
    int ind;
};

#endif // BOOKSDIALOG_H
