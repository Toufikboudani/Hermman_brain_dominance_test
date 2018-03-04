#include "labellcdpopup.h"
#include "ui_labellcdpopup.h"
#include <QTimer>
#include <QHideEvent>
#include <QDebug>

LabellcdPopup::LabellcdPopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabellcdPopup)
{
     ui->setupUi(this);
    setMax_Width(300);
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshLabellcdPopup()));
    timer->stop();
    this->hide();
    mywidth=0;
    ui->valeulcd->setAutoFillBackground(true);
    this->setAutoFillBackground(true);
    ui->valeulcd->setPalette(this->palette());
}
void LabellcdPopup::Reducing(){
    timer->start(10);
    ReducingExtension=false;
}
void LabellcdPopup::Extension(){
    timer->start(10);
    KR=0;
    mywidth=0;
    ReducingExtension=true;
}

void LabellcdPopup::setText(const QString &Text)
{
    emit textChanged(Text);
    ui->valeulcd->setText(Text);
    Extension();
}

void LabellcdPopup::setColorText(const QString &/*TextColor*/)
{

//    QPalette palette=ui->valeulcd->palette();

//    palette.setBrush(QPalette::WindowText, QColor(TextColor));
//    palette.setBrush(QPalette::Text, QColor(TextColor));
//    ui->valeulcd->setPalette(palette);
}
bool LabellcdPopup::getReducingExtension() const
{
    return ReducingExtension;
}

void LabellcdPopup::setReducingExtension(bool value)
{
    ReducingExtension = value;
}
void  LabellcdPopup::hideEvent(QHideEvent */*e*/)
{
   qDebug()<<"LabellcdPopuphideEvent";
   timer->stop();
}
QLabel *LabellcdPopup::Label() const
{
    return ui->valeulcd;
}

QString LabellcdPopup::text() const
{
    return ui->valeulcd->text();
}

const QPalette &LabellcdPopup::palette() const
{
  return QWidget::palette();
}

void LabellcdPopup::setPalette(const QPalette &p)
{
   QWidget::setPalette(p);
   ui->valeulcd->setPalette(this->palette());
}

void LabellcdPopup::refreshLabellcdPopup(){
    ui->valeulcd->repaint();
    this->show();
    if (ReducingExtension){
        mywidth+=20;
    }else {
        mywidth-=20;
    }
    if (mywidth>=m_Max_Width) {
        mywidth=m_Max_Width;
        KR++;
        if (KR>=m_Max_Width) {
           ReducingExtension=false;
           KR=0;
        }

    }
    if (mywidth<=0) {
        mywidth=0;
        timer->stop();
        this->hide();
    }
  this->resize(mywidth,this->height());
}
LabellcdPopup::~LabellcdPopup()
{
    delete timer;
    delete ui;
}

void LabellcdPopup::on_valeulcd_linkActivated
(const QString &/*link*/)
{

}
int LabellcdPopup::Max_Width() const
{
    return m_Max_Width;
}

void LabellcdPopup::setMax_Width(int Max_Width)
{
    m_Max_Width = Max_Width;
}

