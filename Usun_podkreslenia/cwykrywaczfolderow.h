#ifndef CWYKRYWACZFOLDEROW_H
#define CWYKRYWACZFOLDEROW_H

#include <QString>
#include <QStringList>
#include <QDir>

class CWykrywaczFolderow
{
public:
    CWykrywaczFolderow(QString wybranyFolder, bool czySzukacPodfolderow);

private:
    QString wybranyFolder;

    //----Lista przechowująca folder główny i wszystkie podfoldery----//
    QStringList listaFolderow;

    int iloscPlikow;
    bool czySzukacPodfolderow;

public:
    QStringList zwrocListeFolderow(); //Zwraca listę folderów
    int zwrocIloscPlikow(); //Zwraca ilość plików w podfolderach

private:
    void wyszukajFoldery(); //Uzupełnia liste folderów o podfoldery

public:
    static bool czyJestPodfolderem(QDir sciezkaDostepu, QString nazwaPliku);
    static bool czyToAktualnyLubNadrzednyFolder(QString nazwaPliku);
    static bool czyToNieJestAktualnyLubNadrzednyFolder(QString nazwaPliku);
    static bool czyJestFolderem(QDir sciezkaDostepu, QString nazwaPliku); //Sprawdza czy element jest folderem
};

#endif // CWYKRYWACZFOLDEROW_H
