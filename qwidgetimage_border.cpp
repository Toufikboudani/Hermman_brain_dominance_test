#include "qwidgetimage_border.h"
#include "ui_qwidgetimage_border.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPen>
#include <QFileDialog>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDebug>
//#include "mywstyle.h"
#include <QMessageBox>
//#include "dialogcameratoto.h"
QWidgetImage_border::QWidgetImage_border(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWidgetImage_border)
{
    ui->setupUi(this);

    Image=new QImage();
    defaultfileName = ":/image/defaultImageSp.png";

    fileName=defaultfileName;
    Image->load(fileName);
    Colorborder= "#45a1fe";
}

QWidgetImage_border::~QWidgetImage_border()
{
    delete ui;

}
QString QWidgetImage_border::getDefaultfileName() const
{
    return defaultfileName;
}

void QWidgetImage_border::setDefaultfileName(const QString &value)
{
    defaultfileName = value;
}

QString QWidgetImage_border::getFileName() const
{
    return fileName;
}

void QWidgetImage_border::setFileName(const QString &value)
{
    fileName = value;
    Image->load(fileName);

    this->repaint();
}

void QWidgetImage_border::DefaultfileName()
{
   setFileName(defaultfileName);
}

void QWidgetImage_border::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    QPen pen(Qt::red);
    pen.setWidth(4);

    pen.setColor(Colorborder);
    painter.setPen(pen);
    painter.drawImage(QRect(5,5,this->width()-10,this->height()-5),*Image);

    painter.drawRect(QRect(5,5,this->width()-10,this->height()-7));
    //    pen.setColor("#ff0000");
    //    painter.setPen(pen);

}
QString QWidgetImage_border::getColorborder() const
{
    return Colorborder;
}

void QWidgetImage_border::setColorborder(const QString &value)
{
    Colorborder = value;
}




