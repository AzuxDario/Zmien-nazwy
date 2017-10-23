#include <QtWidgets/QApplication>
#include "Widget.h"
#include <QDesktopWidget>
#include "Views.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); //Dostępne od Qt 5.6
    QApplication a(argc, argv);
    a.setApplicationName(Views::applicationName);
    a.setApplicationVersion("3.4");
    Widget w;
    //w.setMinimumSize(420,397);
    //w.setMaximumSize(420,397);
    w.setWindowIcon(QIcon(":/ikona/ikona"));
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center()); //Przesuń na pozycję środek monitora odjąć środek okna
    w.show();
    return a.exec();
}
