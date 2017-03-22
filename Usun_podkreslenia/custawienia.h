#ifndef CUSTAWIENIA_H
#define CUSTAWIENIA_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include "parametryzmianynazw.h"

class CUstawienia
{
public:
    CUstawienia();
public:
    ParametryZmianyNazw parametryZmianyNazw;

public:
    bool czytajUstawienia(); //Czyta ustawienia z pliku
    bool zapiszUstawienia(); //Zapisuje ustawienia do pliku
private:
    bool odbudujPlik(); //Tworzy plik ustawień
    void zmienUstawienie(QString linia); //Zmienia ustawienie, przyjmuje linie z pliku ustawien
};

#endif // CUSTAWIENIA_H
