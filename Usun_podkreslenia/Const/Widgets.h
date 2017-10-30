#ifndef WIDGETS_H
#define WIDGETS_H

#include <QString>

class Widgets
{
public:
    const static char* applicationName;

    const static char* widgetMain;
    const static char* widgetSettings;
    const static char* widgetChangeLog;
    const static char* widgetAbout;

    const static char* buttonOk;
    const static char* buttonCancel;

    const static char* menuFile;
    const static char* menuSettings;
    const static char* menuHelp;

    const static char* actionSelectFolder;
    const static char* actionSelectFile;
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
    const static char* checkBoxReplacePluses;
    const static char* checkBoxRemoveMultiplySpaces;
    const static char* checkBoxRemoveSpacesAtBegin;
    const static char* checkBoxRemoveSpacesAtEnd;
    const static char* radioButtonChangeFirstLetterToBig;
    const static char* radioButtonChangeFirstLetterToBigRestSmall;
    const static char* radioButtonChangeLettersToBig;
    const static char* radioButtonChangeLettersToSmall;
    const static char* radioButtonChangeFirstLettersToBig;
    const static char* radioButtonDontChange;
    const static char* radioButtonChangeExtensionToBig;
    const static char* radioButtonChangeExtensionToSmall;
    const static char* radioButtonChangeExtensionFirstLettersToBig;

    const static char* buttonGroupSubfolders;
    const static char* buttonGroupReplace;
    const static char* buttonGroupSize;
    const static char* buttonGroupSpace;

    const static char* labelGroupLetterSize;
    const static char* labelGroupExtensionSize;

    const static char* textToStartSelectFolderOrFile;
    const static char* textSelectedFolder;
    const static char* textSelectedFile;
    const static char* textNamesWillBeChangedInFolder;
    const static char* textFileNameWillBeChanged;
    const static char* textFolderDoesntSelected;
    const static char* textFileDoesntSelected;
    const static char* textNamesChanged;
    const static char* textDefaultSettings;
public:
    Widgets();
};

#endif // WIDGETS_H
