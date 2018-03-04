#include "dialoginertdata.h"
#include "ui_dialoginertdata.h"
#include "myqstandarditemmodel.h"
#include "mycomboboxdelegate.h"
#include "mywstyle.h"
#include "write_read_file.h"
#include  <QDebug>


Dialoginertdata::Dialoginertdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoginertdata)
{
    ui->setupUi(this);
    QString color="#45a1fe";

    mModel=new MyQStandardItemModel(56,3);
     ui->tableView->setModel(mModel);

     TypeList tap;
     tap<<QVariant::Int<<QVariant::String<<QVariant::String ;
     mModel->setHeadertype(tap);
     MyComboBoxDelegate *delegate=new MyComboBoxDelegate(this);

     ui->tableView->setItemDelegateForColumn(1,delegate);


      QHeaderView *Hheader =  ui->tableView->horizontalHeader();
     QHeaderView *vheader =  ui->tableView->verticalHeader();
     Hheader->setIconSize(QSize(10,10));

     vheader->setFixedWidth(60);

     Hheader->setSectionResizeMode(QHeaderView::Interactive);
     Hheader->setStyleSheet(MyWstyle::StyleStondareQHeader(color,this->font()));


     ui->tableView->setStyleSheet(ui->tableView->styleSheet()+MyWstyle::StyleStondare_ItemSelected(" QTableView")+
                                  MyWstyle::StyleStondareTableCornerBut(color,this->font()));
     Hheader->setFixedHeight(30);

     vheader->setStyleSheet(MyWstyle::StyleStondareQHeader(color,this->font()));

//     connect(Hheader ,SIGNAL(sectionClicked(int)), this, SLOT(Header_H_Clicked(int)));
//     connect(vheader,SIGNAL(sectionClicked(int)), this, SLOT(Header_V_Clicked(int)));
     Hheader->resizeSection(0,50);
     Hheader->resizeSection(1,50);
     Hheader->resizeSection(2,800);






        mModel->setHeaderData(0,Qt::Horizontal,"الرقم");
        mModel->setHeaderData(1,Qt::Horizontal,"النمط");
        mModel->setHeaderData(2,Qt::Horizontal,"السؤال");
      for (int i = 0; i < mModel->rowCount(); ++i) {
         mModel->setData(mModel->index(i,0),i+1);
     }
      mModel->AppendColumNotEditable(0);
      mModel->AppendColumNotEditable(1);
}

Dialoginertdata::~Dialoginertdata()
{
    delete ui;
}

void Dialoginertdata::on_pushButtonADD_clicked()
{

}

void Dialoginertdata::on_pushButtonSave_clicked()
{
    QString text;

    for (int i = 0; i < mModel->rowCount(); ++i) {
      text.append( mModel->data(mModel->index(i,0)).toString());
      text.append("*=A@A=*");
      text.append( mModel->data(mModel->index(i,1)).toString());
      text.append("*=A@A=*");
      text.append( mModel->data(mModel->index(i,2)).toString());
      if (i!=mModel->rowCount()-1) {
          text.append("\n");
      }

    }


   Write_Read_File::Write_File("dataHBD.txt",text);
}
MyQStandardItemModel *Dialoginertdata::getMModel() const
{
    return mModel;
}

void Dialoginertdata::setMModel(MyQStandardItemModel *value)
{
    mModel = value;
}

void Dialoginertdata::on_pushButtonopen_clicked()
{


        QString Read_F;


        Write_Read_File::Read_File("dataHBD.txt",Read_F);
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
            for (int col = 0; col < 3; ++col) {
                mModel->setData( mModel->index(Row,col),datacolumRow_F.at(col));
            }






 }

}
