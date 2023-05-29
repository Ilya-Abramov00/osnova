#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "spectr.h"



QVector<double> sinus(double f , double fasa, double Fd)
{
    QVector<double> Re;


    for(int i=0; i!=128; i++)
    {
        Re.push_back(cos(f*i/Fd+fasa*3.1415926535/180));
    }
    return Re ;
}

QVector<double> lchm(double  f , double  delta_f, double  Fd)
{
   QVector<double> Re;

    for(int i=0; i!=128; i++)
    {
        Re.push_back(cos((i/Fd)*(f+delta_f*i/64)));
    }
    return Re ;
}

QVector<double> triug(double  t )
{
    QVector<double> Re;
    t=t*128;
    for(int i=0; i!=128; i++)
    {
        if (i<=t/2) { Re.push_back(2*i/(t));}
        else if ( (i>t/2) &&  (i<=t)  ) { Re.push_back(1- (2/t)*(i -t/2) );}
        else Re.push_back(0);
    }
    return Re ;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spectr=new Spectr;
    spectr->show();

     connect(this,&MainWindow::signal,spectr, &Spectr::slot );//изменение графика
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_start_clicked()
{
    QVector<double> x_t;
    QVector<double> y_t;
    QVector<double> y_t_im;

    ui->widget->clearGraphs();




    if(ui->sig_garm->isChecked())
        {
       QString f_0= ui->lineEdit_1->text();
        double f=f_0.toDouble();


       QString fas_0= ui->lineEdit_2->text();
       double fas=fas_0.toDouble();

       QString fd_0= ui->lineEdit_3->text();
       double fd=fd_0.toDouble();

           y_t  =sinus(f, fas, fd);

        }


    else if(ui->sig_lchm->isChecked())
        {
           QString f0_0= ui->lineEdit_4->text();
           double f0=f0_0.toDouble();

           QString f_0= ui->lineEdit_5->text();
           double f=f_0.toDouble();

           QString fd_0= ui->lineEdit_6->text();
           double fd=fd_0.toDouble();

           y_t=lchm(f0, f, fd);
    }


        else if(ui->sig_triug->isChecked())
        {
           QString t_0= ui->lineEdit_7->text();
           double t=t_0.toDouble();



           y_t=triug(t);
        }

int n=y_t.size();

    for(int i=0; i!=n; i++)
    {
        x_t.push_back(i);
        y_t_im.push_back(0);
    }




    ui->widget->xAxis->setRange(0,n);//установка xlabel
    ui->widget->yAxis->setRange(-1,1);

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x_t, y_t );//вывод графика на экран
    ui->widget->replot();


    emit signal(x_t, y_t, y_t_im); //отправка для спектра

   x_t.clear();
    y_t.clear();
    y_t_im.clear();
}




