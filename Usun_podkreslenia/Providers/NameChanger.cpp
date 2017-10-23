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

//----Pokazuje okienko z informacjami, że katalog nie istnieje----//
void NameChanger::showFolderNotExist()
{
    int clickedButton; //Przechowuje informację o wyborze użytkownika w oknie dialogowym
    QMessageBox informationMessageBox(tr(Warnings::warning),tr(Warnings::folderNotFound),QMessageBox::Warning, QMessageBox::Ok | QMessageBox::Default,0,0);
    clickedButton = informationMessageBox.exec();
    if(clickedButton == QMessageBox::Ok) //Zamyka okno po wciśnięciu ok
        informationMessageBox.close();
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString NameChanger::changeFileName(QString fileName)
{
    if(nameChangeParameters.getReplaceUnderscores() == true)
        fileName = nameModifier.replaceUnderscores(fileName);
    if(nameChangeParameters.getReplaceDashes() == true)
        fileName = nameModifier.replaceDashes(fileName, nameChangeParameters.getDontReplaceDashesSurrondedBySpaces());
    if(nameChangeParameters.getReplaceDots() == true)
        fileName = nameModifier.replaceDots(fileName, nameChangeParameters.getReplaceExtensionDot());
    fileName = nameModifier.changeLettersSize(fileName, nameChangeParameters.getChangeLetters());
    fileName = nameModifier.changeExtensionSize(fileName, nameChangeParameters.getChangeExtension());
    fileName = nameModifier.removeSpaces(fileName,nameChangeParameters.getRemoveMultiplySpaces(),nameChangeParameters.getRemoveSpacesAtBegin(),nameChangeParameters.getRemoveSpacesAtEnd());
    return fileName;
}

//----Porównuje dwie nazwy plików jeśli są identyczne zwraca true----//
bool NameChanger::isFileNameIdentical(QString oldName, QString newName)
{
    return oldName == newName;
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

            if(FolderDetector::isFile(currentFolder, currentFolder[static_cast<int>(i)]))
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
