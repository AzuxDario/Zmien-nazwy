#include "DirectoryIdentifier.h"

DirectoryIdentifier::DirectoryIdentifier()
{

}

bool DirectoryIdentifier::isSubfolder(QDir accessPath, QString fileName)
{
    if(isNotCurrentOrParentFolder(fileName))
        if(isFolder(accessPath, fileName))
            return true;
    return false;
}

bool DirectoryIdentifier::isCurrentOrParentFolder(QString fileName)
{
    if((fileName == ".") || (fileName == ".."))
        return true;
    else
        return false;
}

bool DirectoryIdentifier::isNotCurrentOrParentFolder(QString fileName)
{
    return !isCurrentOrParentFolder(fileName);
}

//----Sprawdza czy element jest folderem----//
bool DirectoryIdentifier::isFolder(QDir accessPath, QString fileName)
{
    if(accessPath.cd(fileName) == true)
        return true;
    else
        return false;
}

bool DirectoryIdentifier::isFile(QDir accessPath, QString fileName)
{
     return !isSubfolder(accessPath, fileName);
}

QString DirectoryIdentifier::getFileExtension(QString fileName)
{
    if(fileName.indexOf('.') == -1)
        return "";
    else
    {
       return fileName.section('.',-1,-1);
    }
}
