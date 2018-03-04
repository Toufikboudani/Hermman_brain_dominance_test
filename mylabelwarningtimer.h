#ifndef MYLABELWARNINGTIMER_H
#define MYLABELWARNINGTIMER_H
#include "MyLabelWarning.h"
#include <QTimer>

class MyLabelWarningTimer : public MyLabelWarning
{
    Q_OBJECT
public:
    explicit MyLabelWarningTimer(QWidget *parent = 0);

    int getMax() const;
    void setMax(int value);

signals:

public slots:
    void refreshLabel();
    void setText(const QString &t);
private:
QTimer timer;
int Second;
int Max;
};

#endif // MYLABELWARNINGTIMER_H
