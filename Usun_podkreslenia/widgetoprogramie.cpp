#include "widgetoprogramie.h"
#include "ui_widgetoprogramie.h"

WidgetOProgramie::WidgetOProgramie(QString trescOkna, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetOProgramie)
{
    ui->setupUi(this);
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    trescOkienkaInformacyjengo = trescOkna;

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("O programie"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(500,210);
    setMinimumSize(500,210);
    //setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Okno z tekstem--------//
    poleText = new QLabel(trescOkienkaInformacyjengo,this);
    poleText->setGeometry(148,10,342,128);
    poleText->setWordWrap(true);

    //--------Przycisk--------//
    przyciskOk = new QPushButton("Ok",this);
    przyciskOk->setGeometry(180,170,140,30);

    //--------Obrazek--------//
    poleObrazek = new QLabel(this);
    poleObrazek->setGeometry(10,10,128,128);
    poleObrazek->setPixmap(QPixmap(":/ikona/ikona128x128"));

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked()),this,SLOT(zamknijOkno()));

    move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetOProgramie::~WidgetOProgramie()
{
    delete ui;
}

void WidgetOProgramie::zamknijOkno()
{
    this->close();
}

void WidgetOProgramie::pokazSie()
{
    if(this->isVisible()) //Jeżeli okno jest widoczne
        this->activateWindow(); //Niech stanie się aktywne
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
