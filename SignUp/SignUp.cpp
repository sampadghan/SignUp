#include "SignUp.h"

SignUp::SignUp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

SignUp::~SignUp()
{}

void SignUp::on_LoginButton_clicked()
{
    this->hide();
    LoginWindow->SignUpWindow = this;
    LoginWindow->show();
}


void SignUp::on_ButtonSignup_clicked()
{
    SignUpUserName = ui.lineEditUserName->text();
    SignupPassword = ui.lineEditPassword->text();
    Email = ui.lineEditEmail->text();
    if (SignUpUserName.isEmpty() || SignupPassword.isEmpty() || Email.isEmpty())
    {
        QMessageBox::information(this, "Warning", "Please enter credentials");
    }
    else
    {
        QMessageBox::information(this, "Account Created", "You May Login");
        //LoginWindow = new Login();
        LoginWindow->SetCred(SignUpUserName, SignupPassword);
        this->hide();
        LoginWindow->show();
    }
}

