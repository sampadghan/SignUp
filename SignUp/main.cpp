#include "SignUp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignUp w;
    w.show();
    return a.exec();
}
