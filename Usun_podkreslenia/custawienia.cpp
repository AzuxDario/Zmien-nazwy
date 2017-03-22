#include "custawienia.h"

CUstawienia::CUstawienia()
{
    czyZamienicWPodfolderach = false;
    czyZamienicPodkreslenia = false;
    czyZamienicPauzy = false;
    czyZamienicKropki = false;
    czyZamienicKropkeRozszerzenia = false;
    czyPierwszaDuza = false;
    czyRozszerzenieMale = false;
    czytajUstawienia();
}

//----Czyta ustawienia z pliku----//
bool CUstawienia::czytajUstawienia()
{
    QFile plikUstawien("ustawienia.ini");
    if(!plikUstawien.exists())
    {
        odbudujPlik();
    }
    if(plikUstawien.open(QIODevice::ReadOnly))
    {
        QTextStream zawartoscPliku(&plikUstawien);
        QString linia;
        while(zawartoscPliku.atEnd() == 0)
        {
            linia = zawartoscPliku.readLine();
            zmienUstawienie(linia);
        }
        plikUstawien.close();
        return true;
    }
    else
    {
        return false;
    }
}

//----Zapisuje ustawienia do pliku----//
bool CUstawienia::zapiszUstawienia()
{
    QFile plikUstawien("ustawienia.ini");
    if(plikUstawien.open(QIODevice::WriteOnly))
    {
        QTextStream strumien(&plikUstawien);
        strumien << "[Ustawienia]" << endl;
        strumien << "czyZamienicWPodfolderach=";
        if(czyZamienicWPodfolderach == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyZamienicPodkreslenia=";
        if(czyZamienicPodkreslenia == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyZamienicPauzy=";
        if(czyZamienicPauzy == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyZamienicKropki=";
        if(czyZamienicKropki == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyZamienicKropkeRozszerzenia=";
        if(czyZamienicKropkeRozszerzenia == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyPierwszaDuza=";
        if(czyPierwszaDuza == true)
        {
            strumien << "1" << endl;
        }
        else
        {
            strumien << "0" << endl;
        }
        strumien << "czyRozszerzenieMale=";
        if(czyRozszerzenieMale == true)
        {
            strumien << "1";
        }
        else
        {
            strumien << "0";
        }
        plikUstawien.close();
        return true;
    }
    else
    {
        return false;
    }
}

//----Tworzy plik ustawień----//
bool CUstawienia::odbudujPlik()
{
    QFile plikUstawien("ustawienia.ini");
    if(plikUstawien.open(QIODevice::WriteOnly))
    {
        QTextStream strumien(&plikUstawien);
        strumien << "[Ustawienia]" << endl;
        strumien << "czyZamienicWPodfolderach=0" << endl;
        strumien << "czyZamienicPodkreslenia=0" << endl;
        strumien << "czyZamienicPauzy=0" << endl;
        strumien << "czyZamienicKropki=0" << endl;
        strumien << "czyZamienicKropkeRozszerzenia=0" << endl;
        strumien << "czyPierwszaDuza=0" << endl;
        strumien << "czyRozszerzenieMale=0";
        plikUstawien.close();
        return true;
    }
    else
    {
        return false;
    }
}

//----Zmienia ustawienie, przyjmuje linie z pliku ustawien----//
void CUstawienia::zmienUstawienie(QString linia)
{
    int pozycjaZnakuRownosci = linia.indexOf("=");
    QString opcja;
    for(int i = 0; i < pozycjaZnakuRownosci; i++)
    {
        opcja.append(linia.at(i));
    }
    QChar wartosc = linia.at(pozycjaZnakuRownosci+1);
    if(opcja == "czyZamienicWPodfolderach")
    {
        if(wartosc == '1')
        {
            czyZamienicWPodfolderach = true;
        }
        else
        {
            czyZamienicWPodfolderach = false;
        }
    }
    else if(opcja == "czyZamienicPodkreslenia")
    {
        if(wartosc == '1')
        {
            czyZamienicPodkreslenia = true;
        }
        else
        {
            czyZamienicPodkreslenia = false;
        }
    }
    else if(opcja == "czyZamienicPauzy")
    {
        if(wartosc == '1')
        {
            czyZamienicPauzy = true;
        }
        else
        {
            czyZamienicPauzy = false;
        }
    }
    else if(opcja == "czyZamienicKropki")
    {
        if(wartosc == '1')
        {
            czyZamienicKropki = true;
        }
        else
        {
            czyZamienicKropki = false;
        }
    }
    else if(opcja == "czyZamienicKropkeRozszerzenia")
    {
        if(wartosc == '1')
        {
            czyZamienicKropkeRozszerzenia = true;
        }
        else
        {
            czyZamienicKropkeRozszerzenia = false;
        }
    }
    else if(opcja == "czyPierwszaDuza")
    {
        if(wartosc == '1')
        {
            czyPierwszaDuza = true;
        }
        else
        {
            czyPierwszaDuza = false;
        }
    }
    else if(opcja == "czyRozszerzenieMale")
    {
        if(wartosc == '1')
        {
            czyRozszerzenieMale = true;
        }
        else
        {
            czyRozszerzenieMale = false;
        }
    }
}

//----Funkcje dostępu do pól prywatnych----//
void CUstawienia::ustawCzyZamienicWPodfolderach(bool wartosc)
{
    czyZamienicWPodfolderach = wartosc;
}

void CUstawienia::ustawCzyZamienicPodkreslenia(bool wartosc)
{
    czyZamienicPodkreslenia = wartosc;
}

void CUstawienia::ustawCzyZamienicPauzy(bool wartosc)
{
    czyZamienicPauzy = wartosc;
}

void CUstawienia::ustawCzyZamienicKropki(bool wartosc)
{
    czyZamienicKropki = wartosc;
}

void CUstawienia::ustawCzyZamienicKropkeRozszerzenia(bool wartosc)
{
    czyZamienicKropkeRozszerzenia = wartosc;
}

void CUstawienia::ustawCzyPierwszaDuza(bool wartosc)
{
    czyPierwszaDuza = wartosc;
}

void CUstawienia::ustawCzyRozszerzenieMale(bool wartosc)
{
    czyRozszerzenieMale = wartosc;
}

bool CUstawienia::zwrocCzyZamienicWPodfolderach()
{
    return czyZamienicWPodfolderach;
}

bool CUstawienia::zwrocCzyZamienicPodkreslenia()
{
    return czyZamienicPodkreslenia;
}

bool CUstawienia::zwrocCzyZamienicPauzy()
{
    return czyZamienicPauzy;
}

bool CUstawienia::zwrocCzyZamienicKropki()
{
    return czyZamienicKropki;
}

bool CUstawienia::zwrocCzyZamienicKropkeRozszerzenia()
{
    return czyZamienicKropkeRozszerzenia;
}

bool CUstawienia::zwrocCzyPierwszaDuza()
{
    return czyPierwszaDuza;
}

bool CUstawienia::zwrocCzyRozszerzenieMale()
{
    return czyRozszerzenieMale;
}
