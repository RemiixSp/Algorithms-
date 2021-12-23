#include "Algorithms.h"
#include <QElapsedTimer>


Algorithms::Algorithms(int size){
    this->size = size;
    array = new int [this->size];
    for(int i=0; i<this->size; ++i)
        array[i] = rand() % 1000000-500000;
}

void Algorithms::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Algorithms::printArray(std::string str){

    std::ofstream file;
    file.open(str + ".txt", std::ios::out | std::ios::trunc);
    for(int i=0; i<size; ++i)
        file << std::setw(10) << array[i];
    file.close();
}

void Algorithms::copyArray(const Algorithms &obj){
    this->size = obj.size;
    this->array = new int [this->size];
    for(int i=0; i<this->size; ++i)
        this->array[i] = obj.array[i];
}

void Algorithms::randomizeArray(int size){

    this->size = size;
    array = new int [this->size];
    for(int i=0; i<this->size; ++i)
        array[i] = rand() % 1000000-500000;
}

void Algorithms::bubbleSort(){
    QElapsedTimer timer;
    timer.restart();
    for(int i = 0; i < size; ++i){
        if (timer.elapsed()>5000){
            time=-1;
            return;
        }
        bool swapped = false;
        for(int j = 0; j < size - 1; ++j){
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    time =  timer.elapsed();
    printArray("BubbleSort" + std::to_string(size));
}

void Algorithms::selectionSort(){
    QElapsedTimer timer;
    timer.restart();
    int  min;
    for (int i = 0; i < size-1; ++i) {
        if (timer.elapsed()>5000){
            time=-1;
            return;
        }
        min = i;
        for(int j = i+1; j < size; ++j){
            if(array[j] < array[min]){
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
    time = timer.elapsed();
    printArray("SelectionSort" + std::to_string(size));
}

void Algorithms::shellSort(){
    QElapsedTimer timer;
    timer.restart();
    for (int gap = size/2; gap > 0; gap /= 2) {
        if (timer.elapsed()>5000){
            time=-1;
            return;
        }
        for (int i = gap; i < size; ++i) {
            double temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
    time = timer.elapsed();
    printArray("ShellSort" + std::to_string(size));
}

void Algorithms::mergeSorting(int left, int right){
    QElapsedTimer timer;
    timer.restart();
    mergeSort(left,right);
    time = timer.elapsed();
    printArray("MergeSort" + std::to_string(size));
}

void Algorithms::mergeSort(int left, int right){

    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void Algorithms::merge(int left, int mid, int right) {
    int leftN = mid - left + 1;
    int rightN = right - mid;
    std::vector<int> L, R;

    for (int i = 0; i < leftN; i++)
        L.push_back(array[left + i]);
    for (int j = 0; j < rightN; j++)
        R.push_back(array[mid + 1 + j]);

    int i = 0, j = 0, k = left;

    while (i < leftN && j < rightN) {
        if (L[i] <= R[j]) {

            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftN) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < rightN) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void Algorithms::quickSorting(int left, int right){
    QElapsedTimer timer;
    timer.restart();
    quickSort(left,right);
    time = timer.elapsed();
    printArray("QuickSort" + std::to_string(size));
}

int Algorithms::partition(int low, int high) {
    double pivot = array[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            swap(&i, &j);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void Algorithms::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void Algorithms::countingSort(){
    QElapsedTimer timer;
    timer.restart();
    int min = array[0], max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < min)
            min = array[i];

        else if (array[i] > max)
            max = array[i];
    }
    int *countArr = new int[max - min + 1];
    for (int i = 0; i < max - min+1; ++i)
        countArr[i] = 0;

    for (int i = 0; i < size; ++i)
        countArr[array[i] - min] += 1;

    for (int i = 1; i < max - min + 1; ++i)
        countArr[i] += countArr[i - 1];

    int *tmpArr = new int[size];

    for (int i = size - 1; i >= 0; --i)
        tmpArr[--countArr[array[i] - min]] = array[i];

    for (int i = 0; i < size; ++i)
        array[i] = tmpArr[i];

    time = timer.elapsed();
    delete[]tmpArr;
    delete[]countArr;
    printArray("CountingSort" + std::to_string(size));
}

Algorithms::~Algorithms(){
    delete [] array;
}
