#include "widgetustawienia.h"
#include "ui_widgetustawienia.h"

WidgetUstawienia::WidgetUstawienia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetUstawienia)
{
    ui->setupUi(this);

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("Rejestr zmian"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(420,232);
    setMinimumSize(420,232);
    setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Etykiety--------//
    opisOkna = new QLabel("Ustawienia domyślne podczas uruchamiania programu",this);
    opisOkna->setGeometry(20,12,380,18);

    //--------Przycisk--------//
    przyciskOk = new QPushButton("Ok",this);
    przyciskOk->setGeometry(140,191,140,30);

    //--------Check Boxy--------//
    przyciskWyboruPodfoldery = new QCheckBox("Zastąp znaki także w podfolderach",this);
    przyciskWyboruPodfoldery->setGeometry(20,42,380,18);
    przyciskWyboruZastapPodkreslenia = new QCheckBox("Zastąp podkreślenia",this);
    przyciskWyboruZastapPodkreslenia->setGeometry(20,72,154,18);
    przyciskWyboruZastapPauzy = new QCheckBox("Zastąp pauzy",this);
    przyciskWyboruZastapPauzy->setGeometry(174,72,116,18);
    przyciskWyboruZastapKropki = new QCheckBox("Zastąp kropki",this);
    przyciskWyboruZastapKropki->setGeometry(290,72,110,18);
    przyciskWyboruUsunKropkeRozszerzenia = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń",this);
    przyciskWyboruUsunKropkeRozszerzenia->setGeometry(20,102,380,18);
    przyciskWyboruUsunKropkeRozszerzenia->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    przyciskWyboruUstawPierwszaDuza = new QCheckBox("Zmień pierwszą literę w nazwie pliku na dużą",this);
    przyciskWyboruUstawPierwszaDuza->setGeometry(20,131,380,18);
    przyciskWyboruUstawRozszerzenieMale = new QCheckBox("Zmień rozszerzenie na pisane małymi literami",this);
    przyciskWyboruUstawRozszerzenieMale->setGeometry(20,161,380,18);

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked()),this,SLOT(zamknijOkno()));
    connect(przyciskWyboruZastapKropki,SIGNAL(clicked()),this,SLOT(zmienAktywnoscPrzyciskuKropkiRozszerzenia()));

    //--------Obiekt czytajacy ustawienia--------//
    czytaczUstawien = new Settings;
    ustawPrzyciski();

    move(QApplication::desktop()->screen()->rect().center()-this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetUstawienia::~WidgetUstawienia()
{
    delete ui;
}

void WidgetUstawienia::zamknijOkno()
{
    ustawCzytacz();
    czytaczUstawien->saveSettings();
    this->close();
}

//----Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki----//
void WidgetUstawienia::zmienAktywnoscPrzyciskuKropkiRozszerzenia()
{
    przyciskWyboruUsunKropkeRozszerzenia->setEnabled(przyciskWyboruZastapKropki->isChecked());
}

//----Ustawia przyciski danymi z pliku----//
void WidgetUstawienia::ustawPrzyciski()
{
    przyciskWyboruPodfoldery->setChecked(czytaczUstawien->nameChangeParameters.getReplaceInSubfolders());
    przyciskWyboruZastapPodkreslenia->setChecked(czytaczUstawien->nameChangeParameters.getReplaceUnderscores());
    przyciskWyboruZastapPauzy->setChecked(czytaczUstawien->nameChangeParameters.getReplaceDashes());
    przyciskWyboruZastapKropki->setChecked(czytaczUstawien->nameChangeParameters.getReplaceDots());
    przyciskWyboruUsunKropkeRozszerzenia->setChecked(czytaczUstawien->nameChangeParameters.getReplaceExtensionDot());
    przyciskWyboruUstawPierwszaDuza->setChecked(czytaczUstawien->nameChangeParameters.getChangeFirstLetterToBig());
    przyciskWyboruUstawRozszerzenieMale->setChecked(czytaczUstawien->nameChangeParameters.getChangeExtensionToSmall());
    if(przyciskWyboruZastapKropki->isChecked() == true)
        przyciskWyboruUsunKropkeRozszerzenia->setEnabled(true);
    else
        przyciskWyboruUsunKropkeRozszerzenia->setDisabled(true);
}

//----Ustawia czytacz ustawień wartościami checkboxów----//
void WidgetUstawienia::ustawCzytacz()
{
    czytaczUstawien->nameChangeParameters.setReplaceInSubfolders(przyciskWyboruPodfoldery->isChecked());
    czytaczUstawien->nameChangeParameters.setReplaceUnderscores(przyciskWyboruZastapPodkreslenia->isChecked());
    czytaczUstawien->nameChangeParameters.setReplaceDashes(przyciskWyboruZastapPauzy->isChecked());
    czytaczUstawien->nameChangeParameters.setReplaceDots(przyciskWyboruZastapKropki->isChecked());
    czytaczUstawien->nameChangeParameters.setReplaceExtensionDot(przyciskWyboruUsunKropkeRozszerzenia->isChecked());
    czytaczUstawien->nameChangeParameters.setChangeFirstLetterToBig(przyciskWyboruUstawPierwszaDuza->isChecked());
    czytaczUstawien->nameChangeParameters.setChangeExtensionToSmall(przyciskWyboruUstawRozszerzenieMale->isChecked());
}

//----Pokazuje już utworzone okno----//
void WidgetUstawienia::pokazSie()
{
    czytaczUstawien->readSettings();
    ustawPrzyciski();
    if(this->isVisible()) //Jeżeli okno jest widoczne
        this->activateWindow(); //Niech stanie się aktywne
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
