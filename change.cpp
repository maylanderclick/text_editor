#include "change.h"

Change::Change()
{

}

QColor Change::TextColor()
{
    QColor Color = QColorDialog::getColor();
    if(!Color.isValid())
    {

    }
    return Color;
}

QFont Change::ChangeFont()
{
    bool fnt;
    QFont Font = QFontDialog::getFont(&fnt);
    if(!fnt)
    {
        // Была нажата кнопка Cancel
    }
    return Font;
}
