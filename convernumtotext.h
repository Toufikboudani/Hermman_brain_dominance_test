#ifndef CONVERNUMTOTEXT_H
#define CONVERNUMTOTEXT_H

#include <QObject>
#include <QStringList>

class ConverNumToText : public QObject
{
    Q_OBJECT
public:
    enum  language{AR,FR,EN};
    explicit ConverNumToText(QObject *parent = 0);
    explicit ConverNumToText(ConverNumToText::language lan,QObject *parent = 0);

    int getTybemylanguage() const;
    void setTybemylanguage(int mlang);
    QString ConverDoubleToText(double Numb);
    static QString getTextConver(int lan, double Numebr);
    static QString getTextConver(int lan, double Numebr,
                                 bool mStrInterval,
                                 const QString &mDinar,
                                 const QString &mCentimes);
     QString getDinar() const;
    void setDinar(const QString &value);

    QString getCentimes() const;
    void setCentimes(const QString &value);





    bool SInterval() const;
    void setSInterval(bool SInterval);

private:
    bool     m_SInterval;
    int Tybemylanguage;
    static int Lang;
    QStringList Units;
    QStringList Units10;
    QStringList Dozens;
    QStringList Hundreds;
    QStringList centaines;

    QStringList Thousand;
    QStringList Milion;
    QStringList Billion;

    QString  StrHundreds;
    QString  StrThousands;
    QString  StrMillions;
    QString  StrBillions;
    QString  StrInterval;

    QString  StringFormat;
    QString  And;
    QString  Dinar;
    QString  Centimes;

    QString ConverNumGHunArabe(int Num);
    QString ConverNumGHunEnglish(int Num);
    QString ConverNumGHunFrancais(int Num);
    QString ConverNumGreaterHunArabe(int Num, QStringList GreaterHun);
    QString ConverNumGreaterHunFrancais(int Num, QStringList GreaterHun);
    QString ConverNumGreaterHunEnglish(int Num, QStringList GreaterHun);
signals:

public slots:

};

#endif // CONVERNUMTOTEXT_H
