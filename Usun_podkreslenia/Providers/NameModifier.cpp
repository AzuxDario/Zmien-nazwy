#include "NameModifier.h"

NameModifier::NameModifier()
{

}

//----Zmienia nazwę pliku zastępując znaki "_" na " "----//
QString NameModifier::replaceUnderscores(QString fileName)
{
    fileName.replace("_"," ");
    return fileName;
}

//----Zmienia nazwę pliku zastępując znaki "-" na " "----//
QString NameModifier::replaceDashes(QString fileName, bool dontReplaceDashesSurrondedBySpace)
{
    if(dontReplaceDashesSurrondedBySpace == false)
    {
        fileName.replace("-"," ");
        fileName.replace("—"," ");
    }
    else
    {
        if(fileName[0] == '-' || fileName[0] == "—") fileName[0] = ' ';
        int end = fileName.length()-1;
        if(fileName[end] == '-' || fileName[end] == "—") fileName[end] = ' ';
        for(int i = 1; i < end; i++)
        {
            if((fileName[i-1] != ' '|| fileName[i+1] != ' ') && fileName[i] == '-') fileName[i] = ' ';
            if((fileName[i-1] != ' '|| fileName[i+1] != ' ') && fileName[i] == "—") fileName[i] = ' ';
        }
    }
    return fileName;
}

//----Zmienia nazwę pliku zastępując znaki "." na " "----//
QString NameModifier::replaceDots(QString fileName, bool replaceExtensionDot)
{
    int extensionDotPosition = fileName.lastIndexOf(".");
    fileName.replace("."," ");
    if(isExtensionDotNeedBeRestored(replaceExtensionDot, extensionDotPosition))
        fileName.replace(extensionDotPosition,1,".");
    return fileName;
}

//----Zmienia pierwszą literę na dużą----//
QString NameModifier::changeLettersSize(QString fileName, NameChangeParameters::Letters changeLetters)
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
QString NameModifier::changeExtensionSize(QString fileName, NameChangeParameters::Extensions changeExtension)
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
QString NameModifier::removeSpaces(QString fileName, bool removeMultiplySpaces, bool removeSpacesAtBegin, bool removeSpacesAtEnd)
{
    if(removeSpacesAtBegin == true)
        fileName.replace(QRegExp("^[ ]+"),"");
    if(removeSpacesAtEnd == true)
        fileName.replace(QRegExp("[ ]+$"),"");
    if(removeMultiplySpaces == true)
        fileName.replace(QRegExp("[ ]+")," ");
    return fileName;
}

//----Czy kropka rozszeżenia powinna być przywrócona----//
bool NameModifier::isExtensionDotNeedBeRestored(bool replaceExtensionDot, int extensionDotPosition)
{
    if((extensionDotPosition != -1) && (replaceExtensionDot == false))
        return true;
    else
        return false;
}
