#include "convernumtotext.h"
#include <QDebug>

ConverNumToText::ConverNumToText(QObject *parent) :
    QObject(parent)
{


    for (int i = 0; i < 10; ++i) {
        Units.append("");
        Units10.append("");
        Dozens.append("");
        Hundreds.append("");
        centaines.append("");
    }
    for (int i = 0; i < 3; ++i) {
        Thousand.append("");
        Milion.append("");
        Billion.append("");
    }
    StrHundreds="";
    StrThousands="";
    StrMillions="";
    StrBillions="";
    StrInterval="";

   m_SInterval =true;
    // FilledArrays();
    //  setStringFormat("############.##");
}

ConverNumToText::ConverNumToText(ConverNumToText::language lan, QObject *parent):
    QObject(parent)
{
    for (int i = 0; i < 10; ++i) {
        Units.append("");
        Units10.append("");
        Dozens.append("");
        Hundreds.append("");
        centaines.append("");
    }
    for (int i = 0; i < 3; ++i) {
        Thousand.append("");
        Milion.append("");
        Billion.append("");
    }
    StrHundreds="";
    StrThousands="";
    StrMillions="";
    StrBillions="";
    StrInterval="";
    Tybemylanguage =lan;
    m_SInterval =true;
}
int ConverNumToText::getTybemylanguage() const
{
    return Tybemylanguage;
}
QString ConverNumToText::getTextConver(int lan,double Numebr){
  ConverNumToText *coV= new ConverNumToText();
  coV->setTybemylanguage(lan);
  QString CVN=coV->ConverDoubleToText(Numebr);
  delete coV;
  return CVN;
}

QString ConverNumToText::getTextConver(int lan, double Numebr, bool mStrInterval, const QString &mDinar, const QString &mCentimes)
{
    ConverNumToText *coV= new ConverNumToText();
    qDebug()<<"*********************************************************";
    qDebug()<<"**** "<<mStrInterval;
    coV->setTybemylanguage(lan);
    coV->setDinar(mDinar);
    coV->setCentimes(mCentimes);
    if (mStrInterval==false) {
        coV->setDinar("");
        coV->setCentimes("");
        coV->setSInterval(mStrInterval);
    }
    qDebug()<<"========"<<Numebr;
    QString CVN=coV->ConverDoubleToText(Numebr);
    delete coV;
       qDebug()<<"*********************************************************";
    return CVN;

}
QString ConverNumToText::getDinar() const
{
    return Dinar;
}

void ConverNumToText::setDinar(const QString &value)
{
    Dinar = " "+value;
}
QString ConverNumToText::getCentimes() const
{
    return Centimes;
}

void ConverNumToText::setCentimes(const QString &value)
{
    Centimes = " "+value;
}
bool ConverNumToText::SInterval() const
{
    return m_SInterval;
}

void ConverNumToText::setSInterval(bool SInterval)
{
    m_SInterval = SInterval;
}

void ConverNumToText::setTybemylanguage(int mlang)
{
    Tybemylanguage=mlang;
    switch(Tybemylanguage)
    {
    case AR:

        Units[0]="صفر";
        Units[1]="واحد";
        Units[2]="اثنان";
        Units[3]="ثلاثة";
        Units[4]="أربعة";
        Units[5]="خمسة";
        Units[6]="ستة";
        Units[7]="سبعة";
        Units[8]="ثمانية";
        Units[9]="تسعة";


        Units10[0]="عشرة";
        Units10[1]="احدى عشرة";
        Units10[2]="اثنتى عشرة";
        Units10[3]="ثلاثة عشرة";
        Units10[4]="أربعة عشرة";
        Units10[5]="خمسة عشرة";
        Units10[6]="ستة عشرة";
        Units10[7]="سبعة عشرة";
        Units10[8]="ثمانية عشرة";
        Units10[9]="تسعة عشرة";

        Dozens[0]="";
        Dozens[1]="عشرة";
        Dozens[2]="عشرون";
        Dozens[3]="ثلاثون";
        Dozens[4]="أربعون";
        Dozens[5]="خمسون";
        Dozens[6]="ستون";
        Dozens[7]="سبعون";
        Dozens[8]="ثمانون";
        Dozens[9]="تسعون";

        Hundreds[0]="";
        Hundreds[1]="مئة";
        Hundreds[2]="مئتان";
        Hundreds[3]="ثلاثمئة";
        Hundreds[4]="أربعمئة";
        Hundreds[5]="خمسمئة";
        Hundreds[6]="ستمئة";
        Hundreds[7]="سبعمئة";
        Hundreds[8]="ثمانمئة";
        Hundreds[9]="تسعمئة";

        Thousand[0]="ألف";
        Thousand[1]="ألفان";
        Thousand[2]="ألاف";

        Milion[0]="مليون";
        Milion[1]="مليونان";
        Milion[2]="ملايين";

        Billion[0]="مليار";
        Billion[1]="ملياران";
        Billion[2]="ملايير";

        And=" و ";
        Dinar=" دينار " ;
        Centimes=" سنتيم " ;
        break;

    case FR:

        Units [0] = "zéro";
        Units [1] = "un";
        Units [2] = "deux";
        Units [3] = "trois";
        Units [4] = "quatre";
        Units [5] = "cinq";
        Units [6] = "six";
        Units [7] = "sept";
        Units [8] = "huit";
        Units [9] = "neuf";

        Units10 [0] = "dix";
        Units10 [1] = "onze";
        Units10 [2] = "douze";
        Units10 [3] = "treize";
        Units10 [4] = "quatorze";
        Units10 [5] = "quinze";
        Units10 [6] = "seize";
        Units10 [7] = "dix-sept";
        Units10 [8] = "dix-huit";
        Units10 [9] = "dix-neuf";

        Dozens [0] = "";
        Dozens [1] = "dix";
        Dozens [2] = "vingt";
        Dozens [3] = "trente";
        Dozens [4] = "Quarante";
        Dozens [5] = "cinquante";
        Dozens [6] = "soixante";
        Dozens [7] = "soixante-dix";
        Dozens [8] = "Quatre-vingt";
        Dozens [9] = "quatre-vingt-dix";

        Hundreds [0] = "";
        Hundreds [1] = "cent";
        Hundreds [2] = "deux cents";
        Hundreds [3] = "trois cents";
        Hundreds [4] = "quatre cents";
        Hundreds [5] = "cinq cents";
        Hundreds [6] = "six cents";
        Hundreds [7] = "sept cents";
        Hundreds [8] = "huit cents";
        Hundreds [9] = "neuf cents";

        Thousand [0] = "mille";
        Thousand [1] = "deux mille";
        Thousand [2] = "mille";

        Milion [0] = "million";
        Milion [1] = "deux million";
        Milion [2] = "millions";

        Billion [0] = "milliard";
        Billion [1] = "deux milliard";
        Billion [2] = "milliards";

        And = "-";
        Dinar = " Dinar";
        Centimes = " Centimes";
        break;

    case EN:

        Units [0] = "zero";
        Units [1] = "one";
        Units [2] = "two";
        Units [3] = "three";
        Units [4] = "four";
        Units [5] = "five";
        Units [6] = "six";
        Units [7] = "seven";
        Units [8] = "eight";
        Units [9] = "nine";


        Units10 [0] = "Ten";
        Units10 [1] = "eleven";
        Units10 [2] = "twelve";
        Units10 [3] = "thirteen";
        Units10 [4] = "fourteen";
        Units10 [5] = "fifteen";
        Units10 [6] = "sixteen";
        Units10 [7] = "seventeen";
        Units10 [8] = "eighteen";
        Units10 [9] = "nineteen";

        Dozens [0] = "";
        Dozens [1] = "Ten";
        Dozens [2] = "twenty";
        Dozens [3] = "thirty";
        Dozens [4] = "Forty";
        Dozens [5] = "fifty";
        Dozens [6] = "sixty";
        Dozens [7] = "seventy";
        Dozens [8] = "Eighty";
        Dozens [9] = "ninety";

        Hundreds [0] = "";
        Hundreds [1] = "one hundred";
        Hundreds [2] = "two hundred";
        Hundreds [3] = "three hundred";
        Hundreds [4] = "four hundred";
        Hundreds [5] = "five hundred";
        Hundreds [6] = "six hundred";
        Hundreds [7] = "seven hundred";
        Hundreds [8] = "eight hundred";
        Hundreds [9] = "nine hundred";

        Thousand [0] = "thousand";
        Thousand [1] = "two thousand";
        Thousand [2] = "thousand";

        Milion [0] = "million";
        Milion [1] = "two million";
        Milion [2] = "million";

        Billion [0] = "billion";
        Billion [1] = "two billion";
        Billion [2] = "billion";

        And = "-";
        Dinar = " Dinar";
        Centimes = " Centimes";
        break;





    }
}
QString ConverNumToText::ConverNumGHunArabe(int Num){
    qDebug()<<"ConverNumGHunArabe  ="<<Num;
    QString strNum=QString::number(Num);
    QString strCNum="";

    switch(strNum.length()) {
    case 1:

        strCNum=Units[Num];
        break;
    case 2:
        if (strNum[0]=='1') {
            strCNum=Units10[Num-10];

        }else {
             if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()];
            } else {
                strCNum=Units[QString(strNum[1]).toInt()]+And+Dozens[QString(strNum[0]).toInt()];
               // qDebug()<<"ConverNumGHunArabe case 1: ="<<Units[QString(strNum[1]).toInt()]+And+Dozens[QString(strNum[0]).toInt()];

             }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()];
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-(QString(strNum[0]).toInt()*100);
            strNum=""+Num;
            strCNum=strCNum+And+ConverNumGHunArabe(Nufm);
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverNumGHunEnglish(int Num){
    QString strNum=""+QString::number(Num);
    QString strCNum="";

    switch(strNum.length()) {
    case 1:

        strCNum=Units[Num];
        break;
    case 2:
        if (strNum[0]=='1') {
            strCNum=Units10[Num-10];

        }else {
            if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()];
            }else {
                strCNum=Dozens[QString(strNum[0]).toInt()]+"-"+Units[QString(strNum[1]).toInt()];
            }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()];
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-(QString(strNum[0]).toInt()*100);
            strNum=""+Num;
            strCNum=strCNum+" "+ConverNumGHunEnglish(Nufm);
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverNumGHunFrancais(int Num){



    QString strNum=""+QString::number(Num);
    QString strCNum="";

    switch(strNum.length()) {
    case 1:

        strCNum=Units[Num];
        break;
    case 2:

        if (strNum[0]=='1') {
            strCNum=Units10[Num-10];

        }else if (strNum[0]=='7') {
            strCNum=Dozens[6]+"-"+Units10[Num-70];

        }else if (strNum[0]=='9') {
            strCNum=Dozens[8]+"-"+Units10[Num-90];

        }else {
            if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()];
            }else if (strNum[1]=='1') {
                strCNum=Dozens[QString(strNum[0]).toInt()]+"-et-"+Units[1];
            }else {
                strCNum=Dozens[QString(strNum[0]).toInt()]+"-"+Units[QString(strNum[1]).toInt()];
            }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()];
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-((QString(strNum[0]).toInt())*100);
            strNum=""+Num;
            strCNum=strCNum+" "+ConverNumGHunFrancais(Nufm);
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverNumGreaterHunArabe(int Num,QStringList GreaterHun){
    QString strNum=""+QString::number(Num);
    QString strCNum="";

    switch(strNum.length()) {
    case 1:

        if (Num==1) {
            strCNum= GreaterHun[0];
        } else if (Num==2) {
            strCNum= GreaterHun[1] ;
        } else  {
            strCNum=Units[Num]+" "+GreaterHun[2];
        }

        break;
    case 2:
        if (strNum[0]=='1') {

            if (Num==10) {
                strCNum=Units10[Num-10] +" "+GreaterHun[2];

            } else {

                strCNum=Units10[Num-10]+" "+GreaterHun[0];
            }

        }else {
            if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()]+" "+GreaterHun[0]; ;
            } else {
                strCNum=Units[QString(strNum[0]).toInt()]+And+Dozens[QString(strNum[0]).toInt()]+" "+GreaterHun[0] ;
            }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()]+" ";
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-((QString(strNum[0]).toInt())*100);
            strNum=""+Num;
            if (Nufm>=3 && Nufm<=10) {
                strCNum=strCNum+And+ConverNumGHunArabe(Nufm)+" "+GreaterHun[2];
            }else  {
                strCNum=strCNum+And+ConverNumGHunArabe(Nufm)+" "+GreaterHun[0];
            }
        } else{
            strCNum=strCNum+" "+GreaterHun[0];
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverNumGreaterHunFrancais(int Num,QStringList GreaterHun){

    QString strNum=""+QString::number(Num);
    QString strCNum="";
    switch(strNum.length()) {
    case 1:

        if (Num==1) {
            strCNum= GreaterHun[0];
        } else if (Num==2) {
            strCNum= GreaterHun[1] ;
        } else  {
            strCNum=Units[Num]+" "+GreaterHun[2];
        }

        break;
    case 2:
        if (strNum[0]=='1') {

            if (Num==10) {
                strCNum=Units10[Num-10] +" "+GreaterHun[2];

            } else {

                strCNum=Units10[Num-10]+" "+GreaterHun[2];
            }

        }else {
            if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()]+" "+GreaterHun[2];
            } else {
                strCNum=Dozens[QString(strNum[0]).toInt()]+And+Units[QString(strNum[1]).toInt()]+" "+GreaterHun[2] ;
            }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()]+" ";
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-((QString(strNum[0]).toInt())*100);
            strNum=""+Num;

            strCNum=strCNum+" "+ConverNumGHunFrancais(Nufm)+" "+GreaterHun[2];

        } else{
            strCNum=strCNum+" "+GreaterHun[2];
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverNumGreaterHunEnglish(int Num,QStringList GreaterHun){
    QString strNum=""+QString::number(Num);
    QString strCNum="";

    switch(strNum.length()) {
    case 1:

        if (Num==1) {
            strCNum= GreaterHun[0];
        } else if (Num==2) {
            strCNum= GreaterHun[1] ;
        } else  {
            strCNum=Units[Num]+" "+GreaterHun[2];
        }

        break;
    case 2:
        if (strNum[0]=='1') {

            if (Num==10) {
                strCNum=Units10[Num-10] +" "+GreaterHun[2];

            } else {

                strCNum=Units10[Num-10]+" "+GreaterHun[2];
            }

        }else {
            if (strNum[1]=='0') {
                strCNum=Dozens[QString(strNum[0]).toInt()]+" "+GreaterHun[2];
            } else {
                strCNum=Dozens[QString(strNum[0]).toInt()]+And+Units[QString(strNum[1]).toInt()]+" "+GreaterHun[2] ;
            }
        }
        break;
    case 3:
        strCNum=Hundreds[QString(strNum[0]).toInt()]+" ";
        if (    strNum[2]!='0'||
                strNum[1]!='0') {
            int Nufm=Num-((QString(strNum[0]).toInt())*100);
            strNum=""+Num;

            strCNum=strCNum+" "+ConverNumGHunEnglish(Nufm)+" "+GreaterHun[2];

        } else{
            strCNum=strCNum+" "+GreaterHun[2];
        }
        break;
    }

    return strCNum ;
}
QString ConverNumToText::ConverDoubleToText(double Numb){
    if (Numb <=0) {
      return "";
    }
    if (Numb >999999999999) {

      switch (Tybemylanguage) {
      case AR:
         return "إدخال غير صالحالعدد أكبر 999,999,999,999";

      case FR:
          return "Invalid Input Le plus grand nombre 999,999,999,999";
      default:
          return "Invalid Input The largest number 999,999,999,999";

      }
    }
 QString  StrNumb= QString::number(Numb, 'f', 2);

    StrHundreds="";
    StrThousands="";
    StrMillions="";
    StrBillions="";
    StrInterval="";
    QString Number="";
    qDebug()<<Numb;

    int a= StrNumb.indexOf(".");
      qDebug()<<StrNumb;
    switch(Tybemylanguage)
    {
    case AR:

             qDebug()<<"a =============================== "<<a;
                qDebug()<<"StrInterval==============================="<<m_SInterval;
        if ((a>=0)&&m_SInterval) {
            StrInterval=StrNumb.mid(a+1,StrNumb.length());
            qDebug()<<"Numb==============================="<<StrInterval;
            if (StrInterval.toInt()==0) {
                  StrInterval="" ;
            }else if (StrInterval.length()==1) {

                StrInterval=And+ConverNumGHunArabe(QString(StrInterval+"0").toInt())+Centimes;
            } else {
                StrInterval=And+ConverNumGHunArabe(QString(StrInterval).toInt())+Centimes;
            }


             qDebug()<<"Numb===============================";
        } else {

            StrInterval="" ;
        }
         StrNumb= StrNumb.mid(0,a);
        if (StrNumb.length()<=3 ) {
            Number=ConverNumGHunArabe(QString(StrNumb).toInt())+Dinar+StrInterval;

        } else if (StrNumb.length()<=6 && StrNumb.length()>3) {
            qDebug()<<"Numb===============================";

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunArabe(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";
            }
            StrThousands=StrNumb.mid(0,StrNumb.length()-3);
            StrThousands=ConverNumGreaterHunArabe(QString(StrThousands).toInt(),Thousand);
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }

                Number=StrThousands+StrHundreds+Dinar+StrInterval;




        }
        else if (StrNumb.length()<=9 && StrNumb.length()>6) {

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunArabe(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";
            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);
           qDebug()<<StrThousands;
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunArabe(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";
            }
            qDebug()<<StrThousands;
            StrMillions=StrNumb.mid(0,StrNumb.length()-6);
            StrMillions=ConverNumGreaterHunArabe(QString(StrMillions).toInt(),Milion);
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }

            Number=StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;


        }
        else if (StrNumb.length()<=12 && StrNumb.length()>9) {
            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunArabe(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";
            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunArabe(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";
            }
            StrMillions=StrNumb.mid(StrNumb.length()-9,3);
            if (StrMillions.toInt()>0) {
                StrMillions=ConverNumGreaterHunArabe(QString(StrMillions).toInt(),Milion);

            }else {
                StrMillions="";
            }
            StrBillions=StrNumb.mid(0,StrNumb.length()-9);
            StrBillions=ConverNumGreaterHunArabe(QString(StrBillions).toInt(),Billion);
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }
            if (!StrMillions.isEmpty()){
                StrMillions.insert(0,And);
              }
            Number=StrBillions+StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;



        }else{
            Number="صفر";

        }

        break;
    case FR:
        //mid
        if ((a>=0)&&m_SInterval) {
            StrInterval=StrNumb.mid(a+1,StrNumb.length());
            if (StrInterval.toInt()==0) {
                  StrInterval="" ;
            }else if (StrInterval.length()==1) {

                StrInterval=" et "+ConverNumGHunFrancais(QString(StrInterval+"0").toInt())+Centimes;
            } else {
                StrInterval=" et "+ConverNumGHunFrancais(QString(StrInterval).toInt())+Centimes;
            }

        } else {

            StrInterval="" ;

        }
         StrNumb= StrNumb.mid(0,a);
        if (StrNumb.length()<=3 ) {
            Number=ConverNumGHunFrancais(QString(StrNumb).toInt())+Dinar+StrInterval;

        } else if (StrNumb.length()<=6 && StrNumb.length()>3) {

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunFrancais(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";

            }
            StrThousands=StrNumb.mid(0,StrNumb.length()-3);
            StrThousands=ConverNumGreaterHunFrancais(QString(StrThousands).toInt(),Thousand);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            Number=StrThousands+StrHundreds+Dinar+StrInterval;;

            And=m;
        }
        else if (StrNumb.length()<=9 && StrNumb.length()>6) {

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunFrancais(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";

            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);

            qDebug()<<StrThousands;
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunFrancais(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";

            }
             qDebug()<<StrThousands;
            StrMillions=StrNumb.mid(0,StrNumb.length()-6);
            StrMillions=ConverNumGreaterHunFrancais(QString(StrMillions).toInt(),Milion);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }
            Number=StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;
            And=m;
        }
        else if (StrNumb.length()<=12 && StrNumb.length()>9) {
            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunFrancais(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";
            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunFrancais(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";

            }
            StrMillions=StrNumb.mid(StrNumb.length()-9,3);
            if (StrMillions.toInt()>0) {
                StrMillions=ConverNumGreaterHunFrancais(QString(StrMillions).toInt(),Milion);

            }else {
                StrMillions="";

            }
            StrBillions=StrNumb.mid(0,StrNumb.length()-9);
            StrBillions=ConverNumGreaterHunFrancais(QString(StrBillions).toInt(),Billion);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }
            if (!StrMillions.isEmpty()){
                StrMillions.insert(0,And);
              }
            And=m;
            Number=StrBillions+StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;




        }else{
            Number="zéro";

        }
        break;

    case EN:

        //mid
        if ((a>=0)&&m_SInterval) {
            StrInterval=StrNumb.mid(a+1,StrNumb.length());
            if (StrInterval.toInt()==0) {
                  StrInterval="" ;
            }else  if (StrInterval.length()==1) {

                StrInterval=" and "+ConverNumGHunEnglish(QString(StrInterval+"0").toInt())+Centimes;
            } else {
                StrInterval= " and "+ConverNumGHunEnglish(QString(StrInterval).toInt())+Centimes;
            }


        } else {

            StrInterval="" ;

        }
          StrNumb= StrNumb.mid(0,a);
        if (StrNumb.length()<=3 ) {
            Number=ConverNumGHunEnglish(QString(StrNumb).toInt())+Dinar+StrInterval;

        } else if (StrNumb.length()<=6 && StrNumb.length()>3) {

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunEnglish(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";

            }

            StrThousands=StrNumb.mid(0,StrNumb.length()-3);
            StrThousands=ConverNumGreaterHunEnglish(QString(StrThousands).toInt(),Thousand);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }

            And=m;
            Number=StrThousands+StrHundreds+Dinar+StrInterval;;

        }
        else if (StrNumb.length()<=9 && StrNumb.length()>6) {

            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunEnglish(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";

            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunEnglish(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";

            }
            StrMillions=StrNumb.mid(0,StrNumb.length()-6);
            StrMillions=ConverNumGreaterHunEnglish(QString(StrMillions).toInt(),Milion);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }

            And=m;
            Number=StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;

        }
        else if (StrNumb.length()<=12 && StrNumb.length()>9) {
            StrHundreds=StrNumb.mid(StrNumb.length()-3,3);
            if (StrHundreds.toInt()>0) {
                StrHundreds=ConverNumGHunEnglish(QString(StrHundreds).toInt());

            }else {
                StrHundreds="";

            }
            StrThousands=StrNumb.mid(StrNumb.length()-6,3);
            if (StrThousands.toInt()>0) {
                StrThousands=ConverNumGreaterHunEnglish(QString(StrThousands).toInt(),Thousand);

            }else {
                StrThousands="";

            }
            StrMillions=StrNumb.mid(StrNumb.length()-9,3);
            if (StrMillions.toInt()>0) {
                StrMillions=ConverNumGreaterHunEnglish(QString(StrMillions).toInt(),Milion);

            }else {
                StrMillions="";

            }
            StrBillions=StrNumb.mid(0,StrNumb.length()-9);
            StrBillions=ConverNumGreaterHunEnglish(QString(StrBillions).toInt(),Billion);
            QString m=And;
            And=" ";
            if (!StrHundreds.isEmpty()) {
               StrHundreds.insert(0,And);
            }
            if (!StrThousands.isEmpty()){
              StrThousands.insert(0,And);
            }
            if (!StrMillions.isEmpty()){
                StrMillions.insert(0,And);
              }
            And=m;
            Number=StrBillions+StrMillions+StrThousands+StrHundreds+Dinar+StrInterval;



        }else{
            Number="zéro";

        }
        break;
    }




    return Number;
}
