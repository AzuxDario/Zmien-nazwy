#ifndef WIDGETVIEWPROVIDER_H
#define WIDGETVIEWPROVIDER_H

#include <QFileDialog>
#include <QString>
#include "WidgetAbout.h"
#include "WidgetChangelog.h"
#include "RenamerController.h"
#include "WidgetSettings.h"
#include "Settings.h"
#include "NameChangeParameters.h"
#include "About.h"

class WidgetViewProvider :public QObject
{
    Q_OBJECT

public:


    WidgetViewProvider();

private:
    WidgetChangeLog *widgetChangeLog;
    WidgetAbout *widgetAbout;
    WidgetSettings *widgetSettings;

    QStringList selectedDir;

    RenamerController *renamerController;

    Settings *settingsReader;

    NameChangeParameters nameChangeParameters;

    NameChangeParameters::DirType dirType;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();
    void doneWork();

public:
    void setSelectedDir(QStringList value) noexcept {selectedDir = value;}
    QStringList getSelectedDir() noexcept {return selectedDir;}

    void changeName(NameChangeParameters nameChangeParameters); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    QString selectFile(); //Wybiera plik do przeprowadzenia zmiany nazw
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetChangeLog(); //Wyświetla okienko z rejestrem zmian
    void showWidgetSettings(); //Wyświetla okno ustawień
    void setNameChangeParameters(NameChangeParameters parameters) noexcept {nameChangeParameters = parameters;}
    NameChangeParameters getNameChangeParameters() noexcept {return nameChangeParameters;}

private slots:
    void initializeProgressBarSlot(int minValue, int maxValue) {emit initializeProgressBar(minValue, maxValue);}
    void changeProgressBarSlot(int value) {emit changeProgressBar(value);}
    void resetProgressBarSlot() {emit resetProgressBar();}
    void handleResults() {emit doneWork();}
};

#endif // WIDGETVIEWPROVIDER_H
