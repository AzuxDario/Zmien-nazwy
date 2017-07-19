#ifndef WIDGETCHANGELOG_H
#define WIDGETCHANGELOG_H

#include <QWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QDesktopWidget>

namespace Ui {
    class WidgetChangeLog;
}

class WidgetChangeLog : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChangeLog(QString widgetText, QWidget *parent = 0);
    ~WidgetChangeLog();

private:
    Ui::WidgetChangeLog *ui;

    //--------Przyciski--------//
    QPushButton *buttonOk;

    //--------Pola tekstowe--------//
    QTextBrowser *textBrowserChangeLog;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString widgetChangeLogText;

private slots:
    void closeWindow(); //Zamyka okno

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETCHANGELOG_H
