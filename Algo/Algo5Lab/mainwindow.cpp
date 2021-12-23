#include "mainwindow.h"
#include "ui_mainwindow.h"
QString output;
#include <QElapsedTimer>
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

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void modifiing(double**arr, int size, int size2)
{
    double min = arr[0][0];
      int index=0;
      for(int i = 0; i<size; ++i)
      {

          for(int j = 0; j<size2; ++j)
          {
             if(arr[i][j]<min)
             {
                 min = arr[i][j];
                 index=j;

             }
          }
          if(arr[i][index])
          arr[i][index] = log(fabs(arr[i][index]));
          min = 100;

      }


}


void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}



int partition (double **arr, int low, int high, int size, int size2)
{
    double pivot = arr[0][high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[0][j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[0][i], &arr[0][j]);



            for(int k = 1; k < size; ++k)
                           {
                               double temp2 = arr[k][i];
                               arr[k][i] = arr[k][j];
                               arr[k][j] = temp2;
                           }

        }
    }
    swap(&arr[0][i + 1], &arr[0][high]);
    for(int k = 1; k < size; ++k)
                   {
                       double temp2 = arr[k][i+1];
                       arr[k][i+1] = arr[k][high];
                       arr[k][high] = temp2;
                   }
    for(int i = 0; i < size; ++i)
    {
         output += "|";
        for(int j = 0; j < size2; ++j)
        {
            output += QString::number(arr[i][j], 'g',2)+"\t";
        }
        output += "|";
          output += "\n";
    }
     output += "\n";



    return (i + 1);
}

void quickSort(double **arr, int low, int high, int size, int size2)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, size, size2);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, size, size2);
        quickSort(arr, pi + 1, high, size, size2);
    }
}









void MainWindow::on_pushButton_clicked()
{
    srand(time(0));
    QString size1= ui ->size1 ->toPlainText().trimmed();
    QString size2= ui ->size2 ->toPlainText().trimmed();
    int arrSize1 = size1.toInt();
    int arrSize2 = size2.toInt();
    QString mainArrWindow;
    QString modifiedArray;
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

    modifiing(array, arrSize1, arrSize2);


    for(int i = 0; i < arrSize1; ++i)
    {
         modifiedArray += "|";
        for(int j = 0; j < arrSize2; ++j)
        {
            modifiedArray+= QString::number(array[i][j], 'g',2)+"\t";
        }
        modifiedArray += "|";
         modifiedArray += "\n";
    }


    ui->plainTextEdit_2 ->setPlainText(modifiedArray);
    QElapsedTimer timer;
    timer.start();

    quickSort(array, 0, arrSize2 - 1, arrSize1, arrSize2);
    ui->plainTextEdit_5->setPlainText("Time taken in nanosecond  "+QString::number(timer.nsecsElapsed()));

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

    ui->plainTextEdit_4 ->setPlainText(sortedWindow);
    ui->plainTextEdit_3 ->setPlainText(output);


output ="";


    for(int i = 0; i < arrSize1; ++i)
      delete [] array[i];
    delete [] array;
}

void MainWindow::on_pushButton_2_clicked()
{
    srand(time(0));
    QString size1= ui ->size1 ->toPlainText().trimmed();
    QString size2= ui ->size2 ->toPlainText().trimmed();
    QString mainArrWindow;
    QString sortedWindow;
     QString modifiedArray;
    int arrSize1 = size1.toInt();
    int arrSize2 = size2.toInt();


    double **array = new double*[10];
    for(int i = 0; i < 10; ++i)
        array[i] = new double[10];


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

    modifiing(array, arrSize1, arrSize2);

    for(int i = 0; i < arrSize1; ++i)
    {
         modifiedArray += "|";
        for(int j = 0; j < arrSize2; ++j)
        {
            modifiedArray+= QString::number(array[i][j], 'g',2)+"\t";
        }
        modifiedArray += "|";
         modifiedArray += "\n";
    }


    ui->plainTextEdit_2 ->setPlainText(modifiedArray);
QElapsedTimer timer;
timer.start();
    quickSort(array, 0, arrSize2 - 1, arrSize1, arrSize2);
 ui->plainTextEdit_5->setPlainText("Time taken in nanosecond  "+QString::number(timer.nsecsElapsed()));
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

    ui->plainTextEdit_4 ->setPlainText(sortedWindow);
     ui->plainTextEdit_3 ->setPlainText(output);


output ="";


    for(int i = 0; i < arrSize1; ++i)
      delete [] array[i];
    delete [] array;
}
