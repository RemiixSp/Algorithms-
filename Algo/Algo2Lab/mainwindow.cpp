#include "mainwindow.h"
#include "ui_mainwindow.h"
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





void MainWindow::on_pushButton_2_clicked()
{
    srand(time(0));
    QString size1= ui ->size1 ->toPlainText().trimmed();
    QString size2= ui ->size2 ->toPlainText().trimmed();
    int arrSize1 = size1.toInt();
    int arrSize2 = size2.toInt();
    QString mainArrWindow;
    QString sortedWindow;

    double **array = new double*[arrSize1];
    for(int i = 0; i < arrSize1; ++i)
        array[i] = new double[arrSize2];
    for(int i = 0; i < arrSize1; ++i)
    {
        for(int j = 0; j < arrSize2; ++j)
        {
            array[i][j]=fRand(-10, 10);
        }
    }
    for(int i = 0; i < arrSize1; ++i)
    {
         mainArrWindow += "|";
        for(int j = 0; j < arrSize2; ++j)
        {
            mainArrWindow += QString::number(array[i][j], 'g',2)+"\t";
        }
        mainArrWindow += "|";
         mainArrWindow += "\n";
    }

    ui -> plainTextEdit -> setPlainText(mainArrWindow);

     Sorting(array, arrSize1,arrSize2);


     for(int i = 0; i < arrSize1; ++i)
     {
          sortedWindow += "|";
         for(int j = 0; j < arrSize2; ++j)
         {
             sortedWindow += QString::number(array[i][j], 'g',2)+"\t";
         }
         sortedWindow += "|";
          sortedWindow += "\n";
     }
     ui -> plainTextEdit_2 -> setPlainText(sortedWindow);







    for(int i = 0; i < arrSize1; ++i)
      delete [] array[i];
    delete [] array;
}

void MainWindow::on_pushButton_3_clicked()
{
    srand(time(0));
    QString size1= ui ->size1 ->toPlainText().trimmed();
    QString size2= ui ->size2 ->toPlainText().trimmed();
    QString mainArrWindow;
    QString sortedWindow;
    int arrSize1 = size1.toInt();
    int arrSize2 = size2.toInt();
    double array[5][5];
    /*
    double **array = new double*[arrSize1];
    for(int i = 0; i < arrSize1; ++i)
        array[i] = new double[arrSize2];
        */

    if(arrSize1>=1 || arrSize2>=1 )
    array[0][0] = ui->plainTextEdit_00->toPlainText().trimmed().toDouble();
    if(arrSize1>=1 || arrSize2>=2 )
    array[0][1] = ui->plainTextEdit_01->toPlainText().trimmed().toDouble();
    if(arrSize1>=1 || arrSize2>=3 )
    array[0][2] = ui->plainTextEdit_02->toPlainText().trimmed().toDouble();

    array[0][3] = ui->plainTextEdit_03->toPlainText().trimmed().toDouble();

    array[0][4] = ui->plainTextEdit_04->toPlainText().trimmed().toDouble();

    array[1][0] = ui->plainTextEdit_10->toPlainText().trimmed().toDouble();

    array[1][1] = ui->plainTextEdit_11->toPlainText().trimmed().toDouble();

    array[1][2] = ui->plainTextEdit_12->toPlainText().trimmed().toDouble();

    array[1][3] = ui->plainTextEdit_13->toPlainText().trimmed().toDouble();

    array[1][4] = ui->plainTextEdit_14->toPlainText().trimmed().toDouble();

    array[2][0] = ui->plainTextEdit_20->toPlainText().trimmed().toDouble();

    array[2][1] = ui->plainTextEdit_21->toPlainText().trimmed().toDouble();

    array[2][2] = ui->plainTextEdit_22->toPlainText().trimmed().toDouble();

    array[2][3] = ui->plainTextEdit_23->toPlainText().trimmed().toDouble();

    array[2][4] = ui->plainTextEdit_24->toPlainText().trimmed().toDouble();

    array[3][0] = ui->plainTextEdit_30->toPlainText().trimmed().toDouble();

    array[3][1] = ui->plainTextEdit_31->toPlainText().trimmed().toDouble();

    array[3][2] = ui->plainTextEdit_32->toPlainText().trimmed().toDouble();

    array[3][3] = ui->plainTextEdit_33->toPlainText().trimmed().toDouble();

    array[3][4] = ui->plainTextEdit_34->toPlainText().trimmed().toDouble();

    array[4][0] = ui->plainTextEdit_40->toPlainText().trimmed().toDouble();

    array[4][1] = ui->plainTextEdit_41->toPlainText().trimmed().toDouble();

    array[4][2] = ui->plainTextEdit_42->toPlainText().trimmed().toDouble();

    array[4][3] = ui->plainTextEdit_43->toPlainText().trimmed().toDouble();

    array[4][4] = ui->plainTextEdit_44->toPlainText().trimmed().toDouble();




    for(int i = 0; i < arrSize1; ++i)
    {
         mainArrWindow += "|";
        for(int j = 0; j < arrSize2; ++j)
        {
            mainArrWindow += QString::number(array[i][j], 'g',2)+"\t";
        }
        mainArrWindow += "|";
         mainArrWindow += "\n";
    }

    ui -> plainTextEdit -> setPlainText(mainArrWindow);

     Sorting2(array, arrSize1,arrSize2);


     for(int i = 0; i < arrSize1; ++i)
     {
          sortedWindow += "|";
         for(int j = 0; j < arrSize2; ++j)
         {
             sortedWindow += QString::number(array[i][j], 'g',2)+"\t";
         }
         sortedWindow += "|";
          sortedWindow += "\n";
     }
     ui -> plainTextEdit_2 -> setPlainText(sortedWindow);












/*
    for(int i = 0; i < arrSize1; ++i)
      delete [] array[i];
    delete [] array;
    */

}












