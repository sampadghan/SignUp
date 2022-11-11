#include "ToDo.h"
#include "Login.h"
#include "SignUp.h"

ToDo::ToDo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Todo");
	ui.listWidgetPending->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.listWidgetPending->setDragEnabled(true);
	ui.listWidgetPending->setDefaultDropAction(Qt::DropAction::MoveAction);
	ui.listWidgetPending->viewport()->setAcceptDrops(true);
	ui.listWidgetPending->setDropIndicatorShown(true);
	ui.listWidgetPending->setSortingEnabled(true);

	ui.listWidgetCompleted->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.listWidgetCompleted->setDragEnabled(true);
	ui.listWidgetCompleted->setDefaultDropAction(Qt::DropAction::MoveAction);
	ui.listWidgetCompleted->viewport()->setAcceptDrops(true);
	ui.listWidgetCompleted->setDropIndicatorShown(true);
	ui.listWidgetCompleted->setSortingEnabled(true);

	QListWidgetItem* item;
	item = new QListWidgetItem(tr("Oak"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Fir"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Pine"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Birch"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Hazel"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Redwood"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Sycamore"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Chestnut"), ui.listWidgetPending);
	item = new QListWidgetItem(tr("Mahogany"), ui.listWidgetPending);
}

ToDo::~ToDo()
{}

void ToDo::on_AddTaskButton_clicked()
{
	bool ok;
	QString text = QInputDialog::getText(this, tr("Add Task"), tr("Task Name:"), QLineEdit::Normal, tr("Task n"), &ok);
	if (ok && !text.isEmpty())
	{
		ui.listWidgetPending->addItem(text);
	}
}

void ToDo::on_DeleteButton_clicked()
{
	QListWidgetItem* item = ui.listWidgetPending->takeItem(pending_row_count);
	delete item;
}

void ToDo::on_LogOutButton_clicked()
{
	if (NewLoginWindow != nullptr)
	{
		this->hide();
		NewLoginWindow->show();
	}
}

void ToDo::on_actionEdit_Task_triggered()
{
	bool ok;
	QListWidgetItem* item = ui.listWidgetPending->takeItem(pending_row_count);
	if (item != nullptr)
	{
		QString itemtext = item->text();
		QString text = QInputDialog::getText(this, tr("Edit Task"), tr("Task Name:"), QLineEdit::Normal, itemtext, &ok);
		if (ok && !text.isEmpty())
		{
			ui.listWidgetPending->addItem(text);
		}
		else
		{
			ui.listWidgetPending->addItem(itemtext);
		}
	}
}

void ToDo::on_actionCompleted_Task_triggered()
{
	QListWidgetItem* c_item = ui.listWidgetCompleted->takeItem(completed_row_count);
	delete c_item;
}

void ToDo::on_actionQuit_triggered()
{
	this->close();
	//his->closeEvent();
}

void ToDo::on_listWidgetPending_currentRowChanged(int currentRow)
{
	pending_row_count = currentRow;
}

void ToDo::on_listWidgetCompleted_currentRowChanged(int currentRow)
{
	completed_row_count = currentRow;
}

