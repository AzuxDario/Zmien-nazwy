#include "widgetrejestrzmian.h"
#include "ui_widgetrejestrzmian.h"

WidgetRejestrZmian::WidgetRejestrZmian(QString trescOkna, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRejestrZmian)
{
    ui->setupUi(this);
    //::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    trescOkienkaRejestrZmian = trescOkna;

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("Rejestr zmian"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(500,360);
    setMinimumSize(500,360);
    //setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Okno z tekstem--------//
    okienkoTekst = new QTextBrowser(this);
    okienkoTekst->setGeometry(10,10,480,300);
    okienkoTekst->setAlignment(Qt::AlignTop);
    okienkoTekst->setReadOnly(true);
    okienkoTekst->setText(trescOkienkaRejestrZmian);

    //--------Przycisk--------//
    przyciskOk = new QPushButton("Ok",this);
    przyciskOk->setGeometry(180,320,140,30);

    //----Przypisanie przycisków do slotów----//
    connect(przyciskOk,SIGNAL(clicked()),this,SLOT(zamknijOkno()));

    move(QApplication::desktop()->screen()->rect().center()-this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetRejestrZmian::~WidgetRejestrZmian()
{
    delete ui;
}

//----Zamyka okno----//
void WidgetRejestrZmian::zamknijOkno()
{
    this->close();
}

void WidgetRejestrZmian::pokazSie()
{
        if(this->isVisible()) //Jeżeli okno jest widoczne
        {
            this->activateWindow(); //Niech stanie się aktywne
        }
        else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
        {
            this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
            this->show();
        }
}
