#ifndef MYCOMBOBOXDELEGATE_H
#define MYCOMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>

class MyComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MyComboBoxDelegate(QObject *parent = 0);

    ~MyComboBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData( QWidget *editor,
                       QAbstractItemModel *model,
                       const QModelIndex &index ) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &) const;




signals:


public slots:

private:



};


#endif // MYCOMBOBOXDELEGATE_H
