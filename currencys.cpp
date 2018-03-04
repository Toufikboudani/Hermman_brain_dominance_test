#include "currencys.h"
#include "ui_currencys.h"
#include <QDebug>

#include "write_read_file.h"
#include  "mywstyle.h"
#include  <QHeaderView>
#include  <QMessageBox>
Currencys::Currencys(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Currencys)
{
    ui->setupUi(this);
    Model=new MyQStandardItemModel(0,HaderMax);

    Model->setHeaderData(Country,Qt::Horizontal,"Country");
    Model->setHeaderData(Currency_HomeAR,Qt::Horizontal,"Currency Home Arabic");
    Model->setHeaderData(Currency_HomeFR,Qt::Horizontal,"Currency Home Francais");
    Model->setHeaderData(Currency_HomeEN,Qt::Horizontal,"Currency Home English");
    Model->setHeaderData(Currency_partsAR,Qt::Horizontal,"Currency Parts Arabic");
    Model->setHeaderData(Currency_partsFR,Qt::Horizontal,"Currency Parts Francais");
    Model->setHeaderData(Currency_partsEN,Qt::Horizontal,"Currency Parts English");
    ReadConty();
    ui->tableView->setModel(Model);
    QHeaderView *Vheader =  ui->tableView->verticalHeader();
    QHeaderView *Hheader =  ui->tableView->horizontalHeader();

    connect(Hheader ,SIGNAL(sectionClicked(int)), this, SLOT(Header_H_Clicked(int)));
    connect(Vheader ,SIGNAL(sectionClicked(int)), this, SLOT(Header_V_Clicked(int)));

  //  qDebug()<<"hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh5555555555555555555"<<"/n";

    QString color="#45a1fe";
    Vheader->setFixedWidth(50);
    Hheader->setFixedHeight(35);
    Hheader->setStyleSheet(MyWstyle::StyleStondareQHeader(color,this->font()));
    Vheader->setStyleSheet(MyWstyle::StylebutDelQHeader());
    Model->resetMorder();

    Hheader->resizeSection(Country,135);
    Hheader->resizeSection(Currency_HomeAR,135);
    Hheader->resizeSection(Currency_HomeFR,135);
    Hheader->resizeSection(Currency_HomeEN,135);
    Hheader->resizeSection(Currency_partsAR,135);
    Hheader->resizeSection(Currency_partsFR,135);
    Hheader->resizeSection(Currency_partsEN,135);
    ui->tableView->setStyleSheet(ui->tableView->styleSheet()+MyWstyle::StyleStondare_ItemSelected(" QTableView")+
                                 MyWstyle::StyleStondareTableCornerBut(color,this->font()));

}

Currencys::~Currencys()
{
    if (Model) {
       delete Model;
    }
    delete ui;
}

void Currencys::on_pushButtonNewContry_clicked()
{
    QStandardItem* itm = new QStandardItem();
    Model->appendRow(itm);
    QModelIndex mmIndex=ui->tableView->model()->index( Model->rowCount()-1,0, QModelIndex());


    ui->tableView->scrollTo(mmIndex);
    ui->tableView->setCurrentIndex(mmIndex);
    ui->tableView->edit(mmIndex);

}

void Currencys::on_buttonBox_accepted()
{
    QStringList Data;


     for (int row = 0; row < Model->rowCount(); ++row) {
          QStringList DataRow;
         for (int col = 0; col < HaderMax; ++col) {
              QString md=Model->data(Model->index(row,col)).toString();

              DataRow.append(md);

             }
          QString D=DataRow.join("*=A@A=*");
           D.remove("\n",Qt::CaseSensitive);
         Data.append(D);
   qDebug()<<DataRow.join("*=A@A=*");
     }
     qDebug()<<"SAv_Read_File    "<<Data.join("\n");


     Write_Read_File::Write_File("Currency.Cur",Data.join("\n"));

}

void Currencys::Header_H_Clicked(int col)
{
    qDebug()<<"toufik   order su"<<Model->getMorder().size();
    Model->setHorizontalHeaderlToolTip("CHONGE");
    if (Model->getMorder()[col]==Qt::AscendingOrder) {
        morder=Qt::DescendingOrder;
    }else {
        morder=Qt::AscendingOrder;
    }
    ui->tableView->sortByColumn(col,morder);
    Model->setMorder(col,morder);
    ui->tableView->selectColumn(col);
}

void Currencys::Header_V_Clicked(int row)
{
    QModelIndex mmIndex=ui->tableView->currentIndex().model()->index(row,0, QModelIndex());

    if(QMessageBox::question(this,"question !",
                             "Are you sure rowed this element  \n "
                             +ui->tableView->model()->data(mmIndex).toString()+("\n"))==QMessageBox::Yes)
    {

        Model->removeRow(row);


    }
}
MyQStandardItemModel *Currencys::getModel() const
{
    return Model;
}

void Currencys::setModel(MyQStandardItemModel *value)
{
    Model = value;
}


void Currencys::ReadConty()
{

       QString Read_F;


       Write_Read_File::Read_File("Currency.Cur",Read_F);
qDebug()<<"Write_Read_File    "<<Read_F;
       if (Read_F.isEmpty()) {
       return;
   }


   QStringList StrRow= Read_F.split("\n", QString::SkipEmptyParts);

       for (int Row = 0; Row < StrRow.size(); ++Row) {
           QStandardItem* itm = new QStandardItem();
           Model->appendRow(itm);
           QStringList datacolumRow_F=StrRow.at(Row).split("*=A@A=*", QString::KeepEmptyParts);
           if (datacolumRow_F.size()<HaderMax) {
               return;
           }
           for (int col = 0; col < HaderMax; ++col) {
               Model->setData( Model->index(Row,col),datacolumRow_F.at(col));
           }


       }



}


void Currencys::on_pushButtonCancel_clicked()
{
    if(QMessageBox::question(this,"question !",
                             "Are you sure you want to go out  \n " )==QMessageBox::Yes)
    {

     this->close();


    }
}

void Currencys::on_pushButton_Save_clicked()
{

    for (int row = 0; row < Model->rowCount(); ++row) {
        for (int col = 0; col <  Model->columnCount(); ++col) {
          QString dataTabl= Model->data(Model->index(row,col)).toString();
          dataTabl.remove(" ");
          if (dataTabl.isEmpty()) {
           QMessageBox::critical(this,"warning","exist in Row Nomber "+QString::number(row+1)+" is Empty");
          ui->label->setText("<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ff9900;\">  warning : exist in Row Nomber "+QString::number(row+1)+" is Empty </span></p></body></html>");
           return;
          }
        }
    }
    on_buttonBox_accepted();
    ui->label->setText("<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#1aaa10;\"> Saved </span></p></body></html>");
}

void Currencys::closeEvent(QCloseEvent *)
{
//  on_pushButtonCancel_clicked();
}

void Currencys::on_pushButton_Restore_clicked()
{
    if(QMessageBox::question(this,"question !",
                             "Are you sure you want to Restore Defaults   \n " )==QMessageBox::No)
    {

      return;


    }

  Model->removeRows(0,Model->rowCount());
    QString Read_F;


    Write_Read_File::Read_File(":/text/Currency.Cur",Read_F);
qDebug()<<"Write_Read_File    "<<Read_F;
    if (Read_F.isEmpty()) {
    return;
}


QStringList StrRow= Read_F.split("\n", QString::SkipEmptyParts);

    for (int Row = 0; Row < StrRow.size(); ++Row) {
        QStandardItem* itm = new QStandardItem();
        Model->appendRow(itm);
        QStringList datacolumRow_F=StrRow.at(Row).split("*=A@A=*", QString::KeepEmptyParts);
        if (datacolumRow_F.size()<HaderMax) {
            return;
        }
        for (int col = 0; col < HaderMax; ++col) {
            Model->setData( Model->index(Row,col),datacolumRow_F.at(col));
        }


    }

    ui->label->setText("<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#1aaa10;\"> Complete Restore </span></p></body></html>");

}
