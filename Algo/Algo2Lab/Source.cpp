#include "mainwindow.h"
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void Sorting(double** arr, int size1, int size2)
{
    int min;
    for(int i = 0; i < size1 - 1; ++i)
    {
        min = i + 1;
        for(int j = i + 1; j < size1 - 1; ++j)
        {
            if(arr[0][j+1] < arr[0][min])
            {
                min = j+1;
            }
        }
            if(arr[0][i] >arr[0][min])
            {
                double temp = arr[0][i];
                arr[0][i] = arr[0][min];
                arr[0][min] = temp;
                for(int k = 1; k < size2; ++k)
                {
                    double temp2 = arr[k][i];
                    arr[k][i] = arr[k][min];
                    arr[k][min] = temp2;
                }



            }


    }
}
void Sorting2(double array[5][5], int size1, int size2)
{
    int min;
    for(int i = 0; i < size1 - 1; ++i)
    {
        min = i + 1;
        for(int j = i + 1; j < size1 - 1; ++j)
        {
            if(array[0][j+1] < array[0][min])
            {
                min = j+1;
            }
        }
            if(array[0][i] >array[0][min])
            {
                double temp = array[0][i];
                array[0][i] = array[0][min];
                array[0][min] = temp;
                for(int k = 1; k < size2; ++k)
                {
                    double temp2 = array[k][i];
                    array[k][i] = array[k][min];
                    array[k][min] = temp2;
                }

            }


    }
}


