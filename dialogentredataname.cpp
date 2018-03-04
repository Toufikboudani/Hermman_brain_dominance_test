#include "dialogentredataname.h"
#include "ui_dialogentredataname.h"
#include "mywstyle.h"

DialogEntreDataName::DialogEntreDataName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEntreDataName)
{
    ui->setupUi(this);
     QString color="#45a1fe";
     ui->lineEdit_FName->setStyleSheet(MyWstyle::StyleStondare("QLineEdit",color,this->font()));
     ui->lineEdit_Name->setStyleSheet(MyWstyle::StyleStondare("QLineEdit",color,this->font()));
     ui->spinBox_Age->setStyleSheet(MyWstyle::StyleStondare("QSpinBox",color,this->font()));
    setWindowTitle("إدخال البيانات");
}

DialogEntreDataName::~DialogEntreDataName()
{
    delete ui;
}

void DialogEntreDataName::on_pushButton_clicked()
{
    close();
}
int DialogEntreDataName::Age() const
{
    return m_Age;
}

void DialogEntreDataName::setAge(int Age)
{
    m_Age = Age;
}

bool DialogEntreDataName::FamilyAndNameandAge(QString &family_name, QString &NameObj, int &Age)
{
  DialogEntreDataName d;
   d.exec();
   d.getFamilyAndNameandAge(family_name,
                                      NameObj,
                                        Age);
   return true;
}



QString DialogEntreDataName::family_name() const
{
    return m_family_name;
}

void DialogEntreDataName::setFamily_name(const QString &family_name)
{
    m_family_name = family_name;
}

QString DialogEntreDataName::NameObj() const
{
    return m_NameObj;
}

void DialogEntreDataName::setNameObj(const QString &NameObj)
{
    m_NameObj = NameObj;
}

void DialogEntreDataName::getFamilyAndNameandAge(QString &family_name,
                                     QString &NameObj,
                                     int & Age)
{
     Age = ui->spinBox_Age->value();
    family_name = ui->lineEdit_FName->text();
    NameObj = ui->lineEdit_Name->text();
}
