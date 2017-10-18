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
#include "NameModifier.h"


class NameChanger :public QObject
{
    Q_OBJECT

public:
    NameChanger();

private:
    NameChangeParameters nameChangeParameters;

    QString selectedFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString warningMessageBoxText;

    NameModifier nameModifier;

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
    QString changeFileName(QString fileName); //Wykonuje operacje zmiany nazwy pliku
    bool isFileNameIdentical(QString oldName, QString newName); //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void setBusyProgressBar(); //Ustawia pasek postępu w stan zajętości
    void initiateProgressBar(int max); //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze
    void renameFiles(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
};

#endif // NAMECHANGER_H
