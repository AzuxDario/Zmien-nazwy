#include "czmieniacznazw.h"

CZmieniaczNazw::CZmieniaczNazw(QProgressBar *pasekPostepu)
{
    trescOkienkaOstrzezenie = "Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu";
    this->pasekPostepu = pasekPostepu;
}

void CZmieniaczNazw::inicjujZmianeNazw(bool czyZamienicWPodfolderach, bool czyZamienicPodkreslenia, bool czyZamienicPauzy, bool czyZamienicKropki, bool czyZamienicKropkeRozszerzenia, bool czyPierwszaDuza, bool czyRozszerzenieMale)
{
    this->czyZamienicWPodfolderach = czyZamienicWPodfolderach;
    this->czyZamienicPodkreslenia = czyZamienicPodkreslenia;
    this->czyZamienicPauzy = czyZamienicPauzy;
    this->czyZamienicKropki = czyZamienicKropki;
    this->czyZamienicKropkeRozszerzenia = czyZamienicKropkeRozszerzenia;
    this->czyPierwszaDuza = czyPierwszaDuza;
    this->czyRozszerzenieMale = czyRozszerzenieMale;
    rozpocznijZmiane();
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
bool CZmieniaczNazw::wybierzFolder()
{
    wybranyFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu
    if(wybranyFolder.isNull() == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//----Zwraca ścieżkę dostępu do folderu----//
QString CZmieniaczNazw::zwrocWybranyFolder()
{
    return wybranyFolder;
}

//----Pokazuje okienko z informacjami, że katalog nie istnieje----//
void CZmieniaczNazw::wyswietlBrakKatalogu()
{
    int wcisnietyPrzycisk; //Przechowuje informację o wyborze użytkownika w oknie dialogowym
    QMessageBox okienkoInformacyjne("Ostrzeżenie",trescOkienkaOstrzezenie,QMessageBox::Warning, QMessageBox::Ok | QMessageBox::Default,0,0);
    wcisnietyPrzycisk = okienkoInformacyjne.exec();
    if(wcisnietyPrzycisk == QMessageBox::Ok) //Zamyka okno po wciśnięciu ok
    {
        okienkoInformacyjne.close();
    }
}

//----Zmienia nazwę pliku zastępując znaki "_" na " "----//
QString CZmieniaczNazw::usunPodkreslenia(QString nazwaPliku)
{
    nazwaPliku.replace("_"," ");
    return nazwaPliku;
}

//----Zmienia nazwę pliku zastępując znaki "-" na " "----//
QString CZmieniaczNazw::usunPauzy(QString nazwaPliku)
{
    nazwaPliku.replace("-"," ");
    return nazwaPliku;
}

//----Zmienia nazwę pliku zastępując znaki "." na " "----//
QString CZmieniaczNazw::usunKropki(QString nazwaPliku)
{
    int pozycjaKropkiRozszerzenia = nazwaPliku.lastIndexOf(".");
    nazwaPliku.replace("."," ");
    if((pozycjaKropkiRozszerzenia != -1) && (czyZamienicKropkeRozszerzenia == false))
    {
        nazwaPliku.replace(pozycjaKropkiRozszerzenia,1,".");
    }
    return nazwaPliku;
}

//----Zmienia pierwszą literę na dużą----//
QString CZmieniaczNazw::zmienPierwszaDuza(QString nazwaPliku)
{
    nazwaPliku[0] = nazwaPliku[0].toUpper();
    return nazwaPliku;
}

//----Ustawia rozszeżenie pliku pisane z małej litery----//
QString CZmieniaczNazw::zmienRozszerzenie(QString nazwaPliku)
{
    int pozycjaKropkiRozszerzenia = nazwaPliku.lastIndexOf(".");
    if(pozycjaKropkiRozszerzenia != -1)
    {
        for(int i = pozycjaKropkiRozszerzenia+1; i < nazwaPliku.length(); i++)
        {
        nazwaPliku[i] = nazwaPliku[i].toLower();
        }
    }
    return nazwaPliku;
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString CZmieniaczNazw::zmienNazwePliku(QString nazwaPliku)
{
    if(czyZamienicPodkreslenia == true)
    {
        nazwaPliku = usunPodkreslenia(nazwaPliku);
    }
    if(czyZamienicPauzy == true)
    {
        nazwaPliku = usunPauzy(nazwaPliku);
    }
    if(czyZamienicKropki == true)
    {
        nazwaPliku = usunKropki(nazwaPliku);
    }
    if(czyPierwszaDuza == true)
    {
        nazwaPliku = zmienPierwszaDuza(nazwaPliku);
    }
    if(czyRozszerzenieMale == true)
    {
        nazwaPliku = zmienRozszerzenie(nazwaPliku);
    }
    return nazwaPliku;
}

//----Porównuje dwie nazwy plików jeśli są identyczne zwraca true----//
bool CZmieniaczNazw::czyNazwaIdentyczna(QString nazwaStara, QString nazwaNowa)
{
    if(nazwaStara == nazwaNowa)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//----Ustawia pasek postępu w stan zajętości----//
void CZmieniaczNazw::ustawPasekPostepuZajety()
{
    pasekPostepu->setMaximum(0);
    pasekPostepu->setMinimum(0);
}

//----Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze----//
void CZmieniaczNazw::inicjujPasekPostepu(int maksimum)
{
    pasekPostepu->setMinimum(0);
    pasekPostepu->setMaximum(maksimum);
    pasekPostepu->setValue(0);
}

//----Zeruje pasek postępu----//
void CZmieniaczNazw::zerujPasekPostepu()
{
    pasekPostepu->reset();
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void CZmieniaczNazw::rozpocznijZmiane()
{
    QDir katalogDoZmiany(wybranyFolder);
    if(!katalogDoZmiany.exists()) //Sprawdza czy katalog nie istnieje
    {
        wyswietlBrakKatalogu(); //Wyświetla komunikat o braku katalogu
        wybranyFolder = ""; //Ustawia wybrany folder na ""
        return;
    }
    ustawPasekPostepuZajety();
    CWykrywaczFolderow detektorFolderow(wybranyFolder, czyZamienicWPodfolderach);
    int liczbaPlikow = detektorFolderow.zwrocIloscPlikow();
    inicjujPasekPostepu(liczbaPlikow); //Inicjujemy maksumalną wartość paska postępu

    QStringList listaFolderow = detektorFolderow.zwrocListeFolderow();

    for(auto iteratorListyFolderow = listaFolderow.begin(); iteratorListyFolderow != listaFolderow.end(); iteratorListyFolderow++)
    {
        katalogDoZmiany.cd(*iteratorListyFolderow); //Wchodzimy do przetwarzanego folderu
        //Jeżeli folder nie istnieje lub zniknie idź do kolejnego
        if(!katalogDoZmiany.exists())
        {
            continue;
        }
        for(unsigned int i = 0; i < katalogDoZmiany.count(); i++)
        {
            pasekPostepu->setValue(pasekPostepu->value()+i+1); //Aktualizujemy pasek postępu
            if(!((katalogDoZmiany[i] == ".") || (katalogDoZmiany[i] == "..") || (detektorFolderow.czyJestFolderem(katalogDoZmiany,katalogDoZmiany[i]) == true))) //Unikamy plików "." - aktualny folder i ".." - folder nadrzędny
            {
                QString nazwaPliku = katalogDoZmiany[i];
                QString nowaNazwaPliku = zmienNazwePliku(nazwaPliku); //Otrzymujemy nową nazwę pliku

                if(czyNazwaIdentyczna(nazwaPliku,nowaNazwaPliku))
                {
                    continue;
                }
                else
                {
                    QFile plik(*iteratorListyFolderow + QDir::separator() + nazwaPliku); //Zmieniamy nazwę pliku tylko wtedy kiedy zaszły w niej zmiany
                    plik.rename(*iteratorListyFolderow + QDir::separator() + nowaNazwaPliku);
                }
            }
        }
    }
    zerujPasekPostepu();
    wybranyFolder = "";
}
