#include "myqstandarditemmodel.h"
#include <QColor>
#include <QVariant>
#include <QDebug>
//#include <mycontact.h>

MyQStandardItemModel::MyQStandardItemModel(QObject *parent) :
    QStandardItemModel(parent)
{
    ColorDark=new QColor("#ec5715");
    ColorDiluted =new QColor("#ec8f15");

    ColorDarkColumFocus=new QColor(255,168,111);
    ColorDilutedColumFocus =new QColor(255,204,170);
    ColumFocus=-1;
    //    mConDataBase=NULL;
    //    this->sort();
    //    this->findItems();
    HorizontalHeaderlToolTip="";
    VerticalHeaderlToolTip="";
     Enblemorder=true;
     EroorQueryData="";
}

MyQStandardItemModel::MyQStandardItemModel(int rows, int columns, QObject *parent):
    QStandardItemModel(rows,columns,parent)
{
    //    ColorDark=new QColor(255,168,111);
    //    ColorDiluted =new QColor(255,204,170);
    ColorDark=new QColor("#ec5715");
    ColorDiluted =new QColor("#ec8f15");

    ColorDarkColumFocus=new QColor(255,168,111);
    ColorDilutedColumFocus =new QColor(255,204,170);
    ColumFocus=-1;
    HorizontalHeaderlToolTip="";
    VerticalHeaderlToolTip="";
     Enblemorder=true;
    EroorQueryData="";
}

MyQStandardItemModel::~MyQStandardItemModel()
{
    delete ColorDark;
    delete ColorDiluted;
    delete ColorDarkColumFocus;
    delete ColorDilutedColumFocus;
}

QVariant MyQStandardItemModel::data(const QModelIndex &index, int role) const
{


    QVariant value = QStandardItemModel::data (index, role);
    switch (role) {
    case Qt::BackgroundRole:{
        for (int i = 0; i <IndexColorPrivate.size(); ++i) {
            if (index.column()==IndexColorPrivate[i].column()&&index.row()==IndexColorPrivate[i].row()) {
                return qVariantFromValue (value);
            }
        }

        int row=index.row();
        QColor  ColorRow;

        if(index.column()==ColumFocus)
        {
            if(row%2==0)
            {ColorRow=*ColorDarkColumFocus;}
            else{ColorRow=*ColorDilutedColumFocus;}
        }else {
            if(row%2==0)
            {ColorRow=*ColorDark;}
            else{ColorRow=*ColorDiluted;}
        }



        return qVariantFromValue (ColorRow); // first attribute font color is red
    }
        break;
    case Qt::TextAlignmentRole:{

        if (HeadertypeF.size()>0){

            int mAlign=Qt::AlignVCenter|Qt::AlignLeft;
            if (    HeadertypeF[index.column()]==QVariant::Double||
                    HeadertypeF[index.column()]==QVariant::Int||
                    HeadertypeF[index.column()]==QVariant::LongLong ){
                mAlign=Qt::AlignVCenter|Qt::AlignRight;
                return qVariantFromValue(mAlign);
            }else {
                mAlign=Qt::AlignVCenter|Qt::AlignLeft;
                return qVariantFromValue(mAlign);
            }
        }

    }
        break;
    case Qt::DisplayRole:{
        if(value.type()==QVariant::Double)
        {

            return qVariantFromValue(QString::number(value.toDouble(), 'f', 2)+"  ") ;  // Format shows 2 decimals

        }else if (HeadertypeF.size()>index.column()) {
            if (HeadertypeF[index.column()]==QVariant::Double) {
                return qVariantFromValue(QString::number(value.toDouble(), 'f', 2)+"  ") ;  // Format shows 2 decimals
            }
        }

        if (HeadertypeF.size()>index.column()) {
          // qDebug()<<HeadertypeF;
            if (HeadertypeF[index.column()]==QVariant::Int) {
                return qVariantFromValue(QVariant(value).toInt()) ;  // Format shows 2 decimals
            }
            if (HeadertypeF[index.column()]==QVariant::LongLong) {
                return qVariantFromValue(QVariant(value).toLongLong()) ;  // Format shows 2 decimals
            }
        }


        //           if (HeadertypeF.size()>0){
        //               if(value.type()==QVariant::Double||HeadertypeF[index.column()]==QVariant::Double)
        //               {

        //               return qVariantFromValue(QString::number(value.toDouble(), 'f', 2)+"  ") ;  // Format shows 2 decimals

        //               }
        //           }
    }
        break;
    case Qt::ToolTipRole :{
        return qVariantFromValue(index.model()->data(index).toString()) ;



    }
        break;
    case Qt::FontRole:{
        //            if(index.column()==ColumFocus)
        //            {
        //                  Qfont
        //                return qVariantFromValue(QString::number(value.toDouble(), 'f', 2)+"  ") ;  // Format shows 2 decimals

        //            }
    }
    case Qt::TextColorRole:{
        if(index.column()==ColumFocus)
        {

            return qVariantFromValue(QColor(255,72,72)) ;  // Format shows 2 decimals

        }
    }
    case Qt::EditRole:{
        if(value.type()==QVariant::Double)
        {

            return qVariantFromValue(QString::number(value.toDouble(), 'f', 2)+"  ") ;  // Format shows 2 decimals

        }
    }
        break;
    default:
        break;
    }

    return value;
}

bool MyQStandardItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role==Qt::EditRole||role==Qt::DisplayRole) {
        if (Enblemorder) {
           resetMorder();
        }
        if (HeadertypeF.size()>0){
            if (HeadertypeF[index.column()]==QVariant::Double){
                QVariant  mvalue=value;
                DoubleTocheckdata(mvalue);
                 bool ls= QStandardItemModel::setData(index,mvalue,role);
                 return ls;
            }
        }
//        QVariant  mvalue=value;
//        DoubleTocheckdata(mvalue);
//       bool ls= QStandardItemModel::setData(index,mvalue,role);
    }

    return QStandardItemModel::setData(index,value,role);
}

QVariant MyQStandardItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    QVariant value = QStandardItemModel::headerData(section,orientation,role);
    switch (role) {
    case Qt::DisplayRole:{
        if(orientation==Qt::Vertical && value.type()==QVariant::String)
        {

            return qVariantFromValue("  "+value.toString()+" ") ;  // Format shows 2 decimals

        }

    }
        break;
    case Qt::ToolTipRole :{
        if(orientation==Qt::Vertical)
        {
            if (VerticalHeaderlToolTip.isEmpty()) {
                return qVariantFromValue(headerData(section,Qt::Vertical).toString()) ;
            } else {
                QString html= "<html><head/><body><p><span>"+VerticalHeaderlToolTip+"</span><span style=\" font-weight:600; color:#ff5500;\" Delete >"+data(index(section,1)).toString()+"</span></p></body></html>";
                return qVariantFromValue(html) ;
            }
            // Format shows 2 decimals
        }
        if(orientation==Qt::Horizontal)
        {
            if (HorizontalHeaderlToolTip.isEmpty()) {
                return qVariantFromValue(headerData(section,Qt::Horizontal)) ;
            } else {
                QString html="";
                if (morder[section]==Qt::AscendingOrder) {
                    html= "<html><head/><body><p><span><img src=\":/image/botom.png\"/> ترتيب تنازلي في </span><span style=\" font-weight:600; color:#ff5500;\">"+headerData(section,Qt::Horizontal).toString()+"</span></p></body></html>";


                } else {
                    html= "<html><head/><body><p><span><img src=\":/image/top.png\"/> ترتيب تصاعدي في </span><span style=\" font-weight:600; color:#ff5500;\">"+headerData(section,Qt::Horizontal).toString()+"</span></p></body></html>";
                }
                return qVariantFromValue(html) ;
            }
        }
    }
        break;
    case Qt::FontRole:{
        break;
    }
    case Qt::TextColorRole:{

        return qVariantFromValue(QColor("#45a1fe")) ;  // Format shows 2 decimals
    }
    case Qt::EditRole:{
        if(orientation==Qt::Vertical && value.type()==QVariant::String)
        {

            return qVariantFromValue("  "+value.toString()+" ") ;  // Format shows 2 decimals

        }
    }
        break;
    default:
        break;
    }

    return value;
}

Qt::ItemFlags MyQStandardItemModel::flags( const QModelIndex &index) const
{
    Qt::ItemFlags flags = QStandardItemModel::flags(index);

    if (ColumNotEditable.size()>0) {
        for (int col = 0; col <ColumNotEditable.size(); ++col) {
            if(index.column()==ColumNotEditable[col]){
                flags =(QStandardItemModel::flags(index) & ~Qt::ItemIsEditable);;
                break;
            }
        }
    }
    if (RowNotEditable.size()>0) {
        for (int mRow = 0; mRow <RowNotEditable.size(); ++mRow) {
            if(index.row()==RowNotEditable[mRow]){
                flags =(QStandardItemModel::flags(index) & ~Qt::ItemIsEditable);;
                break;
            }
        }
    }
    return flags;



}

void MyQStandardItemModel::AppendColumNotEditable(const int &colum)
{
    ColumNotEditable.append(colum);
}
void MyQStandardItemModel::AppendRowNotEditable(const int &row)
{
    RowNotEditable.append(row);
}
QModelIndexList MyQStandardItemModel::getIndexColorPrivate() const
{
    return IndexColorPrivate;
}

void MyQStandardItemModel::setIndexColorPrivate(const QModelIndexList &value)
{
    IndexColorPrivate = value;
}


int MyQStandardItemModel::SearchIncolumn(QVariant &valueSearch, const int &columSearch)
{
    for (int Row = 0; Row < this->rowCount(); ++Row) {

        if (valueSearch.toString()==this->data(this->index(Row,columSearch)).toString()) {
            return Row;
        }

    }
    return -1;
}
int MyQStandardItemModel::getColumFocus() const
{
    return ColumFocus;
}

void MyQStandardItemModel::setColumFocus(int value)
{
    ColumFocus = value;
}
ColumNotEditableList MyQStandardItemModel::getRowNotEditable() const
{
    return RowNotEditable;
}

void MyQStandardItemModel::setRowNotEditable(const ColumNotEditableList &value)
{
    RowNotEditable = value;
}


QColor MyQStandardItemModel::getColorDark() const
{
    return *ColorDark;
}

void MyQStandardItemModel::setColorDark(QColor value)
{
    *ColorDark = value;
}
QColor MyQStandardItemModel::getColorDiluted() const
{
    return *ColorDiluted;
}

void MyQStandardItemModel::setColorDiluted(QColor value)
{
    *ColorDiluted = value;
}

void MyQStandardItemModel::setColorDarkDiluted(const QColor &Dark, const QColor &Diluted)
{
    *ColorDiluted = Diluted;
    *ColorDark = Dark;
}

void MyQStandardItemModel::setColorDarkDilutedColumFocus(const QColor &Dark, const QColor &Diluted)
{
    *ColorDilutedColumFocus = Diluted;
    *ColorDarkColumFocus = Dark;
}
bool MyQStandardItemModel::myMovRowFirst(int sourceRow)
{
    if (sourceRow >=rowCount()||
            sourceRow<1) {
        return false;
    }
    QVariantList mListdatasource;
    for (int col = 0; col < columnCount(); ++col) {
        mListdatasource.append(data(index(sourceRow,col)));
    }

    this->removeRow(sourceRow);
    this->insertRow(0);
    for (int col = 0; col < columnCount(); ++col) {
        setData(index(0,col) , mListdatasource[col]);
    }
    return true;
}
bool MyQStandardItemModel::myMovRowLast(int sourceRow)
{
    int mRowLast= rowCount()-1;
    if (sourceRow >= mRowLast||sourceRow<0) {
        return false;
    }
    QVariantList mListdatasource;
    for (int col = 0; col < columnCount(); ++col) {
        mListdatasource.append(data(index(sourceRow,col)));
    }

    this->removeRow(sourceRow);
    this->insertRow(rowCount());
    mRowLast= rowCount()-1;
    for (int col = 0; col < columnCount(); ++col) {
        setData(index(mRowLast,col) , mListdatasource[col]);
    }
    return true;
}
QString MyQStandardItemModel::getHorizontalHeaderlToolTip() const
{
    return HorizontalHeaderlToolTip;
}

void MyQStandardItemModel::setHorizontalHeaderlToolTip(const QString &value)
{
    HorizontalHeaderlToolTip = value;
}
QString MyQStandardItemModel::getVerticalHeaderlToolTip() const
{
    return VerticalHeaderlToolTip;
}

void MyQStandardItemModel::setVerticalHeaderlToolTip(const QString &value)
{
    VerticalHeaderlToolTip = value;
}
QList<Qt::SortOrder> MyQStandardItemModel::getMorder() const
{
    return morder;
}

void MyQStandardItemModel::setMorder(int section, const Qt::SortOrder &value)
{
    if (section>morder.size()-1) {
     return;
    }

      morder[section]=value;

    for (int msecsion = 0; msecsion <morder.size(); ++msecsion) {
        if (section==msecsion) {

            if (morder[section]==Qt::AscendingOrder) {
                horizontalHeaderItem(msecsion)->setIcon(QIcon(":/image/top.png"));

            } else {
                horizontalHeaderItem(msecsion)->setIcon(QIcon(":/image/botom.png"));
            }

        } else {
            morder[msecsion]=Qt::DescendingOrder;
            if (horizontalHeaderItem(msecsion)) {
               horizontalHeaderItem(msecsion)->setIcon(QIcon());
            }

        }
    }
}

void MyQStandardItemModel::resetMorder()
{
    morder.clear();
    for (int var = 0; var < columnCount(); ++var) {
        morder.append(Qt::AscendingOrder);
        if (horizontalHeaderItem(var)) {
           horizontalHeaderItem(var)->setIcon(QIcon());
        }


    }
}
bool MyQStandardItemModel::getEnblemorder() const
{
    return Enblemorder;
}

void MyQStandardItemModel::setEnblemorder(bool value)
{
    Enblemorder = value;
}
QString MyQStandardItemModel::getEroorQueryData() const
{
    return EroorQueryData;
}

void MyQStandardItemModel::setEroorQueryData(const QString &value)
{
    EroorQueryData = value;
}






bool MyQStandardItemModel::myMovRow(int sourceRow,int destinationChild)
{
    if (sourceRow>rowCount()-1||destinationChild>rowCount()-1||
            sourceRow<0||destinationChild<0) {
        return false;
    }
    QVariantList mListdatasource;
    QVariantList mListdatadestination;

    for (int col = 0; col < columnCount(); ++col) {
        mListdatasource.append(data(index(sourceRow,col)));
        mListdatadestination.append(data(index(destinationChild,col)));
    }
    for (int col = 0; col < columnCount(); ++col) {
        setData(index(sourceRow,col),mListdatadestination[col]);
        setData(index(destinationChild,col) , mListdatasource[col]);
    }
    return true;
}
//MyContact *MyQStandardItemModel::getMConDataBase() const
//{
//    return mConDataBase;
//}

//void MyQStandardItemModel::setMConDataBase(MyContact *value)
//{
//    mConDataBase = value;
//    if (mConDataBase) {
//        *ColorDiluted = mConDataBase->getColorDiluted();
//        *ColorDark = mConDataBase->getColorDark();

//    }

//}
TypeList MyQStandardItemModel::Headertype() const
{
    return HeadertypeF;
}

void MyQStandardItemModel::setHeadertype(const TypeList &value)
{
    HeadertypeF = value;
}
void MyQStandardItemModel::DoubleTocheckdata(QVariant & value)
{
    QString check="0123456789.";
    QString val=value.toString();
    bool ok=true;
    if(val[0]=='.')
    {ok=false;}
    if(val.indexOf('.')==-1)
    {ok=false;}
    if(ok){
        for (int i = 0; i < val.length(); i++) {
            qDebug()<<check.indexOf(val[i])<<"/n";
            if(check.indexOf(val[i])==-1)
            {ok=false; break; }
        }

    }
    if(ok==true&&value.type()==QVariant::String){value.convert(QVariant::Double);}
}




















