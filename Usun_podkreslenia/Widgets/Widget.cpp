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
    checkBoxDontReplaceDashesSurrondedBySpaces->setStyleSheet("margin-left:15px;");
    checkBoxReplaceDots = new QCheckBox(tr(Widgets::checkBoxReplaceDots));
    checkBoxReplaceExtensionDot = new QCheckBox(tr(Widgets::checkBoxReplaceExtensionDot));
    checkBoxReplaceExtensionDot->setStyleSheet("margin-left:15px;");
    checkBoxReplacePluses = new QCheckBox(tr(Widgets::checkBoxReplacePluses));
    checkBoxRemoveMultiplySpaces = new QCheckBox(tr(Widgets::checkBoxRemoveMultiplySpaces));
    checkBoxRemoveSpacesAtBegin = new QCheckBox(tr(Widgets::checkBoxRemoveSpacesAtBegin));
    checkBoxRemoveSpacesAtEnd = new QCheckBox(tr(Widgets::checkBoxRemoveSpacesAtEnd));
    comboBoxChangeLettersSize = new QComboBox();
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonChangeFirstLetterToBig));
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonChangeFirstLetterToBigRestSmall));
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonChangeLettersToBig));
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonChangeLettersToSmall));
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonChangeFirstLettersToBig));
    comboBoxChangeLettersSize->addItem(tr(Widgets::radioButtonDontChange));
    comboBoxChangeExtensionSize = new QComboBox();
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionToBig));
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionToSmall));
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionFirstLettersToBig));
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonDontChange));

    //--------Etykiety--------//
    labelChangeLettersSize = new QLabel(tr(Widgets::labelGroupLetterSize));
    labelChangeExtensionSize = new QLabel(tr(Widgets::labelGroupExtensionSize));

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
    buttonGroupSizeLayout = new QVBoxLayout;
    buttonGroupSpaceLayout = new QVBoxLayout;
    buttonHLayout = new QHBoxLayout;
    buttonGroupSubfolders = new QGroupBox(tr(Widgets::buttonGroupSubfolders));
    buttonGroupReplace = new QGroupBox(tr(Widgets::buttonGroupReplace));
    buttonGroupSize = new QGroupBox(tr(Widgets::buttonGroupSize));
    buttonGroupSpace = new QGroupBox(tr(Widgets::buttonGroupSpace));
    leftVLayout->addWidget(buttonGroupSubfolders);
    leftVLayout->addWidget(buttonGroupReplace);
    leftVLayout->addWidget(textBrowserAbout);
    leftVLayout->addWidget(progressBar);
    rightVLayout->addWidget(buttonGroupSize);
    rightVLayout->addWidget(buttonGroupSpace);
    rightVLayout->addSpacing(70);
    rightVLayout->addLayout(buttonHLayout);

    buttonGroupSubfoldersLayout->addWidget(checkBoxReplaceInSubfolders);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceUnderscores);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceDashes);
    buttonGroupReplaceLayout->addWidget(checkBoxDontReplaceDashesSurrondedBySpaces);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceDots);
    buttonGroupReplaceLayout->addWidget(checkBoxReplaceExtensionDot);
    buttonGroupReplaceLayout->addWidget(checkBoxReplacePluses);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveMultiplySpaces);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveSpacesAtBegin);
    buttonGroupSpaceLayout->addWidget(checkBoxRemoveSpacesAtEnd);
    buttonGroupSizeLayout->addWidget(labelChangeLettersSize);
    buttonGroupSizeLayout->addWidget(comboBoxChangeLettersSize);
    buttonGroupSizeLayout->addWidget(labelChangeExtensionSize);
    buttonGroupSizeLayout->addWidget(comboBoxChangeExtensionSize);

    buttonGroupSubfolders->setLayout(buttonGroupSubfoldersLayout);
    buttonGroupReplace->setLayout(buttonGroupReplaceLayout);
    buttonGroupSize->setLayout(buttonGroupSizeLayout);
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
    checkBoxReplacePluses->setChecked(parameters.getReplacePluses());
    checkBoxRemoveMultiplySpaces->setChecked(parameters.getRemoveMultiplySpaces());
    checkBoxRemoveSpacesAtBegin->setChecked(parameters.getRemoveSpacesAtBegin());
    checkBoxRemoveSpacesAtEnd->setChecked(parameters.getRemoveSpacesAtEnd());

    auto selectionLetters = parameters.getChangeLetters();
    switch(selectionLetters)
    {
    case NameChangeParameters::Letters::FirstBig:
        comboBoxChangeLettersSize->setCurrentIndex(0);
        break;
    case NameChangeParameters::Letters::FirstBigRestSmall:
        comboBoxChangeLettersSize->setCurrentIndex(2);
        break;
    case NameChangeParameters::Letters::AllBig:
        comboBoxChangeLettersSize->setCurrentIndex(2);
        break;
    case NameChangeParameters::Letters::AllSmall:
        comboBoxChangeLettersSize->setCurrentIndex(3);
        break;
    case NameChangeParameters::Letters::FirstInWordsBig:
        comboBoxChangeLettersSize->setCurrentIndex(4);
        break;
    case NameChangeParameters::Letters::DoNothing:
        comboBoxChangeLettersSize->setCurrentIndex(5);
        break;
    }

    auto selectionExtensions = parameters.getChangeExtension();
    switch(selectionExtensions)
    {
    case NameChangeParameters::Extensions::FirstBig:
        comboBoxChangeExtensionSize->setCurrentIndex(0);
        break;
    case NameChangeParameters::Extensions::AllBig:
        comboBoxChangeExtensionSize->setCurrentIndex(1);
        break;
    case NameChangeParameters::Extensions::AllSmall:
        comboBoxChangeExtensionSize->setCurrentIndex(2);
        break;
    case NameChangeParameters::Extensions::DoNothing:
        comboBoxChangeExtensionSize->setCurrentIndex(3);
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
    nameChangeParameters.setReplacePluses(checkBoxReplacePluses->isChecked());
    nameChangeParameters.setRemoveMultiplySpaces(checkBoxRemoveMultiplySpaces->isChecked());
    nameChangeParameters.setRemoveSpacesAtBegin(checkBoxRemoveSpacesAtBegin->isChecked());
    nameChangeParameters.setRemoveSpacesAtEnd(checkBoxRemoveSpacesAtEnd->isChecked());

    switch(comboBoxChangeLettersSize->currentIndex())
    {
    case 0:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstBig);
        break;
    case 1:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstBigRestSmall);
        break;
    case 2:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllBig);
        break;
    case 3:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::AllSmall);
        break;
    case 4:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::FirstInWordsBig);
        break;
    case 5:
        nameChangeParameters.setChangeLetters(NameChangeParameters::Letters::DoNothing);
        break;
    }

    switch(comboBoxChangeExtensionSize->currentIndex())
    {
    case 0:
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::FirstBig);
        break;
    case 1:
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllBig);
        break;
    case 2:
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::AllSmall);
        break;
    case 3:
        nameChangeParameters.setChangeExtension(NameChangeParameters::Extensions::DoNothing);
        break;
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
