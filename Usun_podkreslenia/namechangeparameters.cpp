#include "namechangeparameters.h"

NameChangeParameters::NameChangeParameters()
{
    replaceInSubfolders = false;
    replaceUnderscores = false;
    replaceDashes = false;
    replaceDots = false;
    replaceExtensionDot = false;
    changeFirstLetterToBig = false;
    changeExtensionToSmall = false;
}

void NameChangeParameters::setReplaceInSubfolders(bool value)
{
    replaceInSubfolders = value;
}

void NameChangeParameters::setReplaceUnderscores(bool value)
{
    replaceUnderscores = value;
}

void NameChangeParameters::setReplaceDashes(bool value)
{
    replaceDashes = value;
}

void NameChangeParameters::setReplaceDots(bool value)
{
    replaceDots = value;
}

void NameChangeParameters::setReplaceExtensionDot(bool value)
{
    replaceExtensionDot = value;
}

void NameChangeParameters::setChangeFirstLetterToBig(bool value)
{
    changeFirstLetterToBig = value;
}

void NameChangeParameters::setChangeExtensionToSmall(bool value)
{
    changeExtensionToSmall = value;
}

bool NameChangeParameters::getReplaceInSubfolders()
{
    return replaceInSubfolders;
}

bool NameChangeParameters::getReplaceUnderscores()
{
    return replaceUnderscores;
}

bool NameChangeParameters::getReplaceDashes()
{
    return replaceDashes;
}

bool NameChangeParameters::getReplaceDots()
{
    return replaceDots;
}

bool NameChangeParameters::getReplaceExtensionDot()
{
    return replaceExtensionDot;
}

bool NameChangeParameters::getChangeFirstLetterToBig()
{
    return changeFirstLetterToBig;
}

bool NameChangeParameters::getChangeExtensionToSmall()
{
    return changeExtensionToSmall;
}
