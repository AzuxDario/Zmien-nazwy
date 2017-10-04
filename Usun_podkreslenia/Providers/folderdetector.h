#ifndef FOLDERDETECTOR_H
#define FOLDERDETECTOR_H

#include <QString>
#include <QStringList>
#include <QDir>

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
    QStringList getFolderList(); //Zwraca listę folderów
    int getNumberFiles(); //Zwraca ilość plików w podfolderach

private:
    void searchFolders(); //Uzupełnia liste folderów o podfoldery

public:
    static bool isSubfolder(QDir accessPath, QString fileName);
    static bool isCurrentOrParentFolder(QString fileName); //Zwraca true gdy folder to '.' lub '..'
    static bool isNotCurrentOrParentFolder(QString fileName);
    static bool isFolder(QDir accessPath, QString fileName); //Sprawdza czy element jest folderem
};

#endif // FOLDERDETECTOR_H
