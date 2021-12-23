#include "mainwindow.h"
void Bubble_Sorting(double* array, int SIZE)
{
    bool p;
             for(int i = 0; i < SIZE; ++i)
             {
                 p = false;
                 for(int j = 0; j < SIZE-1; ++j)
                 {
                     if(array[j] > array[j+1])
                     {
                         double temp = array[j];
                         array[j] = array[j+1];
                         array[j+1] = temp;

                         p= true;
                     }
                 }

               if(p == false)
                 break;

             }
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void Bubble_Sorting_Without_Flag(double* array, int SIZE)
{

             for(int i = 0; i < SIZE; ++i)
             {

                 for(int j = 0; j < SIZE-1; ++j)
                 {
                     if(array[j] > array[j+1])
                     {
                         double temp = array[j];
                         array[j] = array[j+1];
                         array[j+1] = temp;


                     }
                 }



             }
}
