#ifndef WRITE_READ_FILE_H
#define WRITE_READ_FILE_H

#include <QObject>

class Write_Read_File : public QObject
{
    Q_OBJECT
public:
    explicit Write_Read_File(QObject *parent = 0);

   static bool Write_File(const QString & fileName,const  QString & Text);
   static bool Read_File(const QString & fileName, QString &Text);



signals:

public slots:

};

#endif // WRITE_READ_FILE_H
