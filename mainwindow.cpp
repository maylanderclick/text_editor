#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered() //выход
{
   QMessageBox::StandardButton Exit = QMessageBox::question(this, "Закрыть окно", "Сохранить?",
                                                          QMessageBox::Yes | QMessageBox::No);
   if(Exit == QMessageBox::Yes){
       MainWindow::on_actionSave_triggered();
       QMessageBox::information(this, "Сохранение", "Изменения сохранены");
       // qDebug() << "the changes are saved";
   }
   else QApplication::quit();
}

void MainWindow::on_pushButton_3_clicked() //разобрать поиск
{
        QList<QTextEdit::ExtraSelection> sel;
        ui->textEdit->moveCursor(QTextCursor::Start);
        QString s = ui->lineEdit->text();
          while(ui->textEdit->find(s))
        {
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(QColor(Qt::green).lighter(125));
            extra.cursor = ui->textEdit->textCursor();
            sel.append(extra);
        }
        ui->textEdit->setExtraSelections(sel);
        ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_actionColor_2_triggered()
{
    Change modification;
    ui->textEdit->setTextColor(modification.TextColor());
}

void MainWindow::on_actionFont_triggered()
{
    Change modification;
    ui->textEdit->setFont(modification.ChangeFont());
}

void MainWindow::on_actionNew_triggered()
{
    FileName = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if(file != "")
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                FileName = file;
                QTextStream stream(&sFile);
                QString text = stream.readAll();
                sFile.close();

            ui->textEdit->setText(text);
            }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save File");

    if (file != "") {
        QFile sFile(file);
        if (!sFile.open(QIODevice::WriteOnly)) {
            // error message
            QMessageBox::information(this, "Error", "Error");
        } else {
            QTextStream stream(&sFile);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            sFile.close();
        }
    }
}
