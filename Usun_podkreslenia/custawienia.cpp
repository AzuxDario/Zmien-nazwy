#include "custawienia.h"

CUstawienia::CUstawienia()
{
    czytajUstawienia();
}

//----Czyta ustawienia z pliku----//
bool CUstawienia::czytajUstawienia()
{
    QFile plikUstawien("ustawienia.ini");
    if(!plikUstawien.exists())
        odbudujPlik();
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
        return false;
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
        if(parametryZmianyNazw.zwrocCzyZamienicWPodfolderach() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyZamienicPodkreslenia=";
        if(parametryZmianyNazw.zwrocCzyZamienicPodkreslenia() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyZamienicPauzy=";
        if(parametryZmianyNazw.zwrocCzyZamienicPauzy() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyZamienicKropki=";
        if(parametryZmianyNazw.zwrocCzyZamienicKropki() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyZamienicKropkeRozszerzenia=";
        if(parametryZmianyNazw.zwrocCzyZamienicKropkeRozszerzenia() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyPierwszaDuza=";
        if(parametryZmianyNazw.zwrocCzyPierwszaDuza() == true)
            strumien << "1" << endl;
        else
            strumien << "0" << endl;
        strumien << "czyRozszerzenieMale=";
        if(parametryZmianyNazw.zwrocCzyRozszerzenieMale() == true)
            strumien << "1";
        else
            strumien << "0";
        plikUstawien.close();
        return true;
    }
    else
        return false;
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
        return false;
}

//----Zmienia ustawienie, przyjmuje linie z pliku ustawien----//
void CUstawienia::zmienUstawienie(QString linia)
{
    QString opcja = linia.split("=")[0];
    if(linia != "[Ustawienia]")
    {
        int wartosc = linia.split("=")[1].toInt();
        if(opcja == "czyZamienicWPodfolderach")
            parametryZmianyNazw.ustawCzyZamienicWPodfolderach(wartosc);
        else if(opcja == "czyZamienicPodkreslenia")
            parametryZmianyNazw.ustawCzyZamienicPodkreslenia(wartosc);
        else if(opcja == "czyZamienicPauzy")
            parametryZmianyNazw.ustawCzyZamienicPauzy(wartosc);
        else if(opcja == "czyZamienicKropki")
            parametryZmianyNazw.ustawCzyZamienicKropki(wartosc);
        else if(opcja == "czyZamienicKropkeRozszerzenia")
            parametryZmianyNazw.ustawCzyZamienicKropkeRozszerzenia(wartosc);
        else if(opcja == "czyPierwszaDuza")
            parametryZmianyNazw.ustawCzyPierwszaDuza(wartosc);
        else if(opcja == "czyRozszerzenieMale")
            parametryZmianyNazw.ustawCzyRozszerzenieMale(wartosc);
    }
}
