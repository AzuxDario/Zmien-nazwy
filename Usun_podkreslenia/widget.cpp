#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //--------Zmienne przechowujące ciągi znaków--------//
    aboutApplication = "Program zamienia znaki podkreślenia, pauzy oraz kropki (poza kropką oddzielającą nazwę pliku od rozszerzenia) na spację w nazwach plików w wybranym folderze.\nAby rozpocząć procedurę zmiany nazw proszę wybrać folder.";

    //----Tworzenie paska menu----//
    menuBar = new QMenuBar();
    menuFile = new QMenu(this);
    menuSettings = new QMenu(this);
    menuHelp = new QMenu(this);

    menuFile = menuBar->addMenu(tr("&Plik"));
    menuSettings = menuBar->addMenu(tr("&Ustawienia"));
    menuHelp = menuBar->addMenu(tr("P&omoc"));

    actionSelectFolder = new QAction(QIcon(":/pasek/wybierzFolder"),"Wybierz &folder",this);
    actionSelectFolder->setShortcut(QKeySequence(tr("Ctrl+W")));
    actionStartNameChange = new QAction(QIcon(":/pasek/rozpocznijZmiane"),"&Rozpocznij zmianę",this);
    actionStartNameChange->setShortcut(QKeySequence(tr("Ctrl+R")));
    actionExit = new QAction(QIcon(":/pasek/wyjscie"),"Wyjści&e",this);
    actionExit->setShortcut(QKeySequence(tr("Ctrl+Q")));
    actionSettings = new QAction(QIcon(":/pasek/ustawienia"),"&Opcje",this);
    actionSettings->setShortcut(QKeySequence(tr("Ctrl+U")));
    actionAbout = new QAction(QIcon(":/pasek/oProgramie"),"&O programie",this);
    actionAbout->setShortcuts(QKeySequence::HelpContents);
    actionChangeLog = new QAction(QIcon(":/pasek/rejestrZmian"),"&Rejestr zmian",this);
    actionChangeLog->setShortcut(QKeySequence(tr("Ctrl+Z")));

    menuFile->addAction(actionSelectFolder);
    menuFile->addAction(actionStartNameChange);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuSettings->addAction(actionSettings);
    menuHelp->addAction(actionAbout);
    menuHelp->addAction(actionChangeLog);

    actionStartNameChange->setDisabled(true);

    //--------Przyciski--------//
    buttonSelectFolder = new QPushButton("Wybierz folder",this);
    buttonSelectFolder->setStyleSheet("font-size:11px;");
    buttonStartNameChange = new QPushButton("Rozpocznij zmianę",this);
    buttonStartNameChange->setStyleSheet("font-size:11px;");
    buttonStartNameChange->setDisabled(true);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox("Zastąp znaki także w podfolderach");
    checkBoxReplaceUnderscores = new QCheckBox("Zastąp podkreślenia");
    checkBoxReplaceDashes = new QCheckBox("Zastąp pauzy");
    checkBoxReplaceDots = new QCheckBox("Zastąp kropki");
    checkBoxReplaceExtensionDot = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń");
    checkBoxReplaceExtensionDot->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    checkBoxRemoveMultiplySpaces = new QCheckBox("Usuń wielokrotne spacje");
    checkBoxRemoveSpacesAtBegin = new QCheckBox("Usuń spacje na początku nazwy");
    checkBoxRemoveSpacesAtEnd = new QCheckBox("Usuń spacje na końcu nazwy");
    checkBoxChangeFirstLetterToBig = new QRadioButton("Zmień pierwszą literę w nazwie pliku na dużą");
    checkBoxChangeLettersToBig = new QRadioButton("Zmień wszstkie litery na duże");
    checkBoxChangeLettersToSmall = new QRadioButton("Zmień wszstkie litery na małe");
    checkBoxChangeFirstLettersToBig = new QRadioButton("Zmień pierwsze litery w słowach na duże");
    checkBoxDontChangeName = new QRadioButton("Nie rób nic");
    checkBoxChangeExtensionToBig = new QRadioButton("Zmień rozszerzenie na pisane dużymi literami");
    checkBoxChangeExtensionToSmall = new QRadioButton("Zmień rozszerzenie na pisane małymi literami");
    checkBoxChangeExtensionFirstLettersToBig = new QRadioButton("Zmień pierwszą literę rozszerzenia na dużą");
    checkBoxChangeDontChangeExtension = new QRadioButton("Nie rób nic");

    //--------Okno z tekstem--------//
    textBrowserAbout = new QTextBrowser(this);
    textBrowserAbout->setAlignment(Qt::AlignTop);
    textBrowserAbout->setReadOnly(true);
    //textBrowserAbout->setTextInteractionFlags(Qt::NoTextInteraction);
    textBrowserAbout->setText(aboutApplication);

    //--------Pasek postępu--------//
    progressBar = new QProgressBar(this);
    progressBar->setTextVisible(false);


    //----Layouty----//
    windowVLayout = new QVBoxLayout(this);
    mainHLayout = new QHBoxLayout();
    leftVLayout = new QVBoxLayout();
    rightVLayout = new QVBoxLayout();
    windowVLayout->setMenuBar(menuBar);
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
    leftVLayout->addWidget(textBrowserAbout);
    leftVLayout->addWidget(progressBar);
    rightVLayout->addWidget(buttonGroupLetterSize);
    rightVLayout->addWidget(buttonGroupExtensionSize);
    rightVLayout->addSpacing(100);
    rightVLayout->addLayout(buttonHLayout);

    buttonGroupSubfoldersLayout->addWidget(checkBoxReplaceInSubfolders);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceUnderscores);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceDashes);
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

    buttonHLayout->addWidget(buttonSelectFolder);
    buttonHLayout->addWidget(buttonStartNameChange);

    //----Wskaźnik na rdzeń programu----//
    programCore = new Core(progressBar);

    //----Ustawienie stanu CheckBoxów zgodnie ze zmiennymi w rdzeniu----//
    setButtonSelection();

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(actionSelectFolder,SIGNAL(triggered()),this,SLOT(selectFolder()));
    connect(actionStartNameChange,SIGNAL(triggered()),this,SLOT(startNameChange()));
    connect(actionSettings,SIGNAL(triggered()),this,SLOT(showWidgetSettings()));
    connect(actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(showWidgetAbout()));
    connect(actionChangeLog,SIGNAL(triggered()),this,SLOT(showWidgetChangeLog()));

    //--------Przyciski--------//
    connect(buttonSelectFolder,SIGNAL(clicked()),this,SLOT(selectFolder()));
    connect(buttonStartNameChange,SIGNAL(clicked()),this,SLOT(startNameChange()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));

}


Widget::~Widget()
{
    delete ui;
}

//----Zamyka program po zamknięciu głównego okna----//
void Widget::closeEvent(QCloseEvent *)
{
    qApp->quit();
}

//----Funkcja aktywuje przycisk Rozpocznij----//
void Widget::enableButtonsStartNameChange()
{
    buttonStartNameChange->setEnabled(true);
    actionStartNameChange->setEnabled(true);
}

//----Funkcja deaktywuje przycisk Rozpocznij----//
void Widget::disableButtonsStartNameChange()
{
    buttonStartNameChange->setDisabled(true);
    actionStartNameChange->setDisabled(true);
}

//----Włącza aktywność przycisku Wybierz folder----//
void Widget::enableButtonsSelectFolder()
{
    buttonSelectFolder->setEnabled(true);
    actionSelectFolder->setEnabled(true);
}

//----Wyłącza aktywność przycisków Wybierz folder i Rozpocznij zmianę----//
void Widget::disableButtonsSelectFolder()
{
    buttonSelectFolder->setDisabled(true);
    actionSelectFolder->setDisabled(true);
}

void Widget::changeCheckBoxExtensionDotActivity()
{
    checkBoxReplaceExtensionDot->setEnabled(checkBoxReplaceDots->isChecked());
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
void Widget::selectFolder()
{
    selectedFolder = programCore->selectFolder(); //Otwiera okno wyboru plik
    if(selectedFolder != "")
    {
        enableButtonsStartNameChange();
        textBrowserAbout->setText("Wybrano katalog: <b>" + selectedFolder + "</b><br />Nazwy plików zawierające wybrane znaki zostaną zmienione.");
    }
    else
    {
        disableButtonsStartNameChange();
        textBrowserAbout->setText("Nie wybrano żadnego folderu. Proszę wybrać folder");
    }
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Widget::startNameChange()
{
    setNameChangesParameters();
    programCore->setNameChangeParameters(nameChangeParameters);
    disableButtonsSelectFolder(); //Deaktywacja przycisków na czas zmiany nazwy aby użytkownik nie mógł wywołać drugi raz funkcji
    disableButtonsStartNameChange();
    programCore->changeName();
    enableButtonsSelectFolder(); //Włączenie aktywności przycisku Wybór folderu po zmianie nazwy
    textBrowserAbout->setText("<b>Program zakończył zmianę nazw w wybranym katalogu. Można teraz wybrać kolejny katalog.</b><br />" + aboutApplication);
}

//----Pokazuje okienko z informacjami o programie----//
void Widget::showWidgetAbout()
{
    programCore->showWidgetAbout();
}

//----Wyświetla okienko z rejestrem zmian----//
void Widget::showWidgetChangeLog()
{
    programCore->showWidgetChangeLog();
}

//----Wyświetla okienko ustawienia----//
void Widget::showWidgetSettings()
{
    programCore->showWidgetSettings();
}

//----Ustawia zaznaczenia przycisków----//
void Widget::setButtonSelection()
{
    NameChangeParameters parameters = programCore->getNameChangeParameters();

    checkBoxReplaceInSubfolders->setChecked(parameters.getReplaceInSubfolders());
    checkBoxReplaceUnderscores->setChecked(parameters.getReplaceUnderscores());
    checkBoxReplaceDashes->setChecked(parameters.getReplaceDashes());
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

}

//----Funkcje aktualizujace stany między check boxami a paskiem----//
void Widget::checkBoxDotsClicked()
{
    changeCheckBoxExtensionDotActivity();
}

void Widget::setNameChangesParameters()
{
    nameChangeParameters.setReplaceInSubfolders(checkBoxReplaceInSubfolders->isChecked());
    nameChangeParameters.setReplaceUnderscores(checkBoxReplaceUnderscores->isChecked());
    nameChangeParameters.setReplaceDashes(checkBoxReplaceDashes->isChecked());
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
}
