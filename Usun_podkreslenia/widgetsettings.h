#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QDesktopWidget>
#include "settings.h"

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

    //----Etykiety----//
    QLabel *labelDefaultSettings;

    //----Przyciski----//
    QPushButton *buttonOK;

    //----CheckBoxy----//
    QCheckBox *checkBoxReplaceInSubfolders;
    QCheckBox *checkBoxReplaceUnderscores;
    QCheckBox *checkBoxReplaceDashes;
    QCheckBox *checkBoxReplaceDots;
    QCheckBox *checkBoxReplaceExtensionDot;
    QCheckBox *checkBoxChangeFirstLetterToBig;
    QCheckBox *checkBoxChangeExtensionToSmall;

    //----Obiekt czytajacy ustawienia----//
    Settings *settingsReader;

private slots:
    void closeWindow(); //Zamyka okno
    void changeCheckBoxExtensionDotActivity(); //Ustawia aktywność przycisku usuń kropkę rozszerzenia zależnie od przycisku zastąp kropki
    void setCheckBoxes(); //Ustawia przyciski danymi z pliku
    void setSettingsReader(); //Ustawia czytacz ustawień wartościami checkboxów

public slots:
    void showWindow(); //Pokazuje już utworzone okno
};

#endif // WIDGETSETTINGS_H
