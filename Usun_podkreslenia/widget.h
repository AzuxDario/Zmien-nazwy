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
#include "widgetchangelog.h"
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
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QAction *actionSelectFolder;
    QAction *actionStartNameChange;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionReplaceInSubfolders;
    QAction *actionReplaceUnderscores;
    QAction *actionReplaceDashes;
    QAction *actionReplaceDots;
    QAction *actionReplaceExtensionDot;
    QAction *actionChangeFirstLetterToBig;
    QAction *actionChangeExtensionToSmall;
    QAction *actionAbout;
    QAction *actionChangeLog;

    //----Przyciski----//
    QPushButton *buttonSelectFolder;
    QPushButton *buttonStartNameChange;

    //----CheckBoxy----//
    QCheckBox *checkBoxReplaceInSubfolders;
    QCheckBox *checkBoxReplaceUnderscores;
    QCheckBox *checkBoxReplaceDashes;
    QCheckBox *checkBoxReplaceDots;
    QCheckBox *checkBoxReplaceExtensionDot;
    QCheckBox *checkBoxChangeFirstLetterToBig;
    QCheckBox *checkBoxChangeExtensionToSmall;

    //----Okienko z tekstem----//
    QTextBrowser *textBrowserAbout;

    //----Pasek Postępu----//
    QProgressBar *progressBar;

    //----Zmienna przechowująca folder----//
    QString selectedFolder;

    //----Zmienne przechuwyjące ciągi znaków----//
    QString aboutApplication;
    QString folderNotExistError; //Do usunięcia

    //----Zmienne okienek----//
    WidgetChangeLog *oknoRejestrZmian; //Do usunięcia
    WidgetAbout *oknoOProgramie; //Do usunięcia

    //----Rdzeń----//
    Core *programCore;


private slots:
    void closeEvent(QCloseEvent *); //Zamyka program po zamknięciu głównego okna
    void enableButtonsStartNameChange(); //Funkcja aktywuje przycisk Rozpocznij
    void disableButtonsStartNameChange(); //Funkcja deaktywuje przycisk Rozpocznij
    void enableButtonsSelectFolder(); //Włącza aktywność przycisku Wybierz folder
    void disableButtonsSelectFolder(); //Wyłącza aktywność przycisków Wybierz folder
    void changeCheckBoxExtensionDotActivity(); //Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki
    void selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void startNameChange(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetChangeLog(); //Wyświetla okienko z rejestrem zmian
    void showWidgetSettings(); //Wyświetla okienko ustawienia
    void setButtonSelection(); //Ustawia zaznaczenia przycisków

    //----Funkcje aktualizujace stany między check boxami a paskiem
    void checkBoxSubfoldersClicked();
    void checkBoxUnderscoresClicked();
    void checkBoxDashesClicked();
    void checkBoxDotsClicked();
    void checkBoxExtensionDotsClicked();
    void checkBoxFirstLetterToBigClicked();
    void checkBoxExtensionToSmallClicked();
    void actionSubfoldersClicked();
    void actionUnderscoresClicked();
    void actionDashesClicked();
    void actionDotsClicked();
    void actionExtensionDotsClicked();
    void actionFirstLetterToBigClicked();
    void actionExtensionToSmallClicked();

};

#endif // WIDGET_H
