#ifndef WIDGETOPROGRAMIE_H
#define WIDGETOPROGRAMIE_H

#include <QWidget>
#include <QTextCodec>
#include <QLabel>
#include <QPushButton>
#include <QDesktopWidget>

namespace Ui {
    class WidgetOProgramie;
}

class WidgetOProgramie : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetOProgramie(QString trescOkna, QWidget *parent = 0);
    ~WidgetOProgramie();

private:
    Ui::WidgetOProgramie *ui;

    //--------Przyciski--------//
    QPushButton *przyciskOk;

    //--------Pola tekstowe--------//
    QLabel *poleText;

    //--------Obrazek--------//
    QLabel *poleObrazek
    ;
    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaInformacyjengo;

private slots:
    void zamknijOkno(); //Zamyka okno

public slots:
    void pokazSie(); //Pokazuje już utworzone okno
};

#endif // WIDGETOPROGRAMIE_H
