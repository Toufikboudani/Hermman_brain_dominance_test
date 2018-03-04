#ifndef CURRENCYS_H
#define CURRENCYS_H

#include <QDialog>
#include <QStandardItemModel>
#include "myqstandarditemmodel.h"

namespace Ui {
class Currencys;
}
//class MyQStandardItemModel;

class Currencys : public QDialog
{
    Q_OBJECT

public:
    enum Hader{
        Country,
        Currency_HomeAR,
        Currency_HomeFR,
        Currency_HomeEN,
        Currency_partsAR,
        Currency_partsFR,
        Currency_partsEN,
        HaderMax
    };
    explicit Currencys(QWidget *parent = 0);
    ~Currencys();

//    MyQStandardItemModel  getModel() const;


    MyQStandardItemModel *getModel() const;
    void setModel(MyQStandardItemModel *value);

private slots:
    void on_pushButtonNewContry_clicked();

    void on_buttonBox_accepted();
    void Header_H_Clicked(int col);
    void Header_V_Clicked(int row);



    void on_pushButtonCancel_clicked();

    void on_pushButton_Save_clicked();
    void on_pushButton_Restore_clicked();

protected:
 void closeEvent(QCloseEvent *);
private:
    Ui::Currencys *ui;
    MyQStandardItemModel * Model;
    void ReadConty();
    Qt::SortOrder  morder;
};

#endif // CURRENCYS_H
