#ifndef DIALOGENTREDATA_H
#define DIALOGENTREDATA_H

#include <QDialog>

namespace Ui {
class DialogEntreData;
}
class Mygraph;
class DialogEntreData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEntreData(Mygraph *mygraph,QWidget *parent = 0);
    ~DialogEntreData();

private slots:
    void on_buttonBox_accepted();

private:
    Mygraph* mMygraph;
    Ui::DialogEntreData *ui;
};

#endif // DIALOGENTREDATA_H
