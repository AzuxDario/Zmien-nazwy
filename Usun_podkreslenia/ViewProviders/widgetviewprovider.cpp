#include "WidgetViewProvider.h"

WidgetViewProvider::WidgetViewProvider()
{
    widgetAboutText = "Wersja programu: 4.0\nProgram zamienia znaki podkreślenia, pauzy oraz kropki (poza kropką oddzielającą nazwę pliku od rozszerzenia) "
            "na spację w nazwach plików w wybranym folderze.\n© Paweł Miękina";
    widgetChangeLogText = "Wersja: 4.0 (19.07.2017)\n- dodanie nowych ustawień\n- przebudowa okna\n- usunięcie akcji z menu\n"
            "Wersja: 3.4 (08.03.2017)\n- dodanie klasy przechowującej ustawenia zmiany nazw\n- uporządkowanie kodu\n"
            "Wersja: 3.3 (26.10.2016)\n- dodano ustawienia z możliwością zapisu\n- dodano możliwość zmiany nazw plików w podfolderach\n"
            "- program nie zmienia już nazw podfolderom\n- czyszczenie kodu\n- dodanie klasy (rdzenia)\n"
            "Wersja: 3.2 (23.10.2016)\n- dodano możliwość zmiany rozszerzenia pliku na pisane małymi literami\n"
            "Wersja: 3.1 (19.10.2016)\n- dodano możliwość zmiany pierwszej litery pliku na dużą\n"
            "Wersja: 3.0 (18.10.2016)\n- przejście na Qt 5.7\n- dodano skalowanie aplikacji\n"
            "Wersja: 2.5 (12.10.2016)\n- zmieniono metodę zmiany nazw plików (dodano klasę)\n- dodano ikonę programu\n"
            "Wersja: 2.4 (11.10.2016)\n- dodano skróty klawiaturowe\n- okna pojawiają się na środku ekranu\n- zmieniono okno o programie\n- dodano możliwość zmiany folderu po wybraniu\n"
            "Wersja: 2.3 (07.10.2016)\n- zmieniono okno rejestr zmian\n- program zamyka się po zamknięciu głównego okna\n"
            "Wersja: 2.2 (06.10.2016)\n- dodano ikony\n- zmieniono nazwę programu\n"
            "Wersja: 2.1 (05.10.2016) \n- dodano menu ustawienia\n"
            "Wersja: 2.0 (05.10.2016)\n- dodano możliwość wyboru zamienianych znaków (podkreślenie, pauza, kropka)\n- dodano rejestr zmian\n"
            "- podczas zmiany nazwy przyciski oraz przyciski wyboru zostają dezaktywowane\n- możliwość usunięcia ostatniej kropki jeżeli pliki nie posiadają rozszerzeń\n"
            "Wersja: 1.0 (23.09.2016)\n- możliwość zamiany znaku podkreślenia w nazwie pliku na odstęp";

    //--------Wskaźnik na okienko rejestr zmian--------//
    widgetChangeLog = NULL; //Bez tego będzie crash Segmentation Fault
    widgetAbout = NULL;
    widgetSettings = NULL;

    nameChanger = new NameChanger();

    //--------Obiekt czytajacy ustawienia--------//
    settingsReader = new Settings;

    nameChangeParameters = settingsReader->getNameChangeParameters();
    connect(nameChanger,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBarSlot(int,int)));
    connect(nameChanger,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBarSlot(int)));
    connect(nameChanger,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBarSlot()));
}

void WidgetViewProvider::changeName(NameChangeParameters nameChangeParameters)
{
    nameChanger->initiateRenameFiles(nameChangeParameters);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
QString WidgetViewProvider::selectFolder()
{
    bool stanOperacji = nameChanger->selectFolder(); //Otwiera okno wyboru pliku

    if(stanOperacji == true)
        return nameChanger->getSelectedFolder();
    else
       return "";
}

//----Pokazuje okienko z informacjami o programie----//
void WidgetViewProvider::showWidgetAbout()
{
    if(widgetAbout == NULL) //Jeżli okna nie ma stwórz je
        widgetAbout = new WidgetAbout(widgetAboutText);
    else
        widgetAbout->showWindow();
}

//----Wyświetla okno ustawień----//
void WidgetViewProvider::showWidgetSettings()
{
    if(widgetSettings == NULL) //Jeżli okna nie ma stwórz je
        widgetSettings = new WidgetSettings();
    else
        widgetSettings->showWindow();
}

//----Wyświetla okienko z rejestrem zmian----//
void WidgetViewProvider::showWidgetChangeLog()
{
    if(widgetChangeLog == NULL) //Jeżli okna nie ma stwórz je
        widgetChangeLog = new WidgetChangeLog(widgetChangeLogText);
    else
        widgetChangeLog->showWindow();
}
