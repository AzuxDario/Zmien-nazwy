#ifndef NAMECHANGER_H
#define NAMECHANGER_H

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QRegExp>
#include "FolderDetector.h"
#include "NameChangeParameters.h"

class NameChangerTest;

class NameChanger :public QObject
{
    Q_OBJECT

    friend NameChangerTest;

public:
    NameChanger();

private:
    NameChangeParameters nameChangeParameters;

    QString selectedFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString warningMessageBoxText;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();

public:
    void initiateRenameFiles(NameChangeParameters nameChangeParameters); //Rozpoczyna procedurę zmiany nazw
    bool selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    QString getSelectedFolder(); //Zwraca ścieżkę dostępu do folderu

private:
    void showFolderNotExist(); //Pokazuje okienko z informacjami, że katalog nie istnieje
    QString replaceUnderscores(QString fileName); //Zmienia nazwę pliku zastępując znaki "_" na " "
    QString replaceDashes(QString fileName, bool dontReplaceDashesSurrondedBySpace); //Zmienia nazwę pliku zastępując znaki "-" na " "
    QString replaceDots(QString fileName, bool replaceExtensionDot); //Zmienia nazwę pliku zastępując znaki "." na " "
    QString changeLettersSize(QString fileName, NameChangeParameters::Letters changeLetters); //Zmienia pierwszą literę na dużą
    QString changeExtensionSize(QString fileName, NameChangeParameters::Extensions changeExtension); //Ustawia rozszeżenie pliku pisane z małej litery
    QString removeSpaces(QString fileName, bool removeMultiplySpaces, bool removeSpacesAtBegin, bool removeSpacesAtEnd); //Usuwa spację
    QString changeFileName(QString fileName); //Wykonuje operacje zmiany nazwy pliku
    bool isFileNameIdentical(QString oldName, QString newName); //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void setBusyProgressBar(); //Ustawia pasek postępu w stan zajętości
    void initiateProgressBar(int max); //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze
    void renameFiles(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    bool isExtensionDotNeedBeRestored(bool replaceExtensionDot, int extensionDotPosition);
    bool isFile(QDir accessPath, QString fileName);
};

#endif // NAMECHANGER_H