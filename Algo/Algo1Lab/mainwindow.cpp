#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <math.h>
#include <QElapsedTimer>
using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    srand(time(0));
    int SIZE = 10;
    QString len1 = ui ->size->toPlainText().trimmed();
    SIZE = len1.toInt();
    double*array = new double[SIZE];
    double*array2 = new double[SIZE];


    for(int i = 0; i<SIZE; ++i)
    {
        array[i] = fRand(-100, 100);
    }


 QString arrayStr;
  QString arrayStr2;
  QString arrayStr3;
  QString arrayStr4;
  QString dur;

     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr += QString::number(array[i])+"\t";
     }
     ui->plainTextEdit->setPlainText(arrayStr);

     for(int i = 1; i < SIZE; i +=2)
             {
                 array[i] = sqrt(fabs(array[i]-10));


             }
     for(int i = 0; i<SIZE; ++i)
     {
         array2[i] = array[i];
     }

     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr2 += QString::number(array[i])+"\t";
     }
     ui->plainTextEdit_2->setPlainText(arrayStr2);
     QElapsedTimer timer;
     timer.start();
      Bubble_Sorting(array, SIZE);
    // ui->plainTextEdit_6->setPlainText("Time in nano seconds:"+ QString::number(timer.nsecsElapsed()));

     timer.restart();
     Bubble_Sorting_Without_Flag(array2, SIZE);
      ui->plainTextEdit_4->setPlainText("Time in nano seconds: "+QString::number(timer.nsecsElapsed()));








     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr3 += QString::number(array[i])+"\t";
     }
      ui->plainTextEdit_3->setPlainText(arrayStr3);
      for(int i = 0; i<SIZE; ++i)
      {
         arrayStr4 += QString::number(array2[i])+"\t";
      }
       ui->plainTextEdit_5->setPlainText(arrayStr4);




     delete [] array;



}

void MainWindow::on_pushButton_2_clicked()
{

    srand(time(0));
    int SIZE = 10;
    QString len1 = ui ->size->toPlainText().trimmed();
    SIZE = len1.toInt();
    double*array = new double[SIZE];
    double*array2 = new double[SIZE];
QString array1 = ui -> textEdit->toPlainText().trimmed();
QString array22 = ui -> textEdit_2->toPlainText().trimmed();
QString array3= ui -> textEdit_3->toPlainText().trimmed();
QString array4= ui -> textEdit_4->toPlainText().trimmed();
QString array5= ui -> textEdit_5->toPlainText().trimmed();
QString array6= ui -> textEdit_6->toPlainText().trimmed();
QString array7= ui -> textEdit_7->toPlainText().trimmed();
QString array8= ui -> textEdit_8->toPlainText().trimmed();
QString array9= ui -> textEdit_9->toPlainText().trimmed();
QString array10= ui -> textEdit_10->toPlainText().trimmed();
QString array11= ui -> textEdit_11->toPlainText().trimmed();
QString array12= ui -> textEdit_12->toPlainText().trimmed();
QString array13= ui -> textEdit_13->toPlainText().trimmed();
QString array14= ui -> textEdit_14->toPlainText().trimmed();


//if(SIZE>1)
    array[0]=array1.toDouble();
//if(SIZE>2)
    array[1]=array22.toDouble();
//if(SIZE>3)
    array[2]=array3.toDouble();
//if(SIZE>4)
    array[3]=array4.toDouble();
//if(SIZE>5)
    array[4]=array5.toDouble();
//if(SIZE>6)
    array[5]=array6.toDouble();
//if(SIZE>7)
    array[6]=array7.toDouble();
//if(SIZE>8)
    array[7]=array8.toDouble();
//if(SIZE>9)
    array[8]=array9.toDouble();
//if(SIZE>10)
    array[9]=array10.toDouble();
//if(SIZE>11)
    array[10]=array11.toDouble();
//if(SIZE>12)
    array[11]=array12.toDouble();
//if(SIZE>13)
    array[12]=array13.toDouble();
//if(SIZE>14)
    array[13]=array14.toDouble();

 QString arrayStr;
  QString arrayStr2;
  QString arrayStr3;
  QString arrayStr4;
  QString dur;


     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr += QString::number(array[i])+"\t";
     }
     ui->plainTextEdit->setPlainText(arrayStr);

     for(int i = 1; i < SIZE; i +=2)
             {
                 array[i] = sqrt(fabs(array[i]-10));


             }
     for(int i = 0; i<SIZE; ++i)
     {
         array2[i] = array[i];
     }

     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr2 += QString::number(array[i])+"\t";
     }
     ui->plainTextEdit_2->setPlainText(arrayStr2);
     QElapsedTimer timer;
     timer.start();
      Bubble_Sorting(array, SIZE);
   //  ui->plainTextEdit_6->setPlainText("Time in nano seconds:"+ QString::number(timer.nsecsElapsed()));

     timer.restart();
     Bubble_Sorting_Without_Flag(array2, SIZE);
     // ui->plainTextEdit_4->setPlainText("Time in nano seconds: "+QString::number(timer.nsecsElapsed()));








     for(int i = 0; i<SIZE; ++i)
     {
        arrayStr3 += QString::number(array[i])+"\t";
     }
     ui->plainTextEdit_3->setPlainText(arrayStr3);
      for(int i = 0; i<SIZE; ++i)
      {
         arrayStr4 += QString::number(array2[i])+"\t";
      }
       ui->plainTextEdit_5->setPlainText(arrayStr4);




     delete [] array;

}










