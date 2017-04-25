#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include "namechangeparameters.h"

class Settings
{
public:
    Settings();
public:
    NameChangeParameters nameChangeParameters;

public:
    bool readSettings(); //Czyta ustawienia z pliku
    bool saveSettings(); //Zapisuje ustawienia do pliku
private:
    bool rebuildFile(); //Tworzy plik ustawień
    void setSetting(QString line); //Zmienia ustawienie, przyjmuje linie z pliku ustawien
};

#endif // SETTINGS_H
