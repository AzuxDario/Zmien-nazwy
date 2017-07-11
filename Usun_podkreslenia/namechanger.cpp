#include "namechanger.h"

NameChanger::NameChanger(QProgressBar *progressBar)
{
    warningMessageBoxText = "Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu";
    this->progressBar = progressBar;
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
QString NameChanger::replaceDashes(QString fileName)
{
    fileName.replace("-"," ");
    return fileName;
}

//----Zmienia nazwę pliku zastępując znaki "." na " "----//
QString NameChanger::replaceDots(QString fileName)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    fileName.replace("."," ");
    if(isExtensionDotNeedBeRestored(extensionDotPosition))
        fileName.replace(extensionDotPosition,1,".");
    return fileName;
}

//----Zmienia pierwszą literę na dużą----//
QString NameChanger::changeFirstLetterToBig(QString fileName)
{
    fileName[0] = fileName[0].toUpper();
    return fileName;
}

//----Ustawia rozszeżenie pliku pisane z małej litery----//
QString NameChanger::changeExtensionToSmall(QString fileName)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    if(extensionDotPosition != -1)
        for(int i = extensionDotPosition+1; i < fileName.length(); i++)
            fileName[i] = fileName[i].toLower();
    return fileName;
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString NameChanger::changeFileName(QString fileName)
{
    if(nameChangeParameters.getReplaceUnderscores() == true)
        fileName = replaceUnderscores(fileName);
    if(nameChangeParameters.getReplaceDashes() == true)
        fileName = replaceDashes(fileName);
    if(nameChangeParameters.getReplaceDots() == true)
        fileName = replaceDots(fileName);
    if(nameChangeParameters.getChangeLetters() == true)
        fileName = changeFirstLetterToBig(fileName);
    if(nameChangeParameters.getChangeExtension() == true)
        fileName = changeExtensionToSmall(fileName);
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
    progressBar->setMaximum(0);
    progressBar->setMinimum(0);
}

//----Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze----//
void NameChanger::initiateProgressBar(int max)
{
    progressBar->setMinimum(0);
    progressBar->setMaximum(max);
    progressBar->setValue(0);
}

//----Zeruje pasek postępu----//
void NameChanger::resetProgressBar()
{
    progressBar->reset();
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

    for(auto folderListIterator = folderList.begin(); folderListIterator != folderList.end(); folderListIterator++)
    {
        QString nextFolder = *folderListIterator;
        currentFolder.cd(nextFolder);
        if(!currentFolder.exists())
            continue;
        for(unsigned int i = 0; i < currentFolder.count(); i++)
        {
            progressBar->setValue(progressBar->value()+i+1);

            if(isFile(currentFolder, currentFolder[i]))
            {
                QString fileName = currentFolder[i];
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
    resetProgressBar();
    selectedFolder = "";
}

bool NameChanger::isExtensionDotNeedBeRestored(int extensionDotPosition)
{
    if((extensionDotPosition != -1) && (nameChangeParameters.getReplaceExtensionDot() == false))
        return true;
    else
        return false;
}

bool NameChanger::isFile(QDir accessPath, QString fileName)
{
     return !FolderDetector::isSubfolder(accessPath, fileName);
}
