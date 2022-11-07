// make a class for user with username, password, id, balance, and list of purchased books

#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>

class User {
    public:
        User(QString username, QString password, int id, double balance, QList<QString> purchasedBooks);
        QString getUsername();
        QString getPassword();
        int getId();
        double getBalance();
        QList<QString> getPurchasedBooks();
        void setUsername(QString username);
        void setPassword(QString password);
        void setId(int id);
        void setBalance(double balance);
        void setPurchasedBooks(QList<QString> purchasedBooks);
        void addPurchasedBook(QString purchasedBook);
    private:
        QString username;
        QString password;
        int id;
        double balance;
        QList<QString> purchasedBooks;
};

#endif // USER_H