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
#include <QListWidget>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
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
    QVBoxLayout *centerVLayout;
    QVBoxLayout *rightVLayout;
    QHBoxLayout *mainButtonHLayout;
    QHBoxLayout *extensionButtonHLayout;

    QVBoxLayout *buttonGroupSubfoldersLayout;
    QVBoxLayout *buttonGroupReplaceLayout;
    QVBoxLayout *buttonGroupSizeLayout;
    QVBoxLayout *buttonGroupSpaceLayout;
    QVBoxLayout *buttonGroupExtensionFilterLayout;
    QGroupBox *buttonGroupSubfolders;
    QGroupBox *buttonGroupReplace;
    QGroupBox *buttonGroupSize;
    QGroupBox *buttonGroupSpace;
    QGroupBox *buttonGroupExtensionFilter;

    //----Przyciski----//
    QPushButton *buttonSelectFolder;
    QPushButton *buttonSelectFile;
    QPushButton *buttonStartNameChange;
    QPushButton *buttonAddExtension;
    QPushButton *buttonDeleteExtension;

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

    //----ComboBoxy----//
    QComboBox *comboBoxChangeLettersSize;
    QComboBox *comboBoxChangeExtensionSize;
    QComboBox *comboBoxChangeExtensionFilter;

    //----Etykiety----//
    QLabel *labelChangeLettersSize;
    QLabel *labelChangeExtensionSize;

    //----Okienko z tekstem----//
    QTextBrowser *textBrowserAbout;

    //---Wyrażenia regularne i walidator---//
    QRegExp regExp;
    QRegExpValidator regExpValidator;

    QLineEdit *lineEditExtensionFilter;

    //----Pasek Postępu----//
    QProgressBar *progressBar;

    QListWidget *listWidgetExtensionFilter;

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
    void addExtension(); //Dodaj rozszerzenie do listy
    void deleteExtension(); //Usuwa rozszerzenie z listy

    //----Funkcje aktualizujace stany między check boxami a paskiem----//
    void checkBoxDotsClicked();
    void checkBoxDashesClicked();
    void setNameChangesParameters();
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();
    void handleResults();

};

#endif // WIDGET_H
