#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void tuning(int);
    void full_node_automation(double ,double ,int);
     void setdialog();
    void on_gateopening(int );
    void on_editor_clicked(int );
    void on_graph_clicked(int );

    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_Exit_pushButton_clicked();
    void on_Next_pushButton_clicked();
    void on_accept_clicked();
    void on_cancel_clicked();

    void on_ok_clicked();
protected:
    void closeEvent(QCloseEvent *event);


};

 // MAINWINDOW_H
#endif
