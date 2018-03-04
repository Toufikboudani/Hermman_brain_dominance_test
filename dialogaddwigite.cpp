#include "dialogaddwigite.h"
#include "ui_dialogaddwigite.h"

DialogADDWigite::DialogADDWigite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogADDWigite)
{
    ui->setupUi(this);
}

DialogADDWigite::~DialogADDWigite()
{
    delete ui;
}

void DialogADDWigite::addWidget(QWidget *widget)
{


//    this->resize(widget->geometry().size()+QSize(18,18));
//    connect(widget, SIGNAL(), this, SLOT(close()));

////    this->setMinimumSize(widget->minimumSize()+QSize(18,18));
////    this->setMaximumSize(widget->maximumSize()+QSize(18,18));

    ui->verticalLayout->addWidget(widget);

}
