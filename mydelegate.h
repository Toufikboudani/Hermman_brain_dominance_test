#ifndef MYDELEGATE_H
#define MYDELEGATE_H
enum mclassLineEdit
{
    L_E_String,
    L_E_intv,
    L_E_Doublev,
    L_E_bigint,
    L_E_SqlString,
    L_E_Sqlintv,
    L_E_SqlDoublev,
    L_E_Sqlbigint,
    L_E_Sql_Rela
 };
#include <QItemDelegate>
#include <mycontact.h>
#include <QVariant>
#include <QStyledItemDelegate>
class myDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit myDelegate(QObject *parent = 0);
    void setConectDataBase(MyContact *mDataBase);
    void DoubleTocheckdata(QVariant *value)const;
    MyContact *myDataBase;
    bool EnbeleUpdate;

    bool isEnbeleUpdate();
    void SetEnbeleUpdate(bool mEnbeleUpdate);

    bool EnbeleCompleter();
    void SetEnbeleCompleter(bool enbele);
    bool enbeleCompleter;

    QString nametabel;
    QString nametabel_Rela;
    int colmnametabel;
    int colmnametabel_Rela;
    void SetTable(QString nameTable,int colum);
    void SetTable_Rela(QString nameTable, int colum);
  mutable    QModelIndex *mIndex;
  mutable    QModelIndex *OldmIndex;


   ~myDelegate();

    bool getFontBold() const;
    void setFontBold(bool value);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QString getPenTaxtSelect() const;
    void setPenTaxtSelect(const QString &value);


    bool isEditing() const;
    void setEditing(bool isEditing);

    QModelIndex getMIndex() const;
    void setMIndex(QModelIndex *value);

signals:

    void editFinishe(const QVariant &dataOld,const QVariant &dataNew,const QModelIndex &index)const ;

public slots:
protected:
 mutable   QVariant *dataNew;
 mutable   QVariant *dataOld;
 mutable    QString PenTaxtSelect;

mutable Fields mFid;
mutable bool bold;
mutable bool m_isEditing;
};

#endif // MYDELEGATE_H
