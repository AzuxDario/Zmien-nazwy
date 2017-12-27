#include "WidgetSettings.h"
#include "ui_widgetsettings.h"

WidgetSettings::WidgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettings)
{
    ui->setupUi(this);

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8(Widgets::widgetSettings));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Etykiety--------//
    labelDefaultSettings = new QLabel(tr(Widgets::textDefaultSettings),this);
    labelDefaultSettings->setStyleSheet("font-size:15px; margin-bottom:10px;");
    labelChangeLettersSize = new QLabel(tr(Widgets::labelGroupLetterSize));
    labelChangeExtensionSize = new QLabel(tr(Widgets::labelGroupExtensionSize));

    //--------Przycisk--------//
    buttonOK = new QPushButton(tr(Widgets::buttonOk),this);
    buttonOK->setMinimumHeight(30);
    buttonOK->setMaximumWidth(120);
    buttonCancel = new QPushButton(tr(Widgets::buttonCancel),this);
    buttonCancel->setMinimumHeight(30);
    buttonCancel->setMaximumWidth(120);
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

    regExp.setPattern("^[a-zA-Z0-9]*$");
    regExpValidator.setRegExp(regExp);

    lineEditExtensionFilter = new QLineEdit();
    lineEditExtensionFilter->setValidator(&regExpValidator);

    listWidgetExtensionFilter = new QListWidget();

    mainTabWidget = new QTabWidget();
    mainTab = new QWidget();
    sizeAndSpacesTab = new QWidget();
    extensionFilterTab = new QWidget();

    mainTabWidget->addTab(mainTab,tr("Główne"));
    mainTabWidget->addTab(sizeAndSpacesTab,tr("Rozmiar i spacje"));
    mainTabWidget->addTab(extensionFilterTab,tr("Filtr rozszerzeń"));

    //----Layouty----//
    windowVLayout = new QVBoxLayout(this);
    leftVLayout = new QVBoxLayout();
    centerVLayout = new QVBoxLayout();
    rightVLayout = new QVBoxLayout();
    windowVLayout->addWidget(labelDefaultSettings,0,Qt::AlignCenter);
    windowVLayout->addWidget(mainTabWidget);

    mainTab->setLayout(leftVLayout);
    sizeAndSpacesTab->setLayout(centerVLayout);
    extensionFilterTab->setLayout(rightVLayout);

    buttonGroupSubfoldersLayout = new QVBoxLayout;
    buttonGroupReplaceLayout = new QVBoxLayout;
    buttonGroupSizeLayout = new QVBoxLayout;
    buttonGroupSpaceLayout = new QVBoxLayout;
    buttonGroupExtensionFilterLayout = new QVBoxLayout;
    extensionButtonHLayout = new QHBoxLayout;
    buttonHLayout = new QHBoxLayout;
    buttonGroupSubfolders = new QGroupBox(tr(Widgets::buttonGroupGeneral));
    buttonGroupReplace = new QGroupBox(tr(Widgets::buttonGroupReplace));
    buttonGroupSize = new QGroupBox(tr(Widgets::buttonGroupSize));
    buttonGroupSpace = new QGroupBox(tr(Widgets::buttonGroupSpace));
    buttonGroupExtensionFilter = new QGroupBox(tr(Widgets::buttonGroupExtensionFilter));
    leftVLayout->addWidget(buttonGroupSubfolders);
    leftVLayout->addWidget(buttonGroupReplace);
    leftVLayout->addSpacing(40);
    centerVLayout->addWidget(buttonGroupSize);
    centerVLayout->addWidget(buttonGroupSpace);
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
    windowVLayout->addLayout(buttonHLayout);

    buttonHLayout->addWidget(buttonOK);
    buttonHLayout->addWidget(buttonCancel);

    extensionButtonHLayout->addWidget(buttonAddExtension);
    extensionButtonHLayout->addWidget(buttonDeleteExtension);

    //----Przypisanie przycisków do slotów----//
    connect(buttonOK,SIGNAL(clicked()),this,SLOT(saveSettings()));
    connect(buttonCancel,SIGNAL(clicked()),this,SLOT(closeWindow()));
    connect(checkBoxReplaceDashes,SIGNAL(clicked(bool)),this,SLOT(checkBoxDashesClicked()));
    connect(checkBoxReplaceDots,SIGNAL(clicked()),this,SLOT(checkBoxDotsClicked()));
    connect(buttonAddExtension,SIGNAL(clicked()),this,SLOT(addExtension()));
    connect(buttonDeleteExtension,SIGNAL(clicked()),this,SLOT(deleteExtension()));

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
    NameChangeParameters nameChangeParameters = settingsReader->getNameChangeParameters();

    checkBoxReplaceInSubfolders->setChecked(nameChangeParameters.getReplaceInSubfolders());
    checkBoxReplaceUnderscores->setChecked(nameChangeParameters.getReplaceUnderscores());
    checkBoxReplaceDashes->setChecked(nameChangeParameters.getReplaceDashes());
    checkBoxDontReplaceDashesSurrondedBySpaces->setChecked(nameChangeParameters.getDontReplaceDashesSurrondedBySpaces());
    checkBoxReplaceDots->setChecked(nameChangeParameters.getReplaceDots());
    checkBoxReplaceExtensionDot->setChecked(nameChangeParameters.getReplaceExtensionDot());
    checkBoxReplacePluses->setChecked(nameChangeParameters.getReplacePluses());
    checkBoxRemoveMultiplySpaces->setChecked(nameChangeParameters.getRemoveMultiplySpaces());
    checkBoxRemoveSpacesAtBegin->setChecked(nameChangeParameters.getRemoveSpacesAtBegin());
    checkBoxRemoveSpacesAtEnd->setChecked(nameChangeParameters.getRemoveSpacesAtEnd());

    auto selectionLetters = nameChangeParameters.getChangeLetters();
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

    auto selectionExtensions = nameChangeParameters.getChangeExtension();
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

    auto selectionExtensionFilter = nameChangeParameters.getExtensionFilter();
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

    if(nameChangeParameters.getReplaceDots() == true)
    {
        checkBoxReplaceExtensionDot->setEnabled(true);
    }
    else
    {
        checkBoxReplaceExtensionDot->setDisabled(true);
    }
    if(nameChangeParameters.getReplaceDashes() == true)
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

    settingsReader->setNameChangeParameters(nameChangeParameters);
}

//----Dodaj rozszerzenie do listy----//
void WidgetSettings::addExtension()
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
void WidgetSettings::deleteExtension()
{
    if(listWidgetExtensionFilter->currentRow() > -1)
    {
        delete listWidgetExtensionFilter->takeItem(listWidgetExtensionFilter->currentRow());
    }
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
