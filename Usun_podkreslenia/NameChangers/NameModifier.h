#ifndef NAMEMODIFIER_H
#define NAMEMODIFIER_H

#include <QString>
#include <QRegExp>
#include "NameChangeParameters.h"

class NameModifier
{
public:
    NameModifier();

    QString replaceUnderscores(QString fileName); //Zmienia nazwę pliku zastępując znaki "_" na " "
    QString replaceDashes(QString fileName, bool dontReplaceDashesSurrondedBySpace); //Zmienia nazwę pliku zastępując znaki "-" na " "
    QString replaceDots(QString fileName, bool replaceExtensionDot); //Zmienia nazwę pliku zastępując znaki "." na " "
    QString changeLettersSize(QString fileName, NameChangeParameters::Letters changeLetters); //Zmienia pierwszą literę na dużą
    QString changeExtensionSize(QString fileName, NameChangeParameters::Extensions changeExtension); //Ustawia rozszeżenie pliku pisane z małej litery
    QString removeSpaces(QString fileName, bool removeMultiplySpaces, bool removeSpacesAtBegin, bool removeSpacesAtEnd); //Usuwa spację
    bool isExtensionDotNeedBeRestored(bool replaceExtensionDot, int extensionDotPosition); //Czy kropka rozszeżenia powinna być przywrócona
};

#endif // NAMEMODIFIER_H
