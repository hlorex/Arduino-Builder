#include "common.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //createMenu();
    createCentralWidget();
}

void MainWindow::createCentralWidget()
{
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    runButton = new QPushButton("Build");
    editProject = new QLineEdit;

    QObject::connect(runButton, SIGNAL(clicked()), this, SLOT(build()));

    layout->addWidget(runButton);
    layout->addWidget(editProject);
    widget->setLayout(layout);

    setCentralWidget(widget);
}

void MainWindow::createMenu()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
}

void MainWindow::newFile()
{
    qDebug() << "newFile();";
}

void MainWindow::openFile()
{
    qDebug() << "openFile();";
}

void MainWindow::build()
{
    qDebug() << "build()";
    QProcess builder;

    builder.setWorkingDirectory(editProject->text());
    qDebug() << builder.workingDirectory();
    builder.start("make");

    if (!builder.waitForStarted())
    {
        qDebug() << "builder start failed";
        return;
    }
    qDebug() << "build started";
    if (!builder.waitForFinished())
    {
        qDebug() << "builder finish failed";
        return;
    }
    qDebug() << "build finished";
}

