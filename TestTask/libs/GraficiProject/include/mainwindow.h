#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <spectr.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_clicked();


private:
    Ui::MainWindow *ui;
    Spectr *spectr;

signals:
    void signal(QVector<double>& x_t  , QVector<double>& y_t_re , QVector<double>& y_t_im  );

};
#endif // MAINWINDOW_H
