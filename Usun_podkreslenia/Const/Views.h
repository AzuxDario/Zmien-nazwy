#ifndef VIEWS_H
#define VIEWS_H

#include <QString>

class Views
{
public:
    const static char* menuFile;
    const static char* menuSettings;
    const static char* menuHelp;

    const static char* actionSelectFolder;
    const static char* actionStartChange;
    const static char* actionExit;
    const static char* actionOptions;
    const static char* actionAbout;
    const static char* actionChangeLog;

    const static char* checkBoxReplaceInSubfolders;
    const static char* checkBoxReplaceUnderscores;
    const static char* checkBoxReplaceDashes;
    const static char* checkBoxDontReplaceDashesSurrondedBySpaces;
    const static char* checkBoxReplaceDots;
    const static char* checkBoxReplaceExtensionDot;
    const static char* checkBoxRemoveMultiplySpaces;
    const static char* checkBoxRemoveSpacesAtBegin;
    const static char* checkBoxRemoveSpacesAtEnd;
    const static char* radioButtonChangeFirstLetterToBig;
    const static char* radioButtonChangeLettersToBig;
    const static char* radioButtonChangeLettersToSmall;
    const static char* radioButtonChangeFirstLettersToBig;
    const static char* radioButtonDontChange;
    const static char* radioButtonChangeExtensionToBig;
    const static char* radioButtonChangeExtensionToSmall;
    const static char* radioButtonChangeExtensionFirstLettersToBig;

    const static char* buttonGroupSubfolders;
    const static char* buttonGroupReplace;
    const static char* buttonGroupLetterSize;
    const static char* buttonGroupExtensionSize;
    const static char* buttonGroupSpace;

    const static char* textToStartSelectFolder;
    const static char* textSelectedFolder;
    const static char* textNamesWillBeChanged;
    const static char* textFolderDoesntSelected;
    const static char* textNamesChanged;
public:
    Views();
};

#endif // VIEWS_H
