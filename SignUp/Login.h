#pragma once

#include <QMainWindow>
#include "ui_LoginNew.h"
#include "ToDo.h"

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget* parent = nullptr);
	~Login();

	QString LoginUserName;
	QString LoginPassword;

	//function to set credential
	void SetCred(QString username, QString password);

	//New To Do windows
	ToDo* TodoWindow = new ToDo();

	//use this insted of
	class SignUp* SignUpWindow = nullptr;

	//will give error
	//Signup* SignUpWindow = New SignUpWindow();

private slots:

	void on_SignUpButton_clicked();

	void on_LoginButton_clicked();

private:
	Ui::LoginClass ui;
};
