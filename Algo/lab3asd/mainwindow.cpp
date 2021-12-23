#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include<QElapsedTimer>
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
    QString length = ui ->textEdit->toPlainText().trimmed();
   int size = length.toInt();
   QVector<int> vect(size);
   for(int i = 0; i<vect.size(); ++i)
   {
       vect[i] = rand()%10;
   }
   QString mainVect;

   for(int i = 0; i<vect.size(); ++i)
   {
       mainVect += QString::number(vect[i])+"  ";
   }
   ui -> plainTextEdit_2->setPlainText(mainVect);

   int moda = vect[0], count = 0, amount = 0;
           for (int i = 0; i < vect.size(); i++) {
               if (count > amount) {
                   amount = count;
                   moda = vect[i - 1];
               }
               count = 0;
               for (int j = i; j < vect.size(); j++){
                  if (vect[j] == vect[i]){
                     count++;
                  }
               }
           }
           for (int i=0;i<vect.size();i++) {
                if(vect[i]==moda){
                vect.erase(vect.begin() + i);
                i--;
                  }
              }
       ui -> mostOften -> setPlainText(QString::number(moda));

      QString changedArr;

      for(int i = 0; i<vect.size(); ++i)
      {
          changedArr += QString::number(vect[i])+"  ";
      }
      ui -> plainTextEdit_3->setPlainText(changedArr);

      QElapsedTimer timer;
      QString steped;
      timer.start();
      int j;
      int step=vect.size()/2;
      while (step>0) {
          for (int i=0 ;i<vect.size()-step;i++) {
              j=i;
              while ((j>=0)&&(vect[j]>vect[j+step])) {
                  double temp=vect[j];
                  vect[j]=vect[j+step];
                  vect[j+step]=temp;
                  j--;
                }
              for(int j = 0; j <vect.size(); ++j)
              {
                  steped += QString::number(vect[j])+"  ";
              }



              steped+="\n";

            }
          for(int j = 0; j <vect.size(); ++j)
          {
              steped += QString::number(vect[j])+"  ";
          }



          steped+="\n";


            step=step/2;
        }
      ui->plainTextEdit_5->setPlainText("Time taken in nanosecs:  "+QString::number(timer.nsecsElapsed()));

      QString sortedArr;

      for(int i = 0; i<vect.size(); ++i)
      {
          sortedArr += QString::number(vect[i])+"  ";
      }
      ui -> plainTextEdit_4->setPlainText(steped);




}

void MainWindow::on_pushButton_2_clicked()
{
    QString length = ui ->textEdit->toPlainText().trimmed();
   int size = length.toInt();
   QVector<int> vect(size);
   QString array1 =ui ->arr1->toPlainText().trimmed();
   QString array2 =ui -> arr1_2->toPlainText().trimmed();
   QString array3 =ui -> arr1_3->toPlainText().trimmed();
   QString array4 =ui -> arr1_4->toPlainText().trimmed();
   QString array5 =ui -> arr1_5->toPlainText().trimmed();
   QString array6 =ui -> arr1_6->toPlainText().trimmed();
   QString array7=ui -> arr1_7->toPlainText().trimmed();
   QString array8 =ui -> arr1_8->toPlainText().trimmed();

   if(size>0)
   vect[0] = array1.toInt();
   if(size>1)
   vect[1] = array2.toInt();
   if(size>2)
   vect[2] = array3.toInt();
   if(size>3)
   vect[3] = array4.toInt();
  if(size>4)
   vect[4] = array5.toInt();
   if(size>5)
   vect[5] = array6.toInt();
   if(size>6)
   vect[6] = array7.toInt();
   if(size>7)
   vect[7] = array8.toInt();

   QString mainVect;

   for(int i = 0; i<vect.size(); ++i)
   {
       mainVect += QString::number(vect[i])+"  ";
   }
   ui -> plainTextEdit_2->setPlainText(mainVect);


   int moda = vect[0], count = 0, amount = 0;
           for (int i = 0; i < vect.size(); i++) {
               if (count > amount) {
                   amount = count;
                   moda = vect[i - 1];
               }
               count = 0;
               for (int j = i; j < vect.size(); j++){
                  if (vect[j] == vect[i]){
                     count++;
                  }
               }
           }
       for (int i=0;i<vect.size();i++) {
                if(vect[i]==moda){
                vect.erase(vect.begin() + i);
                i--;
                  }
              }
       ui -> mostOften -> setPlainText(QString::number(moda));

      QString changedArr;

      for(int i = 0; i<vect.size(); ++i)
      {
          changedArr += QString::number(vect[i])+"  ";
      }
      ui -> plainTextEdit_3->setPlainText(changedArr);
QString test;
QString steped;
      QElapsedTimer timer;
      timer.start();
      int j;
      int step=vect.size()/2;
      while (step>0) {
          for (int i=0 ;i<vect.size()-step;i++) {
              j=i;
              while ((j>=0)&&(vect[j]>vect[j+step])) {
                  double temp=vect[j];
                  vect[j]=vect[j+step];
                  vect[j+step]=temp;
                  j--;
                  for(int j = 0; j <vect.size(); ++j)
                  {
                      steped += QString::number(vect[j])+"  ";
                  }



                  steped+="\n";

                }


            }


            step=step/2;
        }
      ui->plainTextEdit_5->setPlainText("Time taken in nanosecs:  "+QString::number(timer.nsecsElapsed()));

      QString sortedArr;

      for(int i = 0; i<vect.size(); ++i)
      {
          sortedArr += QString::number(vect[i])+"  ";
      }
      ui -> plainTextEdit_4->setPlainText(steped);







}
