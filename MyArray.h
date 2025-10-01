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
        int* newColSize = new int[row_count+1];
        T** newArray = new T*[row_count+1];

        for (int i = 0; i < row_index; i++)
        {
            newColSize[i] = col_size[i];
            newArray[i] = array[i];
        }

        newArray[row_index] = nullptr;
        newColSize[row_index] = 0;

        for (int i = row_index; i < row_count+1; i++)
        {
            newArray[i+1] = array[i];
            newColSize[i+1] = col_size[i];
        }
        
      
        delete[] arr;
        delete [] col_size;
        newArray = array;
        newColSize = col_size;
        
        
    }

    // 4.	Deletes an existing Row: Deletes a complete row shifting the remaining rows to the left..
    void deleteRow(int row_index)
    {
  
    }

    // 5.	Append Function: Adds an element at the end of the specified row.
    void append(T value, int row_num)
    {

    }

    // 6.	Prepend Function: Adds an element at the start of the specified row.
    void prepend(T value, int row_num)
    {
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
void insertAt(int row_num, int col_index, T value) {

    
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
