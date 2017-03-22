#ifndef CUSTAWIENIA_H
#define CUSTAWIENIA_H

#include <QFile>
#include <QTextStream>
#include <QString>

class CUstawienia
{
public:
    CUstawienia();

private:
    //----Zmienne przechowujące ustawienia----//
    bool czyZamienicWPodfolderach;
    bool czyZamienicPodkreslenia;
    bool czyZamienicPauzy;
    bool czyZamienicKropki;
    bool czyZamienicKropkeRozszerzenia;
    bool czyPierwszaDuza;
    bool czyRozszerzenieMale;


public:
    bool czytajUstawienia(); //Czyta ustawienia z pliku
    bool zapiszUstawienia(); //Zapisuje ustawienia do pliku
private:
    bool odbudujPlik(); //Tworzy plik ustawień
    void zmienUstawienie(QString linia); //Zmienia ustawienie, przyjmuje linie z pliku ustawien

public:
    //----Funkcje dostępu do pól prywatnych----//
    void ustawCzyZamienicWPodfolderach(bool wartosc);
    void ustawCzyZamienicPodkreslenia(bool wartosc);
    void ustawCzyZamienicPauzy(bool wartosc);
    void ustawCzyZamienicKropki(bool wartosc);
    void ustawCzyZamienicKropkeRozszerzenia(bool wartosc);
    void ustawCzyPierwszaDuza(bool wartosc);
    void ustawCzyRozszerzenieMale(bool wartosc);

    bool zwrocCzyZamienicWPodfolderach();
    bool zwrocCzyZamienicPodkreslenia();
    bool zwrocCzyZamienicPauzy();
    bool zwrocCzyZamienicKropki();
    bool zwrocCzyZamienicKropkeRozszerzenia();
    bool zwrocCzyPierwszaDuza();
    bool zwrocCzyRozszerzenieMale();
};

#endif // CUSTAWIENIA_H
