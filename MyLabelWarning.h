#ifndef MYLABELWARNING_H
#define MYLABELWARNING_H

#include <QLabel>

class MyLabelWarning : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabelWarning(QWidget *parent = 0);
    bool WarningEroor ;
    bool isWarningEroor() const;
    void setWarningEroor(bool value);

signals:
void linkclikcd(const QString & mtext);
public slots:

protected :
    void mousePressEvent(QMouseEvent *ev);
};

#endif // MYLABELWARNING_H
