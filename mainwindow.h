#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QtCore>
#include <QtGui>

#include "change.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Change modification;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_pushButton_3_clicked();
    void on_actionColor_2_triggered();
    void on_actionFont_triggered();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QString FileName;
};

#endif // MAINWINDOW_H
