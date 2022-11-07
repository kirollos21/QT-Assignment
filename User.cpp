#include "User.h"
#include <QString>
#include <QList>

User::User(QString username, QString password, int id, double balance, QList<QString> purchasedBooks) {
    this->username = username;
    this->password = password;
    this->id = id;
    this->balance = balance;
    this->purchasedBooks = purchasedBooks;
}

QString User::getUsername() {
    return username;
}

QString User::getPassword() {
    return password;
}

int User::getId() {
    return id;
}

double User::getBalance() {
    return balance;
}

QList<QString> User::getPurchasedBooks() {
    return purchasedBooks;
}

void User::setUsername(QString username) {
    this->username = username;
}

void User::setPassword(QString password) {
    this->password = password;
}

void User::setId(int id) {
    this->id = id;
}

void User::setBalance(double balance) {
    this->balance = balance;
}

void User::setPurchasedBooks(QList<QString> purchasedBooks) {
    this->purchasedBooks = purchasedBooks;
}

void User::addPurchasedBook(QString purchasedBook) {
    purchasedBooks.append(purchasedBook);
}
