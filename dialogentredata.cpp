#include "dialogentredata.h"
#include "ui_dialogentredata.h"
#include "mygraph.h"
DialogEntreData::DialogEntreData(Mygraph *mygraph,
                                 QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEntreData)
{
    ui->setupUi(this);
    mMygraph=mygraph;
           connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)),
            mMygraph, SLOT(setPercentageHBD_A(double)));
            connect(ui->doubleSpinBox_2, SIGNAL(valueChanged(double)),
                    mMygraph, SLOT(setPercentageHBD_B(double)));
            connect(ui->doubleSpinBox_3, SIGNAL(valueChanged(double)),
                    mMygraph, SLOT(setPercentageHBD_C(double)));
            connect(ui->doubleSpinBox_4, SIGNAL(valueChanged(double)),
                    mMygraph, SLOT(setPercentageHBD_D(double)));


}

DialogEntreData::~DialogEntreData()
{
    delete ui;
}

void DialogEntreData::on_buttonBox_accepted()
{

}
