#ifndef WIDGETABOUT_H
#define WIDGETABOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDesktopWidget>
#include "About.h"
#include "Widgets.h"

namespace Ui {
    class WidgetAbout;
}

class WidgetAbout : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAbout(QWidget *parent = 0);
    ~WidgetAbout();

private:
    Ui::WidgetAbout *ui;

    //--------Przyciski--------//
    QPushButton *buttonOk;

    //--------Pola tekstowe--------//
    QLabel *labelText;

    //--------Obrazek--------//
    QLabel *labelPicture;

private slots:
    void closeWindow(); //Zamyka okno

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETABOUT_H
