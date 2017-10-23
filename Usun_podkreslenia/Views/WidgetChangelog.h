#ifndef WIDGETCHANGELOG_H
#define WIDGETCHANGELOG_H

#include <QWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QDesktopWidget>
#include "About.h"
#include "Views.h"

namespace Ui {
    class WidgetChangeLog;
}

class WidgetChangeLog : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChangeLog(QWidget *parent = 0);
    ~WidgetChangeLog();

private:
    Ui::WidgetChangeLog *ui;

    //--------Przyciski--------//
    QPushButton *buttonOk;

    //--------Pola tekstowe--------//
    QTextBrowser *textBrowserChangeLog;

private slots:
    void closeWindow(); //Zamyka okno

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETCHANGELOG_H
