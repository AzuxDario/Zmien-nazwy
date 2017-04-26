#ifndef CORE_H
#define CORE_H

#include <QProgressBar>
#include "widgetabout.h"
#include "widgetrejestrzmian.h"
#include "namechanger.h"
#include "widgetsettings.h"
#include "settings.h"
#include "namechangeparameters.h"

class Core
{
public:
    Core(QProgressBar *progressBar);

private:
    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaTekst; //Do wyrzucenia
    QString trescOkienkaOProgramie;
    QString trescOkienkaOstrzezenie; //Do wyrzucenia
    QString trescOkienkaRejestrZmian;

    WidgetRejestrZmian *oknoRejestrZmian;
    WidgetAbout *oknoOProgramie;
    WidgetSettings *oknoUstawienia;

    NameChanger *zmieniaczNazw;

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
