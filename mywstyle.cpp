#include "mywstyle.h"
#include <QtDebug>
MyWstyle::MyWstyle(QObject *parent) :
    QObject(parent)
{
}


QString MyWstyle::Stondare_border(const QString mcolor)
{
    QString mStyle=       "border-width: 1px;"
            "border-style: solid;"
            //     "border-radius: 4px;"
            "border-color: "+mcolor+";"
            ;
    return mStyle;
}

QString MyWstyle::Stondare_setfont(QWidget * Widget,const QFont & f)
{

    QString mStyle= Widget->styleSheet();
    QString  str = mStyle.section("font-family:",-1);  // str == "middlename,surname"
    if (!str.isEmpty()) {
        str.insert(0,"font-family:");
        mStyle.remove(str);
    }
    qDebug() << mStyle+MyWstyle::Stondare_font(f)+"}";

    return mStyle+MyWstyle::Stondare_font(f)+"}";
}
QString MyWstyle::Stondare_font(const QFont & f)
{

    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: "+QString::number(f.weight())+"px;";
    }
    QString mStyle= "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight ;
    return mStyle;
}

QString MyWstyle::StyleQLineEdit(const QString mcolor)
{
    QString mStyle= "{border-width: 1px;"
            "border-style: solid;"
            //     " border-radius: 4px;"
            "border-color: "+mcolor+";"
            "}";
    return mStyle;
}

QString MyWstyle::StyleQComboBox(const QString mcolor)
{
    QString mStyle= "{border-width: 1px;"
            "border-style: solid;"
            //     " border-radius: 4px;"
            "border-color: "+mcolor+";"
            "}";
    return mStyle;
}

QString MyWstyle::StyleQListView(const QString mcolor)
{
    QString mStyle= "{border-width: 1px;"
            "border-style: solid;"
            //     " border-radius: 4px;"
            "border-color: "+mcolor+";"
            "}";
    return mStyle;
}

QString MyWstyle::StyleStondare(const QString mcolor,const QFont & f,const QString mcolorText)
{
    //    QString mStyle= "{    border-width: 1px;"
    //                          "border-style: solid;"
    //                   //     " border-radius: 4px;"
    //                           "border-color: "+mcolor+
    //            ";font-family:"+f.family()+"; font-style:"+
    //            f.styleName()+";font-size: "+QString::number(28)+";font-weight: bold"
    //            ";"
    //                    "}";

    //    setCentralWidget(edit);
    //    edit->setStyleSheet("font-family: Arial;font-style: normal;font-size: 12pt;font-weight: bold;");
    //    edit->setPlainText("Hello World");
    //    qDebug() << "Font: " << edit->font().family() << edit->font().pointSize();

    //    qDebug()<<mStyle;

    //    return mStyle;
    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: bold;";
    }



    QString mStyle= "{"
            "selection-color: white;"
            " border-style: solid;"
            " border: 2px solid gray;"
            "border-radius: 4px;"
            "padding: 3px;"
            "color: "+mcolorText+
            ";border-color: "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}";

    //   QString styleSheet = QString("font-size:%1px;").arg(QApplication::font().pointSize());
    //   qDebug() << mStyle;
    return mStyle;
}

QString MyWstyle::StyleStondare(QString Widget, const QString mcolor, const QFont &f,const QString mcolorText)
{

    QString mStyle=Widget+StyleStondare(mcolor, f,mcolorText)+"     "+
            Widget+":disabled"+StyleStondare("#767676", f,"#767676");
    qDebug() <<" ****************************************";
    qDebug() << mStyle;
    qDebug() << "*******************************************";

    //    QString mStyle=Widget+StyleStondare(mcolor, f)+"    "+
    //    Widget+":disabled"+StyleStondare("#767676", f);
    //    qDebug() << mStyle;
    //     return mStyle;
    return mStyle;

}
QString MyWstyle::StyleStondareQLineEdit(QString ColorSelect, const QString mcolor, const QFont &f,const QString mcolorText)
{

    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: bold;";
    }



    QString mStyle= "QLineEdit{ "
            "selection-color: white; "
            "selection-background-color: "+ColorSelect+";"
            " border-style: solid;"
            " border: 2px solid gray;"
            "border-radius: 4px;"
            "padding: 3px;"
            "color: "+mcolorText+
            ";border-color: "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QLineEdit:disabled{ "
            "selection-color: "+ColorSelect+"; "
            " border-style: solid;"
            " border: 2px solid gray;"
            "border-radius: 4px;"
            "padding: 3px;"
            "color: "+mcolorText+
            ";border-color: "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}";

    //   QString styleSheet = QString("font-size:%1px;").arg(QApplication::font().pointSize());
    //   qDebug() << mStyle;
    return mStyle;


}

QString MyWstyle::Stondare_ColorTaxtItemSelected()
{
    return "#000000";
}
QString MyWstyle::StyleStondare_Item(const QString &Widget)
{
    return     Widget+"::item"
            "{"
            " color:"+MyWstyle::Stondare_ColorTaxtItemSelected()+
            " ; background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #fffecb, stop: 0.1 #fbffcb, stop: 0.49 #fcff2f, stop: 0.5 #ffed1c, stop: 1 #fcffbd);"
            "}";
}
QString MyWstyle::StyleStondare_ItemSelected(const QString &Widget)
{
    return     Widget+"::item:selected"
            "{"
            " color:"+MyWstyle::Stondare_ColorTaxtItemSelected()+
            " ; background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #fffecb, stop: 0.1 #fbffcb, stop: 0.49 #fcff2f, stop: 0.5 #ffed1c, stop: 1 #fcffbd);"
            "}";
}
QString MyWstyle::StyleQcheckboxSwitch(int w,int h)
{
    return "QCheckBox { spacing:0px;}"

            "QCheckBox::indicator {"
            "width: "+QString::number(w)+"px;"
            "height:"+QString::number(h)+"px;"
            "}"

            "QCheckBox::indicator:unchecked {"
            "image: url(:/image/of.png);"
            "}"

            "QCheckBox::indicator:unchecked:hover {"
            "image: url(:/image/of.png);"
            " }"

            "QCheckBox::indicator:unchecked:pressed {"
            "image: url(:/image/on.png);"
            " }"

            " QCheckBox::indicator:checked {"
            " image: url(:/image/on.png);"
            " }"

            " QCheckBox::indicator:checked:hover {"
            "image: url(:/image/on.png);"
            "}"

            " QCheckBox::indicator:checked:pressed {"
            " image: url(:/image/of.png);"
            "  }"

            " QCheckBox::indicator:indeterminate:hover {"
            " image: url(:/image/of.png);"
            " }"

            " QCheckBox::indicator:indeterminate:pressed {"
            " image: url(:/image/of.png);"
            " }";

}
QString MyWstyle::StyleQRadioButtonSwitch(int w,int h)
{
    return "QRadioButton { spacing:0px;}"

            "QRadioButton::indicator {"
            "width: "+QString::number(w)+"px;"
            "height:"+QString::number(h)+"px;"
            "}"

            "QRadioButton::indicator:unchecked {"
            "image: url(:/image/of.png);"
            "}"

            "QRadioButton::indicator:unchecked:hover {"
            "image: url(:/image/of.png);"
            " }"

            "QRadioButton::indicator:unchecked:pressed {"
            "image: url(:/image/on.png);"
            " }"

            " QRadioButton::indicator:checked {"
            " image: url(:/image/on.png);"
            " }"

            " QRadioButton::indicator:checked:hover {"
            "image: url(:/image/on.png);"
            "}"

            " QRadioButton::indicator:checked:pressed {"
            " image: url(:/image/of.png);"
            "  }"

            " QRadioButton::indicator:indeterminate:hover {"
            " image: url(:/image/of.png);"
            " }"

            " QRadioButton::indicator:indeterminate:pressed {"
            " image: url(:/image/of.png);"
            " }";

}

QString MyWstyle::StyleQRadioButtonSwitch()
{
    return "QRadioButton { spacing:0px;}"

            "QRadioButton::indicator {"
            "width: 40px;"
            "height:20px;"
            "}"

            "QRadioButton::indicator:unchecked {"
            "image: url(:/image/of.png);"
            "}"

            "QRadioButton::indicator:unchecked:hover {"
            "image: url(:/image/of.png);"
            " }"

            "QRadioButton::indicator:unchecked:pressed {"
            "image: url(:/image/on.png);"
            " }"

            " QRadioButton::indicator:checked {"
            " image: url(:/image/on.png);"
            " }"

            " QRadioButton::indicator:checked:hover {"
            "image: url(:/image/on.png);"
            "}"

            " QRadioButton::indicator:checked:pressed {"
            " image: url(:/image/of.png);"
            "  }"

            " QRadioButton::indicator:indeterminate:hover {"
            " image: url(:/image/of.png);"
            " }"

            " QRadioButton::indicator:indeterminate:pressed {"
            " image: url(:/image/of.png);"
            " }";

}
QString MyWstyle::StyleQcheckboxSwitch()
{
    return "QCheckBox { spacing:0px;}"

            "QCheckBox::indicator {"
            "width: 40px;"
            "height:20px;"
            "}"

            "QCheckBox::indicator:unchecked {"
            "image: url(:/image/of.png);"
            "}"

            "QCheckBox::indicator:unchecked:hover {"
            "image: url(:/image/of.png);"
            " }"

            "QCheckBox::indicator:unchecked:pressed {"
            "image: url(:/image/on.png);"
            " }"

            " QCheckBox::indicator:checked {"
            " image: url(:/image/on.png);"
            " }"

            " QCheckBox::indicator:checked:hover {"
            "image: url(:/image/on.png);"
            "}"

            " QCheckBox::indicator:checked:pressed {"
            " image: url(:/image/of.png);"
            "  }"

            " QCheckBox::indicator:indeterminate:hover {"
            " image: url(:/image/of.png);"
            " }"

            " QCheckBox::indicator:indeterminate:pressed {"
            " image: url(:/image/of.png);"
            " }";

}

QString MyWstyle::StylebutDelQHeader()
{
    QString mStyle=  "QHeaderView::section {image:url(:/image/del.png);border:0px;}"
            "QHeaderView::section:hover {image:url(:/image/del1.png);border:0px; }"
            "QHeaderView::section:pressed{image:url(:/image/del2.png); position: relative;top: 1px; left: 1px;}";
    return mStyle;


}

QString MyWstyle::StyleStondareQHeader(const QString mcolor,const QFont & f)
{

    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: "+QString::number(f.weight())+"px;";
    }

    return "QHeaderView::section {"
           " color: white;"
           " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QHeaderView::section:hover {"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #78ceee, stop: 0.5 #e0eaec,"
            "stop: 0.6 #d5dddc, stop:1 #98ceee);"
            "color: #1891c9;"
            //            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QHeaderView::section:pressed{"
            " color: white;"
            " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
             "padding-left: 4px;"
             "text-align: center;"

             "border: 1px solid "+mcolor+";"
             "font-family:\""+f.family()+
             "\";font-size: "+QString::number(f.pointSize()+2)+"pt;"
             +fontweight+"}";




}

QString MyWstyle::StyleStondareButton(const QString mcolor,const QFont & f)
{
    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: "+QString::number(f.weight())+"px;";
    }

    return"QPushButton{"
         " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
         " color: white;"
            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QPushButton:hover{"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #78ceee, stop: 0.5 #e0eaec,"
            "stop: 0.6 #d5dddc, stop:1 #98ceee);"
            "color: #45a1fe;"
            //            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QPushButton:pressed{"
            " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
            " color: white;"

            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize()+2)+"pt;"
            +fontweight+"} ";

}

QString MyWstyle::StyleStondareTableCornerBut(const QString mcolor, const QFont &f)
{
    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: "+QString::number(f.weight())+"px;";
    }

    return"QTableView QTableCornerButton::section {"
            " color: white;"
            " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
             "padding-left: 4px;"
             "text-align: center;"

             "border: 1px solid "+mcolor+";"
             "font-family:\""+f.family()+
             "\";font-size: "+QString::number(f.pointSize())+"pt;"
             +fontweight+"}"

            "QTableView QTableCornerButton::section:hover{"
            "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #78ceee, stop: 0.5 #e0eaec,"
            "stop: 0.6 #d5dddc, stop:1 #98ceee);"
            "color: #45a1fe;"
            //            "padding-left: 4px;"
            "text-align: center;"

            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"}"
            "QTableView QTableCornerButton::section:pressed{"
            " color: white;"
            " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
             "padding-left: 4px;"
             "text-align: center;"

             "border: 1px solid "+mcolor+";"
             "font-family:\""+f.family()+
             "\";font-size: "+QString::number(f.pointSize()+2)+"pt;"
             +fontweight+"}"
            ;
}

QString MyWstyle::StyleStondareCombox(const QString mcolor, const QFont &f)
{
    QString fontweight="font-weight: "+QString::number(f.weight())+"px;";
    if (f.bold()) {
        fontweight="font-weight: bold;";
    } else {
        fontweight="font-weight: "+QString::number(f.weight())+"px;";
    }
    return   "QComboBox{"
            "subcontrol-origin: padding;"
            "subcontrol-position: top right;"
            "selection-background-color: #45a1fe;"
            "selection-color: yellow;"
            "color:  #45a1fe;   border-style: solid;"
            "border-radius: 5;"
            "padding: 1px 0px 1px 20px;"
            "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e6f2f6, stop: 0.1 #e2e8ea, stop: 0.5 #e8ebeb, stop: 0.9 #f0f5f5, stop: 1 #f0f5f5);"
            "border: 1px solid "+mcolor+";"
            "font-family:\""+f.family()+
            "\";font-size: "+QString::number(f.pointSize())+"pt;"
            +fontweight+"} ";

}

QString MyWstyle::StylebuttonAdd()
{
    return QLatin1String("QPushButton{background:url(:/image/Save.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Save.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Save.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Save.png);border:0px;}");

}

QString MyWstyle::StyleButtontheMan()
{
    return QLatin1String("QPushButton{background:url(:/image/DisplayValeu.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/DisplayValeu22.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/DisplayValeu23.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/DisplayValeu24.png);border:0px;}");

}

QString MyWstyle::StyleButtonCancelInvoice()
{
    return QLatin1String("QPushButton{background:url(:/image/CancelInvoice.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/CancelInvoice2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/CancelInvoice3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/CancelInvoice4.png);border:0px;}");

}

QString MyWstyle::StylebuttonInsert()
{
    return QLatin1String("QPushButton{background:url(:/image/Save.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Save2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Save3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Save4.png);border:0px;}");

}
QString MyWstyle::StylebuttonInsertLog()
{
    return QLatin1String("QPushButton{background:url(:/image/Savelog.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Savelog2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Savelog3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Savelog4.png);border:0px;}");

}
QString MyWstyle:: StylebuttonPrintEmpty()
{
    return QLatin1String("QPushButton{background:url(:/image/PrintPageEmpit.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/PrintPageEmpit2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/PrintPageEmpit3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/PrintPageEmpit4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSearch_All()
{
    return QLatin1String("QPushButton{background:url(:/image/searchAll.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/searchAll2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/searchAll3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/searchAll4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSearch()
{
    return QLatin1String("QPushButton{background:url(:/image/MySearch.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/MySearch2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/MySearch3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/MySearch4.png);border:0px;}");

}
QString MyWstyle::StylebuttonPrintFull()
{
    return QLatin1String("QPushButton{background:url(:/image/PrintPagefull.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/PrintPageful2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/PrintPageful3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/PrintPageful4.png);border:0px;}");

}
QString MyWstyle::StylebuttonNewUp()
{
    return QLatin1String("QPushButton{background:url(:/image/NewUp.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/NewUp2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/NewUp3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/NewUp4.png);border:0px;}");

}
QString MyWstyle::StylebuttonNewUp30()
{
    return QLatin1String("QPushButton{background:url(:/image/newInvoice30_.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/newInvoice30_2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/newInvoice30_3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/newInvoice30_4.png);border:0px;}");

}
QString MyWstyle::StylebuttonNewInvoice()
{
    return QLatin1String("QPushButton{background:url(:/image/newInvoice.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/newInvoice2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/newInvoice3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/newInvoice4.png);border:0px;}");


}

QString MyWstyle::StylebuttonMovtop()
{
    return QLatin1String("QPushButton{background:url(:/image/newInvoice.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/newInvoice2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/newInvoice3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/newInvoice4.png);border:0px;}");

}

QString MyWstyle::StylebuttonMovbot()
{
    return QLatin1String("QPushButton{background:url(:/image/Movboton.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Movboton2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Movboton3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Movboton4.png);border:0px;}");

}
QString MyWstyle::StylebuttonCalculator()
{
    return QLatin1String("QPushButton{background:url(:/image/calculator.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/calculator2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/calculator3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/calculator4.png);border:0px;}");


}

QString MyWstyle::StylebuttonEdt()
{
    return QLatin1String("QPushButton{background:url(:/image/SaveUp.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/SaveUp2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/SaveUp3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/SaveUp4.png);border:0px;}");

}

QString MyWstyle::StylebuttonDel()
{
    QString mStyle= "QPushButton {"
            "color: white;"
            "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
            "border-width: 1px;"
            "border-color: #339;"
            "border-style: solid;"
            "border-radius: 7;"
            "padding: 3px;"
            "font-size: 12px;"
            "padding-left: 5px;"
            "padding-right: 5px;"
            "min-width: 50px;"
            "max-width: 50px;"
            "min-height: 13px;"
            " max-height: 13px;"
            " }"
            ;
    return mStyle;
}

QString MyWstyle::StylebuttonDisplay()
{
    QString mStyle= "QPushButton {"
            "color: white;"
            "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
            "border-width: 1px;"
            "border-color: #339;"
            "border-style: solid;"
            "border-radius: 7;"
            "padding: 3px;"
            "font-size: 10px;"
            "padding-left: 5px;"
            "padding-right: 5px;"
            "min-width: 170px;"
            "max-width: 170px;"
            "min-height: 30px;"
            "max-height: 30px;"
            " }"
            ;
    return mStyle;

}

QString MyWstyle::StyleBarecode()
{


    return QLatin1String("QPushButton{background:url(:/image/bar-code.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/bar-code-2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/bar-code-3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/bar-code-4.png);border:0px;}");
}

QString MyWstyle::StyleClaseGdoos()
{
    return QLatin1String("QPushButton{background:url(:/image/classgoods.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/classgoods2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/classgoods3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/classgoods4.png);border:0px;}");



}

QString MyWstyle::StylebuttongoodsSharch()
{
    return QLatin1String("QPushButton{background:url(:/image/goodsSharch.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/goodsSharch2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/goodsSharch3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/goodsSharch4.png);border:0px;}");


}

QString MyWstyle::StyleUnit()
{
    return QLatin1String("QPushButton{background:url(:/image/Unit.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Unit2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Unit3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Unit4.png);border:0px;}");


}

QString MyWstyle::StylebuttonMales()
{

    return QLatin1String("QPushButton{background:url(:/image/males.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/males2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/males3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/males4.png);border:0px;}");

}

QString MyWstyle::Stylebuttonfemales()
{

    return QLatin1String("QPushButton{background:url(:/image/females.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/females2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/females3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/females4.png);border:0px;}");

}

QString MyWstyle::StylebuttonfemalesAll()
{
    return QLatin1String("QPushButton{background:url(:/image/femalesAll.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/femalesAll2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/femalesAll3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/femalesAll4.png);border:0px;}");

}

QString MyWstyle::StylebuttonsharchClient()
{
    return QLatin1String("QPushButton{background:url(:/image/clientChonge.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/clientChonge2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/clientChonge3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/clientChonge4.png);border:0px;}");

}

QString MyWstyle::StylebuttonsharchSuppliers()
{
    return QLatin1String("QPushButton{background:url(:/image/suppliersChonge.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/suppliersChonge2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/suppliersChonge3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/suppliersChonge4.png);border:0px;}");

}

QString MyWstyle::StylebuttonPLAY()
{
    return QLatin1String("QPushButton{background:url(:/image/PLAY.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/PLAY2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/PLAY3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/PLAY4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSTOP()
{
    return QLatin1String("QPushButton{background:url(:/image/STOP.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/STOP2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/STOP3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/STOP4.png);border:0px;}");

}

QString MyWstyle::StylebuttonCamera()
{
    return QLatin1String("QPushButton{background:url(:/image/cameraTAK.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/cameraTAK2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/cameraTAK3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/cameraTAK4.png);border:0px;}");

}

QString MyWstyle::StylebuttonIMagicon()
{
    return QLatin1String("QPushButton{background:url(:/image/imageICON.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/imageICON2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/imageICON3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/imageICON4.png);border:0px;}");

}

QString MyWstyle::StylebuttonCamera2()
{
    return QLatin1String("QPushButton{background:url(:/image/camera2TAK.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/camera2TAK2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/camera2TAK3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/camera2TAK4.png);border:0px;}");

}

QString MyWstyle::StylebuttonIMagicon2()
{
    return QLatin1String("QPushButton{background:url(:/image/image2ICON.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/image2ICON2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/image2ICON3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/image2ICON4.png);border:0px;}");

}

QString MyWstyle::StylebuttonPhone()
{
    return QLatin1String("QPushButton{background:url(:/image/phone.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/phone2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/phone3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/phone4.png);border:0px;}");

}

QString MyWstyle::StylebuttonFax()
{
    return QLatin1String("QPushButton{background:url(:/image/Fax.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Fax2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Fax3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Fax4.png);border:0px;}");

}
QString MyWstyle::StyleQTabWidget()
{
    return QLatin1String( "QTabWidget"
                          "{"
                         " color: white;"
                         " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"
                         "}"
                          "QTabWidget::pane"
                         "{"
                         "  border-top: 2px solid #1B1B1B;"
                         "background: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #262626, stop: 1.0 #3D3D3D );"
                         "border-radius: 10px;"
                         "}"

                         "QTabWidget::tab-bar"
                         "{"
                         "  left: 5px;"
                         "  alignment: left;"
                          " color: white;"
                          " background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);"

                         "}"

                         "QTabBar::tab"
                         "{"
                         " border: 1px solid #C4C4C3;"
                         " border-bottom-color: #1B1B1B;"
                         "border-top-left-radius: 8px;"
                         "border-top-right-radius: 8px;"
                         "padding: 1px 3px;"
                         "margin-left: 1px;"
                         "margin-bottom: 0px;"
                         " background: transparent;"
                         "color: #757575;"
                         "padding: 5px 5px ;"
                         "}"

                         "QTabBar::tab:hover"
                         "{"
                         " text-decoration: underline;"
                         "}"

                         "QTabBar::tab:selected"
                         "{"
                         "color: #DEF600;"
                         " background: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #262626, stop: 1.0 #3D3D3D );"
                         "}");
}

QString MyWstyle::StylebuttonClientADD()
{
    return QLatin1String("QPushButton{background:url(:/image/clientAdd.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/clientAdd2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/clientAdd3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/clientAdd4.png);border:0px;}");

}

QString MyWstyle::StylebuttonClientEdit()
{
    return QLatin1String("QPushButton{background:url(:/image/clientEDIT.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/clientEDIT2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/clientEDIT3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/clientEDIT4.png);border:0px;}");

}

QString MyWstyle::StylebuttonClientIonformtion()
{
    return QLatin1String("QPushButton{background:url(:/image/clienIonformtion.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/clientIonformtion2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/clientIonformtion3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/clientIonformtion4.png);border:0px;}");

}

QString MyWstyle::StylebuttonClientPAY()
{
    return QLatin1String("QPushButton{background:url(:/image/clientpay.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/clientpay2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/clientpay3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/clientpay4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSuppliersADD()
{
    return QLatin1String("QPushButton{background:url(:/image/suppliersADD.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/suppliersADD2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/suppliersADD3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/suppliersADD4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSuppliersEdit()
{
    return QLatin1String("QPushButton{background:url(:/image/suppliersEdit.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/suppliersEdit2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/suppliersEdit3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/suppliersEdit4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSuppliersPAY()
{
    return QLatin1String("QPushButton{background:url(:/image/supplierspay.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/supplierspay2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/supplierspay3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/supplierspay4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSuppliersIonformtion()
{
    return QLatin1String("QPushButton{background:url(:/image/suppliersIonformtion.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/suppliersIonformtion2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/suppliersIonformtion3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/suppliersIonformtion4.png);border:0px;}");

}

QString MyWstyle::StylebuttonInventoryinformation()
{
    return QLatin1String("QPushButton{background:url(:/image/Inventoryinformation.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Inventoryinformation2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Inventoryinformation3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Inventoryinformation4.png);border:0px;}");

}

QString MyWstyle::StylebuttonInventoryADD()
{
    return QLatin1String("QPushButton{background:url(:/image/InventoryADD.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/InventoryADD2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/InventoryADD3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/InventoryADD4.png);border:0px;}");

}

QString MyWstyle::StylebuttonInventoryEDit()
{
    return QLatin1String("QPushButton{background:url(:/image/InventoryEdit.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/InventoryEdit2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/InventoryEdit3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/InventoryEdit4.png);border:0px;}");

}

QString MyWstyle::StylebuttonClose()
{
    return QLatin1String("QPushButton{background:url(:/image/close.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/close2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/close3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/close4.png);border:0px;}");

}

QString MyWstyle::StylebuttonAddGoods()
{
    return QLatin1String("QPushButton{background:url(:/image/Addgoods.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Addgoods2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Addgoods3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Addgoods4.png);border:0px;}");

}

QString MyWstyle::StylebuttonEditGoods()
{
    return QLatin1String("QPushButton{background:url(:/image/Editgoods.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Editgoods2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Editgoods3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Editgoods4.png);border:0px;}");

}

QString MyWstyle::StylebuttonInfrmtioGoods()
{
    return QLatin1String("QPushButton{background:url(:/image/Informationgoods.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Informationgoods2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Informationgoods3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Informationgoods4.png);border:0px;}");

}

QString MyWstyle::StylebuttonOK()
{
    return QLatin1String("QPushButton{background:url(:/image/OK.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/OK2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/OK3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/OK4.png);border:0px;}");

}

QString MyWstyle::StylebuttonOKblak()
{
    return QLatin1String("QPushButton{background:url(:/image/okblak.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/okblak2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/okblak3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/okblak4.png);border:0px;}");


}

QString MyWstyle::StylebuttonSign_Out()
{
    return QLatin1String("QPushButton{background:url(:/image/sign-out.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/sign-out2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/sign-out3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/sign-out4.png);border:0px;}");

}

QString MyWstyle::StylebuttonSign_In()
{
    return QLatin1String("QPushButton{background:url(:/image/sign_in.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/sign_in2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/sign_in3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/sign_in4.png);border:0px;}");

}

QString MyWstyle::StylebuttonBack()
{
    return QLatin1String("QPushButton{background:url(:/image/nzxt.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/nzxt2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/nzxt3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/nzxt4.png);border:0px;}");

}

QString MyWstyle::StylebuttonNext()
{
    return QLatin1String("QPushButton{background:url(:/image/Back.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Back2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Back3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Back4.png);border:0px;}");

}

QString MyWstyle::StylebuttonFrst()
{
    return QLatin1String("QPushButton{background:url(:/image/Last Page.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/Last Page2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/Last Page3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/Last Page4.png);border:0px;}");

}

QString MyWstyle::StyleButtonEye()
{
    return QLatin1String("QToolButton{background:url(:/image/Eye.png);border:0px;}\n"
                         "QToolButton:hover{background:url(:/image/Eye2.png);border:0px}\n"
                         "QToolButton:pressed{background:url(:/image/Eye3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QToolButton:!enabled {background:url(:/image/Eye4.png);border:0px;}");

}

QString MyWstyle::StylebuttonJobADD()
{

    return QLatin1String("QPushButton{background:url(:/image/jobADD.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/jobADD2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/jobADD3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/jobADD4.png);border:0px;}");

}

QString MyWstyle::StylebuttonLast()
{
    return QLatin1String("QPushButton{background:url(:/image/FirstPage.png);border:0px;}\n"
                         "QPushButton:hover{background:url(:/image/FirstPage2.png);border:0px}\n"
                         "QPushButton:pressed{background:url(:/image/FirstPage3.png); position: relative;top: 1px; left: 1px;}\n"
                         "QPushButton:!enabled {background:url(:/image/FirstPage4.png);border:0px;}");

}
