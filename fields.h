#ifndef FIELDS_H
#define FIELDS_H
#include <QString>
#include <QVariant>
#include <QtSql/QSqlField>

class Fields
{
public:
    enum keyTybe {PRIMARY = 1,UNIQUE = 2,INDEX = 3,keyNULL = -1};
    QString Name ;
    QVariant val ;
    QVariant::Type type;
    QSqlField::RequiredStatus Required;
    bool isAutoValue;
    keyTybe key_Tybe;
    void Statuskey_Tybe(QString _keyTybe);


     Fields();
    ~Fields();
//     Fields& operator=(Fields &F);			// operator-= is used to subtract another Vector3D from this Vector3D.

     bool getIsAutoValue() const;
     void setIsAutoValue(bool value);
};
template<typename T> class QList;
typedef QList<Fields> FieldsList;
typedef QList<FieldsList> QListFieldsList;
typedef QList <QVariant::Type > TypeList;

#endif // FIELDS_H
