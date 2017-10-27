#ifndef RENAMER_H
#define RENAMER_H

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QRegExp>
#include "FolderDetector.h"
#include "NameChangeParameters.h"
#include "NameModifier.h"
#include "Warnings.h"
#include "DirectoryIdentifier.h"


class Renamer :public QObject
{
    Q_OBJECT

public:
    Renamer();

private:
    NameChangeParameters nameChangeParameters;
    QString selectedFolder;

    NameModifier nameModifier;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();

public:
    QString getSelectedFolder() noexcept {return selectedFolder;} //Zwraca ścieżkę dostępu do folderu
    void setSelectedFolder(QString value) noexcept {selectedFolder = value;} //Ustawia ścieżkę dostępu do folderu
    void initiateRenameFiles(NameChangeParameters nameChangeParameters); //Rozpoczyna procedurę zmiany nazw

private:
    void renameInFolders(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    void renameOneFile(); //Funkcja zmienia nazwę jednego pliku
    void renameFiles(QDir currentFolder, const QStringList& folderList); //Funkcja zmienia nazwy plików w folderach
    void showError(const char* string); //Funkcja pokazuje błąd
    QString changeFileName(QString fileName); //Wykonuje operacje zmiany nazwy pliku
    bool isFileNameIdentical(QString oldName, QString newName) {return oldName == newName;} //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void setBusyProgressBar() {emit initializeProgressBar(0,0);} //Ustawia pasek postępu w stan zajętości
    void initiateProgressBar(int max) {emit initializeProgressBar(0, max); emit changeProgressBar(0);} //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze

};

#endif // RENAMER_H
