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
    //----Zmienna przechowująca folder----//
    QString wybranyFolder;

    //----Lista przechowująca folder główny i wszystkie podfoldery----//
    QStringList listaFolderow;

    //----Zmienna przechowująca ilośc plików w podfolderach----//
    int iloscPlikow;

    //----Zmienna  informująca o tym czy wyszukiwać podfolderów----//
    bool czySzukacPodfolderow;

public:
    QStringList zwrocListeFolderow(); //Zwraca listę folderów
    int zwrocIloscPlikow(); //Zwraca ilość plików w podfolderach

private:
    void wyszukajFoldery(); //Uzupełnia liste folderów o podfoldery

public:
    bool czyJestFolderem(QDir sciezkaDostepu, QString nazwaPliku); //Sprawdza czy element jest folderem
};

#endif // CWYKRYWACZFOLDEROW_H
