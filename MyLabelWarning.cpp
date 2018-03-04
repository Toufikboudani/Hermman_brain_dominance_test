#include "MyLabelWarning.h"

MyLabelWarning::MyLabelWarning(QWidget *parent) :
    QLabel(parent)
{
     this->setTextFormat(Qt::RichText);
     this->setTextInteractionFlags(Qt::TextBrowserInteraction);
     this->setOpenExternalLinks(true);
    WarningEroor=true;
}
void MyLabelWarning::mousePressEvent(QMouseEvent *ev)
{
    QLabel::mousePressEvent(ev);
    if (text().indexOf("href")>-1) {
        emit linkclikcd(text());
    }

}
bool MyLabelWarning::isWarningEroor() const
{
    return WarningEroor;
}

void MyLabelWarning::setWarningEroor(bool value)
{
    WarningEroor = value;
}

