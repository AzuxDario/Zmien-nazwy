#ifndef CRDZEN_H
#define CRDZEN_H

#include <QProgressBar>
#include "widgetoprogramie.h"
#include "widgetrejestrzmian.h"
#include "czmieniacznazw.h"
#include "widgetustawienia.h"
#include "custawienia.h"
#include "parametryzmianynazw.h"

class CRdzen
{
public:
    CRdzen(QProgressBar *pasekPostepu);

private:
    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaTekst;
    QString trescOkienkaOProgramie;
    QString trescOkienkaOstrzezenie;
    QString trescOkienkaRejestrZmian;

    WidgetRejestrZmian *oknoRejestrZmian;
    WidgetOProgramie *oknoOProgramie;
    WidgetUstawienia *oknoUstawienia;

    CZmieniaczNazw *zmieniaczNazw;

    CUstawienia *czytaczUstawien;

public:
    ParametryZmianyNazw parametryZmianyNazw;

public:
    void zmienNazwy(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString wybierzFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlRejestrZmian(); //Wyświetla okienko z rejestrem zmian
    void wyswietlUstawienia(); //Wyświetla okno ustawień
};

#endif // CRDZEN_H
