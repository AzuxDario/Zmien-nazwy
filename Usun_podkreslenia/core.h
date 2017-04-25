#ifndef CORE_H
#define CORE_H

#include <QProgressBar>
#include "widgetoprogramie.h"
#include "widgetrejestrzmian.h"
#include "czmieniacznazw.h"
#include "widgetustawienia.h"
#include "settings.h"
#include "namechangeparameters.h"

class Core
{
public:
    Core(QProgressBar *progressBar);

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

    Settings *czytaczUstawien;

public:
    NameChangeParameters nameChangeParameters;

public:
    void zmienNazwy(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString wybierzFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlRejestrZmian(); //Wyświetla okienko z rejestrem zmian
    void wyswietlUstawienia(); //Wyświetla okno ustawień
};

#endif // CORE_H
