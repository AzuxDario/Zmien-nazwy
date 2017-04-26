#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QProgressBar>
#include <QTextCodec>
#include <QMenuBar>
#include <QFile>
#include <QCheckBox>
#include <QCloseEvent>
#include <QKeySequence>
#include <QDesktopWidget>
#include "widgetrejestrzmian.h"
#include "widgetabout.h"
#include "namechanger.h"
#include "core.h"


namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    //----Zmienne od paska menu----//
    QMenuBar *pasekMenu;
    QMenu *pasekPlik;
    QMenu *pasekUstawienia;
    QMenu *pasekPomoc;
    QAction *pasekWybierzFolder;
    QAction *pasekRozpocznijZmiane;
    QAction *pasekWyjscie;
    QAction *pasekOpcje;
    QAction *pasekWyboruPodfoldery;
    QAction *pasekWyboruZastapPodkreslenia;
    QAction *pasekWyboruZastapPauzy;
    QAction *pasekWyboruZastapKropki;
    QAction *pasekWyboruUsunKropkeRozszerzenia;
    QAction *pasekWyboruUstawPierwszaDuza;
    QAction *pasekWyboruUstawRozszerzenieMale;
    QAction *pasekInformacje;
    QAction *pasekRejestrZmian;

    //----Przyciski----//
    QPushButton *przyciskWybierzFolder;
    QPushButton *przyciskRozpocznijZmiane;

    //----CheckBoxy----//
    QCheckBox *przyciskWyboruPodfoldery;
    QCheckBox *przyciskWyboruZastapPodkreslenia;
    QCheckBox *przyciskWyboruZastapPauzy;
    QCheckBox *przyciskWyboruZastapKropki;
    QCheckBox *przyciskWyboruUsunKropkeRozszerzenia;
    QCheckBox *przyciskWyboruUstawPierwszaDuza;
    QCheckBox *przyciskWyboruUstawRozszerzenieMale;

    //----Okienko z tekstem----//
    QTextBrowser *okienkoTekst;

    //----Pasek Postępu----//
    QProgressBar *pasekPostepu;

    //----Zmienna przechowująca folder----//
    QString wybranyFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString trescOkienkaTekst;
    QString trescOkienkaOstrzezenie;

    //----Zmienne okienek----//
    WidgetRejestrZmian *oknoRejestrZmian;
    WidgetAbout *oknoOProgramie;

    //----Rdzeń----//
    Core *rdzenProgramu;


private slots:
    void closeEvent(QCloseEvent *); //Zamyka program po zamknięciu głównego okna
    void aktywujPrzyciskRozpocznij(); //Funkcja aktywuje przycisk Rozpocznij
    void deaktywujPrzyciskRozpocznij(); //Funkcja deaktywuje przycisk Rozpocznij
    void aktywujPrzyciskWybierzFolder(); //Włącza aktywność przycisku Wybierz folder
    void deaktywujPrzyciskWybierzFolder(); //Wyłącza aktywność przycisków Wybierz folder
    void zmienAktywnoscPrzyciskuKropkiRozszerzenia(); //Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki
    void wybierzFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void rozpocznijZmiane(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    void wyswietlOProgramie(); //Pokazuje okienko z informacjami o programie
    void wyswietlRejestrZmian(); //Wyświetla okienko z rejestrem zmian
    void wyswietlUstawienia(); //Wyświetla okienko ustawienia
    void ustawPrzyciski(); //Ustawia zaznaczenia przycisków

    //----Funkcje aktualizujace stany między check boxami a paskiem
    void przyciskPodfolderyKliknieto();
    void przyciskZastapPodkresleniaKliknieto();
    void przyciskZastapPauzyKliknieto();
    void przyciskZastapKropkiKliknieto();
    void przyciskZastapKropkeRozszerzeniaKliknieto();
    void przyciskUstawPierwszaDuzaKliknieto();
    void przyciskUstawRozszerzenieMaleKliknieto();
    void pasekPodfolderyKliknieto();
    void pasekZastapPodkresleniaKliknieto();
    void pasekZastapPauzyKliknieto();
    void pasekZastapKropkiKliknieto();
    void pasekZastapKropkeRozszerzeniaKliknieto();
    void pasekUstawPierwszaDuzaKliknieto();
    void pasekUstawRozszerzenieMaleKliknieto();

};

#endif // WIDGET_H
