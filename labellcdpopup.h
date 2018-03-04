#ifndef LABELLCDPOPUP_H
#define LABELLCDPOPUP_H

#include <QWidget>

namespace Ui {
class LabellcdPopup;
}
class  QTimer;
class  QLabel;
class LabellcdPopup : public QWidget
{
    Q_OBJECT

public:
    explicit LabellcdPopup(QWidget *parent = 0);
    ~LabellcdPopup();

    bool getReducingExtension() const;
    void setReducingExtension(bool value);
    //void show();
    QLabel *Label() const;
    QString text() const;

    const QPalette &palette() const;
    void setPalette(const QPalette &p);

    int Max_Width() const;
    void setMax_Width(int Max_Width);

signals :
    void textChanged(const QString &);

public slots:
    void refreshLabellcdPopup();
    void Reducing();
    void Extension();
    void setText(const QString & Text);
    void setColorText(const QString &);
protected:
    void hideEvent(QHideEvent *);
private slots:
    void on_valeulcd_linkActivated(const QString &);

private:
    Ui::LabellcdPopup *ui;
     QTimer *timer;
     int mywidth;
     int KR;
     bool ReducingExtension;
     int m_Max_Width;

};

#endif // LABELLCDPOPUP_H
