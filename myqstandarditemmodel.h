#ifndef MYQSTANDARDITEMMODEL_H
#define MYQSTANDARDITEMMODEL_H
#include "fields.h"
#include <QStandardItemModel>

template<typename T> class QList;
typedef QList<int> ColumNotEditableList;

//class MyContact;

class MyQStandardItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit MyQStandardItemModel(QObject *parent = 0);
    MyQStandardItemModel(int rows, int columns, QObject *parent = 0);
    ~MyQStandardItemModel();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value,
//                       int role = Qt::EditRole);
    QColor getColorDark() const;
    void setColorDark(QColor value);

    QColor getColorDiluted() const;
    void setColorDiluted(QColor value);
    void  setColorDarkDiluted(const QColor &Dark, const QColor &Diluted);
    void  setColorDarkDilutedColumFocus(const QColor &Dark, const QColor &Diluted);

//    MyContact *getMConDataBase() const;
//    void setMConDataBase(MyContact *value);
   bool myMovRow(int sourceRow, int destinationChild);

     TypeList Headertype() const;
    void setHeadertype(const TypeList &value);

    void DoubleTocheckdata(QVariant &value);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void AppendColumNotEditable(const int & colum);
    int SearchIncolumn(QVariant & valueSearch,const int & columSearch);

    int getColumFocus() const;
    void setColumFocus(int value);

    ColumNotEditableList getRowNotEditable() const;
    void setRowNotEditable(const ColumNotEditableList &value);

    void AppendRowNotEditable(const int &row);
    QModelIndexList getIndexColorPrivate() const;
    void setIndexColorPrivate(const QModelIndexList &value);

    bool myMovRowFirst(int sourceRow);
    bool myMovRowLast(int sourceRow);
    QString getHorizontalHeaderlToolTip() const;
    void setHorizontalHeaderlToolTip(const QString &value);

    QString getVerticalHeaderlToolTip() const;
    void setVerticalHeaderlToolTip(const QString &value);

    QList<Qt::SortOrder>  getMorder() const;
    void setMorder(int section,const Qt::SortOrder &value);
    void resetMorder();

    bool getEnblemorder() const;
    void setEnblemorder(bool value);

    QString getEroorQueryData() const;
    void setEroorQueryData(const QString &value);

signals:

public slots:
private slots:
private:
    QColor  *ColorDark ;
    QColor  *ColorDiluted ;
    QColor  *ColorDarkColumFocus ;
    QColor  *ColorDilutedColumFocus ;
   // MyContact * mConDataBase;
 TypeList HeadertypeF;
 ColumNotEditableList ColumNotEditable;
 ColumNotEditableList RowNotEditable;
 QModelIndexList IndexColorPrivate;

 QString HorizontalHeaderlToolTip;
 QString VerticalHeaderlToolTip;
 QList<Qt::SortOrder>  morder;
 bool Enblemorder;
 QString EroorQueryData;

 int ColumFocus;
};

#endif // MYQSTANDARDITEMMODEL_H
