#include "About.h"

const QString About::aboutApp ="Wersja programu: 4.2\nProgram oczyszcza nazwy plików pobranych z internetu.\n"
    "Zamienia znaki podkreślenia, pauzy oraz kropki na spację, usuwa wielokrotne spacje i zmienia rozmiar liter.\n"
    "Zmiana obywa się w folderze i opcjonalnie jego podfolderach.\n© Paweł Miękina\n\n"
    "Aplikacja korzysta z bibliotek Qt.";

const QString About::changeLog =
    "Wersja: 4.2 (02.11.2017)\n- refaktoryzacja\n- wielowątkowość (przetwarzanie nazw na osobnym wątku)\n"
    "Wersja: 4.1 (30.10.2017)\n- refaktoryzacja\n- zmiana opisu programu\n- dodano przycisk anuluj do ustawień\n- dodano opcję usuwania plusów\n- dodano opcję zmiany jednej nazwy pliku\n"
    "Wersja: 4.0 (19.07.2017)\n- dodanie nowych ustawień\n- przebudowa okna\n- usunięcie akcji z menu\n"
    "Wersja: 3.4 (08.03.2017)\n- dodanie klasy przechowującej ustawenia zmiany nazw\n- uporządkowanie kodu\n"
    "Wersja: 3.3 (26.10.2016)\n- dodano ustawienia z możliwością zapisu\n- dodano możliwość zmiany nazw plików w podfolderach\n"
    "- program nie zmienia już nazw podfolderom\n- czyszczenie kodu\n- dodanie klasy (rdzenia)\n"
    "Wersja: 3.2 (23.10.2016)\n- dodano możliwość zmiany rozszerzenia pliku na pisane małymi literami\n"
    "Wersja: 3.1 (19.10.2016)\n- dodano możliwość zmiany pierwszej litery pliku na dużą\n"
    "Wersja: 3.0 (18.10.2016)\n- przejście na Qt 5.7\n- dodano skalowanie aplikacji\n"
    "Wersja: 2.5 (12.10.2016)\n- zmieniono metodę zmiany nazw plików (dodano klasę)\n- dodano ikonę programu\n"
    "Wersja: 2.4 (11.10.2016)\n- dodano skróty klawiaturowe\n- okna pojawiają się na środku ekranu\n- zmieniono okno o programie\n- dodano możliwość zmiany folderu po wybraniu\n"
    "Wersja: 2.3 (07.10.2016)\n- zmieniono okno rejestr zmian\n- program zamyka się po zamknięciu głównego okna\n"
    "Wersja: 2.2 (06.10.2016)\n- dodano ikony\n- zmieniono nazwę programu\n"
    "Wersja: 2.1 (05.10.2016)\n- dodano menu ustawienia\n"
    "Wersja: 2.0 (05.10.2016)\n- dodano możliwość wyboru zamienianych znaków (podkreślenie, pauza, kropka)\n- dodano rejestr zmian\n"
    "- podczas zmiany nazwy przyciski oraz przyciski wyboru zostają dezaktywowane\n- możliwość usunięcia ostatniej kropki jeżeli pliki nie posiadają rozszerzeń\n"
    "Wersja: 1.0 (23.09.2016)\n- możliwość zamiany znaku podkreślenia w nazwie pliku na odstęp";

About::About()
{

}
