#include "settings.h"

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
        QTextStream zawartoscPliku(&settingsFile);
        QString line;
        while(zawartoscPliku.atEnd() == 0)
        {
            line = zawartoscPliku.readLine();
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
        stream << "czyPierwszaDuza=";
        if(nameChangeParameters.getChangeFirstLetterToBig() == true)
            stream << "1" << endl;
        else
            stream << "0" << endl;
        stream << "czyRozszerzenieMale=";
        if(nameChangeParameters.getChangeExtensionToSmall() == true)
            stream << "1";
        else
            stream << "0";
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
        stream << "czyZamienicKropki=0" << endl;
        stream << "czyZamienicKropkeRozszerzenia=0" << endl;
        stream << "czyPierwszaDuza=0" << endl;
        stream << "czyRozszerzenieMale=0";
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
        else if(option == "czyZamienicKropki")
            nameChangeParameters.setReplaceDots(value);
        else if(option == "czyZamienicKropkeRozszerzenia")
            nameChangeParameters.setReplaceExtensionDot(value);
        else if(option == "czyPierwszaDuza")
            nameChangeParameters.setChangeFirstLetterToBig(value);
        else if(option == "czyRozszerzenieMale")
            nameChangeParameters.setChangeExtensionToSmall(value);
    }
}
