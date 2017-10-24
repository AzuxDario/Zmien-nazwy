#include "FolderDetector.h"

FolderDetector::FolderDetector(QString selectedFolder, bool searchInSubfolders)
{
    this->selectedFolder = selectedFolder;
    this->searchInSubfolders = searchInSubfolders;
    numberFiles = 0;
    searchFolders();
}

//----Zwraca listę folderów----//
QStringList FolderDetector::getFolderList()
{
    return folderList;
}

//----Zwraca ilość plików w podfolderach----//
int FolderDetector::getNumberFiles()
{
    return numberFiles;
}

//----Uzupełnia liste folderów o podfoldery----//
void FolderDetector::searchFolders()
{
    QDir currentFolder(selectedFolder);
    folderList.push_back(selectedFolder);
    if(searchInSubfolders == true)
    {
        for(int folderListIterator = 0; folderList.begin()+folderListIterator != folderList.end(); folderListIterator++)
        {
            //Należy co pętle pobierać iterator początku, gdyż może dojść do przemieszczenia się vectora w pamięci
            //co spowoduje, że iterator będzie pokazywał na poprzednie już puste miejsce
            QString nextSearchFolder = *(folderList.begin()+folderListIterator);
            currentFolder.cd(nextSearchFolder);
            if(!currentFolder.exists())
                continue;
            numberFiles += currentFolder.count();
            for(unsigned int i = 0; i < currentFolder.count(); i++)
                if(DirectoryIdentifier::isSubfolder(currentFolder, currentFolder[static_cast<int>(i)]))
                    folderList.push_back(currentFolder.absoluteFilePath(currentFolder[static_cast<int>(i)]));
        }
    }
    else
        numberFiles += currentFolder.count();
}
