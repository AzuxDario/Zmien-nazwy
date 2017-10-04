#ifndef WIDGETVIEWPROVIDER_H
#define WIDGETVIEWPROVIDER_H

#include "WidgetAbout.h"
#include "WidgetChangelog.h"
#include "NameChanger.h"
#include "WidgetSettings.h"
#include "Settings.h"
#include "NameChangeParameters.h"

class WidgetViewProvider :public QObject
{
    Q_OBJECT

public:
    WidgetViewProvider();

private:
    //----Zmienne przechuwyjące ciągi znaków----//
    QString widgetAboutText;
    QString widgetChangeLogText;

    WidgetChangeLog *widgetChangeLog;
    WidgetAbout *widgetAbout;
    WidgetSettings *widgetSettings;

    NameChanger *nameChanger;

    Settings *settingsReader;

    NameChangeParameters nameChangeParameters;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();

public:
    void changeName(NameChangeParameters nameChangeParameters); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetChangeLog(); //Wyświetla okienko z rejestrem zmian
    void showWidgetSettings(); //Wyświetla okno ustawień
    void setNameChangeParameters(NameChangeParameters parameters) noexcept {nameChangeParameters = parameters;}
    NameChangeParameters getNameChangeParameters() noexcept {return nameChangeParameters;}

private slots:
    void initializeProgressBarSlot(int minValue, int maxValue) {emit initializeProgressBar(minValue, maxValue);}
    void changeProgressBarSlot(int value) {emit changeProgressBar(value);}
    void resetProgressBarSlot() {emit resetProgressBar();}
};

#endif // WIDGETVIEWPROVIDER_H
