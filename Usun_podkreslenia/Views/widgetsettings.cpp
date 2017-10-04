#include "WidgetSettings.h"
#include "ui_widgetsettings.h"

WidgetSettings::WidgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettings)
{
    ui->setupUi(this);

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("Ustawienia"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Etykiety--------//
    labelDefaultSettings = new QLabel("Ustawienia domyślne podczas uruchamiania programu",this);

    //--------Przycisk--------//
    buttonOK = new QPushButton("Ok",this);
    buttonOK->setMinimumHeight(30);
    buttonOK->setMaximumWidth(120);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox("Zastąp znaki także w podfolderach");
    checkBoxReplaceUnderscores = new QCheckBox("Zastąp podkreślenia");
    checkBoxReplaceDashes = new QCheckBox("Zastąp pauzy");
    checkBoxDontReplaceDashesSurrondedBySpaces = new QCheckBox("Nie zastępuj pauz otoczonych spacjami");
    checkBoxReplaceDots = new QCheckBox("Zastąp kropki");
    checkBoxReplaceExtensionDot = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń");
    checkBoxReplaceExtensionDot->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    checkBoxRemoveMultiplySpaces = new QCheckBox("Usuń wielokrotne spacje");
    checkBoxRemoveSpacesAtBegin = new QCheckBox("Usuń spacje na początku nazwy");
    checkBoxRemoveSpacesAtEnd = new QCheckBox("Usuń spacje na końcu nazwy");
    checkBoxChangeFirstLetterToBig = new QRadioButton("Zmień pierwszą literę w nazwie pliku na dużą");
    checkBoxChangeLettersToBig = new QRadioButton("Zmień wszystkie litery na duże");
    checkBoxChangeLettersToSmall = new QRadioButton("Zmień wszystkie litery na małe");
    checkBoxChangeFirstLettersToBig = new QRadioButton("Zmień pierwsze litery w słowach na duże");
    checkBoxDontChangeName = new QRadioButton("Nie rób nic");
    checkBoxChangeExtensionToBig = new QRadioButton("Zmień rozszerzenie na pisane dużymi literami");
    checkBoxChangeExtensionToSmall = new QRadioButton("Zmień rozszerzenie na pisane małymi literami");
    checkBoxChangeExtensionFirstLettersToBig = new QRadioButton("Zmień pierwszą literę rozszerzenia na dużą");
    checkBoxChangeDontChangeExtension = new QRadioButton("Nie rób nic");

    //----Layouty----//
    windowVLayout = new QVBoxLayout(this);
    mainHLayout = new QHBoxLayout();
    leftVLayout = new QVBoxLayout();
    rightVLayout = new QVBoxLayout();
    windowVLayout->addWidget(labelDefaultSettings);
    windowVLayout->addLayout(mainHLayout);
    mainHLayout->addLayout(leftVLayout);
    mainHLayout->addLayout(rightVLayout);

    buttonGroupSubfoldersLayout = new QVBoxLayout;
    buttonGroupReplaceLayout = new QVBoxLayout;
    buttonGroupLetterSizeLayout = new QVBoxLayout;
    buttonGroupExtensionSizeLayout = new QVBoxLayout;
    buttonGroupSpaceLayout = new QVBoxLayout;
    buttonHLayout = new QHBoxLayout;
    buttonGroupSubfolders = new QGroupBox("Podfoldery");
    buttonGroupReplace = new QGroupBox("Zastąp znaki");
    buttonGroupLetterSize = new QGroupBox("Zmień rozmiar liter w nazwie");
    buttonGroupExtensionSize = new QGroupBox("Zmień rozmiar liter w rozszerzeniu");
    buttonGroupSpace = new QGroupBox("Spacje");
    leftVLayout->addWidget(buttonGroupSubfolders);
    leftVLayout->addWidget(buttonGroupReplace);
    leftVLayout->addWidget(buttonGroupSpace);
    rightVLayout->addWidget(buttonGroupLetterSize);
    rightVLayout->addWidget(buttonGroupExtensionSize);
    rightVLayout->addLayout(buttonHLayout);

    buttonGroupSubfoldersLayout->addWidget(checkBoxReplaceInSubfolders);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceUnderscores);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceDashes);
    buttonGroupReplaceLayout->addWidget(checkBoxDontReplaceDashesSurrondedBySpaces);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceDots);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceExtensionDot);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveMultiplySpaces);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveSpacesAtBegin);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveSpacesAtEnd);
    buttonGroupLetterSizeLayout->addWidget(checkBoxChangeFirstLetterToBig);
    buttonGroupLetterSizeLayout->addWidget(checkBoxChangeLettersToBig);
    buttonGroupLetterSizeLayout->addWidget(checkBoxChangeLettersToSmall);
    buttonGroupLetterSizeLayout->addWidget(checkBoxChangeFirstLettersToBig);
    buttonGroupLetterSizeLayout->addWidget(checkBoxDontChangeName);
    buttonGroupExtensionSizeLayout->addWidget(checkBoxChangeExtensionToBig);
    buttonGroupExtensionSizeLayout->addWidget(checkBoxChangeExtensionToSmall);
    buttonGroupExtensionSizeLayout->addWidget(checkBoxChangeExtensionFirstLettersToBig);
    buttonGroupExtensionSizeLayout->addWidget(checkBoxChangeDontChangeExtension);

    buttonGroupSubfolders->setLayout(buttonGroupSubfoldersLayout);
    buttonGroupReplace->setLayout(buttonGroupReplaceLayout);
    buttonGroupLetterSize->setLayout(buttonGroupLetterSizeLayout);
    buttonGroupExtensionSize->setLayout(buttonGroupExtensionSizeLayout);
    buttonGroupSpace->setLayout(buttonGroupSpaceLayout);

    buttonHLayout->addWidget(buttonOK);

    //----Przypisanie przycisków do slotów----//
    connect(buttonOK,SIGNAL(clicked()),this,SLOT(closeWindow()));
    connect(checkBoxReplaceDashes,SIGNAL(clicked(bool)),this,SLOT(checkBoxDashesClicked()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));

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
void WidgetSettings::checkBoxDotsClicked()
{
    checkBoxReplaceExtensionDot->setEnabled(checkBoxReplaceDots->isChecked());
}

void WidgetSettings::checkBoxDashesClicked()
{
    checkBoxDontReplaceDashesSurrondedBySpaces->setEnabled(checkBoxReplaceDashes->isChecked());
}

//----Ustawia przyciski danymi z pliku----//
void WidgetSettings::setCheckBoxes()
{
    NameChangeParameters parameters = settingsReader->getNameChangeParameters();

    checkBoxReplaceInSubfolders->setChecked(parameters.getReplaceInSubfolders());
    checkBoxReplaceUnderscores->setChecked(parameters.getReplaceUnderscores());
    checkBoxReplaceDashes->setChecked(parameters.getReplaceDashes());
    checkBoxDontReplaceDashesSurrondedBySpaces->setChecked(parameters.getDontReplaceDashesSurrondedBySpaces());
    checkBoxReplaceDots->setChecked(parameters.getReplaceDots());
    checkBoxReplaceExtensionDot->setChecked(parameters.getReplaceExtensionDot());
    checkBoxRemoveMultiplySpaces->setChecked(parameters.getRemoveMultiplySpaces());
    checkBoxRemoveSpacesAtBegin->setChecked(parameters.getRemoveSpacesAtBegin());
    checkBoxRemoveSpacesAtEnd->setChecked(parameters.getRemoveSpacesAtEnd());

    auto selectionLetters = parameters.getChangeLetters();
    switch(selectionLetters)
    {
    case NameChangeParameters::Letters::FirstBig:
        checkBoxChangeFirstLetterToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::AllBig:
        checkBoxChangeLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::AllSmall:
        checkBoxChangeLettersToSmall->setChecked(true);
        break;
    case NameChangeParameters::Letters::FirstInWordsBig:
        checkBoxChangeFirstLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::DoNothing:
        checkBoxDontChangeName->setChecked(true);
        break;
    }

    auto selectionExtensions = parameters.getChangeExtension();
    switch(selectionExtensions)
    {
    case NameChangeParameters::Extensions::FirstBig:
        checkBoxChangeExtensionFirstLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Extensions::AllBig:
        checkBoxChangeExtensionToBig->setChecked(true);
        break;
    case NameChangeParameters::Extensions::AllSmall:
        checkBoxChangeExtensionToSmall->setChecked(true);
        break;
    case NameChangeParameters::Extensions::DoNothing:
        checkBoxChangeDontChangeExtension->setChecked(true);
        break;
    }

    if(parameters.getReplaceDots() == true)
    {
        checkBoxReplaceExtensionDot->setEnabled(true);
    }
    else
    {
        checkBoxReplaceExtensionDot->setDisabled(true);
    }
    if(parameters.getReplaceDashes() == true)
    {
        checkBoxDontReplaceDashesSurrondedBySpaces->setEnabled(true);
    }
    else
    {
        checkBoxDontReplaceDashesSurrondedBySpaces->setDisabled(true);
    }

}

//----Ustawia czytacz ustawień wartościami checkboxów----//
void WidgetSettings::setSettingsReader()
{
    NameChangeParameters nameChangeParameters;
    nameChangeParameters.setReplaceInSubfolders(checkBoxReplaceInSubfolders->isChecked());
    nameChangeParameters.setReplaceUnderscores(checkBoxReplaceUnderscores->isChecked());
    nameChangeParameters.setReplaceDashes(checkBoxReplaceDashes->isChecked());
    nameChangeParameters.setDontReplaceDashesSurrondedBySpaces(checkBoxDontReplaceDashesSurrondedBySpaces->isChecked());
    nameChangeParameters.setReplaceDots(checkBoxReplaceDots->isChecked());
    nameChangeParameters.setReplaceExtensionDot(checkBoxReplaceExtensionDot->isChecked());
    nameChangeParameters.setRemoveMultiplySpaces(checkBoxRemoveMultiplySpaces->isChecked());
    nameChangeParameters.setRemoveSpacesAtBegin(checkBoxRemoveSpacesAtBegin->isChecked());
    nameChangeParameters.setRemoveSpacesAtEnd(checkBoxRemoveSpacesAtEnd->isChecked());

    if(checkBoxChangeFirstLetterToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstBig);
    }
    else if(checkBoxChangeLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllBig);
    }
    else if(checkBoxChangeLettersToSmall->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllSmall);
    }
    else if(checkBoxChangeFirstLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstInWordsBig);
    }
    else if(checkBoxDontChangeName->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::DoNothing);
    }

    if(checkBoxChangeExtensionFirstLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::FirstBig);
    }
    else if(checkBoxChangeExtensionToBig->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllBig);
    }
    else if(checkBoxChangeExtensionToSmall->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllSmall);
    }
    else if(checkBoxChangeDontChangeExtension->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::DoNothing);
    }
    settingsReader->setNameChangeParameters(nameChangeParameters);
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
