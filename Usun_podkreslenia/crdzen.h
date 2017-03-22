#ifndef CRDZEN_H
#define CRDZEN_H

#include <QProgressBar>
#include "widgetoprogramie.h"
#include "widgetrejestrzmian.h"
#include "czmieniacznazw.h"
#include "widgetustawienia.h"
#include "custawienia.h"

class CRdzen
{
public:
    CRdzen(QProgressBar *pasekPostepu);

private:

    //----Zmienne przechowujące ustawienia----//
    bool czyZamienicWPodfolderach;
    bool czyZamienicPodkreslenia;
    bool czyZamienicPauzy;
    bool czyZamienicKropki;
    bool czyZamienicKropkeRozszerzenia;
    bool czyPierwszaDuza;
    bool czyRozszerzenieMale;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaTekst;
    QString trescOkienkaOProgramie;
    QString trescOkienkaOstrzezenie;
    QString trescOkienkaRejestrZmian;

    //----Zmienne okienek----//
    WidgetRejestrZmian *oknoRejestrZmian;
    WidgetOProgramie *oknoOProgramie;
    WidgetUstawienia *oknoUstawienia;

    //----Obiekt zmieniający nazwy----//
    CZmieniaczNazw *zmieniaczNazw;

    //----Obiekt czytajacy ustawienia----//
    CUstawienia *czytaczUstawien;

public:
    void zmienNazwy(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    QString wybierzFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlRejestrZmian(); //Wyświetla okienko z rejestrem zmian
    void wyswietlUstawienia(); //Wyświetla okno ustawień

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

#endif // CRDZEN_H
