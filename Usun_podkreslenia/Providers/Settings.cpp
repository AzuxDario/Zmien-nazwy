#include "Settings.h"

Settings::Settings()
{
    readSettings();
}

//----Czyta ustawienia z pliku----//
bool Settings::readSettings()
{
    QFile settingsFile("ustawienia.ini");
    if(!settingsFile.exists())
        rebuildFile();
    if(settingsFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&settingsFile);
        QString line;
        while(stream.atEnd() == 0)
        {
            line = stream.readLine();
            setSetting(line);
        }
        settingsFile.close();
        return true;
    }
    else
        return false;
}

//----Zapisuje ustawienia do pliku----//
bool Settings::saveSettings()
{
    QFile settingsFile("ustawienia.ini");
    if(settingsFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&settingsFile);
        stream << "[Ustawienia]" << endl;
        stream << "czyZamienicWPodfolderach=";
        if(nameChangeParameters.getReplaceInSubfolders() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyZamienicPodkreslenia=";
        if(nameChangeParameters.getReplaceUnderscores() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyZamienicPauzy=";
        if(nameChangeParameters.getReplaceDashes() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyZachowacPauzyPomiedzySpacjami=";
        if(nameChangeParameters.getDontReplaceDashesSurrondedBySpaces() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyZamienicKropki=";
        if(nameChangeParameters.getReplaceDots() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyZamienicKropkeRozszerzenia=";
        if(nameChangeParameters.getReplaceExtensionDot() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "usunWielokrotneSpacje=";
        if(nameChangeParameters.getRemoveMultiplySpaces() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "usunSpacjeNaPoczatku=";
        if(nameChangeParameters.getRemoveSpacesAtBegin() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "usunSpacjeNaKoncu=";
        if(nameChangeParameters.getRemoveSpacesAtEnd() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "rozmiarLiter=";
        stream << static_cast<int>(nameChangeParameters.getChangeLetters()) << endl;
        stream << "rozmiarRozszezenia=";
        stream << static_cast<int>(nameChangeParameters.getChangeExtension());

        settingsFile.close();
        return true;
    }
    else
        return false;
}

//----Tworzy plik ustawień----//
bool Settings::rebuildFile()
{
    QFile settingsFile("ustawienia.ini");
    if(settingsFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&settingsFile);
        stream << "[Ustawienia]" << endl;
        stream << "czyZamienicWPodfolderach=0" << endl;
        stream << "czyZamienicPodkreslenia=0" << endl;
        stream << "czyZamienicPauzy=0" << endl;
        stream << "czyZachowacPauzyPomiedzySpacjami=0" <<endl;
        stream << "czyZamienicKropki=0" << endl;
        stream << "czyZamienicKropkeRozszerzenia=0" << endl;
        stream << "usunWielokrotneSpacje=0" << endl;
        stream << "usunSpacjeNaPoczatku=0" << endl;
        stream << "usunSpacjeNaKoncu=0" << endl;
        stream << "rozmiarLiter=4" << endl;
        stream << "rozmiarRozszezenia=3";
        settingsFile.close();
        return true;
    }
    else
        return false;
}

//----Zmienia ustawienie, przyjmuje linie z pliku ustawien----//
void Settings::setSetting(QString line)
{
    QString option = line.split("=")[0];
    if(line != "[Ustawienia]")
    {
        int value = line.split("=")[1].toInt();
        if(option == "czyZamienicWPodfolderach")
            nameChangeParameters.setReplaceInSubfolders(value);
        else if(option == "czyZamienicPodkreslenia")
            nameChangeParameters.setReplaceUnderscores(value);
        else if(option == "czyZamienicPauzy")
            nameChangeParameters.setReplaceDashes(value);
        else if(option == "czyZachowacPauzyPomiedzySpacjami")
            nameChangeParameters.setDontReplaceDashesSurrondedBySpaces(value);
        else if(option == "czyZamienicKropki")
            nameChangeParameters.setReplaceDots(value);
        else if(option == "czyZamienicKropkeRozszerzenia")
            nameChangeParameters.setReplaceExtensionDot(value);
        else if(option == "usunWielokrotneSpacje")
            nameChangeParameters.setRemoveMultiplySpaces(value);
        else if(option == "usunSpacjeNaPoczatku")
            nameChangeParameters.setRemoveSpacesAtBegin(value);
        else if(option == "usunSpacjeNaKoncu")
            nameChangeParameters.setRemoveSpacesAtEnd(value);
        else if(option == "rozmiarLiter")
            nameChangeParameters.setChangeLetters(static_cast<NameChangeParameters::Letters>(value));
        else if(option == "rozmiarRozszezenia")
            nameChangeParameters.setChangeExtension(static_cast<NameChangeParameters::Extensions>(value));
    }
}