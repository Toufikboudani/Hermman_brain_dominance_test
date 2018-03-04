#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QDialog>
#include <QImage>

namespace Ui {
class Mygraph;
}

class Mygraph : public QDialog
{
    Q_OBJECT

public:
    enum ENUMTypeHBD{
        HBD_A,
        HBD_B,
        HBD_C,
        HBD_D,
        MaxHBD

    };
    explicit Mygraph(QWidget *parent = 0);
    ~Mygraph();
    void DrawAllPdf();

    double Value() const;
    void setValue(double Value);

    double percentage() const;
    void setPercentage(double percentage);

    int TypeHBD() const;
    void setTypeHBD(int TypeHBD);
    void DrawHBD_A(QPainter &Painter);
    void DrawHBD_B(QPainter &Painter);
    void DrawHBD_C(QPainter &Painter);
    void DrawHBD_D(QPainter &Painter);
    double percentageHBD_A() const;

    double percentageHBD_B() const;

    double percentageHBD_C() const;

    double percentageHBD_D() const;

    QPointF P_pos(qreal Alfa, qreal mR);
    QPointF P_pos(QPointF mpos, qreal Alfa, qreal mR);

    QString NameObj() const;
    void setNameObj(const QString &NameObj);

    QString family_name() const;
    void setFamily_name(const QString &family_name);

    int Age() const;
    void setAge(int Age);
    void setFamilyAndNameandAge(const QString &family_name,
                                const QString &NameObj,int Age);

public slots:
    void setPercentageHBD_D(double percentageHBD_D);
    void setPercentageHBD_B(double percentageHBD_B);
    void setPercentageHBD_A(double percentageHBD_A);

    void setPercentageHBD_C(double percentageHBD_C);


private slots:
    void on_pushButton_clicked();

    double Diameter_rect();
    void on_pushButtonPrint_clicked();

private:
QString m_NameObj;
QString m_family_name;
int m_Age;
    double m_Value;
    double m_percentage;
    double m_percentageHBD_A;
    double m_percentageHBD_B;
    double m_percentageHBD_C;
    double m_percentageHBD_D;

    QPointF P_HBD_A;
    QPointF P_HBD_B;
    QPointF P_HBD_C;
    QPointF P_HBD_D;
QImage Myimag;
     int m_TypeHBD;
    int angel1;
    double Mywidth ;
    double Myheight ;

    Ui::Mygraph *ui;
    void DrawAll(QPainter &Painter);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // MYGRAPH_H
