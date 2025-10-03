#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

// template <typename T>
// class MyArray
// {
// private:
//     int row_count;
//     int *col_size;
//     T **array;

// public:
//     // 1.	Constructor: Initializes an empty 2D array with row size set to 3 and column sizes set to 0 for each row.
//     MyArray()
//     {
//         row_count = 3;
//         col_size = new int[row_count];
//         array = new T *[row_count];
//         for (int i = 0; i < row_count; ++i)
//         {
//             col_size[i] = 0;
//             array[i] = nullptr;
//         }
//     }

//     // 2.	Destructor: Frees the dynamically allocated memory.
//     ~MyArray()
//     {
//         if (array)
//         {
//             for (int i = 0; i < row_count; ++i)
//             {
//                 delete[] array[i];
//             }
//             delete[] array;
//             array = nullptr;
//         }
//         delete[] col_size;
//         col_size = nullptr;
//         row_count = 0;
//     }

//     // 3.	Add a new Row: Add a new empty row at the index and increase the row_count by 1 and shifting the previous columns to right.
//     void addRow(int row_index)
//     {
//         if (row_index < 0 || row_index > row_count)
//         {
//             row_index = row_count;
//         }

//         int newcount = row_count + 1;
//         int *newColSize = new int[row_count + 1];
//         T **newArray = new T *[row_count + 1];

//         for (int i = 0; i < row_index; i++)
//         {
//             newColSize[i] = col_size[i];
//             newArray[i] = array[i];
//         }

//         newArray[row_index] = nullptr;
//         newColSize[row_index] = 0;

//         for (int i = row_index; i < row_count + 1; i++)
//         {
//             newArray[i + 1] = array[i];
//             newColSize[i + 1] = col_size[i];
//         }

//         delete[] array;
//         delete[] col_size;
//         array = newArray;
//         col_size = newColSize;
//         row_count = newcount;
//     }

//     // 4.	Deletes an existing Row: Deletes a complete row shifting the remaining rows to the left..
//     void deleteRow(int row_index)
//     {
//         if (row_index < 0 || row_index >= row_count)
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }

//         if (array[index] != nullptr)
//         {
//             delete[] array[row_index];
//             array[row_index] = nullptr;
//         }

//         int newcount = row_count - 1;

//         if (newcount == 0)
//         {
//             delete[] array;
//             delete[] col_size;
//             row_count = 0;
//             array = nullptr;
//             col_size = nullptr;
//             return;
//         }

//         int *newColSize = new int[newcount];
//         T **newArray = new T *[newcount];

//         for (int i = 0; i < row_index; i++)
//         {
//             newColSize[i] = col_size[i];
//             newArray[i] = array[i];
//         }

//         for (int i = row_index; i < newcount; i++)
//         {
//             newArray[i] = array[i + 1];
//             newColSize[i] = col_size[i + 1];
//         }

//         delete[] array;
//         delete[] col_size;

//         array = newArray;
//         col_size = newColSize;
//         row_count = newcount;
//     }

//     // 5.	Append Function: Adds an element at the end of the specified row.
//     void append(T value, int row_num)
//     {
//         if (row_num < 0 || row_num >= row_count)
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }

//         // int* newColSize = new int[newcount];
//         // array[row_num]

//         int n = col_size[row_num];
//         int newSize = n + 1;
//         T *arr = new T[newSize];

//         for (int i = 0; i < col_size[row_num]; i++)
//         {
//             arr[i] = array[row_num][i];
//         }

//         arr[newSize - 1] = value;
//         delete[] array[row_num];
//         array[row_num] = arr;
//         col_size[row_num] = newSize;
//     }

//     // 6.	Prepend Function: Adds an element at the start of the specified row.
//     void prepend(T value, int row_num)
//     {
//         if (row_num < 0 || row_num >= row_count)
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }

//         int n = col_size[row_num];
//         int newSize = n + 1;

//         T *arr = new T[newSize];

//         arr[0] = value;
//         for (int i = 0; i < n; i++)
//         {
//             arr[i + 1] = array[row_num][i];
//         }

//         delete[] array[row_num];
//         array[row_num] = arr;
//         col_size[row_num] = newSize;
//     }

//     // 7.	Delete From Last Function: Deletes the last element of the given row and shrinks its size.
//     void delete_from_last(int row_num)
//     {
//         if (row_num < 0 || row_num >= row_count)
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }

//         int n = col_size[row_num];
//         if (n == 0)
//         {
//             cout << "Array is already zero" << endl;
//             return;
//         }

//         // if (array[row_num][n-1] != nullptr)  // Realized that it is array of type T not pointers
//         // {
//         //     delete[] array[row_num][n];
//         //     array[row_num][n] = nullptr;
//         // }

//         int newSize = n - 1;

//         T *arr = (newSize > 0) ? new T[newSize] : nullptr;
//         for (int i = 0; i < newSize; i++)
//         {
//             arr[i] = array[row_num][i];
//         }

//         delete[] array[row_num];
//         array[row_num] = arr;
//         col_size[row_num] = newSize;
//     }

//     // 8.	Delete From Start Function: Deletes the first element of the given row and shrinks its size.
//     void delete_from_start(int row_num)
//     {
//         if (row_num < 0 || row_num >= row_count)
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }

//         int n = col_size[row_num];
//         if (n == 0)
//         {
//             cout << "Array is already zero" << endl;
//             return;
//         }

//         int newSize = n - 1;

//         T *arr = (newSize > 0) ? new T[newSize] : nullptr;
//         for (int i = 0; i < newSize; i++)
//         {
//             arr[i] = array[row_num][i + 1];
//         }

//         delete[] array[row_num];
//         array[row_num] = arr;
//         col_size[row_num] = newSize;
//     }

//     // 9.	Insert at specific Index: Inserts value at a specific index in a row, shifting elements right.
//     void insertAt(int row_num, int col_index, T value)
//     {
//         if (row_num < 0 || row_num >= row_count || col_index < 0 || col_index > col_size[row_num])
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }
//         int row_size = col_size[row_num];
//         int newSize = row_size + 1;
//         if (row_size == 0)
//         {
//             col_index = 0;
//             T *newArray = new T[newSize];
//             newArray[col_index] = value;
//             delete[] array[row_num];
//             array[row_num] = newArray;
//             col_size[row_num] = newSize;
//             return;
//         }
//         T *newArray = new T[newSize];
//         for (int i = 0; i < col_index; i++)
//         {
//             newArray[i] = array[row_num][i];
//         }
//         newArray[col_index] = value;
//         for (int i = col_index; i < n; i++)
//         {
//             newArray[i + 1] = array[row_num][i];
//         }

//         delete[] array[row_num];
//         array[row_num] = newArray;
//         col_size[row_num] = newSize;
//     }

//     // 10.	Delete from specific Index: Deletes the value from a specific index in a row, shifting elements left.
//     void deleteAt(int row_num, int col_index)
//     {
//         if (row_num < 0 || row_num >= row_count || col_index < 0 || col_index >= col_size[row_num])
//         {
//             cout << "Invalid Index" << endl;
//             return;
//         }
//         int row_size = col_size[row_num];
//         int newSize = row_size - 1;
//         if (row_size == 0)
//         {
//             cout << "Array is already empty :)" << endl;
//             return;
//         }
//         T *newArray = new T[newSize];
//         for (int i = 0; i < col_index; i++)
//         {
//             newArray[i] = array[row_num][i];
//         }
//         for (int i = col_index; i < newSize; i++)
//         {
//             newArray[i] = array[row_num][i+ 1];
//         }

//         delete[] array[row_num];
//         array[row_num] = newArray;
//         col_size[row_num] = newSize;
//     }

//     // 11.	Display Function: Displays all rows, empty rows are displayed as blank lines.
//     void display()
//     {
//         for (int i = 0; i < row_count; i++)
//         {
//             int n = col_size[i];
//             if(n==0){
//                 cout << endl;
//                 continue;
//             }
//             for (int j = 0; j < n; j++)
//             {
//                 cout << array[i][j] << " ";
//             }
//             cout << endl;
//         }
        
//     }

//     // 12.	Get Row Size Function: Returns the current number of rows.
//     int getRowSize()
//     {
//         return row_count;
//     }

//     // 13.	Get Column Size Function: Returns the column size of the specified row. Will return -1 on invalid row number.
//     int getColSize(int row_num)
//     {
//         if(row_num<0 || row_num>= row_count)
//             return -1;
//         int n = col_size[row_num];
//         return n;
//     }

//     // 14.	Get Array Function: Returns a pointer to the 2D array.
//     T **getArray()
//     {
//         return array;
//     }

//     // 15.	Palindrome Function: Returns true if the row is palindrome.
//     bool isRowPalindrome(int row_num)
//     {
//         bool check = true;
//         if(row_num < 0 || row_num >= row_count){
//             cout << "Invalid Index" << endl;
//             return false;
//         }
//         int size = col_size[row_num];
//         if(size==1)
//         return true;
//         // else if(size==2){
//         //     if(array[row_num][0] == array[row_num][1])
//         //     return true;
//         //     else
//         //     return false;
//         // }
//         else if(size==0){
//             cout << "Row is empty" << endl;
//             return true;
//         }
//         else{
//             for (int i = 0; i < size/2; i++)
//             {
//                 if(array[row_num][i] != array[row_num][(size-1)-i]){
//                     check = false;
//                     break;
//                 }
//             }
//             return check;
//         }
        
//     }
// };

template <typename T>
class MyArray
{
private:
    T *arr1D;   // - A pointer to a dynamically allocated 1D array,
    T **arr2D;  //- A pointer to a dynamically allocated 2D array
    T ***arr3D; //- A pointer to a dynamically allocated 3D array
    int d0;     //- The first dimension
    int d1;     //- The second dimension
    int d2;     //- The third dimension

public:
    MyArray(int d0, int d1 = 0, int d2 = 0)
    {
        arr1D = new T[d0];
        arr2D = new T *[d1];
        arr3D = new T **[d2];
        for (int i = 0; i < d2; i++)
        {
            arr3D[i] = nullptr;
        }
        for (int i = 0; i < d1; i++)
        {
            arr2D[i] = nullptr;
        }
        this->d0 = d0;
        this->d1 = d1;
        this->d2 = d2;
    }
    ~MyArray()
    {
        delete[] arr1D;
        for (int i = 0; i < d1; i++)
        {
            delete[] arr2D[i];
        }
        delete[] arr2D;
        for (int i = 0; i < d2; i++)
        {
            for (int j = 0; j < d1; j++)
            {
                delete[] arr3D[i][j];
            }
            delete[] ar3D[i];
        }
        delete[] arr3D;
    }
    MyArray(const Matrix &other)
    {
    }
    void setElement(double value, int dim0, int dim1 = 0, int dim2 = 0) // Sets the value of a specific MyArray element.
    {
        if (this->d1 == 0 && this->d2 == 0)
        {
            if (dim0 < 0 || dim0 >= d0)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            arr1D[dim0] = value;
        }

        else if (this->d1 > 0 && this->d2 == 0)
        {
            if (dim1 < 0 || dim1 >= d1)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            arr2D[dim0][dim1] = value;
        }

        else
        {
            if (dim2 < 0 || dim2 >= d2)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            arr3D[dim0][dim1][dim2] = value;
        }
    }
    double getElement(int dim, int dim1 = 0, int dim2 = 0) const
    {
        if (this->d1 == 0 && this->d2 == 0)
        {
            if (dim0 < 0 || dim0 >= d0)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            return arr1D[dim0];
        }

        else if (this->d1 > 0 && this->d2 == 0)
        {
            if (dim1 < 0 || dim1 >= d1)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            return arr2D[dim0][dim1];
        }

        else
        {
            if (dim2 < 0 || dim2 >= d2)
            {
                cout << "Invalid Index" << endl;
                return;
            }
            return arr3D[dim0][dim1][dim2];
        }
    }
    void display() const
    {
        if (d2 > 0 && d1 > 0 && d0 > 0 && arr3D != nullptr)
        {
            for (int i = 0; i < d2; i++)
            {
                if (arr3D[i] != nullptr)
                {
                    for (int j = 0; j < d1; j++)
                    {
                        if (arr3D[i][j] != nullptr)
                        {
                            for (int k = 0; k < d0; k++)
                            {
                                cout << arr3D[i][j][k] << " ";
                            }
                            cout << endl;
                        }
                        else
                        {
                            cout << "Layer " << i << " " << j << " is not allocated!" << endl;
                        }
                    }
                    cout << endl
                         << endl;
                }
                else
                {
                    cout << "Layer " << i << " is not allocated!" << endl;
                }
            }
        }

        if ((!(d2 > 0)) && d1 > 0 && d0 > 0 && arr2D != nullptr)
        {
            for (int j = 0; j < d1; j++)
            {
                if (arr2D[j] != nullptr)
                {
                    for (int k = 0; k < d0; k++)
                    {
                        cout << arr2D[j][k] << " ";
                    }
                    cout << endl;
                }
                 else
                {
                    cout << "Layer " << j << " is not allocated!" << endl;
                }
                
            }
        }

        if ((!(d2 > 0)) && (!(d1 > 0)) && d0 > 0 && arr1D != nullptr)
        {
            for (int k = 0; k < d0; k++)
            {
                cout << arr1D[k] << endl;
            }
        }
    }

    T *getDeterminant()
    {
        
    }
    MyArray *multiply(const Matrix &other) const
    {
    }
    MyArray *getTranspose()
    {
    }
    MyArray *sum(const Matrix &other) const
    {
         if ((d0 > 0) && (d0 == other.d0) && arr1D != nullptr &&(!(d2 > 0)) && (!(d1 > 0)))
        {
            MyArray *result1d = new MyArray(d0);
            for (int k = 0; k < d0; k++)
            {
                result1d->getElement(k) = this->getElement(k) + other.getElement(k);
            }
            return result1d;    
        }
        
        else if ((d1 > 0) && ( d0>0)&& (d1 == other.d1) && (d0 == other.d0) && arr2D != nullptr &&(!(d2 > 0)))
        {
            MyArray *result2d = new MyArray(d0,d1);
            for (int j = 0; j < d1; j++)
            {
                for (int k = 0; k < d0; k++)
                {
                    result2d->getElement(j,k) = this->getElement(j, k) + other.getElement(j,k);
                }
            }
            return result2d;
        }
        
        else if ((d2 > 0) && (d1 > 0) &&(d0 > 0) &&(d2 == other.d2) && (d1 == other.d1) && (d0 == other.d0) && arr3D != nullptr)
        {
            MyArray *result3d = new MyArray(d0,d1,d2);
            for (int i = 0; i < d2; i++)
            {
                for (int j = 0; j < d1; j++)
                {
                    for (int k = 0; k < d0; k++)
                    {
                        result3d->getElement(i,j,k) = this->getElement(i, j, k) + other.getElement(i,j,k);
                    }
                }
            }
            return result3d;
        }

        else{
            cout << "Given Array is not compatible for sum" << endl;
            return nullptr;
        }
    }
};

#endif
