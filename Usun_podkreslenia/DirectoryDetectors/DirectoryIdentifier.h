#ifndef DIRECTORYIDENTIFIER_H
#define DIRECTORYIDENTIFIER_H

#include <QDir>
#include <QString>

class DirectoryIdentifier
{
public:
    DirectoryIdentifier();

    static bool isSubfolder(QDir accessPath, QString fileName);
    static bool isCurrentOrParentFolder(QString fileName); //Zwraca true gdy folder to '.' lub '..'
    static bool isNotCurrentOrParentFolder(QString fileName);
    static bool isFolder(QDir accessPath, QString fileName); //Sprawdza czy element jest folderem
    static bool isFile(QDir accessPath, QString fileName);
    static QString getFileExtension(QString fileName);
};

#endif // DIRECTORYIDENTIFIER_H
