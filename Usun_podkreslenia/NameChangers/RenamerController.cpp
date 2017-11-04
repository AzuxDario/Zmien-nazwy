#include "RenamerController.h"

RenamerController::RenamerController(QObject *parent) : QObject(parent)
{
    parametersId = qRegisterMetaType<NameChangeParameters>();
    Renamer *worker = new Renamer;
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, SIGNAL(doWorkChangeInFolder(NameChangeParameters, QString)), worker, SLOT(initiateRenameFilesInFolder(NameChangeParameters, QString)));
    connect(this, SIGNAL(doWorkChangeFile(NameChangeParameters, QString)), worker, SLOT(initiateRenameFile(NameChangeParameters, QString)));
    connect(worker,SIGNAL(doneWork()), this, SLOT(handleResults()));
    connect(worker,SIGNAL(initializeProgressBar(int,int)), this, SLOT(initializeProgressBarSlot(int,int)));
    connect(worker,SIGNAL(changeProgressBar(int)), this, SLOT(changeProgressBarSlot(int)));
    connect(worker,SIGNAL(resetProgressBar()), this, SLOT(resetProgressBarSlot()));
    workerThread.start();
}

RenamerController::~RenamerController()
{
    workerThread.quit();
    workerThread.wait();
}

void RenamerController::handleResults()
{
    emit doneWork();
    return;
}

void RenamerController::initiateRenameFiles(NameChangeParameters nameChangeParameters, QString selectedDir, NameChangeParameters::DirType dirType)
{
    switch(dirType)
    {
    case NameChangeParameters::DirType::Folder:
        emit doWorkChangeInFolder(nameChangeParameters, selectedDir);
        break;
    case NameChangeParameters::DirType::File:
        emit doWorkChangeFile(nameChangeParameters, selectedDir);
        break;
    }
}

