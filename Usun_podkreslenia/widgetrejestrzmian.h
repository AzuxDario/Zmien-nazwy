#ifndef WIDGETINFORMACJE_H
#define WIDGETINFORMACJE_H

#include <QWidget>
#include <QTextCodec>
#include <QTextBrowser>
#include <QPushButton>
#include <QDesktopWidget>

namespace Ui {
    class WidgetRejestrZmian;
}

class WidgetRejestrZmian : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRejestrZmian(QString trescOkna, QWidget *parent = 0);
    ~WidgetRejestrZmian();

private:
    Ui::WidgetRejestrZmian *ui;

    //--------Przyciski--------//
    QPushButton *przyciskOk;

    //--------Pola tekstowe--------//
    QTextBrowser *okienkoTekst;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaRejestrZmian;

private slots:
    void zamknijOkno(); //Zamyka okno

public slots:
    void pokazSie(); //Pokazuje już utworzone okno
};

#endif // WIDGETINFORMACJE_H
