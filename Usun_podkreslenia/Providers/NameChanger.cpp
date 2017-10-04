#include "NameChanger.h"

NameChanger::NameChanger()
{
    warningMessageBoxText = "Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu";
}

void NameChanger::initiateRenameFiles(NameChangeParameters nameChangeParameters)
{
    this->nameChangeParameters = nameChangeParameters;
    renameFiles();
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
bool NameChanger::selectFolder()
{
    selectedFolder = QFileDialog::getExistingDirectory(); //Pobiera adres folderu
    if(selectedFolder.isNull() == false)
        return true;
    else
        return false;
}

//----Zwraca ścieżkę dostępu do folderu----//
QString NameChanger::getSelectedFolder()
{
    return selectedFolder;
}

//----Pokazuje okienko z informacjami, że katalog nie istnieje----//
void NameChanger::showFolderNotExist()
{
    int clickedButton; //Przechowuje informację o wyborze użytkownika w oknie dialogowym
    QMessageBox informationMessageBox("Ostrzeżenie",warningMessageBoxText,QMessageBox::Warning, QMessageBox::Ok | QMessageBox::Default,0,0);
    clickedButton = informationMessageBox.exec();
    if(clickedButton == QMessageBox::Ok) //Zamyka okno po wciśnięciu ok
        informationMessageBox.close();
}

//----Zmienia nazwę pliku zastępując znaki "_" na " "----//
QString NameChanger::replaceUnderscores(QString fileName)
{
    fileName.replace("_"," ");
    return fileName;
}

//----Zmienia nazwę pliku zastępując znaki "-" na " "----//
QString NameChanger::replaceDashes(QString fileName, bool dontReplaceDashesSurrondedBySpace)
{
    if(dontReplaceDashesSurrondedBySpace == false)
    {
        fileName.replace("-"," ");
    }
    else
    {
        if(fileName[0] == '-') fileName[0] = ' ';
        int end = fileName.length()-1;
        if(fileName[end] == '-') fileName[end] = ' ';
        for(int i = 1; i < end; i++)
        {
            if((fileName[i-1] != ' '|| fileName[i+1] != ' ') && fileName[i] == '-') fileName[i] = ' ';
        }
    }
    return fileName;
}

//----Zmienia nazwę pliku zastępując znaki "." na " "----//
QString NameChanger::replaceDots(QString fileName, bool replaceExtensionDot)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    fileName.replace("."," ");
    if(isExtensionDotNeedBeRestored(replaceExtensionDot, extensionDotPosition))
        fileName.replace(extensionDotPosition,1,".");
    return fileName;
}

//----Zmienia pierwszą literę na dużą----//
QString NameChanger::changeLettersSize(QString fileName, NameChangeParameters::Letters changeLetters)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    switch(changeLetters)
    {
    case NameChangeParameters::Letters::DoNothing:
        break;
    case NameChangeParameters::Letters::FirstBig:
        fileName[0] = fileName[0].toUpper();
        break;
    case NameChangeParameters::Letters::AllBig:    
        for(int i = 0; i<extensionDotPosition; i++)
            fileName[i] = fileName[i].toUpper();
        break;
    case NameChangeParameters::Letters::AllSmall:
        for(int i = 0; i<extensionDotPosition; i++)
            fileName[i] = fileName[i].toLower();
        break;
    case NameChangeParameters::Letters::FirstInWordsBig:
        fileName[0] = fileName[0].toUpper();
        int end = fileName.length();
        for(int i = 1; i < end; i++)
        {
            if(fileName[i-1] == ' ') fileName[i] = fileName[i].toUpper();
        }
        break;

    }
    return fileName;
}

//----Ustawia rozszeżenie pliku pisane z małej litery----//
QString NameChanger::changeExtensionSize(QString fileName, NameChangeParameters::Extensions changeExtension)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    if(extensionDotPosition != -1)
    {
        switch(changeExtension)
        {
        case NameChangeParameters::Extensions::FirstBig:
            if(extensionDotPosition+1 < fileName.length())
                fileName[extensionDotPosition+1] = fileName[extensionDotPosition+1].toUpper();
            break;
        case NameChangeParameters::Extensions::AllBig:
            for(int i = extensionDotPosition+1; i < fileName.length(); i++)
                fileName[i] = fileName[i].toUpper();
            break;
        case NameChangeParameters::Extensions::AllSmall:
            for(int i = extensionDotPosition+1; i < fileName.length(); i++)
                fileName[i] = fileName[i].toLower();
            break;
        case NameChangeParameters::Extensions::DoNothing:
            break;
        }
    }
    return fileName;
}

//----Usuwa spację----//
QString NameChanger::removeSpaces(QString fileName, bool removeMultiplySpaces, bool removeSpacesAtBegin, bool removeSpacesAtEnd)
{
    if(removeSpacesAtBegin == true)
        fileName.replace(QRegExp("^[ ]+"),"");
    if(removeSpacesAtEnd == true)
        fileName.replace(QRegExp("[ ]+$"),"");
    if(removeMultiplySpaces == true)
        fileName.replace(QRegExp("[ ]+")," ");
    return fileName;
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString NameChanger::changeFileName(QString fileName)
{
    if(nameChangeParameters.getReplaceUnderscores() == true)
        fileName = replaceUnderscores(fileName);
    if(nameChangeParameters.getReplaceDashes() == true)
        fileName = replaceDashes(fileName, nameChangeParameters.getDontReplaceDashesSurrondedBySpaces());
    if(nameChangeParameters.getReplaceDots() == true)
        fileName = replaceDots(fileName, nameChangeParameters.getReplaceExtensionDot());
    fileName = changeLettersSize(fileName, nameChangeParameters.getChangeLetters());
    fileName = changeExtensionSize(fileName, nameChangeParameters.getChangeExtension());
    fileName = removeSpaces(fileName,nameChangeParameters.getRemoveMultiplySpaces(),nameChangeParameters.getRemoveSpacesAtBegin(),nameChangeParameters.getRemoveSpacesAtEnd());
    return fileName;
}

//----Porównuje dwie nazwy plików jeśli są identyczne zwraca true----//
bool NameChanger::isFileNameIdentical(QString oldName, QString newName)
{
    if(oldName == newName)
        return true;
    else
        return false;
}

//----Ustawia pasek postępu w stan zajętości----//
void NameChanger::setBusyProgressBar()
{
    emit initializeProgressBar(0,0);
}

//----Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze----//
void NameChanger::initiateProgressBar(int max)
{
    emit initializeProgressBar(0, max);
    emit changeProgressBar(0);
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void NameChanger::renameFiles()
{
    QDir currentFolder(selectedFolder);
    if(!currentFolder.exists())
    {
        showFolderNotExist();
        selectedFolder = "";
        return;
    }
    setBusyProgressBar();
    FolderDetector folderDetector(selectedFolder, nameChangeParameters.getReplaceInSubfolders());
    int numberFiles = folderDetector.getNumberFiles();
    initiateProgressBar(numberFiles);

    QStringList folderList = folderDetector.getFolderList();

    int numberOfRenamedFiles = 0;
    for(auto folderListIterator = folderList.begin(); folderListIterator != folderList.end(); folderListIterator++)
    {
        QString nextFolder = *folderListIterator;
        currentFolder.cd(nextFolder);
        if(!currentFolder.exists())
            continue;
        for(unsigned int i = 0; i < currentFolder.count(); i++)
        {
            numberOfRenamedFiles++;
            changeProgressBar(numberOfRenamedFiles);

            if(isFile(currentFolder, currentFolder[static_cast<int>(i)]))
            {
                QString fileName = currentFolder[static_cast<int>(i)];
                QString newFileName = changeFileName(fileName);
                if(isFileNameIdentical(fileName,newFileName))
                    continue;
                else
                {
                    QFile file(nextFolder + QDir::separator() + fileName);
                    file.rename(nextFolder + QDir::separator() + newFileName);
                }
            }
        }
    }
    emit resetProgressBar();
    selectedFolder = "";
}

bool NameChanger::isExtensionDotNeedBeRestored(bool replaceExtensionDot, int extensionDotPosition)
{
    if((extensionDotPosition != -1) && (replaceExtensionDot == false))
        return true;
    else
        return false;
}

bool NameChanger::isFile(QDir accessPath, QString fileName)
{
     return !FolderDetector::isSubfolder(accessPath, fileName);
}