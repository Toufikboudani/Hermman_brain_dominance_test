#ifndef DIALOGINERTDATA_H
#define DIALOGINERTDATA_H

#include <QDialog>

namespace Ui {
class Dialoginertdata;
}
class  MyQStandardItemModel;
class Dialoginertdata : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoginertdata(QWidget *parent = 0);
    ~Dialoginertdata();

    MyQStandardItemModel *getMModel() const;
    void setMModel(MyQStandardItemModel *value);

private slots:
    void on_pushButtonADD_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonopen_clicked();



private:
    MyQStandardItemModel *mModel;
    Ui::Dialoginertdata *ui;
};

#endif // DIALOGINERTDATA_H
