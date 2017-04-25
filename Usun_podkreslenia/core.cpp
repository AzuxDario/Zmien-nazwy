#include "core.h"

Core::Core(QProgressBar *progressBar)
{
    trescOkienkaOProgramie = "Wersja programu: 3.4\nProgram zamienia znaki podkreślenia, pauzy oraz kropki (poza kropką oddzielającą nazwę pliku od rozszerzenia) na spację w nazwach plików w wybranym folderze.\n© Paweł Miękina";
    trescOkienkaRejestrZmian = "Wersja: 3.4 (08.03.2017)\n- dodanie klasy przechowującej ustawenia zmiany nazw\n- uporządkowanie kodu\nWersja: 3.3 (26.10.2016)\n- dodano ustawienia z możliwością zapisu\n- dodano możliwość zmiany nazw plików w podfolderach\n- program nie zmienia już nazw podfolderom\n- czyszczenie kodu\n- dodanie klasy (rdzenia)\nWersja: 3.2 (23.10.2016)\n- dodano możliwość zmiany rozszerzenia pliku na pisane małymi literami\nWersja: 3.1 (19.10.2016)\n- dodano możliwość zmiany pierwszej litery pliku na dużą\nWersja: 3.0 (18.10.2016)\n- przejście na Qt 5.7\n- dodano skalowanie aplikacji\nWersja: 2.5 (12.10.2016)\n- zmieniono metodę zmiany nazw plików (dodano klasę)\n- dodano ikonę programu\nWersja: 2.4 (11.10.2016)\n- dodano skróty klawiaturowe\n- okna pojawiają się na środku ekranu\n- zmieniono okno o programie\n- dodano możliwość zmiany folderu po wybraniu\nWersja: 2.3 (07.10.2016)\n- zmieniono okno rejestr zmian\n- program zamyka się po zamknięciu głównego okna\nWersja: 2.2 (06.10.2016)\n- dodano ikony\n- zmieniono nazwę programu\nWersja: 2.1 (05.10.2016) \n- dodano menu ustawienia\nWersja: 2.0 (05.10.2016)\n- dodano możliwość wyboru zamienianych znaków (podkreślenie, pauza, kropka)\n- dodano rejestr zmian\n- podczas zmiany nazwy przyciski oraz przyciski wyboru zostają dezaktywowane\n- możliwość usunięcia ostatniej kropki jeżeli pliki nie posiadają rozszerzeń\nWersja: 1.0 (23.09.2016)\n- możliwość zamiany znaku podkreślenia w nazwie pliku na odstęp";

    //--------Wskaźnik na okienko rejestr zmian--------//
    oknoRejestrZmian = NULL; //Bez tego będzie crash Segmentation Fault
    oknoOProgramie = NULL;
    oknoUstawienia = NULL;

    zmieniaczNazw = new CZmieniaczNazw(progressBar);

    //--------Obiekt czytajacy ustawienia--------//
    czytaczUstawien = new Settings;

    nameChangeParameters = czytaczUstawien->nameChangeParameters;
}

void Core::zmienNazwy()
{
    zmieniaczNazw->inicjujZmianeNazw(nameChangeParameters);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
QString Core::wybierzFolder()
{
    bool stanOperacji = zmieniaczNazw->wybierzFolder(); //Otwiera okno wyboru pliku

    if(stanOperacji == true)
        return zmieniaczNazw->zwrocWybranyFolder();
    else
       return "";
}

//----Pokazuje okienko z informacjami o programie----//
void Core::wyswietlOProgramie()
{
    if(oknoOProgramie == NULL) //Jeżli okna nie ma stwórz je
        oknoOProgramie = new WidgetOProgramie(trescOkienkaOProgramie);
    else
        oknoOProgramie->pokazSie();
}

//----Wyświetla okno ustawień----//
void Core::wyswietlUstawienia()
{
    if(oknoUstawienia == NULL) //Jeżli okna nie ma stwórz je
        oknoUstawienia = new WidgetUstawienia();
    else
        oknoUstawienia->pokazSie();
}

//----Wyświetla okienko z rejestrem zmian----//
void Core::wyswietlRejestrZmian()
{
    if(oknoRejestrZmian == NULL) //Jeżli okna nie ma stwórz je
        oknoRejestrZmian = new WidgetRejestrZmian(trescOkienkaRejestrZmian);
    else
        oknoRejestrZmian->pokazSie();
}
