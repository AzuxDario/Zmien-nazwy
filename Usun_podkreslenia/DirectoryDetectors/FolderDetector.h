#ifndef FOLDERDETECTOR_H
#define FOLDERDETECTOR_H

#include <QString>
#include <QStringList>
#include <QDir>
#include "DirectoryIdentifier.h"

class FolderDetector
{
public:
    FolderDetector(QString selectedFolder, bool searchInSubfolders);

private:
    QString selectedFolder;

    //----Lista przechowująca folder główny i wszystkie podfoldery----//
    QStringList folderList;

    int numberFiles;
    bool searchInSubfolders;

public:
    const QStringList& getFolderList(); //Zwraca listę folderów
    int getNumberFiles(); //Zwraca ilość plików w podfolderach

private:
    void searchFolders(); //Uzupełnia liste folderów o podfoldery
};

#endif // FOLDERDETECTOR_H
