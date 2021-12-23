#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Algorithms.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QValidator>

const int count = 6;
long double sizeArr[7] = {1024, 4096, 16384, 65536, 262144, 1048576, 4194304};
Algorithms *AlgoArray = new Algorithms [count];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0 ; i<ui->tableWidget->rowCount(); ++i){
        for(int j=0; j<ui->tableWidget->columnCount(); ++j){
            if(!ui->tableWidget->item(i,j)){
                QTableWidgetItem *item = new QTableWidgetItem;
                ui->tableWidget->setItem(i,j, item);
                ui->tableWidget->item(i,j)->setText("");
            }
        }
    }
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_sort_clicked(){
    AlgoArray[0].randomizeArray(ui->comboBox->currentText().toInt());
    for(int i=1; i < count; ++i)
        AlgoArray[i].copyArray(AlgoArray[0]);
    AlgoArray[0].bubbleSort();
    AlgoArray[1].selectionSort();
    AlgoArray[2].shellSort();
    AlgoArray[3].quickSorting(0, AlgoArray[3].getSize() - 1);
    AlgoArray[4].mergeSorting(0, AlgoArray[4].getSize() - 1);
    AlgoArray[5].countingSort();
    for(int i=0; i<ui->tableWidget->rowCount(); ++i){
        ui->tableWidget->item(i, ui->comboBox->currentIndex())->setText(QString::number(AlgoArray[i].getTime(), 'g', 10));
    }
}

void MainWindow::on_pushButton_showDiagram_clicked(){
    QLineSeries **series =  new QLineSeries *[count]();

        for(int i=0; i<count; ++i)
            series[i] = new QLineSeries();

        for(int i=0; i<count; ++i)
            series[i]->append(0,0);

        for(int i=0; i<ui->tableWidget->rowCount(); ++i){
            for(int j=0; j<ui->tableWidget->columnCount(); ++j){
                if(ui->tableWidget->item(i,j)->text() != ""){

                    if(ui->tableWidget->item(i,j)->text() == "-1"){
                        int jCount=j-1;
                        while (ui->tableWidget->item(i,jCount)->text() == "-1"){
                            jCount--;
                        }
                        double k=ui->tableWidget->horizontalHeaderItem(j)->text().toDouble()/ui->tableWidget->horizontalHeaderItem(jCount)->text().toDouble();
                        int approximateTime=ui->tableWidget->item(i,jCount)->text().toDouble()*k*k;
                        AlgoArray[i].setTime(approximateTime);

                        series[i]->append(ui->tableWidget->horizontalHeaderItem(j)->text().toDouble(), approximateTime);
                    }
                    else
                        series[i]->append(ui->tableWidget->horizontalHeaderItem(j)->text().toDouble(), ui->tableWidget->item(i,j)->text().toDouble());
                }
            }
        }

        series[0]->setName("BubbleSort");
        series[1]->setName("SelectionSort");
        series[2]->setName("ShellSort");
        series[3]->setName("QuickSort");
        series[4]->setName("MergeSort");
        series[5]->setName("CountingSort");

        series[0]->setColor(Qt::darkMagenta);
        series[1]->setColor(Qt::blue);
        series[2]->setColor(Qt::darkBlue);
        series[3]->setColor(Qt::yellow);
        series[4]->setColor(Qt::cyan);
        series[5]->setColor(Qt::magenta);

        for(int i=0; i<count; ++i){
            series[i]->setPointsVisible(true);
            series[i]->pen().setWidth(10);
        }

        QChart *chart = new QChart();
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        chart->setMinimumSize(1400,500);

        for(int i=0; i<count; ++i)
            chart->addSeries(series[i]);

        chart->createDefaultAxes();

        chart->axisX()->setTitleText("Size of array");
        chart->axisY()->setMin(-1);
        chart->axisX()->setMin(-1);
        chart->axisY()->setTitleText("Time");

        chart->setTitle("Sorting");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->horizontalFrame);
        chartView->show();

        QPieSeries * series2 = new QPieSeries[count]();
            long totalTime = 0;
            for (int i=0; i<count; i++){
                totalTime+=AlgoArray[i].getTime();
            }

            for(int i=0; i<count; ++i){
                    series2->append(ui->tableWidget->verticalHeaderItem(i)->text(), AlgoArray[i].getTime()/totalTime);
            }

            QPieSlice **slices = new QPieSlice*[count];
            for (int i=0; i<count; i++){
                slices[i]=series2->slices().at(i);
                slices[i]->setLabelVisible();
            }

            slices[0]->setColor(Qt::darkMagenta);
            slices[1]->setColor(Qt::blue);
            slices[2]->setColor(Qt::darkBlue);
            slices[3]->setColor(Qt::yellow);
            slices[4]->setColor(Qt::cyan);
            slices[5]->setColor(Qt::magenta);

            QChart *chart2 = new QChart();
            chart2->setMinimumSize(600,500);
            chart2->addSeries(series2);
            chart2->setAnimationOptions(QChart::SeriesAnimations);

            QChartView *chartView2 = new QChartView(chart2);
            chartView2->setRenderHint(QPainter::Antialiasing);
            chartView2->setParent(ui->horizontalFrame_2);
            chartView2->show();
}
