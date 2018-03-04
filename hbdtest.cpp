#include "hbdtest.h"
#include "mywstyle.h"
#include "mygraph.h"
#include "ui_hbdtest.h"
#include "myqstandarditemmodel.h"
#include "write_read_file.h"
#include <QDebug>
#include "dialogentredataname.h"
Hbdtest::Hbdtest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hbdtest)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    setWindowTitle("Hbd_Test");
     m_isComplat=false;

        QString color="#45a1fe";
//       StyleQRadioButtonSwitch()
//       ui->checkBox_No->setStyleSheet(MyWstyle::StyleStondare("QCheckBox",color,this->font()));
//       ui->checkBox_Yes->setStyleSheet(MyWstyle::StyleStondare("QCheckBox",color,this->font()));

       QFont F=qApp->font();
         F.setPixelSize(24);
        ui->radioButton_No->setStyleSheet(MyWstyle::StyleStondare("QRadioButton",color,F));
        ui->radioButton_Yes->setStyleSheet(MyWstyle::StyleStondare("QRadioButton",color,F));
      ui->groupBox_2->setStyleSheet(MyWstyle::StyleStondare("QGroupBox",color,this->font()));
      ui->groupBox_3->setStyleSheet(MyWstyle::StyleStondare("QGroupBox",color,this->font()));
      ui->radioButton_No->setChecked(false);
      ui->radioButton_Yes->setChecked(false);
    posindex=0;


Hbdtest::Read_File();
prepareLable();

}

Hbdtest::~Hbdtest()
{
    delete ui;
}
void Hbdtest::Read_File()
{
    mDataTestList.clear();






    QString Read_F;


    Write_Read_File::Read_File(":/text/dataHBD.txt",Read_F);
    qDebug()<<"Write_Read_File    "<<Read_F;
    if (Read_F.isEmpty()) {
        return;
    }


    QStringList StrRow= Read_F.split("\n", QString::SkipEmptyParts);
    if (StrRow.size()!=56) {
        return;
    }
    qDebug() <<"*********  A  ***********";
    for (int i = 0,iN=0; i < 56; ++i) {

        if(StrRow.at(i).indexOf("*=A@A=*A*")>-1){
            ++iN;
            qDebug() <<iN<<"  "<<StrRow.at(i);
        }
    }
    qDebug() <<"*********  B  ***********";

    for (int i = 0,iN=0; i < 56; ++i) {

        if(StrRow.at(i).indexOf("*=A@A=*B*")>-1){
            ++iN;
            qDebug() <<iN<<"  "<<StrRow.at(i);
        }
    }
    qDebug() <<"*********  C  ***********";

    for (int i = 0,iN=0; i < 56; ++i) {
        if(StrRow.at(i).indexOf("*=A@A=*C*")>-1){
            ++iN;
            qDebug() <<iN<<"  "<<StrRow.at(i);
        }
    }
    qDebug() <<"*********  D  ***********";

    for (int i = 0,iN=0; i < 56; ++i) {
        if(StrRow.at(i).indexOf("*=A@A=*D*")>-1){
            ++iN;
            qDebug() <<iN<<"  "<<StrRow.at(i);
        }
    }

    for (int Row = 0; Row < StrRow.size(); ++Row) {
        QStringList datacolumRow_F=StrRow.at(Row).split("*=A@A=*", QString::KeepEmptyParts);
        if (datacolumRow_F.size()<3) {
            return;
        }

            dataTest d;
            d.ID=datacolumRow_F.at(0);
            d.statment=datacolumRow_F.at(2);
            d.TypeHBD=datacolumRow_F.at(1);

            mDataTestList.append(d);






    }




}
void Hbdtest::prepareLable(){

    if (posindex<=0) {

       ui->pushButton_back->setEnabled(false);
       ui->pushButton_Next->setEnabled(true);

    }else if (posindex > mDataTestList.size()-1) {
//        on_verifyDataTest();
//        ui->pushButton_Next->setEnabled(false);
//        ui->pushButton_back->setEnabled(true);
     } else if (mDataTestList.size()<1) {
       ui->pushButton_back->setEnabled(false);
       ui->pushButton_Next->setEnabled(false);
    } else {
       ui->pushButton_Next->setEnabled(true);
       ui->pushButton_back->setEnabled(true);
    }

    dataTest d= mDataTestList.at(posindex);
//     d.ID=datacolumRow_F.at(0);


    QString  htmlHBDType ="<html><head/><body><p><span style=\" font-weight:600; color:#00aaff;\">"+d.TypeHBD+"</span></p></body></html>";
    QString  htmlstatment ="<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">"+d.statment+"</span></p></body></html>";
    QString  htmlID ="<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">"+d.ID+"</span></p></body></html>";

    ui->label_HBDType->setText(htmlHBDType);
    ui->label_statmentAnswar->setText(htmlstatment);
    ui->label_HBDNo->setText(htmlID);

    ui->radioButton_Yes->setAutoExclusive(false);
    ui->radioButton_No->setAutoExclusive(false);

    ui->radioButton_Yes->setChecked(false);
    ui->radioButton_No->setChecked(false);


}

bool Hbdtest::prepareLableAnswer()
{
    QString  html ="<html><head/><body><p align=\"center\"><img src=\":/image/warning.png\"/><span style=\" font-size:14pt; font-weight:600; color:#ff5500;\">&nbsp;&nbsp;&nbsp;&nbsp;m%%m&nbsp;&nbsp;&nbsp;&nbsp;</span></p></body></html>";
//<html><head/><body><p align="right"><span style=" font-size:22pt; font-weight:600; color:#00ffff;">TextLabel</span></p></body></html>
  //  QString phtml=getHtml().replace("<span style=",<span style=").replace("#Text#"," : Invoice is Empty &nbsp;&nbsp;&nbsp;&nbsp;").replace("#COLOR#","#f55827").replace("#SIZEFO#","12");

    if (!ui->radioButton_No->isChecked()&&!ui->radioButton_Yes->isChecked()) {
        ui->MessagePopup->setText(QString(html).replace("m%%m","لا يمكن ترك الجواب فارغ"));
         return false;
    }

  return true;

}
void Hbdtest::on_pushButton_Next_clicked()
{
    if (!prepareLableAnswer()) {
        return;
    }
   posindex++;

   if (posindex>mDataTestList.size()-1) {
      on_verifyDataTest();
       posindex=mDataTestList.size()-1;


   }

 prepareLable();

}

void Hbdtest::on_pushButton_back_clicked()
{
    if (!prepareLableAnswer()) {
        return;
    }
   posindex--;
   if (posindex<=0) {
       posindex=0;

   }


   prepareLable();
}
dataTestList Hbdtest::getMDataTestList() const
{
    return mDataTestList;
}

void Hbdtest::setMDataTestList(const dataTestList &value)
{
    mDataTestList = value;
}


void Hbdtest::on_radioButton_Yes_clicked()
{
    if (posindex>=0&&posindex<56) {
        mDataTestList[posindex].Answer=ui->radioButton_Yes->isChecked();

    }

}

void Hbdtest::on_radioButton_No_clicked()
{
    if (posindex>=0&&posindex<56) {
        mDataTestList[posindex].Answer=ui->radioButton_Yes->isChecked();

    }
}

void Hbdtest::on_pushButton_Cancel_clicked()
{
    close();
}

void Hbdtest::on_radioButton_Yes_pressed()
{
    ui->radioButton_Yes->setAutoExclusive(true);
    ui->radioButton_No->setAutoExclusive(true);

}

void Hbdtest::on_radioButton_No_pressed()
{
    ui->radioButton_Yes->setAutoExclusive(true);
    ui->radioButton_No->setAutoExclusive(true);

}

void Hbdtest::on_verifyDataTest()
{
     mData_HBD_A.clear();
     mData_HBD_B.clear();
     mData_HBD_C.clear();
     mData_HBD_D.clear();

    for (int i = 0; i < 56; ++i) {
        if (mDataTestList.at(i).TypeHBD=="A") {
          mData_HBD_A.append(mDataTestList.at(i));
        }else if (mDataTestList.at(i).TypeHBD=="B") {
            mData_HBD_B.append(mDataTestList.at(i));
          }
       else if (mDataTestList.at(i).TypeHBD=="C") {
            mData_HBD_C.append(mDataTestList.at(i));
          }
      else if (mDataTestList.at(i).TypeHBD=="D") {
            mData_HBD_D.append(mDataTestList.at(i));
          }
    }
    qDebug()<<"A   size= "<<mData_HBD_A.size();
    qDebug()<<"B   size= "<<mData_HBD_B.size();
    qDebug()<<"C   size= "<<mData_HBD_C.size();
    qDebug()<<"D   size= "<<mData_HBD_D.size();


    qreal contHBD_A=0.0;
    qreal contHBD_B=0.0;
    qreal contHBD_C=0.0;
    qreal contHBD_D=0.0;
     for (int i = 0; i < 14; ++i) {

     if (mData_HBD_A.at(i).Answer) {
        contHBD_A++;
     }if (mData_HBD_B.at(i).Answer) {
         contHBD_B++;
      }if (mData_HBD_C.at(i).Answer) {
         contHBD_C++;
      }if (mData_HBD_D.at(i).Answer) {
         contHBD_D++;
      }



    }
     m_percentageHBD_A=(contHBD_A/14)*100.0;
     m_percentageHBD_B=(contHBD_B/14)*100.0;
     m_percentageHBD_C=(contHBD_C/14)*100.0;
     m_percentageHBD_D=(contHBD_D/14)*100.0;
     qDebug()<<"A   size= "<<m_percentageHBD_A;
     qDebug()<<"B   size= "<<m_percentageHBD_B;
     qDebug()<<"C   size= "<<m_percentageHBD_C;
     qDebug()<<"D   size= "<<m_percentageHBD_D;

m_isComplat=true;

     Mygraph  Dgraph(this);
     Dgraph.setFamilyAndNameandAge(m_family_name,m_NameObj,m_Age);
     Dgraph.setPercentageHBD_A(m_percentageHBD_A);
     Dgraph.setPercentageHBD_B(m_percentageHBD_B);
     Dgraph.setPercentageHBD_C(m_percentageHBD_C);
     Dgraph.setPercentageHBD_D(m_percentageHBD_D);
     Dgraph.exec();

}
bool Hbdtest::isComplat() const
{
    return m_isComplat;
}

void Hbdtest::setIsComplat(bool isComplat)
{
    m_isComplat = isComplat;
}

int Hbdtest::Age() const
{
    return m_Age;
}

void Hbdtest::setAge(int Age)
{
    m_Age = Age;
}

QString Hbdtest::family_name() const
{
    return m_family_name;
}

void Hbdtest::setFamily_name(const QString &family_name)
{
    m_family_name = family_name;
}

QString Hbdtest::NameObj() const
{
    return m_NameObj;
}

void Hbdtest::setNameObj(const QString &NameObj)
{
    m_NameObj = NameObj;
}

double Hbdtest::percentageHBD_D() const
{
    return m_percentageHBD_D;
}
void Hbdtest::setFamilyAndNameandAge(const QString &family_name,
                                     const QString &NameObj,
                                     int Age)
{
    m_Age = Age;  m_family_name = family_name;    m_NameObj = NameObj;
     setWindowTitle(m_NameObj+" "+m_family_name);


}
void Hbdtest::setPercentageHBD_D(double percentageHBD_D)
    {
        m_percentageHBD_D = percentageHBD_D;
    }

    double Hbdtest::percentageHBD_C() const
    {
        return m_percentageHBD_C;
    }

    void Hbdtest::setPercentageHBD_C(double percentageHBD_C)
    {
        m_percentageHBD_C = percentageHBD_C;
    }

    double Hbdtest::percentageHBD_B() const
    {
        return m_percentageHBD_B;
    }

    void Hbdtest::setPercentageHBD_B(double percentageHBD_B)
    {
        m_percentageHBD_B = percentageHBD_B;
    }

    double Hbdtest::percentageHBD_A() const
    {
        return m_percentageHBD_A;
    }

    void Hbdtest::setPercentageHBD_A(double percentageHBD_A)
    {
m_percentageHBD_A = percentageHBD_A;
}


void Hbdtest::on_pushButton_Next_2_clicked()
{
    ui->groupBox_4->hide();
    ui->groupBox->show();
}
