#include "mainwindow.h"
#include "ui_mainwindow.h"
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



void countingSort(int arr[], int n) {
  int arr1[50];

  int x = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > x)
      x = arr[i];
  }


  int count_arr[50];

  for (int i = 0; i <= x; ++i) {
    count_arr[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count_arr[arr[i]]++;
  }

  for(int i = 0; i<=x; ++i)
  {
      output+=QString::number(count_arr[i])+"  ";
  }
   output+="\n";

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }


  for (int i = n - 1; i >= 0; i--) {
    arr1[count_arr[arr[i]] - 1] = arr[i];
    count_arr[arr[i]]--;
  }


  for (int i = 0; i < n; i++) {
    arr[i] = arr1[i];
  }
}





void MainWindow::on_pushButton_clicked()
{

    QString size1 = ui ->size1->toPlainText().trimmed();
     QString size2 = ui ->size2->toPlainText().trimmed();
     int arrSize1 = size1.toInt();
     int arrSize2 = size2.toInt();

     int firstArray[arrSize1];
     int secondArray[arrSize2];

     for(int i = 0; i<arrSize1; ++i)
     {
         firstArray[i] = rand()%20;
     }
     for(int i = 0; i<arrSize2; ++i)
     {
         secondArray[i] = rand()%20;
     }
     QString first, second;

     for(int i = 0; i<arrSize1; ++i)
     {
         first += QString::number(firstArray[i])+"  ";
     }
     for(int i = 0; i<arrSize2; ++i)
     {
         second += QString::number(secondArray[i])+"  ";
     }
     ui->plainTextEdit->setPlainText(first);
     ui->plainTextEdit_2->setPlainText(second);

     int index1=0;
             int index2=0;

     for(int i = 0; i<arrSize1; ++i)
     {
         if(firstArray[i]%2==0)
             ++index1;
     }
     for(int i = 0; i<arrSize2; ++i)
     {
         if(secondArray[i]%2!=0)
             ++index2;
     }
      int arrSize3 = index1+index2;
     int mainArr[arrSize3];


     int mArrInd=0;
     for(int i = 0; i <arrSize1;++i)
     {
         if(firstArray[i]%2==0)
         {
             mainArr[mArrInd]= firstArray[i];
             ++mArrInd;
         }



     }


     for(int i = 0; i <arrSize2;++i)
     {
         if(secondArray[i]%2!=0)
         {
             mainArr[mArrInd]= secondArray[i];
             ++mArrInd;


         }

     }

     QString mixed;

     for(int i = 0; i<arrSize3; ++i)
     {
         mixed += QString::number(mainArr[i])+"  ";
     }

     ui->plainTextEdit_3->setPlainText(mixed);

     QString sorted;
     int n = sizeof(mainArr) / sizeof(mainArr[0]);
     countingSort(mainArr, n);


     for(int i = 0; i<arrSize3; ++i)
     {
         sorted += QString::number(mainArr[i])+"  ";
     }


     ui->plainTextEdit_4->setPlainText(sorted);
     ui->plainTextEdit_5->setPlainText(output);
     output="";






}

void MainWindow::on_pushButton_2_clicked()
{
    QString size1 = ui ->size1->toPlainText().trimmed();
     QString size2 = ui ->size2->toPlainText().trimmed();
     int arrSize1 = size1.toInt();
     int arrSize2 = size2.toInt();

     int firstArray[20];
     int secondArray[20];

     firstArray[0] = ui->a1->toPlainText().trimmed().toInt();
     firstArray[1] = ui->a1_2->toPlainText().trimmed().toInt();
     firstArray[2] = ui->a1_3->toPlainText().trimmed().toInt();
     firstArray[3] = ui->a1_4->toPlainText().trimmed().toInt();
     firstArray[4] = ui->a1_5->toPlainText().trimmed().toInt();
     firstArray[5] = ui->a1_6->toPlainText().trimmed().toInt();
     firstArray[6] = ui->a1_7->toPlainText().trimmed().toInt();
     firstArray[7] = ui->a1_8->toPlainText().trimmed().toInt();


     secondArray[0] = ui->b1->toPlainText().trimmed().toInt();
     secondArray[1] = ui->b1_2->toPlainText().trimmed().toInt();
     secondArray[2] = ui->b1_3->toPlainText().trimmed().toInt();
     secondArray[3] = ui->b1_4->toPlainText().trimmed().toInt();
     secondArray[4] = ui->b1_5->toPlainText().trimmed().toInt();
     secondArray[5] = ui->b1_6->toPlainText().trimmed().toInt();
     secondArray[6] = ui->b1_7->toPlainText().trimmed().toInt();
     secondArray[7] = ui->b1_8->toPlainText().trimmed().toInt();





     QString first, second;

     for(int i = 0; i<arrSize1; ++i)
     {
         first += QString::number(firstArray[i])+"  ";
     }
     for(int i = 0; i<arrSize2; ++i)
     {
         second += QString::number(secondArray[i])+"  ";
     }
     ui->plainTextEdit->setPlainText(first);
     ui->plainTextEdit_2->setPlainText(second);

     int index1=0;
             int index2=0;

     for(int i = 0; i<arrSize1; ++i)
     {
         if(firstArray[i]%2==0)
             ++index1;
     }
     for(int i = 0; i<arrSize2; ++i)
     {
         if(secondArray[i]%2!=0)
             ++index2;
     }
      int arrSize3 = index1+index2;
     int mainArr[arrSize3];


     int mArrInd=0;
     for(int i = 0; i <arrSize1;++i)
     {
         if(firstArray[i]%2==0)
         {
             mainArr[mArrInd]= firstArray[i];
             ++mArrInd;
         }



     }


     for(int i = 0; i <arrSize2;++i)
     {
         if(secondArray[i]%2!=0)
         {
             mainArr[mArrInd]= secondArray[i];
             ++mArrInd;


         }

     }

     QString mixed;

     for(int i = 0; i<arrSize3; ++i)
     {
         mixed += QString::number(mainArr[i])+"  ";
     }

     ui->plainTextEdit_3->setPlainText(mixed);

     QString sorted;
     int n = sizeof(mainArr) / sizeof(mainArr[0]);
     countingSort(mainArr, n);


     for(int i = 0; i<arrSize3; ++i)
     {
         sorted += QString::number(mainArr[i])+"  ";
     }


     ui->plainTextEdit_4->setPlainText(sorted);
}
