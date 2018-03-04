#ifndef DIALOGABOUTT_H
#define DIALOGABOUTT_H

#include <QDialog>

namespace Ui {
class DialogAboutt;
}

class DialogAboutt : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAboutt(QWidget *parent = 0);
    ~DialogAboutt();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
     void on_linkclikcd(const QString &);
     void on_pushButton_you_clicked();

private:
    Ui::DialogAboutt *ui;
};

#endif // DIALOGABOUTT_H
