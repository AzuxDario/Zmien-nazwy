#ifndef CORE_H
#define CORE_H

#include <QProgressBar>
#include "widgetabout.h"
#include "widgetchangelog.h"
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
    QString widgetAboutText;
    QString widgetChangeLogText;

    WidgetChangeLog *widgetChangeLog;
    WidgetAbout *widgetAbout;
    WidgetSettings *widgetSettings;

    NameChanger *nameChanger;

    Settings *settingsReader;

    //NameChangeParameters nameChangeParameters;

public:
    void changeName(NameChangeParameters nameChangeParameters); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetChangeLog(); //Wyświetla okienko z rejestrem zmian
    void showWidgetSettings(); //Wyświetla okno ustawień
    //void setNameChangeParameters(NameChangeParameters parameters) noexcept {nameChangeParameters = parameters;}
    //NameChangeParameters getNameChangeParameters() noexcept {return nameChangeParameters;}
};

#endif // CORE_H
