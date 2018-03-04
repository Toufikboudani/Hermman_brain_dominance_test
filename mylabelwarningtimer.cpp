#include "mylabelwarningtimer.h"

#include "htmlprepara.h"

MyLabelWarningTimer::MyLabelWarningTimer(QWidget *parent) :
    MyLabelWarning(parent)
{

    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshLabel()));
    timer.start(1000);

    Second=0;
    Max=3;
}

void MyLabelWarningTimer::refreshLabel()
{
    Second++;
    if (Second>=Max) {
      timer.stop();
       this->setText(HtmlPrepara::PreparaText("MyLabelWarningTimer","&nbsp;",1,"ff4400"));
    Second=0;
    }

}

void MyLabelWarningTimer::setText(const QString & t)
{
    QLabel::setText(t);
     timer.start(1000);
}
int MyLabelWarningTimer::getMax() const
{
    return Max;
}

void MyLabelWarningTimer::setMax(int value)
{
    Max = value;
}

