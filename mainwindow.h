#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void change_balan(User *user = nullptr);
    ~MainWindow();
    // make list of users
    QList<User> users;

private slots:
    void on_signInButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
