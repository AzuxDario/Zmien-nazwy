#include "RenamerController.h"

RenamerController::RenamerController(QObject *parent) : QObject(parent)
{
    parametersId = qRegisterMetaType<NameChangeParameters>();
    parametersDirTypeId = qRegisterMetaType<NameChangeParameters::DirType>();
    Renamer *worker = new Renamer;
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, SIGNAL(doWork(NameChangeParameters, QString, NameChangeParameters::DirType)), worker, SLOT(initiateRenameFiles(NameChangeParameters, QString, NameChangeParameters::DirType)));
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
    emit doWork(nameChangeParameters, selectedDir, dirType);
}

