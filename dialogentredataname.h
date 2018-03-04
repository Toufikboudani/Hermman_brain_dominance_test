#ifndef DIALOGENTREDATANAME_H
#define DIALOGENTREDATANAME_H

#include <QDialog>

namespace Ui {
class DialogEntreDataName;
}

class DialogEntreDataName : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEntreDataName(QWidget *parent = 0);
    ~DialogEntreDataName();

    QString NameObj() const;
    void setNameObj(const QString &NameObj);

    QString family_name() const;
    void setFamily_name(const QString &family_name);

    int Age() const;
    void setAge(int Age);
    static bool  FamilyAndNameandAge(QString &family_name, QString &NameObj, int &Age);
public slots:
    void  getFamilyAndNameandAge(QString &family_name, QString &NameObj, int &Age);
private slots:
    void on_pushButton_clicked();

private:
    QString m_NameObj;
    QString m_family_name;
    int m_Age;
    Ui::DialogEntreDataName *ui;
};

#endif // DIALOGENTREDATANAME_H
