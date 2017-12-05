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
#include <QComboBox>
#include "Renamer.h"
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
    QAction *actionSelectFile;
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
    QVBoxLayout *buttonGroupSizeLayout;
    QVBoxLayout *buttonGroupSpaceLayout;
    QGroupBox *buttonGroupSubfolders;
    QGroupBox *buttonGroupReplace;
    QGroupBox *buttonGroupSize;
    QGroupBox *buttonGroupSpace;

    //----Przyciski----//
    QPushButton *buttonSelectFolder;
    QPushButton *buttonSelectFile;
    QPushButton *buttonStartNameChange;

    //----CheckBoxy----//
    QCheckBox *checkBoxReplaceInSubfolders;
    QCheckBox *checkBoxReplaceUnderscores;
    QCheckBox *checkBoxReplaceDashes;
    QCheckBox *checkBoxDontReplaceDashesSurrondedBySpaces;
    QCheckBox *checkBoxReplaceDots;
    QCheckBox *checkBoxReplaceExtensionDot;
    QCheckBox *checkBoxReplacePluses;
    QCheckBox *checkBoxRemoveMultiplySpaces;
    QCheckBox *checkBoxRemoveSpacesAtBegin;
    QCheckBox *checkBoxRemoveSpacesAtEnd;
    QComboBox *comboBoxChangeLettersSize;
    QComboBox *comboBoxChangeExtensionSize;

    //----Etykiety----//
    QLabel *labelChangeLettersSize;
    QLabel *labelChangeExtensionSize;

    //----Okienko z tekstem----//
    QTextBrowser *textBrowserAbout;

    //----Pasek Postępu----//
    QProgressBar *progressBar;

    //----Zmienna przechowująca folder----//
    QString selectedDirectory;
    QStringList selectedFiles;

    //----Rdzeń----//
    WidgetViewProvider *programCore;

    //----Parametry zmiany nazw----//
    NameChangeParameters nameChangeParameters;

    NameChangeParameters::DirType dirType;

private slots:
    void closeEvent(QCloseEvent *); //Zamyka program po zamknięciu głównego okna
    void enableButtonsStartNameChange(); //Funkcja aktywuje przycisk Rozpocznij
    void disableButtonsStartNameChange(); //Funkcja deaktywuje przycisk Rozpocznij
    void enableButtonsSelect(); //Włącza aktywność przycisku Wybierz folder
    void disableButtonsSelect(); //Wyłącza aktywność przycisków Wybierz folder
    void selectFolder(); //Wybiera folder do przeprowadzenia zmiany nazw
    void selectFile(); //Wybiera plik do przeprowadzenia zmiany nazw
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
    void handleResults();

};

#endif // WIDGET_H
