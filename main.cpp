#include "Hbdtest.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include <QFontDatabase>
#include <QSettings>
#include <QStyle>
#include "mygraph.h"
#include "mainwindowinertdata.h"
#include "mainwindowhbdtest.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setLayoutDirection(Qt::RightToLeft);
    int id = QFontDatabase::addApplicationFont(":/Font/code128.ttf");
    QFontDatabase::applicationFontFamilies(id).at(0);
    int id_jazeera = QFontDatabase::addApplicationFont(":/Font/ah-manal-black.ttf");
    QFontDatabase::applicationFontFamilies(id_jazeera).at(0);
    int id_digital = QFontDatabase::addApplicationFont(":/Font/digital display tfb.ttf");
    QFontDatabase::applicationFontFamilies(id_digital).at(0);

    //    QFont ff= this->font();
    //    ff.setFamily("digital display tfb");
    //    ff.setBold(true);
    //    this->setFont(ff);
    //    qApp->setFont(ff);

    QFont font;
    font.setFamily("ah-manal-black");
    a.setFont(font);
    a.setWindowIcon(QIcon(":/image/hbd_test.png"));
    // QApplication::setDesktopSettingsAware(false);
    QString defaultStyle = qApp->style()->objectName();
    qDebug()<<"===========Style==============";
    qDebug()<<defaultStyle;




//            MainWindowinertdata w;
//            w.show();
           MainWindowHbdtest  w;
            w.show();
            int aa=a.exec();
         //   w.DrawAllPdf();
    return aa;


}
