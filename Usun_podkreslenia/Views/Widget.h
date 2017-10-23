#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QProgressBar>
#include <QMenuBar>
#include <QFile>
#include <QCheckBox>
#include <QRadioButton>
#include <QCloseEvent>
#include <QKeySequence>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include "NameChanger.h"
#include "WidgetViewProvider.h"
#include "Widgets.h"


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
    QAction *actionOptions;
    QAction *actionAbout;
    QAction *actionChangeLog;

    //----Layouty----//
    QVBoxLayout *windowVLayout;
    QHBoxLayout *mainHLayout;
    QVBoxLayout *leftVLayout;
    QVBoxLayout *rightVLayout;
    QHBoxLayout *buttonHLayout;

    QVBoxLayout *buttonGroupSubfoldersLayout;
    QVBoxLayout *buttonGroupReplaceLayout;
    QVBoxLayout *buttonGroupLetterSizeLayout;
    QVBoxLayout *buttonGroupExtensionSizeLayout;
    QVBoxLayout *buttonGroupSpaceLayout;
    QGroupBox *buttonGroupSubfolders;
    QGroupBox *buttonGroupReplace;
    QGroupBox *buttonGroupLetterSize;
    QGroupBox *buttonGroupExtensionSize;
    QGroupBox *buttonGroupSpace;

    //----Przyciski----//
    QPushButton *buttonSelectFolder;
    QPushButton *buttonStartNameChange;

    //----CheckBoxy----//
    QCheckBox *checkBoxReplaceInSubfolders;
    QCheckBox *checkBoxReplaceUnderscores;
    QCheckBox *checkBoxReplaceDashes;
    QCheckBox *checkBoxDontReplaceDashesSurrondedBySpaces;
    QCheckBox *checkBoxReplaceDots;
    QCheckBox *checkBoxReplaceExtensionDot;
    QCheckBox *checkBoxRemoveMultiplySpaces;
    QCheckBox *checkBoxRemoveSpacesAtBegin;
    QCheckBox *checkBoxRemoveSpacesAtEnd;
    QRadioButton *radioButtonChangeFirstLetterToBig;
    QRadioButton *radioButtonChangeLettersToBig;
    QRadioButton *radioButtonChangeLettersToSmall;
    QRadioButton *radioButtonChangeFirstLettersToBig;
    QRadioButton *radioButtonDontChangeName;
    QRadioButton *radioButtonChangeExtensionToSmall;
    QRadioButton *radioButtonChangeExtensionToBig;
    QRadioButton *radioButtonChangeExtensionFirstLettersToBig;
    QRadioButton *radioButtonChangeDontChangeExtension;

    //----Okienko z tekstem----//
    QTextBrowser *textBrowserAbout;

    //----Pasek Postępu----//
    QProgressBar *progressBar;

    //----Zmienna przechowująca folder----//
    QString selectedFolder;

    //----Rdzeń----//
    WidgetViewProvider *programCore;

    //----Parametry zmiany nazw----//
    NameChangeParameters nameChangeParameters;

private slots:
    void closeEvent(QCloseEvent *); //Zamyka program po zamknięciu głównego okna
    void enableButtonsStartNameChange(); //Funkcja aktywuje przycisk Rozpocznij
    void disableButtonsStartNameChange(); //Funkcja deaktywuje przycisk Rozpocznij
    void enableButtonsSelectFolder(); //Włącza aktywność przycisku Wybierz folder
    void disableButtonsSelectFolder(); //Wyłącza aktywność przycisków Wybierz folder
    void selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void startNameChange(); //Funkcja rozpoczyna procedurę zmiany nazw po wybraniu folderu
    void showWidgetAbout(); //Pokazuje okienko z informacjami o programie
    void showWidgetChangeLog(); //Wyświetla okienko z rejestrem zmian
    void showWidgetSettings(); //Wyświetla okienko ustawienia
    void setButtonSelection(); //Ustawia zaznaczenia przycisków

    //----Funkcje aktualizujace stany między check boxami a paskiem
    void checkBoxDotsClicked();
    void checkBoxDashesClicked();
    void setNameChangesParameters();
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();

};

#endif // WIDGET_H
