#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

template <typename T> // Template Declaration
class MyArray
{
private:
    T *data;
    int size;
    int capacity;

public:
    MyArray()
    {
        capacity = 5;
        size = 0;
        data = new T[capacity]; // Dynamically Allocated Array
    }
    ~MyArray()
    {
        delete[] data;
    }
    void append(T value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T *temp = new T[capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
        }
        data[size++] = value;
    }
    void prepend(T value)
    {
        if (size >= capacity)
        {
            T *temp = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity = capacity * 2;
        }
        cout << "    SIZE = " << size;
        for (int i = size; i>0; i--)
        {
            data[i] = data[i-1];
        }
        data[0] = value;
        size +=1 ;
        cout  << "    NEW SIZE = " << size;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << endl;
        }
    }
    int get_size()
    {
        return size;
    }
    int get_capacity()
    {
        return capacity;
    }
    T *get_array()
    {
        return data;
    }
    
};

#endif
