#ifndef NAMECHANGER_H
#define NAMECHANGER_H

#include <QString>
#include <QProgressBar>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include "folderdetetor.h"
#include "namechangeparameters.h"

class NameChanger
{
public:
    NameChanger(QProgressBar *progressBar);

private:
    NameChangeParameters nameChangeParameters;

    QProgressBar *progressBar;

    QString selectedFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString warningMessageBoxText;

public:
    void initiateRenameFiles(NameChangeParameters nameChangeParameters); //Rozpoczyna procedurę zmiany nazw
    bool selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    QString getSelectedFolder(); //Zwraca ścieżkę dostępu do folderu

private:
    void showFolderNotExist(); //Pokazuje okienko z informacjami, że katalog nie istnieje
    QString replaceUnderscores(QString fileName); //Zmienia nazwę pliku zastępując znaki "_" na " "
    QString replaceDashes(QString fileName); //Zmienia nazwę pliku zastępując znaki "-" na " "
    QString replaceDots(QString fileName); //Zmienia nazwę pliku zastępując znaki "." na " "
    QString changeFirstLetterToBig(QString fileName); //Zmienia pierwszą literę na dużą
    QString changeExtensionToSmall(QString fileName); //Ustawia rozszeżenie pliku pisane z małej litery
    QString changeFileName(QString fileName); //Wykonuje operacje zmiany nazwy pliku
    bool isFileNameIdentical(QString oldName, QString newName); //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void setBusyProgressBar(); //Ustawia pasek postępu w stan zajętości
    void initiateProgressBar(int max); //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze
    void resetProgressBar(); //Zeruje pasek postępu
    void renameFiles(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    bool isExtensionDotNeedBeRestored(int extensionDotPosition);
    bool isFile(QDir accessPath, QString fileName);
};

#endif // NAMECHANGER_H
