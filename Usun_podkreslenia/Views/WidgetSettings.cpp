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
    buttonCancel = new QPushButton("Anuluj",this);
    buttonCancel->setMinimumHeight(30);
    buttonCancel->setMaximumWidth(120);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox(tr(Views::checkBoxReplaceInSubfolders));
    checkBoxReplaceUnderscores = new QCheckBox(tr(Views::checkBoxReplaceUnderscores));
    checkBoxReplaceDashes = new QCheckBox(tr(Views::checkBoxReplaceDashes));
    checkBoxDontReplaceDashesSurrondedBySpaces = new QCheckBox(tr(Views::checkBoxDontReplaceDashesSurrondedBySpaces));
    checkBoxReplaceDots = new QCheckBox(tr(Views::checkBoxReplaceDots));
    checkBoxReplaceExtensionDot = new QCheckBox(tr(Views::checkBoxReplaceExtensionDot));
    checkBoxRemoveMultiplySpaces = new QCheckBox(tr(Views::checkBoxRemoveMultiplySpaces));
    checkBoxRemoveSpacesAtBegin = new QCheckBox(tr(Views::checkBoxRemoveSpacesAtBegin));
    checkBoxRemoveSpacesAtEnd = new QCheckBox(tr(Views::checkBoxRemoveSpacesAtEnd));
    radioButtonChangeFirstLetterToBig = new QRadioButton(tr(Views::radioButtonChangeFirstLetterToBig));
    radioButtonChangeLettersToBig = new QRadioButton(tr(Views::radioButtonChangeLettersToBig));
    radioButtonChangeLettersToSmall = new QRadioButton(tr(Views::radioButtonChangeLettersToSmall));
    radioButtonChangeFirstLettersToBig = new QRadioButton(tr(Views::radioButtonChangeFirstLettersToBig));
    radioButtonDontChangeName = new QRadioButton(tr(Views::radioButtonDontChange));
    radioButtonChangeExtensionToBig = new QRadioButton(tr(Views::radioButtonChangeExtensionToBig));
    radioButtonChangeExtensionToSmall = new QRadioButton(tr(Views::radioButtonChangeExtensionToSmall));
    radioButtonChangeExtensionFirstLettersToBig = new QRadioButton(tr(Views::radioButtonChangeExtensionFirstLettersToBig));
    radioButtonChangeDontChangeExtension = new QRadioButton(tr(Views::radioButtonDontChange));

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
    buttonGroupSubfolders = new QGroupBox(tr(Views::buttonGroupSubfolders));
    buttonGroupReplace = new QGroupBox(tr(Views::buttonGroupReplace));
    buttonGroupLetterSize = new QGroupBox(tr(Views::buttonGroupLetterSize));
    buttonGroupExtensionSize = new QGroupBox(tr(Views::buttonGroupExtensionSize));
    buttonGroupSpace = new QGroupBox(tr(Views::buttonGroupSpace));
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
    buttonGroupLetterSizeLayout->addWidget(radioButtonChangeFirstLetterToBig);
    buttonGroupLetterSizeLayout->addWidget(radioButtonChangeLettersToBig);
    buttonGroupLetterSizeLayout->addWidget(radioButtonChangeLettersToSmall);
    buttonGroupLetterSizeLayout->addWidget(radioButtonChangeFirstLettersToBig);
    buttonGroupLetterSizeLayout->addWidget(radioButtonDontChangeName);
    buttonGroupExtensionSizeLayout->addWidget(radioButtonChangeExtensionToBig);
    buttonGroupExtensionSizeLayout->addWidget(radioButtonChangeExtensionToSmall);
    buttonGroupExtensionSizeLayout->addWidget(radioButtonChangeExtensionFirstLettersToBig);
    buttonGroupExtensionSizeLayout->addWidget(radioButtonChangeDontChangeExtension);

    buttonGroupSubfolders->setLayout(buttonGroupSubfoldersLayout);
    buttonGroupReplace->setLayout(buttonGroupReplaceLayout);
    buttonGroupLetterSize->setLayout(buttonGroupLetterSizeLayout);
    buttonGroupExtensionSize->setLayout(buttonGroupExtensionSizeLayout);
    buttonGroupSpace->setLayout(buttonGroupSpaceLayout);

    buttonHLayout->addWidget(buttonOK);
    buttonHLayout->addWidget(buttonCancel);

    //----Przypisanie przycisków do slotów----//
    connect(buttonOK,SIGNAL(clicked()),this,SLOT(saveSettings()));
    connect(buttonCancel,SIGNAL(clicked()),this,SLOT(closeWindow()));
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
//----Zamyka okno----//
void WidgetSettings::closeWindow()
{
    this->close();
}
//----Zapisuje ustawienia----//
void WidgetSettings::saveSettings()
{
    setSettingsReader();
    settingsReader->saveSettings();
    closeWindow();
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
        radioButtonChangeFirstLetterToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::AllBig:
        radioButtonChangeLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::AllSmall:
        radioButtonChangeLettersToSmall->setChecked(true);
        break;
    case NameChangeParameters::Letters::FirstInWordsBig:
        radioButtonChangeFirstLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Letters::DoNothing:
        radioButtonDontChangeName->setChecked(true);
        break;
    }

    auto selectionExtensions = parameters.getChangeExtension();
    switch(selectionExtensions)
    {
    case NameChangeParameters::Extensions::FirstBig:
        radioButtonChangeExtensionFirstLettersToBig->setChecked(true);
        break;
    case NameChangeParameters::Extensions::AllBig:
        radioButtonChangeExtensionToBig->setChecked(true);
        break;
    case NameChangeParameters::Extensions::AllSmall:
        radioButtonChangeExtensionToSmall->setChecked(true);
        break;
    case NameChangeParameters::Extensions::DoNothing:
        radioButtonChangeDontChangeExtension->setChecked(true);
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

    if(radioButtonChangeFirstLetterToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstBig);
    }
    else if(radioButtonChangeLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllBig);
    }
    else if(radioButtonChangeLettersToSmall->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllSmall);
    }
    else if(radioButtonChangeFirstLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstInWordsBig);
    }
    else if(radioButtonDontChangeName->isChecked())
    {
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::DoNothing);
    }

    if(radioButtonChangeExtensionFirstLettersToBig->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::FirstBig);
    }
    else if(radioButtonChangeExtensionToBig->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllBig);
    }
    else if(radioButtonChangeExtensionToSmall->isChecked())
    {
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllSmall);
    }
    else if(radioButtonChangeDontChangeExtension->isChecked())
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
