#ifndef QSPINBOXDELEGATE_H
#define QSPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QSpinBox>
class QSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit QSpinBoxDelegate(QObject *parent = 0);

    ~QSpinBoxDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData( QWidget *editor,
                            QAbstractItemModel *model,
                            const QModelIndex &index ) const;

    void updateEditorGeometry(QWidget *editor,
                            const QStyleOptionViewItem &option, const QModelIndex &) const;


    int getMinimum() const;
    void setMinimum(int min);

    int getMaximum() const;
    void setMaximum(int max);

signals:

void editFinishe(const QVariant &dataOld,const QVariant &dataNew,const QModelIndex &index)const ;

public slots:

private:

    mutable int Minimum;
    mutable int Maximum;

};

#endif // QSPINBOXDELEGATE_H
