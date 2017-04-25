#ifndef CZMIENIACZNAZW_H
#define CZMIENIACZNAZW_H

#include <QString>
#include <QProgressBar>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include "folderdetetor.h"
#include "namechangeparameters.h"

class CZmieniaczNazw
{
public:
    CZmieniaczNazw(QProgressBar *pasekPostepu);

private:
    NameChangeParameters nameChangeParameters;

    QProgressBar *pasekPostepu;

    QString wybranyFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaOstrzezenie;

public:
    void inicjujZmianeNazw(NameChangeParameters nameChangeParameters); //Rozpoczyna procedurę zmiany nazw
    bool wybierzFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    QString zwrocWybranyFolder(); //Zwraca ścieżkę dostępu do folderu

private:
    void wyswietlBrakKatalogu(); //Pokazuje okienko z informacjami, że katalog nie istnieje
    QString usunPodkreslenia(QString nazwaPliku); //Zmienia nazwę pliku zastępując znaki "_" na " "
    QString usunPauzy(QString nazwaPliku); //Zmienia nazwę pliku zastępując znaki "-" na " "
    QString usunKropki(QString nazwaPliku); //Zmienia nazwę pliku zastępując znaki "." na " "
    QString zmienPierwszaDuza(QString nazwaPliku); //Zmienia pierwszą literę na dużą
    QString zmienRozszerzenie(QString nazwaPliku); //Ustawia rozszeżenie pliku pisane z małej litery
    QString zmienNazwePliku(QString nazwaPliku); //Wykonuje operacje zmiany nazwy pliku
    bool czyNazwaIdentyczna(QString nazwaStara, QString nazwaNowa); //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void ustawPasekPostepuZajety(); //Ustawia pasek postępu w stan zajętości
    void inicjujPasekPostepu(int maksimum); //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze
    void zerujPasekPostepu(); //Zeruje pasek postępu
    void rozpocznijZmiane(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    bool czyPrzywrocicKropkeRozszezenia(int pozycjaKropkiRozszerzenia);
    bool czyJestPlikiem(QDir sciezkaDostepu, QString nazwaPliku);
};

#endif // CZMIENIACZNAZW_H
