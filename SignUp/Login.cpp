#include "Login.h"
#include "SignUp.h"

Login::Login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Login::~Login()
{}

void Login::on_SignUpButton_clicked()
{
	if (SignUpWindow != nullptr)
	{
		this->hide();
		SignUpWindow->show();
	}
}

void Login::on_LoginButton_clicked()
{
	//Local username and password
	QString LocalUserName = ui.lineEditPassword->text();
	QString LocalPassword = ui.lineEditPassword->text();
	if (LoginUserName.isEmpty() || LoginPassword.isEmpty())
	{
		QMessageBox::information(this, "Warning", "First create a account");
		return;
	}
	if (LoginUserName == LocalUserName && LoginPassword == LocalPassword)
	{
		QMessageBox::information(this, "Login", "UserName and Password are correct");
		this->hide();
		TodoWindow->NewLoginWindow = this;
		TodoWindow->show();
	}
	else
	{
		QMessageBox::information(this, "Warning", "UserName and Password are not correct");
	}
}

void Login::SetCred(QString username, QString password)
{
	//Sign up UserName and password
	LoginUserName = username;
	LoginPassword = password;
}

