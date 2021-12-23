#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QElapsedTimer"
QString output;
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
void merge(double *arr, int low, int high, int mid, int size)
{
    int i, j, k;
   double c[500];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
    for(int i =0; i<size; ++i)
    {
        output += QString::number(arr[i], 'g', 3)+"   ";
    }
    output +="\n";


}
void merge_sort(double *arr, int low, int high, int arrSize)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid, arrSize);
        merge_sort(arr,mid+1,high, arrSize);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid, arrSize);


    }
}

void MainWindow::on_randomArr_clicked()
{
    srand(time(0));
    int arrSize = ui->size->toPlainText().trimmed().toInt();
    double*arr = new double[arrSize];
    for(int i = 0; i<arrSize; ++i)
    {
        arr[i] = fRand(-50, 50);
    }


    QString randomArray;
    for(int i = 0; i<arrSize; ++i)
    {
        randomArray += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->startedArr->setPlainText(randomArray);

    for(int i = 0; i< arrSize; ++i)
    {
        if(arr[i]<0)
            arr[i] = sin(arr[i]);

    }

    QString sinus;
    for(int i = 0; i<arrSize; ++i)
    {
        sinus += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->changedArr->setPlainText(sinus);

QElapsedTimer timer;

timer.start();
    merge_sort(arr, 0, arrSize-1, arrSize);
    ui->time->setPlainText("Time: "+QString::number(timer.nsecsElapsed()));

    QString sorting;
    for(int i = 0; i<arrSize; ++i)
    {
        sorting += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->sortedArray->setPlainText(sorting);

    ui->step->setPlainText(output);
    output = "";




    delete [] arr;

}

void MainWindow::on_ownArr_clicked()
{
    int arrSize = ui->size->toPlainText().trimmed().toInt();
    double*arr = new double[arrSize];

    QString array1 =ui ->textEdit->toPlainText().trimmed();
    QString array2 =ui -> textEdit_2->toPlainText().trimmed();
    QString array3 =ui -> textEdit_3->toPlainText().trimmed();
    QString array4 =ui -> textEdit_4->toPlainText().trimmed();
    QString array5 =ui -> textEdit_5->toPlainText().trimmed();
    QString array6 =ui -> textEdit_6->toPlainText().trimmed();
    QString array7=ui -> textEdit_7->toPlainText().trimmed();
    QString array8 =ui -> textEdit_8->toPlainText().trimmed();
    QString array9 =ui -> textEdit_9->toPlainText().trimmed();
    QString array10 =ui -> textEdit_10->toPlainText().trimmed();
    QString array11 =ui -> textEdit_11->toPlainText().trimmed();

    if(arrSize>0)
    arr[0] = array1.toInt();
    if(arrSize>1)
    arr[1] = array2.toInt();
    if(arrSize>2)
    arr[2] = array3.toInt();
    if(arrSize>3)
    arr[3] = array4.toInt();
   if(arrSize>4)
    arr[4] = array5.toInt();
    if(arrSize>5)
    arr[5] = array6.toInt();
    if(arrSize>6)
    arr[6] = array7.toInt();
    if(arrSize>7)
    arr[7] = array8.toInt();
    if(arrSize>8)
    arr[8] = array9.toInt();
    if(arrSize>9)
    arr[9] = array10.toInt();
    if(arrSize>10)
    arr[10] = array11.toInt();

    QString keybord;
    for(int i = 0; i<arrSize; ++i)
    {
        keybord += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->startedArr->setPlainText(keybord);

    for(int i = 0; i< arrSize; ++i)
    {
        if(arr[i]<0)
            arr[i] = sin(arr[i]);

    }


    QString sinus;
    for(int i = 0; i<arrSize; ++i)
    {
        sinus += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->changedArr->setPlainText(sinus);


QElapsedTimer timer;
    timer.start();
        merge_sort(arr, 0, arrSize-1, arrSize);
        ui->time->setPlainText("Time: "+QString::number(timer.nsecsElapsed()));

    QString sorting;
    for(int i = 0; i<arrSize; ++i)
    {
        sorting += QString::number(arr[i], 'g', 3)+"   ";
    }
    ui->sortedArray->setPlainText(sorting);

    ui->step->setPlainText(output);

    output = "";





    delete [] arr;





}
