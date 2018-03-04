#ifndef QWIDGETIMAGE_BORDER_H
#define QWIDGETIMAGE_BORDER_H

#include <QWidget>

class QImage;
class QPixmap;
namespace Ui {
class QWidgetImage_border;
}

class QWidgetImage_border : public QWidget
{
    Q_OBJECT

public:
    explicit QWidgetImage_border(QWidget *parent = 0);
    ~QWidgetImage_border();

    QString getFileName() const;

    QString getDefaultfileName() const;
    void setDefaultfileName(const QString &value);

    QString getNameimage() const;
    void setNameimage(const QString &value);

    QString getColorborder() const;
    void setColorborder(const QString &value);

public slots:
    void setFileName(const QString &value);
    void DefaultfileName();
protected: //Member Functions
    void paintEvent(QPaintEvent *);
private slots:

private:
    Ui::QWidgetImage_border *ui;
    QString  fileName;
    QImage * Image;
    QPixmap * pixmap;
    QString Colorborder;
    QString defaultfileName;
};
#endif // QWIDGETIMAGE_BORDER_H
