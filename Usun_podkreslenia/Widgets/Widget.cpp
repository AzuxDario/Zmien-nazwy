#include "Widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8(Widgets::widgetMain));

    //----Tworzenie paska menu----//
    menuBar = new QMenuBar();
    menuFile = new QMenu(this);
    menuSettings = new QMenu(this);
    menuHelp = new QMenu(this);

    menuFile = menuBar->addMenu(tr(Widgets::menuFile));
    menuSettings = menuBar->addMenu(tr(Widgets::menuSettings));
    menuHelp = menuBar->addMenu(tr(Widgets::menuHelp));

    actionSelectFolder = new QAction(QIcon(":/pasek/wybierzFolder"),tr(Widgets::actionSelectFolder),this);
    actionSelectFolder->setShortcut(QKeySequence(tr("Ctrl+W")));
    actionStartNameChange = new QAction(QIcon(":/pasek/rozpocznijZmiane"),tr(Widgets::actionStartChange),this);
    actionStartNameChange->setShortcut(QKeySequence(tr("Ctrl+R")));
    actionExit = new QAction(QIcon(":/pasek/wyjscie"),tr(Widgets::actionExit),this);
    actionExit->setShortcut(QKeySequence(tr("Ctrl+Q")));
    actionOptions = new QAction(QIcon(":/pasek/ustawienia"),tr(Widgets::actionOptions),this);
    actionOptions->setShortcut(QKeySequence(tr("Ctrl+U")));
    actionAbout = new QAction(QIcon(":/pasek/oProgramie"),tr(Widgets::actionAbout),this);
    actionAbout->setShortcuts(QKeySequence::HelpContents);
    actionChangeLog = new QAction(QIcon(":/pasek/rejestrZmian"),tr(Widgets::actionChangeLog),this);
    actionChangeLog->setShortcut(QKeySequence(tr("Ctrl+Z")));

    menuFile->addAction(actionSelectFolder);
    menuFile->addAction(actionStartNameChange);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuSettings->addAction(actionOptions);
    menuHelp->addAction(actionAbout);
    menuHelp->addAction(actionChangeLog);

    actionStartNameChange->setDisabled(true);

    //--------Przyciski--------//
    buttonSelectFolder = new QPushButton(tr(Widgets::actionSelectFolder),this);
    buttonSelectFolder->setStyleSheet("font-size:11px;");
    buttonSelectFolder->setMinimumHeight(30);
    buttonSelectFolder->setMaximumWidth(120);
    buttonStartNameChange = new QPushButton(tr(Widgets::actionStartChange),this);
    buttonStartNameChange->setStyleSheet("font-size:11px;");
    buttonStartNameChange->setMaximumHeight(30);
    buttonStartNameChange->setMaximumWidth(120);
    buttonStartNameChange->setDisabled(true);

    //--------Check Boxy--------//
    checkBoxReplaceInSubfolders = new QCheckBox(tr(Widgets::checkBoxReplaceInSubfolders));
    checkBoxReplaceUnderscores = new QCheckBox(tr(Widgets::checkBoxReplaceUnderscores));
    checkBoxReplaceDashes = new QCheckBox(tr(Widgets::checkBoxReplaceDashes));
    checkBoxDontReplaceDashesSurrondedBySpaces = new QCheckBox(tr(Widgets::checkBoxDontReplaceDashesSurrondedBySpaces));
    checkBoxReplaceDots = new QCheckBox(tr(Widgets::checkBoxReplaceDots));
    checkBoxReplaceExtensionDot = new QCheckBox(tr(Widgets::checkBoxReplaceExtensionDot));
    checkBoxRemoveMultiplySpaces = new QCheckBox(tr(Widgets::checkBoxRemoveMultiplySpaces));
    checkBoxRemoveSpacesAtBegin = new QCheckBox(tr(Widgets::checkBoxRemoveSpacesAtBegin));
    checkBoxRemoveSpacesAtEnd = new QCheckBox(tr(Widgets::checkBoxRemoveSpacesAtEnd));
    radioButtonChangeFirstLetterToBig = new QRadioButton(tr(Widgets::radioButtonChangeFirstLetterToBig));
    radioButtonChangeLettersToBig = new QRadioButton(tr(Widgets::radioButtonChangeLettersToBig));
    radioButtonChangeLettersToSmall = new QRadioButton(tr(Widgets::radioButtonChangeLettersToSmall));
    radioButtonChangeFirstLettersToBig = new QRadioButton(tr(Widgets::radioButtonChangeFirstLettersToBig));
    radioButtonDontChangeName = new QRadioButton(tr(Widgets::radioButtonDontChange));
    radioButtonChangeExtensionToBig = new QRadioButton(tr(Widgets::radioButtonChangeExtensionToBig));
    radioButtonChangeExtensionToSmall = new QRadioButton(tr(Widgets::radioButtonChangeExtensionToSmall));
    radioButtonChangeExtensionFirstLettersToBig = new QRadioButton(tr(Widgets::radioButtonChangeExtensionFirstLettersToBig));
    radioButtonChangeDontChangeExtension = new QRadioButton(tr(Widgets::radioButtonDontChange));

    //--------Okno z tekstem--------//
    textBrowserAbout = new QTextBrowser(this);
    textBrowserAbout->setAlignment(Qt::AlignTop);
    textBrowserAbout->setReadOnly(true);
    //textBrowserAbout->setTextInteractionFlags(Qt::NoTextInteraction);
    textBrowserAbout->setText(tr(Widgets::textToStartSelectFolder));

    //--------Pasek postępu--------//
    progressBar = new QProgressBar(this);
    progressBar->setTextVisible(false);
    progressBar->setMinimumHeight(30);


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
    buttonGroupSubfolders = new QGroupBox(tr(Widgets::buttonGroupSubfolders));
    buttonGroupReplace = new QGroupBox(tr(Widgets::buttonGroupReplace));
    buttonGroupLetterSize = new QGroupBox(tr(Widgets::buttonGroupLetterSize));
    buttonGroupExtensionSize = new QGroupBox(tr(Widgets::buttonGroupExtensionSize));
    buttonGroupSpace = new QGroupBox(tr(Widgets::buttonGroupSpace));
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

    buttonHLayout->addWidget(buttonSelectFolder);
    buttonHLayout->addWidget(buttonStartNameChange);

    //----Wskaźnik na rdzeń programu----//
    programCore = new WidgetViewProvider();

    //----Ustawienie stanu CheckBoxów zgodnie ze zmiennymi w rdzeniu----//
    setButtonSelection();

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(actionSelectFolder,SIGNAL(triggered()),this,SLOT(selectFolder()));
    connect(actionStartNameChange,SIGNAL(triggered()),this,SLOT(startNameChange()));
    connect(actionOptions,SIGNAL(triggered()),this,SLOT(showWidgetSettings()));
    connect(actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(showWidgetAbout()));
    connect(actionChangeLog,SIGNAL(triggered()),this,SLOT(showWidgetChangeLog()));

    //--------Przyciski--------//
    connect(buttonSelectFolder,SIGNAL(clicked()),this,SLOT(selectFolder()));
    connect(buttonStartNameChange,SIGNAL(clicked()),this,SLOT(startNameChange()));
    connect(checkBoxReplaceDashes,SIGNAL(clicked(bool)),this,SLOT(checkBoxDashesClicked()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));

    connect(programCore,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBar(int,int)));
    connect(programCore,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBar(int)));
    connect(programCore,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBar()));
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

//----Wybiera folder do przeprowadzenia zmiany nazw----//
void Widget::selectFolder()
{
    selectedFolder = programCore->selectFolder(); //Otwiera okno wyboru plik
    if(selectedFolder != "")
    {
        enableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textSelectedFolder) + selectedFolder + tr(Widgets::textNamesWillBeChanged));
    }
    else
    {
        disableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textFolderDoesntSelected));
    }
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Widget::startNameChange()
{
    setNameChangesParameters();
    disableButtonsSelectFolder(); //Deaktywacja przycisków na czas zmiany nazwy aby użytkownik nie mógł wywołać drugi raz funkcji
    disableButtonsStartNameChange();
    programCore->changeName(nameChangeParameters);
    enableButtonsSelectFolder(); //Włączenie aktywności przycisku Wybór folderu po zmianie nazwy
    textBrowserAbout->setText(tr(Widgets::textNamesChanged) + tr(Widgets::textToStartSelectFolder));
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

//----Funkcje aktualizujace stany między check boxami a paskiem----//
void Widget::checkBoxDotsClicked()
{
    checkBoxReplaceExtensionDot->setEnabled(checkBoxReplaceDots->isChecked());
}

void Widget::checkBoxDashesClicked()
{
    checkBoxDontReplaceDashesSurrondedBySpaces->setEnabled(checkBoxReplaceDashes->isChecked());
}

void Widget::setNameChangesParameters()
{
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
}

void Widget::initializeProgressBar(int minValue, int maxValue)
{
    progressBar->setRange(minValue, maxValue);
}

void Widget::changeProgressBar(int value)
{
    progressBar->setValue(value);
}

void Widget::resetProgressBar()
{
    progressBar->reset();
}
