#include "WidgetAbout.h"
#include "ui_widgetabout.h"

WidgetAbout::WidgetAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetAbout)
{
    ui->setupUi(this);

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8(Widgets::widgetAbout));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(500,210);
    setMinimumSize(500,210);
    //setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Okno z tekstem--------//
    labelText = new QLabel(About::aboutApp,this);
    labelText->setGeometry(148,10,342,128);
    labelText->setWordWrap(true);

    //--------Przycisk--------//
    buttonOk = new QPushButton(Widgets::buttonOk,this);
    buttonOk->setGeometry(180,170,140,30);

    //--------Obrazek--------//
    labelPicture = new QLabel(this);
    labelPicture->setGeometry(10,10,128,128);
    labelPicture->setPixmap(QPixmap(":/ikona/ikona128x128"));

    //----Przypisanie przycisków do slotów----//
    connect(buttonOk,SIGNAL(clicked()),this,SLOT(closeWindow()));

    move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetAbout::~WidgetAbout()
{
    delete ui;
}

void WidgetAbout::closeWindow()
{
    this->close();
}

void WidgetAbout::showWindow()
{
    if(this->isVisible()) //Jeżeli okno jest widoczne
        this->activateWindow(); //Niech stanie się aktywne
    else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
    {
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
        this->show();
    }
}
