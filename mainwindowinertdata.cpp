#include "mainwindowinertdata.h"
#include "ui_mainwindowinertdata.h"
#include "mygraph.h"
#include "myqstandarditemmodel.h"
#include "mycomboboxdelegate.h"
#include "mywstyle.h"
#include "write_read_file.h"
#include  <QDebug>
#include  <QFileDialog>
#include  <QSettings>


MainWindowinertdata::MainWindowinertdata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowinertdata)
{
    ui->setupUi(this);

 posindex=0;


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

    QSettings SettingsCur("MainWindowinertdata","myapp");
    SettingsCur.beginGroup("MainWindowinertdata");
    m_FileNameApp=SettingsCur.value("m_FileNameApp").toString();
    SettingsCur.endGroup();
    m_FileName="C:\\Users\\Toufik Bou\\Documents\\build-Hermman_brain_dominance_test-Desktop_Qt_5_2_1_MinGW_32bit-Release\\dataHBD.txt";
    if (m_FileNameApp.isEmpty()) {
        m_FileNameApp=qApp->applicationDirPath();
    }else {


        on_pushButtonopen_clicked();

        ui->centralwidget->setEnabled(true);
    }

}

MainWindowinertdata::~MainWindowinertdata()
{
    delete ui;
}

void MainWindowinertdata::on_pushButtonADD_clicked()
{

}

void MainWindowinertdata::on_pushButtonSave_clicked()
{
    if (m_FileName.isEmpty()) {
        m_FileName= QFileDialog::getSaveFileName(this,tr("Save file"),qApp->applicationDirPath()+"/"+NameFile_Xml, "Files (*.xml);File(*.xml)");
        if (m_FileName.isEmpty()) {
            return;
        }
        qDebug()<<m_FileName;
    }


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


    Write_Read_File::Write_File(m_FileName,text);
    if (Undo_Redo.indexOf(text)<0) {
        Undo_Redo.append(text);posindex=Undo_Redo.size()-1;
    }
  pvrevee();

}
MyQStandardItemModel *MainWindowinertdata::getMModel() const
{
    return mModel;
}

void MainWindowinertdata::setMModel(MyQStandardItemModel *value)
{
    mModel = value;
}

void MainWindowinertdata::on_pushButtonopen_clicked()
{

    m_FileName=m_FileNameApp;
     Undo_Redo.clear();
    m_FileName= QFileDialog::getOpenFileName(this,tr("Inert Data"),m_FileNameApp, "Files (*.txt);File(*.txt)");
    if (m_FileName.isEmpty()) {
        return;
    }

    NameFile_Xml=QFileInfo(m_FileName).fileName();
    this->setWindowTitle(NameFile_Xml);




    QString Read_F;
  //  QString Read_F2;

//    Write_Read_File::Read_File(QString(m_FileName).replace("dataHBD.txt","data.txt"),Read_F2);
    Write_Read_File::Read_File(m_FileName,Read_F);
    qDebug()<<"Write_Read_File    "<<Read_F;
  //  qDebug()<<"Write_Read_File    "<<Read_F2;
    if (Read_F.isEmpty()) {
        return;
    }


    QStringList StrRow= Read_F.split("\n", QString::SkipEmptyParts);
    if (StrRow.size()!=56) {
        return;
    }
//    QStringList StrRow2= Read_F2.split("\n", QString::SkipEmptyParts);
//    if (StrRow2.size()!=56) {
//        return;
//    }

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
//      QString ffg=  ;
//      ffg.append(StrRow2.at(Row));
        QStringList datacolumRow_F=StrRow.at(Row).split("*=A@A=*", QString::KeepEmptyParts);
        if (datacolumRow_F.size()<3) {
            return;
        }
        for (int col = 0; col < 3; ++col) {
            mModel->setData( mModel->index(Row,col),datacolumRow_F.at(col));
        }






    }

     Undo_Redo.clear();

     if (Undo_Redo.indexOf(Read_F)<0) {
         Undo_Redo.append(Read_F);
         posindex=Undo_Redo.size()-1;
     }

   pvrevee();
}

void MainWindowinertdata::pvrevee()
{
    if (posindex<=0) {
      ui->actionUndo->setEnabled(false);
      ui->actionRedo->setEnabled(true);
    }else if (posindex==Undo_Redo.size()-1) {
        ui->actionUndo->setEnabled(true);
        ui->actionRedo->setEnabled(false);
    }else {
        ui->actionRedo->setEnabled(true);
        ui->actionUndo->setEnabled(true);
    }
    if (Undo_Redo.size()<=1) {
        ui->actionRedo->setEnabled(false);
        ui->actionUndo->setEnabled(false);
    }
}

void MainWindowinertdata::on_actionUndo_triggered()
{
    posindex--;
    if (posindex<0) {
      posindex=0;
    }
   pvrevee();


   if (Undo_Redo.isEmpty()) {
        return;
    }

    QStringList StrRow= Undo_Redo.at(posindex).split("\n", QString::SkipEmptyParts);
    if (StrRow.size()!=56) {
        return;
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

void MainWindowinertdata::on_actionRedo_triggered()
{
    posindex++;
    if (posindex>Undo_Redo.size()-1) {
      posindex=Undo_Redo.size()-1;
    }
   pvrevee();
    if (Undo_Redo.isEmpty()) {
        return;
    }

    QStringList StrRow= Undo_Redo.at(posindex).split("\n", QString::SkipEmptyParts);
    if (StrRow.size()!=56) {
        return;
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

void MainWindowinertdata::on_actionOpen_triggered()
{
    on_pushButtonopen_clicked();
}

void MainWindowinertdata::on_actionSave_triggered()
{
    on_pushButtonSave_clicked();
}

void MainWindowinertdata::on_actionSave_As_triggered()
{

    m_FileName= QFileDialog::getSaveFileName(this,tr("Save file"),qApp->applicationDirPath()+"/"+NameFile_Xml, "Files (*.txt);File(*.txt)");
    if (m_FileName.isEmpty()) {
        return;
    }
    qDebug()<<m_FileName;
    NameFile_Xml=QFileInfo(m_FileName).fileName();
    this->setWindowTitle(NameFile_Xml);



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


    Write_Read_File::Write_File(m_FileName,text);
    Undo_Redo.clear();
     Write_Read_File::Write_File(m_FileName,text);
     if (Undo_Redo.indexOf(text)<0) {
         Undo_Redo.append(text);posindex=Undo_Redo.size()-1;
     }
  pvrevee();
}

void MainWindowinertdata::on_actionAbout_triggered()
{

}
void MainWindowinertdata::closeEvent(QCloseEvent *)
{
    if (!m_FileName.isEmpty()) {
        QSettings SettingsCur("MainWindowinertdata","myapp");
        SettingsCur.beginGroup("MainWindowinertdata");
        SettingsCur.setValue("m_FileNameApp",m_FileName);
        SettingsCur.endGroup();
    }

}
