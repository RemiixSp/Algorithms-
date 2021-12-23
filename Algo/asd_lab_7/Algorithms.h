#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QTextEdit>
#include <QTime>
#include<QTableWidget>
#include <QLineEdit>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <QMessageBox>
#include <QDebug>

class Algorithms {

private:
    int *array;
    int size;
    long double time;

public:
    Algorithms(){}
    Algorithms(int);
    ~Algorithms();

    void randomizeArray(int);
    void copyArray(const Algorithms &);
    void printArray(std::string);

    void bubbleSort();
    void selectionSort();
    void shellSort ();

    void mergeSorting(int, int);
    void mergeSort(int,int);
    void merge(int, int, int);

    void quickSorting(int, int);
    int partition(int, int);
    void quickSort(int, int);
    void countingSort();

    void swap(int *, int*);
    int *getArray() { return array;};
    int getSize() {return size;}
    long double getTime(){return time;}
    void setTime(long t){time=t;}
};

#endif // ALGORITHMS_H
