#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include "NameChangeParameters.h"

class Settings
{
public:
    Settings();
private:
    NameChangeParameters nameChangeParameters;

public:
    bool readSettings(); //Czyta ustawienia z pliku
    bool saveSettings(); //Zapisuje ustawienia do pliku
    void setNameChangeParameters(NameChangeParameters parameters) noexcept {nameChangeParameters = parameters;}
    NameChangeParameters getNameChangeParameters() noexcept {return nameChangeParameters;}
private:
    bool rebuildFile(); //Tworzy plik ustawień
    void setSetting(QString line); //Zmienia ustawienie, przyjmuje linie z pliku ustawien
};

#endif // SETTINGS_H
