#include "widgetsettings.h"
#include "ui_widgetsettings.h"

WidgetSettings::WidgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettings)
{
    ui->setupUi(this);

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("Ustawienia"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(420,232);
    setMinimumSize(420,232);
    setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Etykiety--------//
    labelDefaultSettings = new QLabel("Ustawienia domyślne podczas uruchamiania programu",this);
    labelDefaultSettings->setGeometry(20,12,380,18);

    //--------Przycisk--------//
    buttonOK = new QPushButton("Ok",this);
    buttonOK->setGeometry(140,191,140,30);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox("Zastąp znaki także w podfolderach",this);
    checkBoxReplaceInSubfolders->setGeometry(20,42,380,18);
    checkBoxReplaceUnderscores = new QCheckBox("Zastąp podkreślenia",this);
    checkBoxReplaceUnderscores->setGeometry(20,72,154,18);
    checkBoxReplaceDashes = new QCheckBox("Zastąp pauzy",this);
    checkBoxReplaceDashes->setGeometry(174,72,116,18);
    checkBoxReplaceDots = new QCheckBox("Zastąp kropki",this);
    checkBoxReplaceDots->setGeometry(290,72,110,18);
    checkBoxReplaceExtensionDot = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń",this);
    checkBoxReplaceExtensionDot->setGeometry(20,102,380,18);
    checkBoxReplaceExtensionDot->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    checkBoxChangeFirstLetterToBig = new QCheckBox("Zmień pierwszą literę w nazwie pliku na dużą",this);
    checkBoxChangeFirstLetterToBig->setGeometry(20,131,380,18);
    checkBoxChangeExtensionToSmall = new QCheckBox("Zmień rozszerzenie na pisane małymi literami",this);
    checkBoxChangeExtensionToSmall->setGeometry(20,161,380,18);

    //----Przypisanie przycisków do slotów----//
    connect(buttonOK,SIGNAL(clicked()),this,SLOT(closeWindow()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(changeCheckBoxExtensionDotActivity()));

    //--------Obiekt czytajacy ustawienia--------//
    settingsReader = new Settings;
    setCheckBoxes();

    move(QApplication::desktop()->screen()->rect().center()-this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetSettings::~WidgetSettings()
{
    delete ui;
}

void WidgetSettings::closeWindow()
{
    setSettingsReader();
    settingsReader->saveSettings();
    this->close();
}

//----Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki----//
void WidgetSettings::changeCheckBoxExtensionDotActivity()
{
    checkBoxReplaceExtensionDot->setEnabled(checkBoxReplaceDots->isChecked());
}

//----Ustawia przyciski danymi z pliku----//
void WidgetSettings::setCheckBoxes()
{
    checkBoxReplaceInSubfolders->setChecked(settingsReader->nameChangeParameters.getReplaceInSubfolders());
    checkBoxReplaceUnderscores->setChecked(settingsReader->nameChangeParameters.getReplaceUnderscores());
    checkBoxReplaceDashes->setChecked(settingsReader->nameChangeParameters.getReplaceDashes());
    checkBoxReplaceDots->setChecked(settingsReader->nameChangeParameters.getReplaceDots());
    checkBoxReplaceExtensionDot->setChecked(settingsReader->nameChangeParameters.getReplaceExtensionDot());
    checkBoxChangeFirstLetterToBig->setChecked(settingsReader->nameChangeParameters.getChangeLetters());
    checkBoxChangeExtensionToSmall->setChecked(settingsReader->nameChangeParameters.getChangeExtension());
    if(checkBoxReplaceDots->isChecked() == true)
        checkBoxReplaceExtensionDot->setEnabled(true);
    else
        checkBoxReplaceExtensionDot->setDisabled(true);
}

//----Ustawia czytacz ustawień wartościami checkboxów----//
void WidgetSettings::setSettingsReader()
{
    settingsReader->nameChangeParameters.setReplaceInSubfolders(checkBoxReplaceInSubfolders->isChecked());
    settingsReader->nameChangeParameters.setReplaceUnderscores(checkBoxReplaceUnderscores->isChecked());
    settingsReader->nameChangeParameters.setReplaceDashes(checkBoxReplaceDashes->isChecked());
    settingsReader->nameChangeParameters.setReplaceDots(checkBoxReplaceDots->isChecked());
    settingsReader->nameChangeParameters.setReplaceExtensionDot(checkBoxReplaceExtensionDot->isChecked());
    settingsReader->nameChangeParameters.setChangeLetters(checkBoxChangeFirstLetterToBig->isChecked());
    settingsReader->nameChangeParameters.setChangeExtension(checkBoxChangeExtensionToSmall->isChecked());
}

//----Pokazuje już utworzone okno----//
void WidgetSettings::showWindow()
{
    settingsReader->readSettings();
    setCheckBoxes();
    if(this->isVisible()) //Jeżeli okno jest widoczne
        this->activateWindow(); //Niech stanie się aktywne
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
