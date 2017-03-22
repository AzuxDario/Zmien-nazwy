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
    listaFolderow.push_back(wybranyFolder); //Dodaj folder główny do listy folderów
    if(czySzukacPodfolderow == true)
    {
        //Pętla przebiegająca po wszystkich folderach w liście
        for(int iteratorListyFolderow = 0/*auto iteratorListyFolderow = listaFolderow.begin()*/; listaFolderow.begin()+iteratorListyFolderow != listaFolderow.end(); iteratorListyFolderow++)
        {
            //Należy co pętle pobierać iterator początku, gdyż może dojść do przemieszczenia się vectora w pamięci
            //co spowoduje, że iterator będzie pokazywał na poprzednie już puste miejsce
            obecnyFolder.cd(*(listaFolderow.begin()+iteratorListyFolderow)); //Wchodzimy do przetwarzanego folderu
            //Jeżeli folder nie istnieje lub zniknie idź do kolejnego
            if(!obecnyFolder.exists())
            {
                continue;
            }
            iloscPlikow += obecnyFolder.count(); //Dodajemy to licznika ilość plików w folderze
            //Pętla szukająca podfolderów w folderze
            for(unsigned int i = 0; i < obecnyFolder.count(); i++)
            {
                if(!((obecnyFolder[i] == ".") || (obecnyFolder[i] == ".."))) //Unikamy plików "." - aktualny folder i ".." - folder nadrzędny
                 {
                    //Gdy znaleziono folder
                    if(czyJestFolderem(obecnyFolder, obecnyFolder[i]) == true)
                       {
                            listaFolderow.push_back(obecnyFolder.absoluteFilePath(obecnyFolder[i])); //Dodaj go do listy folderów
                       }
                 }
            }
        }
    }
    else
    {
        iloscPlikow += obecnyFolder.count();
    }

}

//----Sprawdza czy element jest folderem----//
bool CWykrywaczFolderow::czyJestFolderem(QDir sciezkaDostepu, QString nazwaPliku)
{
    if(sciezkaDostepu.cd(nazwaPliku) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
