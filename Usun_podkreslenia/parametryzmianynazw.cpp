#include "parametryzmianynazw.h"

ParametryZmianyNazw::ParametryZmianyNazw()
{
    czyZamienicWPodfolderach = false;
    czyZamienicPodkreslenia = false;
    czyZamienicPauzy = false;
    czyZamienicKropki = false;
    czyZamienicKropkeRozszerzenia = false;
    czyPierwszaDuza = false;
    czyRozszerzenieMale = false;
}

void ParametryZmianyNazw::ustawCzyZamienicWPodfolderach(bool wartosc)
{
    czyZamienicWPodfolderach = wartosc;
}

void ParametryZmianyNazw::ustawCzyZamienicPodkreslenia(bool wartosc)
{
    czyZamienicPodkreslenia = wartosc;
}

void ParametryZmianyNazw::ustawCzyZamienicPauzy(bool wartosc)
{
    czyZamienicPauzy = wartosc;
}

void ParametryZmianyNazw::ustawCzyZamienicKropki(bool wartosc)
{
    czyZamienicKropki = wartosc;
}

void ParametryZmianyNazw::ustawCzyZamienicKropkeRozszerzenia(bool wartosc)
{
    czyZamienicKropkeRozszerzenia = wartosc;
}

void ParametryZmianyNazw::ustawCzyPierwszaDuza(bool wartosc)
{
    czyPierwszaDuza = wartosc;
}

void ParametryZmianyNazw::ustawCzyRozszerzenieMale(bool wartosc)
{
    czyRozszerzenieMale = wartosc;
}

bool ParametryZmianyNazw::zwrocCzyZamienicWPodfolderach()
{
    return czyZamienicWPodfolderach;
}

bool ParametryZmianyNazw::zwrocCzyZamienicPodkreslenia()
{
    return czyZamienicPodkreslenia;
}

bool ParametryZmianyNazw::zwrocCzyZamienicPauzy()
{
    return czyZamienicPauzy;
}

bool ParametryZmianyNazw::zwrocCzyZamienicKropki()
{
    return czyZamienicKropki;
}

bool ParametryZmianyNazw::zwrocCzyZamienicKropkeRozszerzenia()
{
    return czyZamienicKropkeRozszerzenia;
}

bool ParametryZmianyNazw::zwrocCzyPierwszaDuza()
{
    return czyPierwszaDuza;
}

bool ParametryZmianyNazw::zwrocCzyRozszerzenieMale()
{
    return czyRozszerzenieMale;
}
