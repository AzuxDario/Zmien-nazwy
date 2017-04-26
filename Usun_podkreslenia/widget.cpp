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
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(0,0,420,21);
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
    actionReplaceInSubfolders = new QAction("Zastosuj do podfolderów",this);
    actionReplaceInSubfolders->setShortcut(QKeySequence(tr("Ctrl+1")));
    actionReplaceUnderscores = new QAction("Zastąp &podkreślenia",this);
    actionReplaceUnderscores->setShortcut(QKeySequence(tr("Ctrl+2")));
    actionReplaceDashes = new QAction("Zastąp p&auzy",this);
    actionReplaceDashes->setShortcut(QKeySequence(tr("Ctrl+3")));
    actionReplaceDots = new QAction("Zastąp &kropki",this);
    actionReplaceDots->setShortcut(QKeySequence(tr("Ctrl+4")));
    actionReplaceExtensionDot = new QAction("Zastąp &ostatnią kropkę",this);
    actionReplaceExtensionDot->setShortcut(QKeySequence(tr("Ctrl+5")));
    actionChangeFirstLetterToBig = new QAction("Pierwsza litera &duża",this);
    actionChangeFirstLetterToBig->setShortcut(QKeySequence(tr("Ctrl+6")));
    actionChangeExtensionToSmall = new QAction("&Rozszerzenie małe",this);
    actionChangeExtensionToSmall->setShortcut(QKeySequence(tr("Ctrl+7")));
    actionAbout = new QAction(QIcon(":/pasek/oProgramie"),"&O programie",this);
    actionAbout->setShortcuts(QKeySequence::HelpContents);
    actionChangeLog = new QAction(QIcon(":/pasek/rejestrZmian"),"&Rejestr zmian",this);
    actionChangeLog->setShortcut(QKeySequence(tr("Ctrl+Z")));

    menuFile->addAction(actionSelectFolder);
    menuFile->addAction(actionStartNameChange);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuSettings->addAction(actionSettings);
    menuSettings->addSeparator();
    menuSettings->addAction(actionReplaceInSubfolders);
    menuSettings->addAction(actionReplaceUnderscores);
    menuSettings->addAction(actionReplaceDashes);
    menuSettings->addAction(actionReplaceDots);
    menuSettings->addAction(actionReplaceExtensionDot);
    menuSettings->addAction(actionChangeFirstLetterToBig);
    menuSettings->addAction(actionChangeExtensionToSmall);
    menuHelp->addAction(actionAbout);
    menuHelp->addAction(actionChangeLog);

    actionStartNameChange->setDisabled(true);
    actionReplaceInSubfolders->setCheckable(true);
    actionReplaceUnderscores->setCheckable(true);
    actionReplaceDashes->setCheckable(true);
    actionReplaceDots->setCheckable(true);
    actionReplaceExtensionDot->setCheckable(true);
    actionReplaceExtensionDot->setDisabled(true);
    actionChangeFirstLetterToBig->setCheckable(true);
    actionChangeExtensionToSmall->setCheckable(true);

    //----Tworzenie layoutu okna----//
    //--------Przyciski--------//
    buttonSelectFolder = new QPushButton("Wybierz folder",this);
    buttonSelectFolder->setGeometry(20,31,140,30);
    buttonSelectFolder->setStyleSheet("font-size:11px;");
    buttonStartNameChange = new QPushButton("Rozpocznij zmianę",this);
    buttonStartNameChange->setGeometry(260,31,140,30);
    buttonStartNameChange->setStyleSheet("font-size:11px;");
    buttonStartNameChange->setDisabled(true);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox("Zastąp znaki także w podfolderach",this);
    checkBoxReplaceInSubfolders->setGeometry(20,72,380,18);
    checkBoxReplaceUnderscores = new QCheckBox("Zastąp podkreślenia",this);
    checkBoxReplaceUnderscores->setGeometry(20,101,154,18);
    checkBoxReplaceDashes = new QCheckBox("Zastąp pauzy",this);
    checkBoxReplaceDashes->setGeometry(174,101,116,18);
    checkBoxReplaceDots = new QCheckBox("Zastąp kropki",this);
    checkBoxReplaceDots->setGeometry(290,101,110,18);
    checkBoxReplaceExtensionDot = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń",this);
    checkBoxReplaceExtensionDot->setGeometry(20,130,380,18);
    checkBoxReplaceExtensionDot->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    checkBoxChangeFirstLetterToBig = new QCheckBox("Zmień pierwszą literę w nazwie pliku na dużą",this);
    checkBoxChangeFirstLetterToBig->setGeometry(20,159,380,18);
    checkBoxChangeExtensionToSmall = new QCheckBox("Zmień rozszerzenie na pisane małymi literami",this);
    checkBoxChangeExtensionToSmall->setGeometry(20,188,380,18);

    //--------Okno z tekstem--------//
    textBrowserAbout = new QTextBrowser(this);
    textBrowserAbout->setGeometry(20,217,380,120);
    textBrowserAbout->setAlignment(Qt::AlignTop);
    textBrowserAbout->setReadOnly(true);
    textBrowserAbout->setText(aboutApplication);

    //--------Pasek postępu--------//
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(20,347,380,30);
    progressBar->setTextVisible(false);

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
    connect(actionReplaceInSubfolders,SIGNAL(triggered()),this,SLOT(actionSubfoldersClicked()));
    connect(actionReplaceUnderscores,SIGNAL(triggered()),this,SLOT(actionUnderscoresClicked()));
    connect(actionReplaceDashes,SIGNAL(triggered()),this,SLOT(actionDashesClicked()));
    connect(actionReplaceDots,SIGNAL(triggered()),this,SLOT(actionDotsClicked()));
    connect(actionReplaceExtensionDot,SIGNAL(triggered()),this,SLOT(actionExtensionDotsClicked()));
    connect(actionChangeFirstLetterToBig,SIGNAL(triggered()),this,SLOT(actionFirstLetterToBigClicked()));
    connect(actionChangeExtensionToSmall,SIGNAL(triggered()),this,SLOT(actionExtensionToSmallClicked()));

    //--------Przyciski--------//
    connect(buttonSelectFolder,SIGNAL(clicked()),this,SLOT(selectFolder()));
    connect(buttonStartNameChange,SIGNAL(clicked()),this,SLOT(startNameChange()));
    connect(checkBoxReplaceInSubfolders,SIGNAL(clicked()),this,SLOT(checkBoxSubfoldersClicked()));
    connect(checkBoxReplaceUnderscores,SIGNAL(clicked()),this,SLOT(checkBoxUnderscoresClicked()));
    connect(checkBoxReplaceDashes,SIGNAL(clicked()),this,SLOT(checkBoxDashesClicked()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));
    connect(checkBoxReplaceExtensionDot,SIGNAL(clicked()),this,SLOT(checkBoxExtensionDotsClicked()));
    connect(checkBoxChangeFirstLetterToBig,SIGNAL(clicked()),this,SLOT(checkBoxFirstLetterToBigClicked()));
    connect(checkBoxChangeExtensionToSmall,SIGNAL(clicked()),this,SLOT(checkBoxExtensionToSmallClicked()));

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
    actionReplaceExtensionDot->setEnabled(actionReplaceDots->isChecked());
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
    actionReplaceInSubfolders->setChecked(programCore->nameChangeParameters.getReplaceInSubfolders());
    actionReplaceUnderscores->setChecked(programCore->nameChangeParameters.getReplaceUnderscores());
    actionReplaceDashes->setChecked(programCore->nameChangeParameters.getReplaceDashes());
    actionReplaceDots->setChecked(programCore->nameChangeParameters.getReplaceDots());
    actionReplaceExtensionDot->setChecked(programCore->nameChangeParameters.getReplaceExtensionDot());
    actionChangeFirstLetterToBig->setChecked(programCore->nameChangeParameters.getChangeFirstLetterToBig());
    actionChangeExtensionToSmall->setChecked(programCore->nameChangeParameters.getChangeExtensionToSmall());

    checkBoxReplaceInSubfolders->setChecked(programCore->nameChangeParameters.getReplaceInSubfolders());
    checkBoxReplaceUnderscores->setChecked(programCore->nameChangeParameters.getReplaceUnderscores());
    checkBoxReplaceDashes->setChecked(programCore->nameChangeParameters.getReplaceDashes());
    checkBoxReplaceDots->setChecked(programCore->nameChangeParameters.getReplaceDots());
    checkBoxReplaceExtensionDot->setChecked(programCore->nameChangeParameters.getReplaceExtensionDot());
    checkBoxChangeFirstLetterToBig->setChecked(programCore->nameChangeParameters.getChangeFirstLetterToBig());
    checkBoxChangeExtensionToSmall->setChecked(programCore->nameChangeParameters.getChangeExtensionToSmall());

    if(programCore->nameChangeParameters.getReplaceDots() == true)
    {
        actionReplaceExtensionDot->setEnabled(true);
        checkBoxReplaceExtensionDot->setEnabled(true);
    }

}

//----Funkcje aktualizujace stany między check boxami a paskiem----//
void Widget::checkBoxSubfoldersClicked()
{
    actionReplaceInSubfolders->setChecked(checkBoxReplaceInSubfolders->isChecked());
    programCore->nameChangeParameters.setReplaceInSubfolders(checkBoxReplaceInSubfolders->isChecked());
}

void Widget::checkBoxUnderscoresClicked()
{
    actionReplaceUnderscores->setChecked(checkBoxReplaceUnderscores->isChecked());
    programCore->nameChangeParameters.setReplaceUnderscores(checkBoxReplaceUnderscores->isChecked());
}

void Widget::checkBoxDashesClicked()
{
    actionReplaceDashes->setChecked(checkBoxReplaceDashes->isChecked());
    programCore->nameChangeParameters.setReplaceDashes(checkBoxReplaceDashes->isChecked());
}

void Widget::checkBoxDotsClicked()
{
    actionReplaceDots->setChecked(checkBoxReplaceDots->isChecked());
    changeCheckBoxExtensionDotActivity();
    programCore->nameChangeParameters.setReplaceDots(checkBoxReplaceDots->isChecked());
}

void Widget::checkBoxExtensionDotsClicked()
{
    actionReplaceExtensionDot->setChecked(checkBoxReplaceExtensionDot->isChecked());
    programCore->nameChangeParameters.setReplaceExtensionDot(checkBoxReplaceExtensionDot->isChecked());
}

void Widget::checkBoxFirstLetterToBigClicked()
{
    actionChangeFirstLetterToBig->setChecked(checkBoxChangeFirstLetterToBig->isChecked());
    programCore->nameChangeParameters.setChangeFirstLetterToBig(checkBoxChangeFirstLetterToBig->isChecked());
}

void Widget::checkBoxExtensionToSmallClicked()
{
    actionChangeExtensionToSmall->setChecked(checkBoxChangeExtensionToSmall->isChecked());
    programCore->nameChangeParameters.setChangeExtensionToSmall(checkBoxChangeExtensionToSmall->isChecked());
}

void Widget::actionSubfoldersClicked()
{
    checkBoxReplaceInSubfolders->setChecked(actionReplaceInSubfolders->isChecked());
    programCore->nameChangeParameters.setReplaceInSubfolders(actionReplaceInSubfolders->isChecked());
}

void Widget::actionUnderscoresClicked()
{
    checkBoxReplaceUnderscores->setChecked(actionReplaceUnderscores->isChecked());
    programCore->nameChangeParameters.setReplaceUnderscores(actionReplaceUnderscores->isChecked());
}

void Widget::actionDashesClicked()
{
    checkBoxReplaceDashes->setChecked(actionReplaceDashes->isChecked());
    programCore->nameChangeParameters.setReplaceDashes(actionReplaceDashes->isChecked());
}

void Widget::actionDotsClicked()
{
    checkBoxReplaceDots->setChecked(actionReplaceDots->isChecked());
    changeCheckBoxExtensionDotActivity();
    programCore->nameChangeParameters.setReplaceDots(actionReplaceDots->isChecked());
}

void Widget::actionExtensionDotsClicked()
{
    checkBoxReplaceExtensionDot->setChecked(actionReplaceExtensionDot->isChecked());
    programCore->nameChangeParameters.setReplaceExtensionDot(actionReplaceExtensionDot->isChecked());
}

void Widget::actionFirstLetterToBigClicked()
{
    checkBoxChangeFirstLetterToBig->setChecked(actionChangeFirstLetterToBig->isChecked());
    programCore->nameChangeParameters.setChangeFirstLetterToBig(actionChangeFirstLetterToBig->isChecked());
}

void Widget::actionExtensionToSmallClicked()
{
    checkBoxChangeExtensionToSmall->setChecked(actionChangeExtensionToSmall->isChecked());
    programCore->nameChangeParameters.setChangeExtensionToSmall(actionChangeExtensionToSmall->isChecked());
}
