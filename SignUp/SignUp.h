#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SignUp.h"
#include "Login.h"
#include <qmessagebox.h>

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    SignUp(QWidget *parent = nullptr);
    ~SignUp();

    QString SignUpUserName;
    QString SignupPassword;
    QString Email;

private slots:
    void on_LoginButton_clicked();

    void on_ButtonSignup_clicked();

private:
    Ui::SignUpClass ui;
    Login* LoginWindow = new Login();
};
