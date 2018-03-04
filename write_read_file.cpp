#include "write_read_file.h"
#include <QFile>
#include <QTextStream>

Write_Read_File::Write_Read_File(QObject *parent) :
    QObject(parent)
{
}

bool Write_Read_File::Write_File(const QString &fileName, const QString &Text)
{
    QFile file;
    QString s=file.encodeName(fileName);
    file.setFileName(s);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out (&file);
        out.setCodec("UTF-8");
        out<<Text;
       file.flush();
       file.close();
        return true;
    }else {
         file.close();
        return false;
    }
}

bool Write_Read_File::Read_File(const QString &fileName, QString &Text)
{
    QFile file;
    QString s=file.encodeName(fileName);
    file.setFileName(s);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream (&file);
        stream.setCodec("UTF-8");
        Text=stream.readAll();
        file.flush();
        file.close();
        return true;
    }else {
         file.close();
        return false;
    }

}



















