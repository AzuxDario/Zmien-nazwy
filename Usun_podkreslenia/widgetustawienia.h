#ifndef WIDGETUSTAWIENIA_H
#define WIDGETUSTAWIENIA_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QDesktopWidget>
#include "custawienia.h"

namespace Ui {
class WidgetUstawienia;
}

class WidgetUstawienia : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetUstawienia(QWidget *parent = 0);
    ~WidgetUstawienia();

private:
    Ui::WidgetUstawienia *ui;

    //----Etykiety----//
    QLabel *opisOkna;

    //----Przyciski----//
    QPushButton *przyciskOk;

    //----CheckBoxy----//
    QCheckBox *przyciskWyboruPodfoldery;
    QCheckBox *przyciskWyboruZastapPodkreslenia;
    QCheckBox *przyciskWyboruZastapPauzy;
    QCheckBox *przyciskWyboruZastapKropki;
    QCheckBox *przyciskWyboruUsunKropkeRozszerzenia;
    QCheckBox *przyciskWyboruUstawPierwszaDuza;
    QCheckBox *przyciskWyboruUstawRozszerzenieMale;

    //----Obiekt czytajacy ustawienia----//
    CUstawienia *czytaczUstawien;

private slots:
    void zamknijOkno(); //Zamyka okno
    void zmienAktywnoscPrzyciskuKropkiRozszerzenia(); //Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki
    void ustawPrzyciski(); //Ustawia przyciski danymi z pliku
    void ustawCzytacz(); //Ustawia czytacz ustawień wartościami checkboxów

public slots:
    void pokazSie(); //Pokazuje już utworzone okno
};

#endif // WIDGETUSTAWIENIA_H
