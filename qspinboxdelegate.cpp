#include "qspinboxdelegate.h"


QSpinBoxDelegate::QSpinBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    Minimum=0;
    Maximum=999999;
}

QSpinBoxDelegate::~QSpinBoxDelegate()
{

}
QWidget *QSpinBoxDelegate::createEditor( QWidget *parent,
                                         const QStyleOptionViewItem &/*option*/,
                      const QModelIndex &/*index*/ ) const
{

    QSpinBox *meditor=new QSpinBox(parent);;
    meditor->setMinimum(Minimum);
    meditor->setMaximum(Maximum);

    meditor->setAlignment(Qt::AlignVCenter|Qt::AlignRight);



    // *OldmIndex=index;

    return meditor;

}

void QSpinBoxDelegate::setEditorData( QWidget *editor,
                       const QModelIndex &index ) const
{
    QSpinBox *meditor=static_cast<QSpinBox*>(editor);

    meditor->setValue(index.data().toInt());

}

void QSpinBoxDelegate::setModelData( QWidget *editor,
                                     QAbstractItemModel *model,
                                     const QModelIndex &index ) const
{
    QSpinBox *meditor=static_cast<QSpinBox*>(editor);





    model->setData(index,meditor->value());
    int mAlign=Qt::AlignVCenter|Qt::AlignRight;
    model->setData(index,mAlign,Qt::TextAlignmentRole);

}

void QSpinBoxDelegate::updateEditorGeometry( QWidget *editor,
                                             const QStyleOptionViewItem &option,
                                             const QModelIndex &/*index*/ ) const
{
    editor->setGeometry( option.rect );
}

int QSpinBoxDelegate::getMinimum() const
{
    return Minimum;
}

void QSpinBoxDelegate::setMinimum(int min)
{
    Minimum=min;
}

int QSpinBoxDelegate::getMaximum() const
{
    return Maximum;
}

void QSpinBoxDelegate::setMaximum(int max)
{
    Maximum=max;
}

