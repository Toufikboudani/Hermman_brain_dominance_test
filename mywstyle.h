#ifndef MYWSTYLE_H
#define MYWSTYLE_H
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QListView>
#include <QObject>

class MyWstyle : public QObject
{
    Q_OBJECT
public:
    explicit MyWstyle(QObject *parent = 0);

    //    QString DialogBarcode::setMStyle(const QString mcolor)
    //    {
    //       QString mStyle= "{border-width: 1px;"
    //                       "border-style: solid;"
    //                //     " border-radius: 4px;"
    //                       "border-color: "+mcolor+";"
    //                "}";
    //        returnm Style;
    //    }

    static QString Stondare_border(const QString mcolor);
    static QString Stondare_font(const QFont &f);
    static QString Stondare_setfont(QWidget *Widget, const QFont &f);
    static QString StyleQLineEdit(const QString mcolor);
    static QString StyleQComboBox(const QString mcolor);
    static QString StyleQListView(const QString mcolor);
    static QString StyleStondare(const QString mcolor, const QFont &f,const QString mcolorText="#083c60");
    static QString StyleStondare(QString Widget,const QString mcolor, const QFont &f,const QString mcolorText="#083c60");
    static QString Stondare_ColorTaxtItemSelected();
    static QString StyleStondare_Item(const QString &Widget);
    static QString StyleStondare_ItemSelected(const QString &Widget);

    static QString StyleQcheckboxSwitch(int w, int h);
    static QString StyleQcheckboxSwitch();
    static QString StyleQRadioButtonSwitch(int w, int h);
    static QString StyleQRadioButtonSwitch();

    static QString StylebutDelQHeader();
    static QString StyleStondareQHeader(const QString mcolor,const QFont & f);
    static QString StyleStondareButton(const QString mcolor, const QFont &f);
    static QString StyleStondareTableCornerBut(const QString mcolor, const QFont &f);
    static QString StyleStondareCombox(const QString mcolor,const QFont & f);
    static QString StylebuttonAdd();

   static QString StyleButtontheMan();

   static QString StyleButtonCancelInvoice();

    static QString StylebuttonInsert();
    static QString StylebuttonPrintEmpty();
    static QString StylebuttonSearch_All();
    static QString StylebuttonSearch();
    static QString StylebuttonPrintFull();
    static QString StylebuttonNewUp();
    static QString StylebuttonNewUp30();
    static QString StylebuttonNewInvoice();

    static QString StylebuttonMovtop();
    static QString StylebuttonMovbot();

    static QString StylebuttonCalculator();

    static QString StylebuttonInsertLog();
    static QString StylebuttonEdt();
    static QString StylebuttonDel();
    static QString StylebuttonDisplay();
    static QString StyleBarecode();
    static QString StyleClaseGdoos();
    static QString StylebuttongoodsSharch();
    static QString StyleUnit();
    static QString StylebuttonMales();
    static QString Stylebuttonfemales();
    static QString StylebuttonfemalesAll();

    static QString StylebuttonsharchClient();
    static QString StylebuttonsharchSuppliers();


    static QString StylebuttonPLAY();
    static QString StylebuttonSTOP();
    static QString StylebuttonCamera();
    static QString StylebuttonIMagicon();
    static QString StylebuttonCamera2();
    static QString StylebuttonIMagicon2();


    static QString StylebuttonPhone();
    static QString StylebuttonFax();


    static QString StyleQTabWidget();

    static QString StylebuttonClientADD();
    static QString StylebuttonClientEdit();
    static QString StylebuttonClientIonformtion();
    static QString StylebuttonClientPAY();

    static QString StylebuttonSuppliersADD();
    static QString StylebuttonSuppliersEdit();
    static QString StylebuttonSuppliersPAY();
    static QString StylebuttonSuppliersIonformtion();




    static QString StylebuttonInventoryinformation();
    static QString StylebuttonInventoryADD();
    static QString StylebuttonInventoryEDit();



    static QString StylebuttonClose();

    static QString StylebuttonAddGoods();
    static QString StylebuttonEditGoods();
    static QString StylebuttonInfrmtioGoods();
    static QString StylebuttonOK();

    static QString StylebuttonOKblak();

    static QString StylebuttonSign_In();
    static QString StylebuttonSign_Out();

    static QString StylebuttonNext();
    static QString StylebuttonBack();
    static QString StylebuttonLast();
    static QString StylebuttonFrst();


    static QString StyleButtonEye();


    static QString StylebuttonJobADD();







    static QString StyleStondareQLineEdit(QString ColorSelect, const QString mcolor, const QFont &f,const QString mcolorText="#083c60");

signals:

public slots:

};

#endif // MYWSTYLE_H
