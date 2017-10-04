#include "WidgetChangelog.h"
#include "ui_widgetchangelog.h"

WidgetChangeLog::WidgetChangeLog(QString widgetText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetChangeLog)
{
    ui->setupUi(this);

    widgetChangeLogText = widgetText;

    //--------Inicjalizacja okna--------//
    setWindowTitle(QString::fromUtf8("Rejestr zmian"));
    setWindowIcon(QIcon(":/ikona/ikona"));
    setMaximumSize(500,360);
    setMinimumSize(500,360);
    //setWindowModality(Qt::ApplicationModal); //Sprawia że po aktywacji okna główne okno staje się nieklikalne

    //--------Okno z tekstem--------//
    textBrowserChangeLog = new QTextBrowser(this);
    textBrowserChangeLog->setGeometry(10,10,480,300);
    textBrowserChangeLog->setAlignment(Qt::AlignTop);
    textBrowserChangeLog->setReadOnly(true);
    textBrowserChangeLog->setText(widgetChangeLogText);

    //--------Przycisk--------//
    buttonOk = new QPushButton("Ok",this);
    buttonOk->setGeometry(180,320,140,30);

    //----Przypisanie przycisków do slotów----//
    connect(buttonOk,SIGNAL(clicked()),this,SLOT(closeWindow()));

    move(QApplication::desktop()->screen()->rect().center()-this->rect().center()); //Przesunięcie na środek ekranu
    show(); //Zachowaj na końcu konstruktora
}

WidgetChangeLog::~WidgetChangeLog()
{
    delete ui;
}

//----Zamyka okno----//
void WidgetChangeLog::closeWindow()
{
    this->close();
}

void WidgetChangeLog::showWindow()
{
        if(this->isVisible()) //Jeżeli okno jest widoczne
            this->activateWindow(); //Niech stanie się aktywne
        else //Jeżeli okno było stworzone i nie jest widoczne wywołaj je
        {
            this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //Przesunięcie na środek ekranu
            this->show();
        }
}
