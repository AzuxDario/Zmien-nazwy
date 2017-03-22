#include "cwykrywaczfolderow.h"

CWykrywaczFolderow::CWykrywaczFolderow(QString wybranyFolder, bool czySzukacPodfolderow)
{
    this->wybranyFolder = wybranyFolder;
    this->czySzukacPodfolderow = czySzukacPodfolderow;
    iloscPlikow = 0;
    wyszukajFoldery();
}

//----Zwraca listę folderów----//
QStringList CWykrywaczFolderow::zwrocListeFolderow()
{
    return listaFolderow;
}

//----Zwraca ilość plików w podfolderach----//
int CWykrywaczFolderow::zwrocIloscPlikow()
{
    return iloscPlikow;
}

//----Uzupełnia liste folderów o podfoldery----//
void CWykrywaczFolderow::wyszukajFoldery()
{
    QDir obecnyFolder(wybranyFolder);
    listaFolderow.push_back(wybranyFolder);
    if(czySzukacPodfolderow == true)
    {
        for(int iteratorListyFolderow = 0; listaFolderow.begin()+iteratorListyFolderow != listaFolderow.end(); iteratorListyFolderow++)
        {
            //Należy co pętle pobierać iterator początku, gdyż może dojść do przemieszczenia się vectora w pamięci
            //co spowoduje, że iterator będzie pokazywał na poprzednie już puste miejsce
            QString folderWKtorymSzukamyPodfolderow = *(listaFolderow.begin()+iteratorListyFolderow);
            obecnyFolder.cd(folderWKtorymSzukamyPodfolderow);
            if(!obecnyFolder.exists())
                continue;
            iloscPlikow += obecnyFolder.count();
            for(unsigned int i = 0; i < obecnyFolder.count(); i++)
                if(czyJestPodfolderem(obecnyFolder, obecnyFolder[i]))
                    listaFolderow.push_back(obecnyFolder.absoluteFilePath(obecnyFolder[i]));
        }
    }
    else
        iloscPlikow += obecnyFolder.count();
}

bool CWykrywaczFolderow::czyJestPodfolderem(QDir sciezkaDostepu, QString nazwaPliku)
{
    if(czyToNieJestAktualnyLubNadrzednyFolder(nazwaPliku))
        if(czyJestFolderem(sciezkaDostepu, nazwaPliku))
            return true;
    return false;
}

bool CWykrywaczFolderow::czyToAktualnyLubNadrzednyFolder(QString nazwaPliku)
{
    if((nazwaPliku == ".") || (nazwaPliku == ".."))
        return true;
    else
        return false;
}

bool CWykrywaczFolderow::czyToNieJestAktualnyLubNadrzednyFolder(QString nazwaPliku)
{
    return !czyToAktualnyLubNadrzednyFolder(nazwaPliku);
}

//----Sprawdza czy element jest folderem----//
bool CWykrywaczFolderow::czyJestFolderem(QDir sciezkaDostepu, QString nazwaPliku)
{
    if(sciezkaDostepu.cd(nazwaPliku) == true)
        return true;
    else
        return false;
}
