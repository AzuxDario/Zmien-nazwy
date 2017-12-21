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
    actionSelectFolder->setShortcut(QKeySequence(tr("Ctrl+F")));
    actionSelectFile = new QAction(QIcon(":/pasek/plik"),tr(Widgets::actionSelectFiles),this);
    actionSelectFile->setShortcut(QKeySequence(tr("Ctrl+P")));
    actionStartNameChange = new QAction(QIcon(":/pasek/rozpocznijZmiane"),tr(Widgets::actionStartChange),this);
    actionStartNameChange->setShortcut(QKeySequence(tr("Ctrl+R")));
    actionExit = new QAction(QIcon(":/pasek/wyjscie"),tr(Widgets::actionExit),this);
    actionExit->setShortcut(QKeySequence(tr("Ctrl+Q")));
    actionOptions = new QAction(QIcon(":/pasek/ustawienia"),tr(Widgets::actionOptions),this);
    actionOptions->setShortcut(QKeySequence(tr("Ctrl+U")));
    actionAbout = new QAction(QIcon(":/pasek/oProgramie"),tr(Widgets::actionAbout),this);
    actionAbout->setShortcut(QKeySequence(tr("Ctrl+A")));
    actionChangeLog = new QAction(QIcon(":/pasek/rejestrZmian"),tr(Widgets::actionChangeLog),this);
    actionChangeLog->setShortcut(QKeySequence(tr("Ctrl+Z")));

    menuFile->addAction(actionSelectFolder);
    menuFile->addAction(actionSelectFile);
    menuFile->addSeparator();
    menuFile->addAction(actionStartNameChange);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuSettings->addAction(actionOptions);
    menuHelp->addAction(actionAbout);
    menuHelp->addAction(actionChangeLog);

    actionStartNameChange->setDisabled(true);

    //--------Przyciski--------//
    buttonSelectFolder = new QPushButton(tr(Widgets::buttonSelectFolder),this);
    buttonSelectFolder->setStyleSheet("font-size:11px;");
    buttonSelectFolder->setMinimumHeight(30);
    buttonSelectFolder->setMaximumWidth(120);
    buttonSelectFile = new QPushButton(tr(Widgets::buttonSelectFiles),this);
    buttonSelectFile->setStyleSheet("font-size:11px;");
    buttonSelectFile->setMinimumHeight(30);
    buttonSelectFile->setMaximumWidth(120);
    buttonStartNameChange = new QPushButton(tr(Widgets::buttonStartChange),this);
    buttonStartNameChange->setStyleSheet("font-size:11px;");
    buttonStartNameChange->setMaximumHeight(30);
    buttonStartNameChange->setMaximumWidth(120);
    buttonStartNameChange->setDisabled(true);
    buttonAddExtension = new QPushButton(tr(Widgets::buttonAddExtension),this);
    buttonAddExtension->setStyleSheet("font-size:11px;");
    buttonAddExtension->setMinimumHeight(30);
    buttonAddExtension->setMaximumWidth(60);
    buttonDeleteExtension = new QPushButton(tr(Widgets::buttonDeleteExtension),this);
    buttonDeleteExtension->setStyleSheet("font-size:11px;");
    buttonDeleteExtension->setMinimumHeight(30);
    buttonDeleteExtension->setMaximumWidth(60);

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
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionFirstLettersToBig));
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionToBig));
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonChangeExtensionToSmall));    
    comboBoxChangeExtensionSize->addItem(tr(Widgets::radioButtonDontChange));
    comboBoxChangeExtensionFilter = new QComboBox();
    comboBoxChangeExtensionFilter->addItem(tr(Widgets::optionExtensionOnlyThis));
    comboBoxChangeExtensionFilter->addItem(tr(Widgets::optionExtensionAlExceptThis));
    comboBoxChangeExtensionFilter->addItem(tr(Widgets::optionExtensionDontUse));

    //--------Etykiety--------//
    labelChangeLettersSize = new QLabel(tr(Widgets::labelGroupLetterSize));
    labelChangeExtensionSize = new QLabel(tr(Widgets::labelGroupExtensionSize));

    //--------Okno z tekstem--------//
    textBrowserAbout = new QTextBrowser(this);
    textBrowserAbout->setAlignment(Qt::AlignTop);
    textBrowserAbout->setReadOnly(true);
    //textBrowserAbout->setTextInteractionFlags(Qt::NoTextInteraction);
    textBrowserAbout->setText(tr(Widgets::textToStartSelectFolderOrFile));

    regExp.setPattern("^[a-zA-Z0-9]*$");
    regExpValidator.setRegExp(regExp);

    lineEditExtensionFilter = new QLineEdit();
    lineEditExtensionFilter->setValidator(&regExpValidator);

    //--------Pasek postępu--------//
    progressBar = new QProgressBar(this);
    progressBar->setTextVisible(false);
    progressBar->setMinimumHeight(30);

    listWidgetExtensionFilter = new QListWidget();

    //----Layouty----//
    windowVLayout = new QVBoxLayout(this);
    mainHLayout = new QHBoxLayout();
    leftVLayout = new QVBoxLayout();
    centerVLayout = new QVBoxLayout();
    rightVLayout = new QVBoxLayout();
    windowVLayout->setMenuBar(menuBar);
    windowVLayout->addLayout(mainHLayout);
    mainHLayout->addLayout(leftVLayout);
    mainHLayout->addLayout(centerVLayout);
    mainHLayout->addLayout(rightVLayout);

    buttonGroupSubfoldersLayout = new QVBoxLayout;
    buttonGroupReplaceLayout = new QVBoxLayout;
    buttonGroupSizeLayout = new QVBoxLayout;
    buttonGroupSpaceLayout = new QVBoxLayout;
    buttonGroupExtensionFilterLayout = new QVBoxLayout;
    mainButtonHLayout = new QHBoxLayout;
    extensionButtonHLayout = new QHBoxLayout;
    buttonGroupSubfolders = new QGroupBox(tr(Widgets::buttonGroupGeneral));
    buttonGroupReplace = new QGroupBox(tr(Widgets::buttonGroupReplace));
    buttonGroupSize = new QGroupBox(tr(Widgets::buttonGroupSize));
    buttonGroupSpace = new QGroupBox(tr(Widgets::buttonGroupSpace));
    buttonGroupExtensionFilter = new QGroupBox(tr(Widgets::buttonGroupExtensionFilter));
    leftVLayout->addWidget(buttonGroupSubfolders);
    leftVLayout->addWidget(buttonGroupReplace);
    leftVLayout->addWidget(textBrowserAbout);
    leftVLayout->addWidget(progressBar);
    centerVLayout->addWidget(buttonGroupSize);
    centerVLayout->addWidget(buttonGroupSpace);
    centerVLayout->addSpacing(70);
    centerVLayout->addLayout(mainButtonHLayout);
    rightVLayout->addWidget(buttonGroupExtensionFilter);

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
    buttonGroupExtensionFilterLayout->addWidget(comboBoxChangeExtensionFilter);
    buttonGroupExtensionFilterLayout->addWidget(listWidgetExtensionFilter);
    buttonGroupExtensionFilterLayout->addWidget(lineEditExtensionFilter);
    buttonGroupExtensionFilterLayout->addLayout(extensionButtonHLayout);

    buttonGroupSubfolders->setLayout(buttonGroupSubfoldersLayout);
    buttonGroupReplace->setLayout(buttonGroupReplaceLayout);
    buttonGroupSize->setLayout(buttonGroupSizeLayout);
    buttonGroupSpace->setLayout(buttonGroupSpaceLayout);
    buttonGroupExtensionFilter->setLayout(buttonGroupExtensionFilterLayout);

    mainButtonHLayout->addWidget(buttonSelectFolder);
    mainButtonHLayout->addWidget(buttonSelectFile);
    mainButtonHLayout->addWidget(buttonStartNameChange);

    extensionButtonHLayout->addWidget(buttonAddExtension);
    extensionButtonHLayout->addWidget(buttonDeleteExtension);

    //----Wskaźnik na rdzeń programu----//
    programCore = new WidgetViewProvider();

    //----Ustawienie stanu CheckBoxów zgodnie ze zmiennymi w rdzeniu----//
    setButtonSelection();

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(actionSelectFolder,SIGNAL(triggered()),this,SLOT(selectFolder()));
    connect(actionSelectFile,SIGNAL(triggered()),this,SLOT(selectFile()));
    connect(actionStartNameChange,SIGNAL(triggered()),this,SLOT(startNameChange()));
    connect(actionOptions,SIGNAL(triggered()),this,SLOT(showWidgetSettings()));
    connect(actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(showWidgetAbout()));
    connect(actionChangeLog,SIGNAL(triggered()),this,SLOT(showWidgetChangeLog()));

    //--------Przyciski--------//
    connect(buttonSelectFolder,SIGNAL(clicked()),this,SLOT(selectFolder()));
    connect(buttonSelectFile,SIGNAL(clicked()),this,SLOT(selectFile()));
    connect(buttonStartNameChange,SIGNAL(clicked()),this,SLOT(startNameChange()));
    connect(checkBoxReplaceDashes,SIGNAL(clicked(bool)),this,SLOT(checkBoxDashesClicked()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));
    connect(buttonAddExtension,SIGNAL(clicked()),this,SLOT(addExtension()));
    connect(buttonDeleteExtension,SIGNAL(clicked()),this,SLOT(deleteExtension()));

    connect(programCore,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBar(int,int)));
    connect(programCore,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBar(int)));
    connect(programCore,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBar()));
    connect(programCore,SIGNAL(doneWork()),this, SLOT(handleResults()));
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
void Widget::enableButtonsSelect()
{
    buttonSelectFolder->setEnabled(true);
    actionSelectFolder->setEnabled(true);
    buttonSelectFile->setEnabled(true);
    actionSelectFile->setEnabled(true);
}

//----Wyłącza aktywność przycisków Wybierz folder i Rozpocznij zmianę----//
void Widget::disableButtonsSelect()
{
    buttonSelectFolder->setDisabled(true);
    actionSelectFolder->setDisabled(true);
    buttonSelectFile->setDisabled(true);
    actionSelectFile->setDisabled(true);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
void Widget::selectFolder()
{
    progressBar->reset();
    selectedDirectory = programCore->selectFolder(); //Otwiera okno wyboru folderu
    if(selectedDirectory != "")
    {
        enableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textSelectedFolder) + selectedDirectory + tr(Widgets::textNamesWillBeChangedInFolder));
    }
    else
    {
        disableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textFolderDoesntSelected));
    }
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
void Widget::selectFile()
{
    progressBar->reset();
    selectedFiles = programCore->selectFile(); //Otwiera okno wyboru pliku
    if(!selectedFiles.empty())
    {
        QString selection = "<br/>";
        for(int i = 0; i < selectedFiles.length(); i++)
        {
            selection += selectedFiles[i];
            selection += "<br/>";
        }
        enableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textSelectedFiles) + selection + tr(Widgets::textFileNameWillBeChanged));
    }
    else
    {
        disableButtonsStartNameChange();
        textBrowserAbout->setText(tr(Widgets::textFileDoesntSelected));
    }
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Widget::startNameChange()
{
    setNameChangesParameters();
    disableButtonsSelect(); //Deaktywacja przycisków na czas zmiany nazwy aby użytkownik nie mógł wywołać drugi raz funkcji
    disableButtonsStartNameChange();
    programCore->changeName(nameChangeParameters);
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
        comboBoxChangeLettersSize->setCurrentIndex(1);
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

    auto selectionExtensionFilter = parameters.getExtensionFilter();
    switch(selectionExtensionFilter)
    {
    case NameChangeParameters::ExtensionFilter::OnlyThis:
        comboBoxChangeExtensionFilter->setCurrentIndex(0);
        break;
    case NameChangeParameters::ExtensionFilter::AllExceptThis:
        comboBoxChangeExtensionFilter->setCurrentIndex(1);
        break;
    case NameChangeParameters::ExtensionFilter::DontUse:
        comboBoxChangeExtensionFilter->setCurrentIndex(2);
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

    QStringList list = nameChangeParameters.getExtensions();
    for(int i = 0; i< list.count(); i++)
    {
        listWidgetExtensionFilter->addItem(list[i]);
    }
}

//----Dodaj rozszerzenie do listy----//
void Widget::addExtension()
{
    QString extension = lineEditExtensionFilter->text();
    lineEditExtensionFilter->setText("");
    if(extension != "")
    {
        for(int i = 0; i < listWidgetExtensionFilter->count(); i++)
        {
            if(extension == listWidgetExtensionFilter->item(i)->text())
            {
                return;
            }
        }
        listWidgetExtensionFilter->addItem(extension);
    }
}

//----Usuwa rozszerzenie z listy----//
void Widget::deleteExtension()
{
    if(listWidgetExtensionFilter->currentRow() > -1)
    {
        delete listWidgetExtensionFilter->takeItem(listWidgetExtensionFilter->currentRow());
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

    switch(comboBoxChangeExtensionFilter->currentIndex())
    {
    case 0:
        nameChangeParameters.setExtensionFilter(NameChangeParameters::ExtensionFilter::OnlyThis);
        break;
    case 1:
        nameChangeParameters.setExtensionFilter(NameChangeParameters::ExtensionFilter::AllExceptThis);
        break;
    case 2:
        nameChangeParameters.setExtensionFilter(NameChangeParameters::ExtensionFilter::DontUse);
        break;
    }

    QStringList list;
    for(int i = 0; i< listWidgetExtensionFilter->count(); i++)
    {
        list.append(listWidgetExtensionFilter->item(i)->text());
    }
    nameChangeParameters.setExtensions(list);
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

void Widget::handleResults()
{
    enableButtonsSelect(); //Włączenie aktywności przycisku Wybór folderu po zmianie nazwy
    textBrowserAbout->setText(tr(Widgets::textNamesChanged) + tr(Widgets::textToStartSelectFolderOrFile));
}
