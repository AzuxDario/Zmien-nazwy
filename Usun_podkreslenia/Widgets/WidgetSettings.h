#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QTabWidget>
#include "Settings.h"
#include "Widgets.h"

namespace Ui {
class WidgetSettings;
}

class WidgetSettings : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettings(QWidget *parent = 0);
    ~WidgetSettings();

private:
    Ui::WidgetSettings *ui;

    QTabWidget *mainTabWidget;
    QWidget *mainTab;
    QWidget *sizeAndSpacesTab;
    QWidget *extensionFilterTab;

    //----Layouty----//
    QVBoxLayout *windowVLayout;
    QVBoxLayout *mainTabVLayout;
    QVBoxLayout *sizeAndSpacesTabVLayout;
    QVBoxLayout *extensionFilterTabVLayout;
    QHBoxLayout *buttonHLayout;
    QHBoxLayout *extensionButtonHLayout;

    QVBoxLayout *buttonGroupSubfoldersLayout;
    QVBoxLayout *buttonGroupReplaceLayout;
    QVBoxLayout *buttonGroupSizeLayout;
    QVBoxLayout *buttonGroupSpaceLayout;
    QGroupBox *buttonGroupSubfolders;
    QGroupBox *buttonGroupReplace;
    QGroupBox *buttonGroupSize;
    QGroupBox *buttonGroupSpace;

    //----Przyciski----//
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
    QLabel *labelDefaultSettings;
    QLabel *labelChangeLettersSize;
    QLabel *labelChangeExtensionSize;

    //----Przyciski----//
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    //---Wyrażenia regularne i walidator---//
    QRegExp regExp;
    QRegExpValidator regExpValidator;

    //----Pole edycji----//
    QLineEdit *lineEditExtensionFilter;

    //----Lista rozszerzeń----//
    QListWidget *listWidgetExtensionFilter;

    //----Obiekt czytajacy ustawienia----//
    Settings *settingsReader;

private slots:
    void closeWindow(); //Zamyka okno
    void saveSettings(); //Zapisuje ustawienia
    void checkBoxDotsClicked(); //Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki
    void checkBoxDashesClicked();
    void setCheckBoxes(); //Ustawia przyciski danymi z pliku
    void setSettingsReader(); //Ustawia czytacz ustawień wartościami checkboxów
    void addExtension(); //Dodaj rozszerzenie do listy
    void deleteExtension(); //Usuwa rozszerzenie z listy

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETSETTINGS_H
