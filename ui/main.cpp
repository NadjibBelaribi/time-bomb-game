#include "mainwindow.h"
#include <QApplication>
#include "options.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(QApplication::translate("TimeBomb", "TimeBomb"));
    return a.exec();
}
