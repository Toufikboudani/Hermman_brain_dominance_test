#ifndef MAINWINDOWHBDTEST_H
#define MAINWINDOWHBDTEST_H

#include <QMainWindow>

namespace Ui {
class MainWindowHbdtest;
}
class MyQStandardItemModel;
class QStandardItem;

class MainWindowHbdtest : public QMainWindow
{
    Q_OBJECT

public:
    enum columTable
    {
        Name,
        FName,
        Age,
        HBD_A,
        HBD_B,
        HBD_C,
        HBD_D,
        Maxcolum
    };



    explicit MainWindowHbdtest(QWidget *parent = 0);
    ~MainWindowHbdtest();


private slots:
   void  on_itemChanged(QStandardItem *item);

    void on_actionNew_File_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_AS_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_Hbd_Test_triggered();

    void on_actionHelp_triggered();

    void on_actionAdd_New_obj_triggered();

    void on_displayMenuTable(QPoint pos);

    void on_TestHBDAction_triggered()  ;
    void on_ShowTestHBDAction_triggered();
    void on_DeleteAction_triggered();


    void on_m_movtop_clicked();

    void on_m_movbot_clicked();

    void on_m_movforst_clicked();

    void on_m_movlast_clicked();

    void Header_H_Clicked(int col);
    void Copy();
private:
    MyQStandardItemModel * Model;
    Ui::MainWindowHbdtest *ui;
    QString m_FileNameApp;
    QString m_FileName;
    QString NameFile_Xml;

    QAction *TestHBDAction  ;
    QAction *ShowTestHBDAction  ;
    QAction *DeleteAction  ;
    QAction *CopyAction;
    QMenu   *pContextMenutable ;
    bool isSaved;
    Qt::SortOrder morder;

    // QMainWindow interface
public:

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *);
};

#endif // MAINWINDOWHBDTEST_H
