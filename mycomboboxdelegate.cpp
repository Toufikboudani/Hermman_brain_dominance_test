#include "mycomboboxdelegate.h"

MyComboBoxDelegate::MyComboBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

MyComboBoxDelegate::~MyComboBoxDelegate()
{

}
QWidget *MyComboBoxDelegate::createEditor( QWidget *parent,
                                         const QStyleOptionViewItem &/*option*/,
                      const QModelIndex &/*index*/ ) const
{

    QComboBox *meditor=new QComboBox(parent);
    meditor->clear();
    meditor->insertItems(0, QStringList()
     <<"A"
     <<"B"
     <<"C"
     <<"D"
    );

//    *dataOld = index.model()->data( index, Qt::DisplayRole );


//    // *OldmIndex=index;

    return meditor;

}

void MyComboBoxDelegate::setEditorData( QWidget *editor,
              const QModelIndex &index ) const
{
    QComboBox *meditor=static_cast<QComboBox*>(editor);

    meditor->setCurrentText(index.model()->data( index, Qt::DisplayRole ).toString());

}

void MyComboBoxDelegate::setModelData( QWidget *editor,
                                     QAbstractItemModel *model,
                                     const QModelIndex &index ) const
{
    QComboBox *meditor=static_cast<QComboBox*>(editor);




    model->setData(index,meditor->currentText());

}

void MyComboBoxDelegate::updateEditorGeometry( QWidget *editor,
                                             const QStyleOptionViewItem &option,
                                             const QModelIndex &/*index*/ ) const
{
    editor->setGeometry( option.rect );
}



