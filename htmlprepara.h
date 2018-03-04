#ifndef HTMLPREPARA_H
#define HTMLPREPARA_H

#include <QObject>

class HtmlPrepara
{

public:
    explicit HtmlPrepara();
    static QString PreparaCell(int SizeCell,int width,QString colorCell,
                               QString text,int Sizetext,QString colortext);
    static QString PreparaText(QString NameObjact,QString text, int Sizetext, QString colortext);
    static QString PreparaText(QString text, int Sizetext, QString colortext);
    static QString PreparaTextbody(QString text,int Sizetext,QString colortext);
    static QString PreparaText_href(QString NameObjact,QString text, int Sizetext, QString colortext);
    static QString PreparastondarToolTip(QString NameObjact, QString text);

















signals:

public slots:

};

#endif // HTMLPREPARA_H
