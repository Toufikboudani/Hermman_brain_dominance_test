#include "mygraph.h"
#include "ui_mygraph.h"
#include <QPrinter>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QTime>
#include <QtMath>
#include <QPainter>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTime>
#include <QImage>
#include <QDesktopServices>
#include  <QFileDialog>
#include  <QSettings>

qreal mySqr(qreal value){
    return value*value;
}
qreal mAB(QPointF A_pos,QPointF B_pos){
    return  qSqrt(mySqr(A_pos.x()-B_pos.x())+mySqr(A_pos.y()-B_pos.y()));
}
qreal mAB_alfaDegrees(QPointF A_pos,QPointF B_pos){
    qreal R =mAB(B_pos,A_pos);
    // qDebug() <<" x - A = "<<(A_pos.x()-B_pos.x());
    // qDebug() <<" cos alfa = "<<(A_pos.x()-B_pos.x())/R;
    qreal xr=(A_pos.x()-B_pos.x());
    qreal yr=(A_pos.y()-B_pos.y());
    qreal alfaDegrees=qRadiansToDegrees(qAcos((xr)/R));
    if (yr>0.0) {
        return   alfaDegrees ;
    } else {
        return  -alfaDegrees ;
    }


}
qreal mAB_alfaDegrees(QPointF A_pos,QPoint B_pos){
    qreal R =mAB(B_pos,A_pos);
    // qDebug() <<" x - A = "<<(A_pos.x()-B_pos.x());
    // qDebug() <<" cos alfa = "<<(A_pos.x()-B_pos.x())/R;
    qreal xr=(A_pos.x()-B_pos.x());
    qreal yr=(A_pos.y()-B_pos.y());
    qreal alfaDegrees=qRadiansToDegrees(qAcos((xr)/R));
    if (yr>0.0) {
        return   alfaDegrees ;
    } else {
        return  -alfaDegrees ;
    }


}
qreal mAB_alfaRadians(QPointF A_pos,QPointF B_pos){
    qreal R =mAB(A_pos,B_pos);
    return   qAsin((B_pos.y()-A_pos.y())/R);
}
QPointF Mygraph::P_pos(qreal Alfa,qreal mR)
{
    qreal myAlfa=qDegreesToRadians(Alfa);

    return QPointF(mR+((mR-50)*qCos(myAlfa)),
                   mR+((mR-50)*qSin(myAlfa))) ;
}
Mygraph::Mygraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mygraph)
{
    ui->setupUi(this);
    setPercentage(50);
Myimag.load(":/image/images.png");

    angel1=0;
        setPercentageHBD_D(25);
        setPercentageHBD_C(70);
        setPercentageHBD_B(50);
        setPercentageHBD_A(100);
}

Mygraph::~Mygraph()
{
    delete ui;
}

void Mygraph::DrawAllPdf()
{
    QString FileName= QFileDialog::getSaveFileName(this,tr("Save file"),qApp->applicationDirPath()+"/"+"Graph_Hermann_"+m_NameObj+"_"+m_family_name+".pdf", "Files (*.pdf);File(*.pdf)");
    if (FileName.isEmpty()) {
        return;
    }

    QPrinter printer;
    QPainter p(this) ; qDebug()<<"p.font() = "<<p.font().family();
  //  if (Setting_PRint->TypeInvoicesPrint==CFTO::Printpdf) {
        printer.setOutputFormat(QPrinter::PdfFormat);

        printer.setOutputFileName(FileName);

        printer.setFullPage(!true);
   // }
    printer.setOrientation(QPrinter::Portrait);
    //    printer.setPaperSize(QPrinter::A6);
    printer.setPageSize(QPrinter::A4);
    printer.setPaperSize(QPrinter::A4);
     printer.setPageMargins(5,0,15,-15,QPrinter::Millimeter);

    p.begin(&printer);

    DrawAll(p);

    p.end();
    // p.begin(&printer);
    //this->DrawInvoicePayBill(p);


    // p.end();
qDebug()<<"FileName   =   "<<FileName;
        QDesktopServices::openUrl(QUrl::fromLocalFile(FileName));

}

void Mygraph::on_pushButton_clicked()
{

}

double Mygraph::Diameter_rect()
{
    return  qSqrt( mySqr(this->rect().width())+
                   mySqr(this->rect().height()));

}
int Mygraph::Age() const
{
    return m_Age;
}

void Mygraph::setAge(int Age)
{
    m_Age = Age;
}

void Mygraph::setFamilyAndNameandAge(const QString &family_name,
                                     const QString &NameObj,
                                     int Age)
{
    m_Age = Age;  m_family_name = family_name;    m_NameObj = NameObj;
     setWindowTitle(m_NameObj+" "+m_family_name);


}

QString Mygraph::family_name() const
{
    return m_family_name;
}

void Mygraph::setFamily_name(const QString &family_name)
{
    m_family_name = family_name;
}

QString Mygraph::NameObj() const
{
    return m_NameObj;
}

void Mygraph::setNameObj(const QString &NameObj)
{
    m_NameObj = NameObj;
}


void Mygraph::DrawAll(QPainter &Painter)
{
     Painter.setRenderHint(QPainter::Antialiasing);
    Mywidth=this->height();
    Myheight=this->height() ;

    Painter.drawImage(QRect(0,0,this->height(),this->height()),Myimag);

 //   double Percenta=((Mywidth/2)*m_percentage);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidthF(2);
    Painter.setPen(pen);
    Painter.drawEllipse(QRect(0,0,Mywidth,Mywidth) );


    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth/2,0));
    Painter.drawLine(QPoint(0,Myheight/2),QPoint(Mywidth/2,Myheight/2));
//    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(0,0));
    pen.setWidthF(4);
    pen.setColor(Qt::blue);
    Painter.setPen(pen);
    ///////////////////////////////////////////////////////

    pen.setColor(Qt::red);
    pen.setWidthF(2);
    Painter.setPen(pen);
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth/2,Myheight));
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(0,Myheight/2));
//    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(0,Myheight));
    pen.setWidthF(4);
    pen.setColor(Qt::blue);
    Painter.setPen(pen);

    /////////////////////////////////////////////
    pen.setColor(Qt::red);
    pen.setWidthF(2);

    pen.setColor(Qt::red);
    pen.setWidthF(2);
    Painter.setPen(pen);
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth/2,Myheight));
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth,Myheight/2));
 //   Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth,Myheight));
    pen.setWidthF(4);
    pen.setColor(Qt::blue);
    Painter.setPen(pen);
    //////////////////////////////////////////
    pen.setColor(Qt::red);
    pen.setWidthF(2);
    Painter.setPen(pen);
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth/2,0));
    Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth,Myheight/2));
 //   Painter.drawLine(QPoint(Mywidth/2,Myheight/2),QPoint(Mywidth,0));
    pen.setWidthF(4);
    pen.setColor(Qt::blue);
    Painter.setPen(pen);


    DrawHBD_A(Painter);
    DrawHBD_B(Painter);
    DrawHBD_C(Painter);
    DrawHBD_D(Painter);

pen.setColor(QColor("#d310f0"));
Painter.setPen(pen);

         QPainterPath  path;

        path.moveTo(P_HBD_A);
        path.lineTo(P_HBD_B);
        path.lineTo(P_HBD_C);
        path.lineTo(P_HBD_D);
        path.lineTo(P_HBD_A);

        Painter.drawPath(path);
        pen.setWidthF(2);
        Painter.setPen(pen);


        QRect RA(this->width()-120,20,100,30);
        QRect RB(this->width()-120,50,100,30);
        QRect RC(this->width()-120,80,100,30);
        QRect RD(this->width()-120,110,100,30);
        Painter.drawRect(RA);
        Painter.drawRect(RB);
        Painter.drawRect(RC);
        Painter.drawRect(RD);

        QRect rectFName(this->width()-100,this->height()-70,80,20);
        QRect rectName(this->width()-100,this->height()-55,80,20);
        QRect rectAge(this->width()-100,this->height()-40,80,20);

        QRect rectFName2(this->width()-200,this->height()-70,100,20);
        QRect rectName2(this->width()-200,this->height()-55,100,20);
        QRect rectAge2(this->width()-200,this->height()-40,100,20);

//        Painter.drawRect(rectFName);
//        Painter.drawRect(rectName);
//        Painter.drawRect(rectAge);
//        Painter.drawRect(rectFName2);
//        Painter.drawRect(rectName2);
//        Painter.drawRect(rectAge2);
        QFont fFF=Painter.font();
        fFF.setPointSize(10);
        fFF.setBold(true);
        Painter.setFont(fFF);

        Painter.drawText(rectName,Qt::AlignRight+Qt::AlignVCenter,"الإسم");
        Painter.drawText(rectAge,Qt::AlignRight+Qt::AlignVCenter,"العمر");
        Painter.drawText(rectFName,Qt::AlignRight+Qt::AlignVCenter,"الإسم العائلي");


        pen.setWidthF(20);
        pen.setColor(QColor("#4e70f1"));
        Painter.setPen(pen);

        Painter.setLayoutDirection(Qt::RightToLeft);
         Painter.drawText(rectFName2,Qt::AlignLeft+Qt::AlignVCenter," : "+m_family_name);
         Painter.drawText(rectName2,Qt::AlignLeft+Qt::AlignVCenter," : "+m_NameObj);
         Painter.drawText(rectAge2,Qt::AlignLeft+Qt::AlignVCenter," : "+QString::number(m_Age));
      Painter.setLayoutDirection(Qt::LeftToRight);


        Painter.drawPoint(this->width()-105,35);
        Painter.drawText(RA,Qt::AlignRight+Qt::AlignVCenter,QString::number(m_percentageHBD_A,'f',2)+" % A ");


        pen.setColor(QColor("#68be84"));
        Painter.setPen(pen);
        Painter.drawPoint(this->width()-105,65);
        Painter.drawText(RB,Qt::AlignRight+Qt::AlignVCenter,QString::number(m_percentageHBD_B,'f',2)+" % B ");

        pen.setColor(QColor("#ec3652"));
        Painter.setPen(pen);
        Painter.drawPoint(this->width()-105,95);
        Painter.drawText(RC,Qt::AlignRight+Qt::AlignVCenter,QString::number(m_percentageHBD_C,'f',2)+" % C ");

        pen.setColor(QColor("#fbd650"));
        Painter.setPen(pen);
        Painter.drawPoint(this->width()-105,125);
        Painter.drawText(RD,Qt::AlignRight+Qt::AlignVCenter,QString::number(m_percentageHBD_D,'f',2)+" % D ");




}
double Mygraph::percentageHBD_D() const
{
    return m_percentageHBD_D;
}

void Mygraph::setPercentageHBD_D(double percentageHBD_D)
{
    if ( percentageHBD_D>100) {
      m_percentageHBD_D=100; repaint();
      return;
    }
    m_percentageHBD_D = percentageHBD_D ;  repaint();
}

double Mygraph::percentageHBD_C() const
{
    return m_percentageHBD_C;
}

void Mygraph::setPercentageHBD_C(double percentageHBD_C)
{
    if ( percentageHBD_C>100) {
      m_percentageHBD_C=100; repaint();
      return;
    }
    m_percentageHBD_C = percentageHBD_C;  repaint();
}

double Mygraph::percentageHBD_B() const
{
    return m_percentageHBD_B;
}

void Mygraph::setPercentageHBD_B(double percentageHBD_B)
{
    if ( percentageHBD_B>100) {
      m_percentageHBD_B=100; repaint();
      return;
    }
    m_percentageHBD_B = percentageHBD_B;  repaint();
}

double Mygraph::percentageHBD_A() const
{
    return m_percentageHBD_A;
}

void Mygraph::setPercentageHBD_A(double percentageHBD_A)
{
    if ( percentageHBD_A>100) {
      m_percentageHBD_A=100; repaint();
      return;
    }
    m_percentageHBD_A = percentageHBD_A;  repaint();
}

int Mygraph::TypeHBD() const
{
    return m_TypeHBD;
}

void Mygraph::setTypeHBD(int TypeHBD)
{
    m_TypeHBD = TypeHBD;
}

void Mygraph::DrawHBD_A(QPainter &Painter)
{
    double Percenta=((Mywidth/2)*(m_percentageHBD_A/100.00));

    Painter.save();
    QPen pen;
    pen.setWidthF(3);

    Painter.translate((Mywidth/2),(Mywidth/2));
    Painter.rotate(-45);
    Painter.translate(-(Mywidth/2),-(Mywidth/2));


    ///******************************
    ///
    P_HBD_A=P_pos(QPointF(Mywidth/2,Myheight/2),-135,Percenta);
    pen.setColor(Qt::blue);

    Painter.setPen(pen);
    Painter.drawLine(QPointF(Mywidth/2,Myheight/2),QPointF(Mywidth/2,0));


    Painter.restore();
    pen.setColor(Qt::black);
    Painter.setPen(pen);
    pen.setWidthF(7);
    Painter.setPen(pen);
    Painter.drawPoint(P_HBD_A);
    Painter.drawText(P_HBD_A.x()-10,P_HBD_A.y()-10,QString::number((m_percentageHBD_A),'f',2)+" % A");

}

void Mygraph::DrawHBD_D(QPainter &Painter)
{
    qreal PercentaB=((Mywidth/2)*(m_percentageHBD_D/100.00));

    Painter.save();
    QPen pen;
    pen.setWidthF(3);

    Painter.translate((Mywidth/2),(Mywidth/2));
    Painter.rotate(45);
    Painter.translate(-(Mywidth/2),-(Mywidth/2));


    ///******************************
    ///
    P_HBD_D=P_pos(QPointF(Mywidth/2,Myheight/2),-45,PercentaB);
    pen.setColor(Qt::yellow);

    Painter.setPen(pen);
    Painter.drawLine(QPointF(Mywidth/2,Myheight/2),QPointF(Mywidth/2,0));


    Painter.restore();
    pen.setColor(Qt::black);
    Painter.setPen(pen);
    pen.setWidthF(7);
    Painter.setPen(pen);
    Painter.drawPoint(P_HBD_D);
    Painter.drawText(P_HBD_D.x()+10,P_HBD_D.y()-10,QString::number(m_percentageHBD_D,'f',2)+" % D");

}

void Mygraph::DrawHBD_C(QPainter &Painter)
{
    qreal Percenta=((Mywidth/2)*(m_percentageHBD_C/100.00));

    Painter.save();
    QPen pen;
    pen.setWidthF(3);

    Painter.translate((Mywidth/2),(Mywidth/2));
    Painter.rotate(135);
    Painter.translate(-(Mywidth/2),-(Mywidth/2));


    ///******************************
    ///
    P_HBD_C=P_pos(QPointF(Mywidth/2,Myheight/2),45,Percenta);

    pen.setColor(Qt::red);

    Painter.setPen(pen);
    Painter.drawLine(QPointF(Mywidth/2,Myheight/2),QPointF(Mywidth/2,0));
    Painter.restore();
    pen.setColor(Qt::black);
    Painter.setPen(pen);
    pen.setWidthF(7);
    Painter.setPen(pen);
    Painter.drawPoint(P_HBD_C);
    Painter.drawText(P_HBD_C.x()-10,P_HBD_C.y()+10,QString::number(m_percentageHBD_C,'f',2)+" % C");

}

void Mygraph::DrawHBD_B(QPainter &Painter)
{

    Painter.save();
    qreal Percenta=((Mywidth/2)*(m_percentageHBD_B/100.00));
    QPen pen;
    pen.setWidthF(3);

    Painter.translate((Mywidth/2),(Mywidth/2));
    Painter.rotate(-135);
    Painter.translate(-(Mywidth/2),-(Mywidth/2));


    ///******************************
    ///
    P_HBD_B=P_pos(QPointF(Mywidth/2,Myheight/2),-225,Percenta);
    pen.setColor(Qt::green);

    Painter.setPen(pen);
    Painter.drawLine(QPointF(Mywidth/2,Myheight/2),QPointF(Mywidth/2,0));

    Painter.restore();
    pen.setColor(Qt::black);
    Painter.setPen(pen);
    pen.setWidthF(7);
    Painter.setPen(pen);
    Painter.drawPoint(P_HBD_B);
    Painter.drawText(P_HBD_B.x()-10,P_HBD_B.y()+10,QString::number(m_percentageHBD_B,'f',2)+" % B");


}

double Mygraph::percentage() const
{
    return m_percentage;
}

void Mygraph::setPercentage(double percentage)
{
    m_percentage = (100-percentage)/100;
}

double Mygraph::Value() const
{
    return m_Value;
}

void Mygraph::setValue(double Value)
{
    m_Value = Value;
}

QPointF Mygraph::P_pos(QPointF mpos,qreal Alfa,qreal mR)
{


    // qDebug()<<mR<<"      width "<<this->width();
    qreal myAlfa=qDegreesToRadians(Alfa);
    //    qreal myAlfa2=qAsin((R_pos.y()-mov_pos.y())/mR);
    return QPointF(mpos.x()+((mR)*qCos(myAlfa)),
                   mpos.y()+((mR)*qSin(myAlfa))) ;
}


void Mygraph::paintEvent(QPaintEvent *)
{


    QPainter Painter(this) ;
    DrawAll(Painter);

}



void Mygraph::wheelEvent(QWheelEvent *event)
{

    if ( event->delta()<0) {
        angel1+=5;
        repaint();
    } else {
        angel1-=5; repaint();
    }
    qDebug()<<"angel1 = "<<angel1;
    QWidget::wheelEvent(event);
}

void Mygraph::on_pushButtonPrint_clicked()
{
    DrawAllPdf();
}
