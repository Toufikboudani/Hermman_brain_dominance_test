#include "dialogaboutt.h"
#include "ui_dialogaboutt.h"
#include <QDesktopServices>
#include <QUrl>
#include "htmlprepara.h"

DialogAboutt::DialogAboutt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAboutt)
{
    ui->setupUi(this);
    ui->widget_imag->setFileName(":/image/hbd_test.png");
   // ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->label_2->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->label_3->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->label_4->setTextInteractionFlags(Qt::TextSelectableByMouse);
    // ui->label->setText(HtmlPrepara::PreparaText_href("DialogAboutt","ToufikboudaniSoft",2,"000000"));

    connect(ui->label,SIGNAL(linkclikcd(QString)), this, SLOT(on_linkclikcd(QString)));

}

DialogAboutt::~DialogAboutt()
{
    delete ui;
}

void DialogAboutt::on_pushButton_2_clicked()
{
    this->close();
}

void DialogAboutt::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://web.facebook.com/Horsesoft/"));
}

void DialogAboutt::on_linkclikcd(const QString & /*mlink*/)
{
    QDesktopServices::openUrl(QUrl("https://web.facebook.com/Horsesoft/"));

}

void DialogAboutt::on_pushButton_you_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UCBk9FvrHV-0rKzvMKknjnAg"));

}

