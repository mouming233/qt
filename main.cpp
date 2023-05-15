#include "widget.h"
#include <QApplication>
#include "title.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    title s;
    s.show();
//    Widget w;
//    w.show();

    return a.exec();
}
