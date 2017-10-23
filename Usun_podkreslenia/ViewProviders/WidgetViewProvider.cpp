#include "WidgetViewProvider.h"

WidgetViewProvider::WidgetViewProvider()
{
    //--------Wskaźnik na okienko rejestr zmian--------//
    widgetChangeLog = NULL; //Bez tego będzie crash Segmentation Fault
    widgetAbout = NULL;
    widgetSettings = NULL;

    nameChanger = new NameChanger();

    //--------Obiekt czytajacy ustawienia--------//
    settingsReader = new Settings;

    nameChangeParameters = settingsReader->getNameChangeParameters();
    connect(nameChanger,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBarSlot(int,int)));
    connect(nameChanger,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBarSlot(int)));
    connect(nameChanger,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBarSlot()));
}

void WidgetViewProvider::changeName(NameChangeParameters nameChangeParameters)
{
    nameChanger->initiateRenameFiles(nameChangeParameters);
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
QString WidgetViewProvider::selectFolder()
{
    QString selectedFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu

    if(selectedFolder.isNull() == false)
    {
        nameChanger->setSelectedFolder(selectedFolder);
        return selectedFolder;
    }
    else
        return "";
}

//----Pokazuje okienko z informacjami o programie----//
void WidgetViewProvider::showWidgetAbout()
{
    if(widgetAbout == NULL) //Jeżli okna nie ma stwórz je
        widgetAbout = new WidgetAbout(About::aboutApp);
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
        widgetChangeLog = new WidgetChangeLog(About::changeLog);
    else
        widgetChangeLog->showWindow();
}
