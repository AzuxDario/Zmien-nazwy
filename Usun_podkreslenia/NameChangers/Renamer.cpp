#include "Renamer.h"

Renamer::Renamer()
{

}

void Renamer::initiateRenameFiles(NameChangeParameters nameChangeParameters)
{
    this->nameChangeParameters = nameChangeParameters;
    renameInFolders();
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Renamer::renameInFolders()
{
    QDir currentFolder(selectedFolder);
    if(isFolderExist(currentFolder))
    {
        setBusyProgressBar();
        FolderDetector folderDetector(selectedFolder, nameChangeParameters.getReplaceInSubfolders());
        initiateProgressBar(folderDetector.getNumberFiles());
        QStringList folderList = folderDetector.getFolderList();

        renameFiles(currentFolder, folderList);
        emit resetProgressBar();
    }
    selectedFolder = "";
}

//----Sprawdza czy folder istnieje----//
bool Renamer::isFolderExist(QDir directory)
{
    if(directory.exists())
    {
        return true;
    }
    else
    {
        showFolderNotExist();
        return false;
    }
}
//----Funkcja zmienia nazwy plików w folderach----//
void Renamer::renameFiles(QDir currentFolder, QStringList folderList)
{
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

            if(DirectoryIdentifier::isFile(currentFolder, currentFolder[static_cast<int>(i)]))
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
}

//----Pokazuje okienko z informacjami, że katalog nie istnieje----//
void Renamer::showFolderNotExist()
{
    int clickedButton; //Przechowuje informację o wyborze użytkownika w oknie dialogowym
    QMessageBox informationMessageBox(tr(Warnings::warning),tr(Warnings::folderNotFound),QMessageBox::Warning, QMessageBox::Ok | QMessageBox::Default,0,0);
    clickedButton = informationMessageBox.exec();
    if(clickedButton == QMessageBox::Ok) //Zamyka okno po wciśnięciu ok
        informationMessageBox.close();
}

//----Wykonuje operacje zmiany nazwy pliku----//
QString Renamer::changeFileName(QString fileName)
{
    if(nameChangeParameters.getReplaceUnderscores() == true)
        fileName = nameModifier.replaceUnderscores(fileName);
    if(nameChangeParameters.getReplaceDashes() == true)
        fileName = nameModifier.replaceDashes(fileName, nameChangeParameters.getDontReplaceDashesSurrondedBySpaces());
    if(nameChangeParameters.getReplaceDots() == true)
        fileName = nameModifier.replaceDots(fileName, nameChangeParameters.getReplaceExtensionDot());
    if(nameChangeParameters.getReplacePluses() == true)
        fileName = nameModifier.replacePluses(fileName);
    fileName = nameModifier.changeLettersSize(fileName, nameChangeParameters.getChangeLetters());
    fileName = nameModifier.changeExtensionSize(fileName, nameChangeParameters.getChangeExtension());
    fileName = nameModifier.removeSpaces(fileName,nameChangeParameters.getRemoveMultiplySpaces(),nameChangeParameters.getRemoveSpacesAtBegin(),nameChangeParameters.getRemoveSpacesAtEnd());
    return fileName;
}
