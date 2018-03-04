#ifndef DIALOGADDWIGITE_H
#define DIALOGADDWIGITE_H

#include <QDialog>

namespace Ui {
class DialogADDWigite;
}

class DialogADDWigite : public QDialog
{
    Q_OBJECT

public:
    explicit DialogADDWigite(QWidget *parent = 0);
    ~DialogADDWigite();
     void addWidget(QWidget * widget);

private:
    Ui::DialogADDWigite *ui;
};

#endif // DIALOGADDWIGITE_H
