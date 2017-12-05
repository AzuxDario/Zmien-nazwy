#include "WidgetViewProvider.h"

WidgetViewProvider::WidgetViewProvider()
{
    //--------Wskaźnik na okienko rejestr zmian--------//
    widgetChangeLog = NULL; //Bez tego będzie crash Segmentation Fault
    widgetAbout = NULL;
    widgetSettings = NULL;

    renamerController = new RenamerController;

    settingsReader = new Settings;

    nameChangeParameters = settingsReader->getNameChangeParameters();
    connect(renamerController,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBarSlot(int,int)));
    connect(renamerController,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBarSlot(int)));
    connect(renamerController,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBarSlot()));
    connect(renamerController,SIGNAL(doneWork()),this, SLOT(handleResults()));
}

void WidgetViewProvider::changeName(NameChangeParameters nameChangeParameters)
{
        renamerController->initiateRenameFiles(nameChangeParameters, selectedDir, dirType);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
QString WidgetViewProvider::selectFolder()
{
    QString selectedFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu

    if(selectedFolder.isNull() == false)
    {
        selectedDir.clear();
        selectedDir.push_back(selectedFolder);
        dirType = NameChangeParameters::DirType::Folder;
        return selectedFolder;
    }
    else
        return "";
}
//----Wybiera plik do przeprowadzenia zmiany nazw----//
QString WidgetViewProvider::selectFile()
{
    QString selectedFile = QFileDialog::getOpenFileName(); //Pobiera adres folderu

    if(selectedFile.isNull() == false)
    {
        selectedDir.clear();
        selectedDir.push_back(selectedFile);
        dirType = NameChangeParameters::DirType::File;
        return selectedFile;
    }
    else
        return "";
}

//----Pokazuje okienko z informacjami o programie----//
void WidgetViewProvider::showWidgetAbout()
{
    if(widgetAbout == NULL) //Jeżli okna nie ma stwórz je
        widgetAbout = new WidgetAbout();
    else
        widgetAbout->showWindow();
}

//----Wyświetla okno ustawień----//
void WidgetViewProvider::showWidgetSettings()
{
    if(widgetSettings == NULL) //Jeżli okna nie ma stwórz je
        widgetSettings = new WidgetSettings();
    else
        widgetSettings->showWindow();
}

//----Wyświetla okienko z rejestrem zmian----//
void WidgetViewProvider::showWidgetChangeLog()
{
    if(widgetChangeLog == NULL) //Jeżli okna nie ma stwórz je
        widgetChangeLog = new WidgetChangeLog();
    else
        widgetChangeLog->showWindow();
}
