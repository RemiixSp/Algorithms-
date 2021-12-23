#ifndef ARRAY_H
#define ARRAY_H


class Array
{
    int size;
    double*array;
public:
    Array();
    Array(int size)
    {
        this->size = size;
        this->array = new double[this->size];
    }
    int getSize()
    {
        return 5;
    }
};

#endif // ARRAY_H
