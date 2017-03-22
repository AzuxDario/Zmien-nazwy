#include "czmieniacznazw.h"

CZmieniaczNazw::CZmieniaczNazw(QProgressBar *pasekPostepu)
{
    trescOkienkaOstrzezenie = "Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu";
    this->pasekPostepu = pasekPostepu;
}

void CZmieniaczNazw::inicjujZmianeNazw(ParametryZmianyNazw parametryZmianyNazw)
{
    this->parametryZmianyNazw = parametryZmianyNazw;
    rozpocznijZmiane();
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
bool CZmieniaczNazw::wybierzFolder()
{
    wybranyFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu
    if(wybranyFolder.isNull() == false)
        return true;
    else
        return false;
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
        okienkoInformacyjne.close();
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
    if(czyPrzywrocicKropkeRozszezenia(pozycjaKropkiRozszerzenia))
        nazwaPliku.replace(pozycjaKropkiRozszerzenia,1,".");
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
        for(int i = pozycjaKropkiRozszerzenia+1; i < nazwaPliku.length(); i++)
            nazwaPliku[i] = nazwaPliku[i].toLower();
    return nazwaPliku;
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString CZmieniaczNazw::zmienNazwePliku(QString nazwaPliku)
{
    if(parametryZmianyNazw.zwrocCzyZamienicPodkreslenia() == true)
        nazwaPliku = usunPodkreslenia(nazwaPliku);
    if(parametryZmianyNazw.zwrocCzyZamienicPauzy() == true)
        nazwaPliku = usunPauzy(nazwaPliku);
    if(parametryZmianyNazw.zwrocCzyZamienicKropki() == true)
        nazwaPliku = usunKropki(nazwaPliku);
    if(parametryZmianyNazw.zwrocCzyPierwszaDuza() == true)
        nazwaPliku = zmienPierwszaDuza(nazwaPliku);
    if(parametryZmianyNazw.zwrocCzyRozszerzenieMale() == true)
        nazwaPliku = zmienRozszerzenie(nazwaPliku);
    return nazwaPliku;
}

//----Porównuje dwie nazwy plików jeśli są identyczne zwraca true----//
bool CZmieniaczNazw::czyNazwaIdentyczna(QString nazwaStara, QString nazwaNowa)
{
    if(nazwaStara == nazwaNowa)
        return true;
    else
        return false;
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
    if(!katalogDoZmiany.exists())
    {
        wyswietlBrakKatalogu();
        wybranyFolder = "";
        return;
    }
    ustawPasekPostepuZajety();
    CWykrywaczFolderow detektorFolderow(wybranyFolder, parametryZmianyNazw.zwrocCzyZamienicWPodfolderach());
    int liczbaPlikow = detektorFolderow.zwrocIloscPlikow();
    inicjujPasekPostepu(liczbaPlikow);

    QStringList listaFolderow = detektorFolderow.zwrocListeFolderow();

    for(auto iteratorListyFolderow = listaFolderow.begin(); iteratorListyFolderow != listaFolderow.end(); iteratorListyFolderow++)
    {
        QString folderWKtorymZmeniamyNazwy = *iteratorListyFolderow;
        katalogDoZmiany.cd(folderWKtorymZmeniamyNazwy);
        if(!katalogDoZmiany.exists())
            continue;
        for(unsigned int i = 0; i < katalogDoZmiany.count(); i++)
        {
            pasekPostepu->setValue(pasekPostepu->value()+i+1);

            if(czyJestPlikiem(katalogDoZmiany, katalogDoZmiany[i]))
            {
                QString nazwaPliku = katalogDoZmiany[i];
                QString nowaNazwaPliku = zmienNazwePliku(nazwaPliku);
                if(czyNazwaIdentyczna(nazwaPliku,nowaNazwaPliku))
                    continue;
                else
                {
                    QFile plik(folderWKtorymZmeniamyNazwy + QDir::separator() + nazwaPliku);
                    plik.rename(folderWKtorymZmeniamyNazwy + QDir::separator() + nowaNazwaPliku);
                }
            }
        }
    }
    zerujPasekPostepu();
    wybranyFolder = "";
}

bool CZmieniaczNazw::czyPrzywrocicKropkeRozszezenia(int pozycjaKropkiRozszerzenia)
{
    if((pozycjaKropkiRozszerzenia != -1) && (parametryZmianyNazw.zwrocCzyZamienicKropkeRozszerzenia() == false))
        return true;
    else
        return false;
}

bool CZmieniaczNazw::czyJestPlikiem(QDir sciezkaDostepu, QString nazwaPliku)
{
     return !CWykrywaczFolderow::czyJestPodfolderem(sciezkaDostepu, nazwaPliku);
}
