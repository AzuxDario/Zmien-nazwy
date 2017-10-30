#include "NameChangeParameters.h"

NameChangeParameters::NameChangeParameters()
{
    replaceInSubfolders = false;
    replaceUnderscores = false;
    replaceDashes = false;
    dontReplaceDashesSurrondedBySpaces = false;
    replaceDots = false;
    replaceExtensionDot = false;
    replacePluses = false;
    removeMultiplySpaces = false;
    removeSpacesAtBegin = false;
    removeSpacesAtEnd = false;
    changeLetters = Letters::DoNothing;
    changeExtension = Extensions::DoNothing;
}
