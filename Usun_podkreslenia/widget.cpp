#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //--------Zmienne przechowujące ciągi znaków--------//
    trescOkienkaTekst = "Program zamienia znaki podkreślenia, pauzy oraz kropki (poza kropką oddzielającą nazwę pliku od rozszerzenia) na spację w nazwach plików w wybranym folderze.\nAby rozpocząć procedurę zmiany nazw proszę wybrać folder.";
    trescOkienkaOstrzezenie = "Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu";

    //----Tworzenie paska menu----//
    pasekMenu = new QMenuBar(this);
    pasekMenu->setGeometry(0,0,420,21);
    pasekPlik = new QMenu(this);
    pasekUstawienia = new QMenu(this);
    pasekPomoc = new QMenu(this);

    pasekPlik = pasekMenu->addMenu(tr("&Plik"));
    pasekUstawienia = pasekMenu->addMenu(tr("&Ustawienia"));
    pasekPomoc = pasekMenu->addMenu(tr("P&omoc"));

    pasekWybierzFolder = new QAction(QIcon(":/pasek/wybierzFolder"),"Wybierz &folder",this);
    pasekWybierzFolder->setShortcut(QKeySequence(tr("Ctrl+W")));
    pasekRozpocznijZmiane = new QAction(QIcon(":/pasek/rozpocznijZmiane"),"&Rozpocznij zmianę",this);
    pasekRozpocznijZmiane->setShortcut(QKeySequence(tr("Ctrl+R")));
    pasekWyjscie = new QAction(QIcon(":/pasek/wyjscie"),"Wyjści&e",this);
    pasekWyjscie->setShortcut(QKeySequence(tr("Ctrl+Q")));
    pasekOpcje = new QAction(QIcon(":/pasek/ustawienia"),"&Opcje",this);
    pasekOpcje->setShortcut(QKeySequence(tr("Ctrl+U")));
    pasekWyboruPodfoldery = new QAction("Zastosuj do podfolderów",this);
    pasekWyboruPodfoldery->setShortcut(QKeySequence(tr("Ctrl+1")));
    pasekWyboruZastapPodkreslenia = new QAction("Zastąp &podkreślenia",this);
    pasekWyboruZastapPodkreslenia->setShortcut(QKeySequence(tr("Ctrl+2")));
    pasekWyboruZastapPauzy = new QAction("Zastąp p&auzy",this);
    pasekWyboruZastapPauzy->setShortcut(QKeySequence(tr("Ctrl+3")));
    pasekWyboruZastapKropki = new QAction("Zastąp &kropki",this);
    pasekWyboruZastapKropki->setShortcut(QKeySequence(tr("Ctrl+4")));
    pasekWyboruUsunKropkeRozszerzenia = new QAction("Zastąp &ostatnią kropkę",this);
    pasekWyboruUsunKropkeRozszerzenia->setShortcut(QKeySequence(tr("Ctrl+5")));
    pasekWyboruUstawPierwszaDuza = new QAction("Pierwsza litera &duża",this);
    pasekWyboruUstawPierwszaDuza->setShortcut(QKeySequence(tr("Ctrl+6")));
    pasekWyboruUstawRozszerzenieMale = new QAction("&Rozszerzenie małe",this);
    pasekWyboruUstawRozszerzenieMale->setShortcut(QKeySequence(tr("Ctrl+7")));
    pasekInformacje = new QAction(QIcon(":/pasek/oProgramie"),"&O programie",this);
    pasekInformacje->setShortcuts(QKeySequence::HelpContents);
    pasekRejestrZmian = new QAction(QIcon(":/pasek/rejestrZmian"),"&Rejestr zmian",this);
    pasekRejestrZmian->setShortcut(QKeySequence(tr("Ctrl+Z")));

    pasekPlik->addAction(pasekWybierzFolder);
    pasekPlik->addAction(pasekRozpocznijZmiane);
    pasekPlik->addSeparator();
    pasekPlik->addAction(pasekWyjscie);
    pasekUstawienia->addAction(pasekOpcje);
    pasekUstawienia->addSeparator();
    pasekUstawienia->addAction(pasekWyboruPodfoldery);
    pasekUstawienia->addAction(pasekWyboruZastapPodkreslenia);
    pasekUstawienia->addAction(pasekWyboruZastapPauzy);
    pasekUstawienia->addAction(pasekWyboruZastapKropki);
    pasekUstawienia->addAction(pasekWyboruUsunKropkeRozszerzenia);
    pasekUstawienia->addAction(pasekWyboruUstawPierwszaDuza);
    pasekUstawienia->addAction(pasekWyboruUstawRozszerzenieMale);
    pasekPomoc->addAction(pasekInformacje);
    pasekPomoc->addAction(pasekRejestrZmian);

    pasekRozpocznijZmiane->setDisabled(true);
    pasekWyboruPodfoldery->setCheckable(true);
    pasekWyboruZastapPodkreslenia->setCheckable(true);
    pasekWyboruZastapPauzy->setCheckable(true);
    pasekWyboruZastapKropki->setCheckable(true);
    pasekWyboruUsunKropkeRozszerzenia->setCheckable(true);
    pasekWyboruUsunKropkeRozszerzenia->setDisabled(true);
    pasekWyboruUstawPierwszaDuza->setCheckable(true);
    pasekWyboruUstawRozszerzenieMale->setCheckable(true);

    //----Tworzenie layoutu okna----//
    //--------Przyciski--------//
    przyciskWybierzFolder = new QPushButton("Wybierz folder",this);
    przyciskWybierzFolder->setGeometry(20,31,140,30);
    przyciskWybierzFolder->setStyleSheet("font-size:11px;");
    przyciskRozpocznijZmiane = new QPushButton("Rozpocznij zmianę",this);
    przyciskRozpocznijZmiane->setGeometry(260,31,140,30);
    przyciskRozpocznijZmiane->setStyleSheet("font-size:11px;");
    przyciskRozpocznijZmiane->setDisabled(true);

    //--------Check Boxy--------//
    przyciskWyboruPodfoldery = new QCheckBox("Zastąp znaki także w podfolderach",this);
    przyciskWyboruPodfoldery->setGeometry(20,72,380,18);
    przyciskWyboruZastapPodkreslenia = new QCheckBox("Zastąp podkreślenia",this);
    przyciskWyboruZastapPodkreslenia->setGeometry(20,101,154,18);
    przyciskWyboruZastapPauzy = new QCheckBox("Zastąp pauzy",this);
    przyciskWyboruZastapPauzy->setGeometry(174,101,116,18);
    przyciskWyboruZastapKropki = new QCheckBox("Zastąp kropki",this);
    przyciskWyboruZastapKropki->setGeometry(290,101,110,18);
    przyciskWyboruUsunKropkeRozszerzenia = new QCheckBox("Zastąp ostatnią kropkę. Zaznacz gdy pliki nie posiadają rozszerzeń",this);
    przyciskWyboruUsunKropkeRozszerzenia->setGeometry(20,130,380,18);
    przyciskWyboruUsunKropkeRozszerzenia->setDisabled(true); //Ma być klikalny wtedy gdy wybrano zastępowanie kropek
    przyciskWyboruUstawPierwszaDuza = new QCheckBox("Zmień pierwszą literę w nazwie pliku na dużą",this);
    przyciskWyboruUstawPierwszaDuza->setGeometry(20,159,380,18);
    przyciskWyboruUstawRozszerzenieMale = new QCheckBox("Zmień rozszerzenie na pisane małymi literami",this);
    przyciskWyboruUstawRozszerzenieMale->setGeometry(20,188,380,18);

    //--------Okno z tekstem--------//
    okienkoTekst = new QTextBrowser(this);
    okienkoTekst->setGeometry(20,217,380,120);
    okienkoTekst->setAlignment(Qt::AlignTop);
    okienkoTekst->setReadOnly(true);
    okienkoTekst->setText(trescOkienkaTekst);

    //--------Pasek postępu--------//
    pasekPostepu = new QProgressBar(this);
    pasekPostepu->setGeometry(20,347,380,30);
    pasekPostepu->setTextVisible(false);

    //----Wskaźnik na rdzeń programu----//
    rdzenProgramu = new CRdzen(pasekPostepu);

    //----Ustawienie stanu CheckBoxów zgodnie ze zmiennymi w rdzeniu----//
    ustawPrzyciski();

    //----Przypisanie przycisków do slotów----//
    //--------Menu--------//
    connect(pasekWybierzFolder,SIGNAL(triggered()),this,SLOT(wybierzFolder()));
    connect(pasekRozpocznijZmiane,SIGNAL(triggered()),this,SLOT(rozpocznijZmiane()));
    connect(pasekOpcje,SIGNAL(triggered()),this,SLOT(wyswietlUstawienia()));
    connect(pasekWyjscie,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(pasekInformacje,SIGNAL(triggered()),this,SLOT(wyswietlOProgramie()));
    connect(pasekRejestrZmian,SIGNAL(triggered()),this,SLOT(wyswietlRejestrZmian()));
    connect(pasekWyboruPodfoldery,SIGNAL(triggered()),this,SLOT(pasekPodfolderyKliknieto()));
    connect(pasekWyboruZastapPodkreslenia,SIGNAL(triggered()),this,SLOT(pasekZastapPodkresleniaKliknieto()));
    connect(pasekWyboruZastapPauzy,SIGNAL(triggered()),this,SLOT(pasekZastapPauzyKliknieto()));
    connect(pasekWyboruZastapKropki,SIGNAL(triggered()),this,SLOT(pasekZastapKropkiKliknieto()));
    connect(pasekWyboruUsunKropkeRozszerzenia,SIGNAL(triggered()),this,SLOT(pasekZastapKropkeRozszerzeniaKliknieto()));
    connect(pasekWyboruUstawPierwszaDuza,SIGNAL(triggered()),this,SLOT(pasekUstawPierwszaDuzaKliknieto()));
    connect(pasekWyboruUstawRozszerzenieMale,SIGNAL(triggered()),this,SLOT(pasekUstawRozszerzenieMaleKliknieto()));

    //--------Przyciski--------//
    connect(przyciskWybierzFolder,SIGNAL(clicked()),this,SLOT(wybierzFolder()));
    connect(przyciskRozpocznijZmiane,SIGNAL(clicked()),this,SLOT(rozpocznijZmiane()));
    connect(przyciskWyboruPodfoldery,SIGNAL(clicked()),this,SLOT(przyciskPodfolderyKliknieto()));
    connect(przyciskWyboruZastapPodkreslenia,SIGNAL(clicked()),this,SLOT(przyciskZastapPodkresleniaKliknieto()));
    connect(przyciskWyboruZastapPauzy,SIGNAL(clicked()),this,SLOT(przyciskZastapPauzyKliknieto()));
    connect(przyciskWyboruZastapKropki,SIGNAL(clicked()),this,SLOT(przyciskZastapKropkiKliknieto()));
    connect(przyciskWyboruUsunKropkeRozszerzenia,SIGNAL(clicked()),this,SLOT(przyciskZastapKropkeRozszerzeniaKliknieto()));
    connect(przyciskWyboruUstawPierwszaDuza,SIGNAL(clicked()),this,SLOT(przyciskUstawPierwszaDuzaKliknieto()));
    connect(przyciskWyboruUstawRozszerzenieMale,SIGNAL(clicked()),this,SLOT(przyciskUstawRozszerzenieMaleKliknieto()));

}


Widget::~Widget()
{
    delete ui;
}

//----Zamyka program po zamknięciu głównego okna----//
void Widget::closeEvent(QCloseEvent *)
{
    qApp->quit();
}

//----Funkcja aktywuje przycisk Rozpocznij----//
void Widget::aktywujPrzyciskRozpocznij()
{
    przyciskRozpocznijZmiane->setEnabled(true);
    pasekRozpocznijZmiane->setEnabled(true);
}

//----Funkcja deaktywuje przycisk Rozpocznij----//
void Widget::deaktywujPrzyciskRozpocznij()
{
    przyciskRozpocznijZmiane->setDisabled(true);
    pasekRozpocznijZmiane->setDisabled(true);
}

//----Włącza aktywność przycisku Wybierz folder----//
void Widget::aktywujPrzyciskWybierzFolder()
{
    przyciskWybierzFolder->setEnabled(true);
    pasekWybierzFolder->setEnabled(true);
}

//----Wyłącza aktywność przycisków Wybierz folder i Rozpocznij zmianę----//
void Widget::deaktywujPrzyciskWybierzFolder()
{
    przyciskWybierzFolder->setDisabled(true);
    pasekWybierzFolder->setDisabled(true);
}

void Widget::zmienAktywnoscPrzyciskuKropkiRozszerzenia()
{
    przyciskWyboruUsunKropkeRozszerzenia->setEnabled(przyciskWyboruZastapKropki->isChecked());
    pasekWyboruUsunKropkeRozszerzenia->setEnabled(pasekWyboruZastapKropki->isChecked());
}

//----Wybiera folder do przeprowadzenia zmiany nazw----//
void Widget::wybierzFolder()
{
    wybranyFolder = rdzenProgramu->wybierzFolder(); //Otwiera okno wyboru plik
    if(wybranyFolder != "")
    {
        aktywujPrzyciskRozpocznij();
        okienkoTekst->setText("Wybrano katalog: <b>" + wybranyFolder + "</b><br />Nazwy plików zawierające wybrane znaki zostaną zmienione.");
    }
    else
    {
        deaktywujPrzyciskRozpocznij();
        okienkoTekst->setText("Nie wybrano żadnego folderu. Proszę wybrać folder");
    }
}

//----Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu----//
void Widget::rozpocznijZmiane()
{
    deaktywujPrzyciskWybierzFolder(); //Deaktywacja przycisków na czas zmiany nazwy aby użytkownik nie mógł wyołać drugi raz funkcji
    deaktywujPrzyciskRozpocznij();
    rdzenProgramu->zmienNazwy();
    aktywujPrzyciskWybierzFolder(); //Włączenie aktywności przycisku Wybór folderu po zmianie nazwy
    okienkoTekst->setText("<b>Program zakończył zmianę nazw w wybranym katalogu. Można teraz wybrać kolejny katalog.</b><br />" + trescOkienkaTekst);
}

//----Pokazuje okienko z informacjami o programie----//
void Widget::wyswietlOProgramie()
{
    rdzenProgramu->wyswietlOProgramie();
}

//----Wyświetla okienko z rejestrem zmian----//
void Widget::wyswietlRejestrZmian()
{
    rdzenProgramu->wyswietlRejestrZmian();
}

//----Wyświetla okienko ustawienia----//
void Widget::wyswietlUstawienia()
{
    rdzenProgramu->wyswietlUstawienia();
}

//----Ustawia zaznaczenia przycisków----//
void Widget::ustawPrzyciski()
{
    pasekWyboruPodfoldery->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicWPodfolderach());
    pasekWyboruZastapPodkreslenia->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicPodkreslenia());
    pasekWyboruZastapPauzy->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicPauzy());
    pasekWyboruZastapKropki->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicKropki());
    pasekWyboruUsunKropkeRozszerzenia->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicKropkeRozszerzenia());
    pasekWyboruUstawPierwszaDuza->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyPierwszaDuza());
    pasekWyboruUstawRozszerzenieMale->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyRozszerzenieMale());

    przyciskWyboruPodfoldery->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicWPodfolderach());
    przyciskWyboruZastapPodkreslenia->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicPodkreslenia());
    przyciskWyboruZastapPauzy->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicPauzy());
    przyciskWyboruZastapKropki->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicKropki());
    przyciskWyboruUsunKropkeRozszerzenia->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicKropkeRozszerzenia());
    przyciskWyboruUstawPierwszaDuza->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyPierwszaDuza());
    przyciskWyboruUstawRozszerzenieMale->setChecked(rdzenProgramu->parametryZmianyNazw.zwrocCzyRozszerzenieMale());

    if(rdzenProgramu->parametryZmianyNazw.zwrocCzyZamienicKropki() == true)
    {
        pasekWyboruUsunKropkeRozszerzenia->setEnabled(true);
        przyciskWyboruUsunKropkeRozszerzenia->setEnabled(true);
    }

}

//----Funkcje aktualizujace stany między check boxami a paskiem----//
void Widget::przyciskPodfolderyKliknieto()
{
    pasekWyboruPodfoldery->setChecked(przyciskWyboruPodfoldery->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicWPodfolderach(przyciskWyboruPodfoldery->isChecked());
}

void Widget::przyciskZastapPodkresleniaKliknieto()
{
    pasekWyboruZastapPodkreslenia->setChecked(przyciskWyboruZastapPodkreslenia->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicPodkreslenia(przyciskWyboruZastapPodkreslenia->isChecked());
}

void Widget::przyciskZastapPauzyKliknieto()
{
    pasekWyboruZastapPauzy->setChecked(przyciskWyboruZastapPauzy->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicPauzy(przyciskWyboruZastapPauzy->isChecked());
}

void Widget::przyciskZastapKropkiKliknieto()
{
    pasekWyboruZastapKropki->setChecked(przyciskWyboruZastapKropki->isChecked());
    zmienAktywnoscPrzyciskuKropkiRozszerzenia();
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicKropki(przyciskWyboruZastapKropki->isChecked());
}

void Widget::przyciskZastapKropkeRozszerzeniaKliknieto()
{
    pasekWyboruUsunKropkeRozszerzenia->setChecked(przyciskWyboruUsunKropkeRozszerzenia->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicKropkeRozszerzenia(przyciskWyboruUsunKropkeRozszerzenia->isChecked());
}

void Widget::przyciskUstawPierwszaDuzaKliknieto()
{
    pasekWyboruUstawPierwszaDuza->setChecked(przyciskWyboruUstawPierwszaDuza->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyPierwszaDuza(przyciskWyboruUstawPierwszaDuza->isChecked());
}

void Widget::przyciskUstawRozszerzenieMaleKliknieto()
{
    pasekWyboruUstawRozszerzenieMale->setChecked(przyciskWyboruUstawRozszerzenieMale->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyRozszerzenieMale(przyciskWyboruUstawRozszerzenieMale->isChecked());
}

void Widget::pasekPodfolderyKliknieto()
{
    przyciskWyboruPodfoldery->setChecked(pasekWyboruPodfoldery->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicWPodfolderach(pasekWyboruPodfoldery->isChecked());
}

void Widget::pasekZastapPodkresleniaKliknieto()
{
    przyciskWyboruZastapPodkreslenia->setChecked(pasekWyboruZastapPodkreslenia->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicPodkreslenia(pasekWyboruZastapPodkreslenia->isChecked());
}

void Widget::pasekZastapPauzyKliknieto()
{
    przyciskWyboruZastapPauzy->setChecked(pasekWyboruZastapPauzy->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicPauzy(pasekWyboruZastapPauzy->isChecked());
}

void Widget::pasekZastapKropkiKliknieto()
{
    przyciskWyboruZastapKropki->setChecked(pasekWyboruZastapKropki->isChecked());
    zmienAktywnoscPrzyciskuKropkiRozszerzenia();
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicKropki(pasekWyboruZastapKropki->isChecked());
}

void Widget::pasekZastapKropkeRozszerzeniaKliknieto()
{
    przyciskWyboruUsunKropkeRozszerzenia->setChecked(pasekWyboruUsunKropkeRozszerzenia->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyZamienicKropkeRozszerzenia(pasekWyboruUsunKropkeRozszerzenia->isChecked());
}

void Widget::pasekUstawPierwszaDuzaKliknieto()
{
    przyciskWyboruUstawPierwszaDuza->setChecked(pasekWyboruUstawPierwszaDuza->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyPierwszaDuza(pasekWyboruUstawPierwszaDuza->isChecked());
}

void Widget::pasekUstawRozszerzenieMaleKliknieto()
{
    przyciskWyboruUstawRozszerzenieMale->setChecked(pasekWyboruUstawRozszerzenieMale->isChecked());
    rdzenProgramu->parametryZmianyNazw.ustawCzyRozszerzenieMale(pasekWyboruUstawRozszerzenieMale->isChecked());
}
