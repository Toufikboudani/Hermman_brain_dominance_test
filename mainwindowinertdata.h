#ifndef MAINWINDOWINERTDATA_H
#define MAINWINDOWINERTDATA_H

#include <QMainWindow>
class  MyQStandardItemModel;
namespace Ui {
class MainWindowinertdata;
}

class MainWindowinertdata : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowinertdata(QWidget *parent = 0);
    ~MainWindowinertdata();

    MyQStandardItemModel *getMModel() const;
    void setMModel(MyQStandardItemModel *value);

protected:
    void closeEvent(QCloseEvent *);
private slots:
    void on_pushButtonADD_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonopen_clicked();

void pvrevee();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionAbout_triggered();

private:
    MyQStandardItemModel *mModel;
    Ui::MainWindowinertdata *ui;


    QString m_FileNameApp;
    QString m_FileName;
    QString NameFile_Xml;
    QStringList Undo_Redo;
    int  posindex;

   int select;
};

#endif // MAINWINDOWINERTDATA_H
