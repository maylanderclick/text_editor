#ifndef CHANGE_H
#define CHANGE_H

#include <QColor>
#include <QColorDialog>
#include <QTextCursor>
#include <QFont>
#include <QFontDialog>
#include <QFontInfo>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QString>

class Change
{
public:
    Change();
    QColor TextColor();
    QFont ChangeFont();
};

#endif // CHANGE_H
