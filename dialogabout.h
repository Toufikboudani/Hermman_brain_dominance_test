#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>

namespace Ui {
class DialogAbout;
}
class QTimer;
class DialogAbout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAbout(QWidget *parent = 0);
     explicit DialogAbout(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~DialogAbout();

public slots:
    void refreshAbout();
private:
    Ui::DialogAbout *ui;
    QTimer *timer;int  mcl;
};

#endif // DIALOGABOUT_H
