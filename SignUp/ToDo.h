#pragma once

#include <QMainWindow>
#include "ui_ToDo.h"
#include <qinputdialog.h>


class ToDo : public QMainWindow
{
	Q_OBJECT

public:
	ToDo(QWidget *parent = nullptr);
	~ToDo();

    class Login* NewLoginWindow;
    class Signup* PreviousLoginWindow;
    
private slots:
    void on_AddTaskButton_clicked();

    void on_DeleteButton_clicked();

    void on_LogOutButton_clicked();

    void on_actionEdit_Task_triggered();

    void on_actionCompleted_Task_triggered();

    void on_actionQuit_triggered();

    void on_listWidgetPending_currentRowChanged(int currentRow);

    void on_listWidgetCompleted_currentRowChanged(int currentRow);

private:
	Ui::ToDoClass ui;

    int pending_row_count = -1;
    int completed_row_count = -1;
};
