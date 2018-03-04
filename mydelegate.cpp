#include "mydelegate.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>
myDelegate::myDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    mIndex=new QModelIndex();
    OldmIndex=new QModelIndex();
    EnbeleUpdate=false;


    enbeleCompleter=false;
    m_isEditing =false;
    dataNew=new QVariant();
    dataOld=new QVariant();
    myDataBase=NULL;
    bold=true;
    PenTaxtSelect="";
}

myDelegate::~myDelegate()
{
    delete mIndex;
    delete OldmIndex;
    delete  dataNew;
    delete  dataOld;

}
void myDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV4 opt = option;

    QItemDelegate::paint(painter,option,index);
    const QWidget *widget = option.widget;
    QStyle *style = widget ? widget->style() : QApplication::style();

    if (option.state & QStyle::State_Selected)
    {
        if (PenTaxtSelect.isEmpty()) {
            painter->setPen(option.palette.highlightedText().color());
        } else {
            painter->setPen(PenTaxtSelect);
        }
        style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
        painter->drawText(option.rect, qvariant_cast<int>(index.data(Qt::TextAlignmentRole)),index.data().toString());
    }


}
QString myDelegate::getPenTaxtSelect() const
{
    return PenTaxtSelect;
}

void myDelegate::setPenTaxtSelect(const QString &value)
{
    PenTaxtSelect = value;
}
bool myDelegate::isEditing() const
{
    return m_isEditing;
}

void myDelegate::setEditing(bool isEditing)
{
    m_isEditing = isEditing;
}



bool myDelegate::getFontBold() const
{
    return bold;
}

void myDelegate::setFontBold(bool value)
{
    bold = value;
}

void myDelegate::DoubleTocheckdata(QVariant *value)const
{
    QString check="0123456789.";
    QString val=value->toString();
    val.remove(QChar(' '), Qt::CaseInsensitive);
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
    if(ok==true&&value->type()==QVariant::String){value->convert(QVariant::Double);}
    qDebug()<<"value      value->type() "<<value->type();
}
void myDelegate::SetEnbeleUpdate(bool mEnbeleUpdate)
{
    EnbeleUpdate=mEnbeleUpdate;
}
bool myDelegate::isEnbeleUpdate()
{
    return  EnbeleUpdate;
}
bool myDelegate::EnbeleCompleter(){
    return enbeleCompleter;
}
void myDelegate::SetEnbeleCompleter(bool enbele){
    enbeleCompleter= enbele;

}
void myDelegate::setConectDataBase(MyContact *mDataBase)
{
    myDataBase=mDataBase;
}
void myDelegate::SetTable(QString nameTable, int colum)
{
    nametabel=nameTable;
    colmnametabel=colum;
    enbeleCompleter= true;


}
void myDelegate::SetTable_Rela(QString nameTable, int colum)
{
    nametabel_Rela=nameTable;
    colmnametabel_Rela=colum;
    qDebug()<<" nametabel_Rela nametabel_Rela "<<nametabel_Rela<<"    "<<colmnametabel_Rela;

}
QModelIndex myDelegate::getMIndex() const
{
    return *mIndex;
}

void myDelegate::setMIndex(QModelIndex *value)
{
    mIndex = value;
}

