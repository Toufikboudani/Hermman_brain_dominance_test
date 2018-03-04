#include "dialogabout.h"
#include "ui_dialogabout.h"
#include <QTimer>
#include <QBitmap>
DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

}

DialogAbout::DialogAbout(QWidget *parent, Qt::WindowFlags f):
    QDialog(parent,f),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    QBitmap mymask(":/image/commercial_shopmsk.bmp");
    this->setMask(mymask);
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshAbout()));
    timer->start(1000);
    mcl=0;

}
void DialogAbout::refreshAbout(){
     mcl++;
    if ( mcl>5) {
      timer->stop();
      this->close();
    }
}
DialogAbout::~DialogAbout()
{
    delete ui;
}
