#ifndef HBDTEST_H
#define HBDTEST_H

#include <QDialog>
#include "datatest.h"
namespace Ui {
class Hbdtest;
}
class MyQStandardItemModel;
class Hbdtest : public QDialog
{
    Q_OBJECT

public:
    explicit Hbdtest(QWidget *parent = 0);
    ~Hbdtest();

    dataTestList getMDataTestList() const;
    void setMDataTestList(const dataTestList &value);

    double percentageHBD_A() const;
    void setPercentageHBD_A(double percentageHBD_A);

    double percentageHBD_B() const;
    void setPercentageHBD_B(double percentageHBD_B);

    double percentageHBD_C() const;
    void setPercentageHBD_C(double percentageHBD_C);

    double percentageHBD_D() const;
    void setPercentageHBD_D(double percentageHBD_D);

    QString NameObj() const;
    void setNameObj(const QString &NameObj);

    QString family_name() const;
    void setFamily_name(const QString &family_name);

    int Age() const;
    void setAge(int Age);

    bool isComplat() const;
    void setIsComplat(bool isComplat);

public slots:
    void setFamilyAndNameandAge(const QString &family_name, const QString &NameObj, int Age);
private slots:
    void on_pushButton_Next_clicked();

    void on_pushButton_back_clicked();

    void Read_File();
    void on_radioButton_Yes_clicked();

    void on_radioButton_No_clicked();

    void on_pushButton_Cancel_clicked();

    void on_radioButton_Yes_pressed();

    void on_radioButton_No_pressed();

    void on_verifyDataTest();





    void on_pushButton_Next_2_clicked();

private:


    int  posindex;

    dataTestList mDataTestList;

    dataTestList mData_HBD_A;
    dataTestList mData_HBD_B;
    dataTestList mData_HBD_C;
    dataTestList mData_HBD_D;

    double m_percentageHBD_A;
    double m_percentageHBD_B;
    double m_percentageHBD_C;
    double m_percentageHBD_D;
    QString m_NameObj;
    QString m_family_name;
    int m_Age;
    Ui::Hbdtest *ui;
    bool m_isComplat;
    void prepareLable();
    bool prepareLableAnswer();
};

#endif // HBDTEST_H
