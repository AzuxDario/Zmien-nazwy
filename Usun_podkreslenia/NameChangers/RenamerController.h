#ifndef RENAMERCONTROLLER_H
#define RENAMERCONTROLLER_H

#include <QObject>
#include <QThread>
#include "Renamer.h"
#include "NameChangeParameters.h"

class RenamerController : public QObject
{
    Q_OBJECT
public:
    explicit RenamerController(QObject *parent = nullptr);
    ~RenamerController();

private:
    QThread workerThread;
    int parametersId;
    int parametersDirTypeId;

signals:
    void initializeProgressBar(int minValue, int maxValue);
    void changeProgressBar(int value);
    void resetProgressBar();
    void doWorkChangeInFolder(NameChangeParameters, QString selectedFolder);
    void doWorkChangeFile(NameChangeParameters, QString seledtedFile);
    void doneWork();

public:
    void initiateRenameFiles(NameChangeParameters nameChangeParameters, QString selectedDir, NameChangeParameters::DirType dirType); //Rozpoczyna procedurę zmiany nazw

private slots:
    void initializeProgressBarSlot(int minValue, int maxValue) {emit initializeProgressBar(minValue, maxValue);}
    void changeProgressBarSlot(int value) {emit changeProgressBar(value);}
    void resetProgressBarSlot() {emit resetProgressBar();}
    void handleResults();

};

#endif // RENAMERCONTROLLER_H
