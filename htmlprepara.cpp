#include "htmlprepara.h"
#include <QApplication>
#include <QDebug>

HtmlPrepara::HtmlPrepara()

{
}
QString HtmlPrepara::PreparaCell(int SizeCell,int width,QString colorCell,
                                 QString text,int Sizetext,QString colortext)
{
    QString p;
    colorCell.insert(0,"#");
    colortext.insert(0,"#");
    // QString style=
    //         "<table style=\"border:1px solid yellowgreen;\">"
    //         "<tr>"
    //         "<td style=\"border:1px solid yellowgreen;\">Table cell 2</td>"
    //         "</tr>"
    //         "</table>";



    p= "<table border='"+QString::number(SizeCell)+"' width='"+QString::number(width)
            +"'> color ='"+colorCell+"'  <tbody> <tr  align=center><td>"+
            " <font  SIZE= '"+QString::number(Sizetext)+
            "' color ='"+colortext+"'> <b>"+text+"</b> </font></td></tr>"
            "</tbody></table>";


    return p;
}
QString HtmlPrepara::PreparaText(QString text,int Sizetext,QString colortext)
{
    QString p;
    colortext.insert(0,"#");
    p= " <font  SIZE= '"+QString::number(Sizetext)+
            "' color ='"+colortext+"'> <b>"+text+"</b> </font>";


    return p;
}
QString HtmlPrepara::PreparaText(QString NameObjact,QString text,int Sizetext,QString colortext)
{
    QString p;
    colortext.insert(0,"#");
    p= " <font  SIZE= '"+QString::number(Sizetext)+
            "' color ='"+colortext+"'> <b>"+text+"</b> </font>";


    return QApplication::translate(NameObjact.toStdString().c_str(),
                                   p.toStdString().c_str()
                                   ,0);
}
QString HtmlPrepara::PreparaText_href(QString NameObjact,QString text,int Sizetext,QString colortext)
{

    QString p;
    colortext.insert(0,"#");
    p=
            " <a href=\"whatever\"><font  SIZE= '"+QString::number(Sizetext)+
            "' color ='"+colortext+"'> <b>"+text+"</b> </font></a>";
    // qDebug() <<" ======================================="<<p;
    return QApplication::translate(NameObjact.toStdString().c_str(),
                                   p.toStdString().c_str()
                                   ,0);
}
// <a href="html_images.asp">HTML Images</a>
//QString HtmlPrepara::PreparaText_href(QString NameObjact,QString text,int Sizetext,QString colortext)
//{
//    QString p;
//    colortext.insert(0,"#");
//    p= " <font  SIZE= '"+QString::number(Sizetext)+
//            "' color ='"+colortext+"'> <b>"+text+"</b> </font>";


//    return QApplication::translate(NameObjact.toStdString().c_str(),
//                                   p.toStdString().c_str()
//                                  ,0);
//}



QString HtmlPrepara::PreparaTextbody(QString text,int Sizetext,QString colortext)
{
    QString p;
    colortext.insert(0,"#");
    p= "<HTML>"
            " <HEAD>"
            "</HEAD>"
            "<BODY DIR=\"RTL\" Align=\"right\" >"
         //   "<BR> <BR><BR> <BR><BR><BR> <BR><BR> <BR><BR> <BR><BR> <BR><BR><BR><BR><BR> <BR><BR><BR>"
            " <FONT Face=\"Arial\" COLOR=\""+colortext+"\" SIZE=\""+QString::number(Sizetext)+"\">"

            "<P Align=\"right\"><B>"+text+"</B></P>"

            "</FONT>"

            "</BODY>"
            "</HTML>";

    return p;
}
//spinBoxContainer_X->setToolTip(QApplication::translate("Barcode", "<html><head/><body><p>Container_X</p></body></html>", 0));
//#
QString HtmlPrepara::PreparastondarToolTip(QString NameObjact,QString text)
{
    //  <html><head/><body><p>Container_X</p></body></html>
    QString colortext="0000ff";
    int Sizetext=2;
    return QApplication::translate(NameObjact.toStdString().c_str(),
                                   HtmlPrepara::PreparaTextbody(text, Sizetext,colortext).toStdString().c_str(),
                                   0);

}
