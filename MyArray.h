#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
private:
    int row_count;
    int *col_size;
    T **array;

public:
    // 1.	Constructor: Initializes an empty 2D array with row size set to 3 and column sizes set to 0 for each row.
    MyArray()
    {
        row_count = 3;
        col_size = new int[row_count];
        array = new T *[row_count];
        for (int i = 0; i < row_count; ++i)
        {
            col_size[i] = 0;
            array[i] = nullptr;
        }
    }

    // 2.	Destructor: Frees the dynamically allocated memory.
    ~MyArray()
    {
        if (array)
        {
            for (int i = 0; i < row_count; ++i)
            {
                delete[] array[i];
            }
            delete[] array;
            array = nullptr;
        }
        delete[] col_size;
        col_size = nullptr;
        row_count = 0;
    }

    // 3.	Add a new Row: Add a new empty row at the index and increase the row_count by 1 and shifting the previous columns to right.
    void addRow(int row_index)
    {
        if (row_index < 0 || row_index > row_count)
        {
            row_index = row_count;
        }

        int newcount = row_count + 1;
        int *newColSize = new int[row_count + 1];
        T **newArray = new T *[row_count + 1];

        for (int i = 0; i < row_index; i++)
        {
            newColSize[i] = col_size[i];
            newArray[i] = array[i];
        }

        newArray[row_index] = nullptr;
        newColSize[row_index] = 0;

        for (int i = row_index; i < row_count + 1; i++)
        {
            newArray[i + 1] = array[i];
            newColSize[i + 1] = col_size[i];
        }

        delete[] array;
        delete[] col_size;
        array = newArray;
        col_size = newColSize;
        row_count = newcount;
    }

    // 4.	Deletes an existing Row: Deletes a complete row shifting the remaining rows to the left..
    void deleteRow(int row_index)
    {
        if (row_index < 0 || row_index >= row_count)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        if (array[index] != nullptr)
        {
            delete[] array[row_index];
            array[row_index] = nullptr;
        }

        int newcount = row_count - 1;

        if (newcount == 0)
        {
            delete[] array;
            delete[] col_size;
            row_count = 0;
            array = nullptr;
            col_size = nullptr;
            return;
        }

        int *newColSize = new int[newcount];
        T **newArray = new T *[newcount];

        for (int i = 0; i < row_index; i++)
        {
            newColSize[i] = col_size[i];
            newArray[i] = array[i];
        }

        for (int i = row_index; i < newcount; i++)
        {
            newArray[i] = array[i + 1];
            newColSize[i] = col_size[i + 1];
        }

        delete[] array;
        delete[] col_size;

        array = newArray;
        col_size = newColSize;
        row_count = newcount;
    }

    // 5.	Append Function: Adds an element at the end of the specified row.
    void append(T value, int row_num)
    {
        if (row_num < 0 || row_num >= row_count)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        // int* newColSize = new int[newcount];
        // array[row_num]

        int n = col_size[row_num];
        int newSize = n + 1;
        T *arr = new T[newSize];

        for (int i = 0; i < col_size[row_num]; i++)
        {
            arr[i] = array[row_num][i];
        }

        arr[newSize - 1] = value;
        delete[] array[row_num];
        array[row_num] = arr;
        col_size[row_num] = newSize;
    }

    // 6.	Prepend Function: Adds an element at the start of the specified row.
    void prepend(T value, int row_num)
    {
        if (row_num < 0 || row_num >= row_count)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        
        int n = col_size[row_num];
        int newSize = n + 1;
        
        T *arr = new T[newSize];

        arr[0] = value;
        for (int i = 0; i < n; i++)
        {
            arr[i+1] = array[row_num][i];
        }

        delete[] array[row_num];
        array[row_num] = arr;
        col_size[row_num] = newSize;

    }

    // 7.	Delete From Last Function: Deletes the last element of the given row and shrinks its size.
    void delete_from_last(int row_num)
    {

    }

    // 8.	Delete From Start Function: Deletes the first element of the given row and shrinks its size.
    void delete_from_start(int row_num)
    {
    }

    // 9.	Insert at specific Index: Inserts value at a specific index in a row, shifting elements right.
    void insertAt(int row_num, int col_index, T value)
    {
    }

    // 10.	Delete from specific Index: Deletes the value from a specific index in a row, shifting elements left.
    void deleteAt(int row_num, int col_index)
    {
    }

    // 11.	Display Function: Displays all rows, empty rows are displayed as blank lines.
    void display()
    {
    }

    // 12.	Get Row Size Function: Returns the current number of rows.
    int getRowSize()
    {
    }

    // 13.	Get Column Size Function: Returns the column size of the specified row. Will return -1 on invalid row number.
    int getColSize(int row_num)
    {
    }

    // 14.	Get Array Function: Returns a pointer to the 2D array.
    T **getArray()
    {
    }

    // 15.	Palindrome Function: Returns true if the row is palindrome.
    bool isRowPalindrome(int row_num)
    {
    }
};

#endif
