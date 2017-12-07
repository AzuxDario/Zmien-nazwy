#ifndef RENAMER_H
#define RENAMER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QFileInfo>
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
    QString selectedDir;

    NameModifier nameModifier;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();
    void doneWork();

public slots:
    void initiateRenameFilesInFolder(NameChangeParameters nameChangeParameters, QStringList selectedFolder); //Rozpoczyna procedurę zmiany nazw
    void initiateRenameSelectedFiles(NameChangeParameters nameChangeParameters, QStringList selectedFiles); //Rozpoczyna procedurę zmiany nazw

public:
    QString getSelectedDir() noexcept {return selectedDir;} //Zwraca ścieżkę dostępu do folderu
    void setSelectedDir(QString value) noexcept {selectedDir = value;} //Ustawia ścieżkę dostępu do folderu

private:
    void renameInFolders(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    void renameOneFile(); //Funkcja zmienia nazwę jednego pliku
    void renameFiles(QDir currentFolder, const QStringList& folderList); //Funkcja zmienia nazwy plików w folderach
    void showError(const char* string); //Funkcja pokazuje błąd
    QString changeFileName(QString fileName); //Wykonuje operacje zmiany nazwy pliku
    bool isNameShouldBeChangeAccordingToExtensionFilter(QString fileName); //Sprawdza czy nazwa pliku powinna być zmieniona biorąc pod uwagę listę rozszerzeń oraz filtr z parametrów zmiany nazw
    bool isFileNameIdentical(QString oldName, QString newName) {return oldName == newName;} //Porównuje dwie nazwy plików jeśli są identyczne zwraca true
    void setBusyProgressBar() {emit initializeProgressBar(0,0);} //Ustawia pasek postępu w stan zajętości
    void initiateProgressBar(int max) {emit initializeProgressBar(0, max); emit changeProgressBar(0);} //Inicjuje pasek postępu ustawiając jako wartość maksymalną ilość plików w folderze   

};

#endif // RENAMER_H
