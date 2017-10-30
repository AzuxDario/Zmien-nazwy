#include "WidgetViewProvider.h"

WidgetViewProvider::WidgetViewProvider()
{
    //--------Wskaźnik na okienko rejestr zmian--------//
    widgetChangeLog = NULL; //Bez tego będzie crash Segmentation Fault
    widgetAbout = NULL;
    widgetSettings = NULL;

    renamer = new Renamer();

    settingsReader = new Settings;

    nameChangeParameters = settingsReader->getNameChangeParameters();
    connect(renamer,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBarSlot(int,int)));
    connect(renamer,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBarSlot(int)));
    connect(renamer,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBarSlot()));
}

void WidgetViewProvider::changeName(NameChangeParameters nameChangeParameters)
{
        renamer->initiateRenameFiles(nameChangeParameters, dirType);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
QString WidgetViewProvider::selectFolder()
{
    QString selectedFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu

    if(selectedFolder.isNull() == false)
    {
        renamer->setSelectedFile(selectedFolder);
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
        renamer->setSelectedFile(selectedFile);
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
