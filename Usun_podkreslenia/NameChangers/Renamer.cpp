#include "Renamer.h"

Renamer::Renamer()
{

}

void Renamer::initiateRenameFiles(NameChangeParameters nameChangeParameters, NameChangeParameters::DirType dirType)
{
    this->nameChangeParameters = nameChangeParameters;
    switch (dirType) {
    case NameChangeParameters::DirType::Folder:
        renameInFolders();
        break;
    case NameChangeParameters::DirType::File:
        renameOneFile();
        break;
    }

}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Renamer::renameInFolders()
{
    QDir currentFolder(selectedFile);
    if(currentFolder.exists())
    {
        setBusyProgressBar();
        FolderDetector folderDetector(selectedFile, nameChangeParameters.getReplaceInSubfolders());
        initiateProgressBar(folderDetector.getNumberFiles());
        QStringList folderList = folderDetector.getFolderList();

        renameFiles(currentFolder, folderList);
        emit resetProgressBar();
    }
    else
    {
        showError(Warnings::folderNotFound);
    }
    selectedFile = "";
}

//----Funkcja zmienia nazwę jednego pliku----//
void Renamer::renameOneFile()
{
    QFile currentFile(selectedFile);
    if(currentFile.exists())
    {
        QString oldName = currentFile.fileName();
        QString newName = changeFileName(oldName);
        if(isFileNameIdentical(oldName, newName) == false)
        {
            currentFile.rename(newName);
        }
    }
    else
    {
        showError(Warnings::fileNotFound);
    }
    selectedFile = "";
}

//----Funkcja zmienia nazwy plików w folderach----//
void Renamer::renameFiles(QDir currentFolder, const QStringList& folderList)
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

//----Funkcja pokazuje błąd----//
void Renamer::showError(const char* string)
{
    int clickedButton; //Przechowuje informację o wyborze użytkownika w oknie dialogowym
    QMessageBox informationMessageBox(tr(Warnings::warning),tr(string),QMessageBox::Warning, QMessageBox::Ok | QMessageBox::Default,0,0);
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
