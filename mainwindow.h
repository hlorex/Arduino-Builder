#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    void newFile();
    void openFile();
    void build();
    
private:
    void createMenu();
    void createCentralWidget();

    QPushButton *runButton;
    QLineEdit *editProject;
    QAction *newAct;
    QAction *openAct;
    QMenu *fileMenu;
};

#endif // MAINWINDOW_H
