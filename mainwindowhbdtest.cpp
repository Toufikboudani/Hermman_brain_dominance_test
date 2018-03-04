#include "mainwindowhbdtest.h"
#include "ui_mainwindowhbdtest.h"
#include "myqstandarditemmodel.h"
#include "mywstyle.h"
#include <QSettings>
#include "qspinboxdelegate.h"
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include "Hbdtest.h"
#include "dialogaddwigite.h"
#include "mygraph.h"
#include <QProgressDialog>
#include <QMessageBox>
#include "write_read_file.h"
#include <QFileDialog>
#include <QDebug>
#include "dialogaboutt.h"
#include <QClipboard>

MainWindowHbdtest::MainWindowHbdtest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowHbdtest)
{

    QFont F= qApp->font();
    F.setBold(true);
    this->setFont(F);
    ui->setupUi(this);



    QString color="#45a1fe";
    Model=new MyQStandardItemModel(0,Maxcolum);
    ui->tableView->setModel(Model);

    TypeList tap;
    tap<<QVariant::String<<QVariant::String<<QVariant::LongLong
      <<QVariant::Double<<QVariant::Double<<QVariant::Double<<QVariant::Double ;

    Model->setHeadertype(tap);


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
    Hheader->resizeSection(Name,200);
    Hheader->resizeSection(FName,200);
    Hheader->resizeSection(Age,100);
    Hheader->resizeSection(HBD_A,100);
    Hheader->resizeSection(HBD_B,100);
    Hheader->resizeSection(HBD_C,100);
    Hheader->resizeSection(HBD_D,100);
    connect(Hheader ,SIGNAL(sectionClicked(int)), this, SLOT(Header_H_Clicked(int)));
  //  connect(vheader,SIGNAL(sectionClicked(int)), this, SLOT(Header_V_Clicked(int)));


    Model->setHeaderData(Name,Qt::Horizontal,"الإسم");
    Model->setHeaderData(FName,Qt::Horizontal,"الإسم العائلي");
    Model->setHeaderData(Age,Qt::Horizontal,"العمر");
    Model->setHeaderData(HBD_A,Qt::Horizontal,"A");
    Model->setHeaderData(HBD_B,Qt::Horizontal,"B");
    Model->setHeaderData(HBD_C,Qt::Horizontal,"C");
    Model->setHeaderData(HBD_D,Qt::Horizontal,"D");


    Hheader->resizeSection(Name,170);
    Hheader->resizeSection(FName,170);
    Hheader->resizeSection(Age,65);
    Hheader->resizeSection(HBD_A,50);
    Hheader->resizeSection(HBD_B,50);
    Hheader->resizeSection(HBD_C,50);
    Hheader->resizeSection(HBD_D,50);

        Model->AppendColumNotEditable(HBD_A);
        Model->AppendColumNotEditable(HBD_B);
        Model->AppendColumNotEditable(HBD_C);
        Model->AppendColumNotEditable(HBD_D);

    QSpinBoxDelegate *SpinBoxDelegate=new QSpinBoxDelegate(this);
    SpinBoxDelegate->setMaximum(200);
    SpinBoxDelegate->setMinimum(1);

    ui->tableView->setItemDelegateForColumn(Age,SpinBoxDelegate);

    TestHBDAction= new QAction(QIcon(":/image/BackZ.png"),"إختبار هيرمن للعضو",this);
    ShowTestHBDAction= new QAction(QIcon(":/image/hbd_test.png"),"عرض الخريطة",this);
    DeleteAction= new QAction(QIcon(":/image/del1.png"),"حذف",this);

    CopyAction= new QAction(QIcon(":/image/Copy.png"),"نسخ الييانات",this);

    TestHBDAction->setShortcut(QApplication::translate("MainWindowHbdtest", "Ctrl+T", 0));
    ShowTestHBDAction->setShortcut(QApplication::translate("MainWindowHbdtest", "Ctrl+H", 0));
    DeleteAction->setShortcut(QApplication::translate("MainWindowHbdtest", "Del", 0));
    CopyAction->setShortcut(QApplication::translate("MainWindowHbdtest", "Ctrl+C", 0));


    pContextMenutable  = new QMenu(this);
    F.setPixelSize(14);
    pContextMenutable->setFont(F);
    pContextMenutable->addAction(TestHBDAction); //
    pContextMenutable->addAction(ShowTestHBDAction); //
    pContextMenutable->addAction(DeleteAction); //
    pContextMenutable->addAction(CopyAction); //

    addAction(TestHBDAction); //
    addAction(ShowTestHBDAction); //
    addAction(DeleteAction); //
    addAction(CopyAction); //

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);


    connect( ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_displayMenuTable(QPoint)));
    connect(TestHBDAction, SIGNAL(triggered()), this, SLOT(on_TestHBDAction_triggered()));
    connect(ShowTestHBDAction, SIGNAL(triggered()), this, SLOT(on_ShowTestHBDAction_triggered()));
    connect(DeleteAction, SIGNAL(triggered()), this, SLOT(on_DeleteAction_triggered()));
    connect(CopyAction, SIGNAL(triggered()), this, SLOT(Copy()));
    connect(Model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(on_itemChanged(QStandardItem*)));












    QSettings SettingsCur("MainWindowHbdtest","myapp");
    SettingsCur.beginGroup("MainWindowHbdtest");
    m_FileNameApp=SettingsCur.value("m_FileNameApp").toString();
    SettingsCur.endGroup();


    if (m_FileNameApp.isEmpty()) {
        m_FileNameApp=qApp->applicationDirPath();
    }else {


        // on_pushButtonopen_clicked();

        ui->centralwidget->setEnabled(true);
    }









on_actionNew_File_triggered();


}

MainWindowHbdtest::~MainWindowHbdtest()
{

    delete ui;
    delete  Model;
    delete TestHBDAction  ;
    delete ShowTestHBDAction  ;
    delete DeleteAction  ;
    delete CopyAction;
    delete pContextMenutable ;
}

void MainWindowHbdtest::on_itemChanged(QStandardItem *item)
{
    qDebug()<<"Item  = "<<item->data().toString();
    qDebug()<<"Item  = "<<item->index();
    ui->actionSave->setEnabled(true);
    ui->actionSave_AS->setEnabled(true);
    isSaved=false;


}

void MainWindowHbdtest::on_actionNew_File_triggered()
{

    if (!isSaved)
    {
        if(QMessageBox::question(this,"تحذير",
                                 "هل تريد حفظ الملف : ",
                                 "نعم",
                                 "لا"
                                 )==QMessageBox::NoButton)
        {
            on_actionSave_triggered();

        }
    }
    NameFile_Xml.clear();
    setWindowTitle(NameFile_Xml+" - Hbd_Test");

    Model->removeRows(0,Model->rowCount());
    ui->actionSave->setEnabled(false);
    ui->actionSave_AS->setEnabled(false);
    isSaved=true;
}

void MainWindowHbdtest::on_actionOpen_triggered()
{
    if (!isSaved)
    {
        if(QMessageBox::question(this,"تحذير",
                                 "هل تريد حفظ الملف : ",
                                 "نعم",
                                 "لا"
                                 )==QMessageBox::NoButton)
        {
            on_actionSave_triggered();

        }
    }

    m_FileName=m_FileNameApp;

    m_FileName= QFileDialog::getOpenFileName(this,tr("فتح الملف"),m_FileNameApp, "Files (*.HBD);File(*.HBD)");
    if (m_FileName.isEmpty()) {
        return;
    }

    NameFile_Xml=QFileInfo(m_FileName).fileName();
    this->setWindowTitle(NameFile_Xml+" - Hbd_Test");




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
    if (StrRow.isEmpty()) {
        return;
    }
    Model->removeRows(0,Model->rowCount());
    Model->insertRows(0,StrRow.size());

    for (int Row = 0; Row < StrRow.size(); ++Row) {
        //      QString ffg=  ;
        //      ffg.append(StrRow2.at(Row));
        QStringList datacolumRow_F=StrRow.at(Row).split("*=A@A=*", QString::KeepEmptyParts);
        if (datacolumRow_F.size()<Maxcolum) {
            return;
        }
        for (int col = 0; col < Maxcolum; ++col) {
            Model->setData( Model->index(Row,col),datacolumRow_F.at(col));
        }






    }
    ui->actionSave->setEnabled(false);
    isSaved=true;
}

void MainWindowHbdtest::on_actionSave_triggered()
{
    if (Model->rowCount()<=0) {
        return;
    }


    if (m_FileName.isEmpty()) {
        m_FileName= QFileDialog::getSaveFileName(this,tr("خقظ الملف"),qApp->applicationDirPath()+"/"+NameFile_Xml, "Files (*.HBD);File(*.HBD)");
        if (m_FileName.isEmpty()) {
            return;
        }
        qDebug()<<m_FileName;
    }


    QString text;

    for (int Row = 0; Row < Model->rowCount(); ++Row) {
        for (int col = 0; col <Model->columnCount(); ++col) {
            text.append( Model->data(Model->index(Row,col)).toString());
            text.append("*=A@A=*");
        }
        if (Row!=Model->rowCount()-1) {
            text.append("\n");
        }

    }

    Write_Read_File::Write_File(m_FileName,text);
    NameFile_Xml=QFileInfo(m_FileName).fileName();
    this->setWindowTitle(NameFile_Xml+" - Hbd_Test");


    ui->actionSave->setEnabled(false);
    isSaved=true;
}

void MainWindowHbdtest::on_actionSave_AS_triggered()
{
    if (Model->rowCount()<=0) {
        return;
    }
    m_FileName= QFileDialog::getSaveFileName(this,tr("حفظ الملف"),qApp->applicationDirPath()+"/"+NameFile_Xml, "Files (*.HBD);File(*.HBD)");
    if (m_FileName.isEmpty()) {
        return;
    }
    qDebug()<<m_FileName;
    /*else {
        if(QMessageBox::question(this,"تحذير",
                             "هل تريد حفظ الملف : ",
                                 "نعم",
                                 "لا"
                                 )==QMessageBox::NoButton)
        {
           on_actionSave_triggered();

        }
    }*/



    QString text;

    for (int Row = 0; Row < Model->rowCount(); ++Row) {
        for (int col = 0; col <Model->columnCount(); ++col) {
            text.append( Model->data(Model->index(Row,col)).toString());
            text.append("*=A@A=*");
        }
        if (Row!=Model->rowCount()-1) {
            text.append("\n");
        }

    }

    Write_Read_File::Write_File(m_FileName,text);
    ui->actionSave->setEnabled(false);
    isSaved=true;
    NameFile_Xml=QFileInfo(m_FileName).fileName();
    this->setWindowTitle(NameFile_Xml+" - Hbd_Test");

}

void MainWindowHbdtest::on_actionExit_triggered()
{
    this->close();
}

void MainWindowHbdtest::on_actionAbout_Hbd_Test_triggered()
{
    DialogAboutt abo(this);
    abo.setWindowTitle("عن البرنامج ");
    abo.exec();
}

void MainWindowHbdtest::on_actionHelp_triggered()
{

}

void MainWindowHbdtest::on_actionAdd_New_obj_triggered()
{
    QStandardItem* itm = new QStandardItem();
    Model->appendRow(itm);
    Model->setData(Model->index(Model->rowCount()-1,Age),15);


}

void MainWindowHbdtest::on_displayMenuTable(QPoint pos)
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();
    if (indexList.size()>0) {

        if (indexList.size()==1) {
           TestHBDAction->setEnabled(true);
        }else {
           TestHBDAction->setEnabled(false);
        }

        QContextMenuEvent*mContextMenuEvent=new QContextMenuEvent (QContextMenuEvent::Mouse,pos);
        pContextMenutable->exec( mContextMenuEvent->globalPos() );

        delete mContextMenuEvent;
        mContextMenuEvent = NULL;


    }
}

void MainWindowHbdtest::on_TestHBDAction_triggered()
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();
    if (indexList.isEmpty()) {
        return;
    }
    if (indexList.size()>1) {
        return;
    }


    Hbdtest Hbd_test(this);
    Hbd_test.setFamilyAndNameandAge(
                Model->data(Model->index(indexList.at(0).row(),Name)).toString(),
                Model->data(Model->index(indexList.at(0).row(),FName)).toString(),
                Model->data(Model->index(indexList.at(0).row(),Age)).toInt()
                );


    Hbd_test.exec();
    if (Hbd_test.isComplat()) {
        Model->setData(Model->index(indexList.at(0).row(),HBD_A),Hbd_test.percentageHBD_A()) ;
        Model->setData(Model->index(indexList.at(0).row(),HBD_B),Hbd_test.percentageHBD_B()) ;
        Model->setData(Model->index(indexList.at(0).row(),HBD_C),Hbd_test.percentageHBD_C()) ;
        Model->setData(Model->index(indexList.at(0).row(),HBD_D),Hbd_test.percentageHBD_D()) ;

    }

}

void MainWindowHbdtest::on_ShowTestHBDAction_triggered()
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();
    if (indexList.isEmpty()) {
        return;
    }
    Mygraph  Dgraph(this);
    if (indexList.size()==1) {
        Dgraph.setFamilyAndNameandAge(
                    Model->data(Model->index(indexList.at(0).row(),Name)).toString(),
                    Model->data(Model->index(indexList.at(0).row(),FName)).toString(),
                    Model->data(Model->index(indexList.at(0).row(),Age)).toInt()
                    );
        Dgraph.setPercentageHBD_A(Model->data(Model->index(indexList.at(0).row(),HBD_A)).toDouble());
        Dgraph.setPercentageHBD_B(Model->data(Model->index(indexList.at(0).row(),HBD_B)).toDouble());
        Dgraph.setPercentageHBD_C(Model->data(Model->index(indexList.at(0).row(),HBD_C)).toDouble());
        Dgraph.setPercentageHBD_D(Model->data(Model->index(indexList.at(0).row(),HBD_D)).toDouble());
        Dgraph.exec();
    }else {
        QString Group ="مجموعة" ;
        int AGEE=0;
        double m_percentageHBD_A=0.0;
        double m_percentageHBD_B=0.0;
        double m_percentageHBD_C=0.0;
        double m_percentageHBD_D=0.0;
        for (int i = 0; i < indexList.size(); ++i) {
            m_percentageHBD_A+=Model->data(Model->index(indexList.at(i).row(),HBD_A)).toDouble();
            m_percentageHBD_B+=Model->data(Model->index(indexList.at(i).row(),HBD_B)).toDouble();
            m_percentageHBD_C+=Model->data(Model->index(indexList.at(i).row(),HBD_C)).toDouble();
            m_percentageHBD_D+=Model->data(Model->index(indexList.at(i).row(),HBD_D)).toDouble();
            AGEE+=Model->data(Model->index(indexList.at(i).row(),Age)).toInt();
        }


        Dgraph.setFamilyAndNameandAge(
                    Group,
                    "معدل",
                    AGEE/indexList.size()
                    );

        Dgraph.setPercentageHBD_A(m_percentageHBD_A/(qreal)indexList.size());
        Dgraph.setPercentageHBD_B(m_percentageHBD_B/(qreal)indexList.size());
        Dgraph.setPercentageHBD_C(m_percentageHBD_C/(qreal)indexList.size());
        Dgraph.setPercentageHBD_D(m_percentageHBD_D/(qreal)indexList.size());
        Dgraph.exec();
    }




}

void MainWindowHbdtest::on_DeleteAction_triggered()
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();
    if (indexList.isEmpty()) {
        return;
    }
    int SizeList=indexList.size();

    QProgressDialog * pd = new QProgressDialog("حالة الحذف",
                                               "يتم الحذف",
                                               0,
                                               indexList.size(),this);
    pd->show();



    if(QMessageBox::question(this,"تحذير",
                             "هل تريد حذف العناصر التالية : ",
                             "نعم",
                             "لا"
                             )==QMessageBox::NoButton)
    {
        while (SizeList!=0) {
            SizeList--;
            Model->removeRow(indexList.at(SizeList).row());
            pd->setValue(indexList.size()-SizeList);
            if (pd->wasCanceled())
                break;

        }



    }






    pd->close(); delete pd; indexList.clear();


}




void MainWindowHbdtest::closeEvent(QCloseEvent *)
{
    if (!isSaved)
    {
        if(QMessageBox::question(this,"تحذير",
                                 "هل تريد حفظ الملف : ",
                                 "نعم",
                                 "لا"
                                 )==QMessageBox::NoButton)
        {
            on_actionSave_triggered();

        }
    }
    if (!m_FileName.isEmpty()) {
        QSettings SettingsCur("MainWindowHbdtest","myapp");
        SettingsCur.beginGroup("MainWindowHbdtest");
        SettingsCur.setValue("m_FileNameApp",m_FileName);
        SettingsCur.endGroup();
    }
}

void MainWindowHbdtest::on_m_movtop_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow >0) {

        Model->myMovRow(currentRow, currentRow-1);
        ui->tableView->selectRow(currentRow-1);

    }
    ui->tableView->setFocus();
}

void MainWindowHbdtest::on_m_movbot_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow <Model->rowCount()-1) {

        Model->myMovRow(currentRow, currentRow+1);

        ui->tableView->selectRow(currentRow+1);



    }
    // Model->setData(Model->index(currentRow+2,0),ui->tableView->palette().highlight(),Qt::TextColorRole);
    ui->tableView->setFocus();


}

void MainWindowHbdtest::on_m_movforst_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow >0) {
        Model->myMovRowFirst(currentRow);
        ui->tableView->selectRow(0);
    }
    ui->tableView->setFocus();

}

void MainWindowHbdtest::on_m_movlast_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow <Model->rowCount()-1) {
        Model->myMovRowLast(currentRow);
        ui->tableView->selectRow(Model->rowCount()-1);
    }
    ui->tableView->setFocus();
}
void MainWindowHbdtest::Header_H_Clicked(int col)
{
    if (Model->rowCount()<=0) {
        return;
    }
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
void MainWindowHbdtest::Copy()
{
    QItemSelectionModel * SelectionModel= ui->tableView->selectionModel();
    QModelIndexList indexList =SelectionModel->selectedRows();


    QString str;
    for (int i = 0; i < indexList.size(); ++i) {
        for (int col = 0; col < Model->columnCount(); ++col) {
            str.append( Model->headerData(col,Qt::Horizontal).toString()+" : ");
            str .append( Model->data(Model->index(indexList.at(i).row(),col)).toString()+"\n");

        }


    }

    QApplication::clipboard()->setText(str.left(str.length()-1));
    qDebug() << QApplication::clipboard()->text();
}

