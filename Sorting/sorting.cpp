#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Sort
{
private:
    int *array;   // A pointer to an integer. This will be used to dynamically allocate memory for the array of numbers.
    int size;     // An integer representing the current number of elements stored in the array.
    int capacity; // An integer representing the maximum number of elements the dynamically allocated array can hold.
public:
    // Default Constructor
    Sort()
    {
        size = 0;
        capacity = 0;
        array = nullptr;
    }

    // Parameterized Constructor
    Sort(int cap)
    {
        capacity = cap;            // Sets the capacity member to cap.
        size = 0;                  // Initializes size to 0.
        array = new int[capacity]; // Dynamically allocates an integer array of size cap and assigns its address to the array pointer
    }

    // Destructor
    ~Sort()
    {
        delete[] array; // Deallocates the dynamic memory previously allocated for the array to prevent memory leaks.
    }

    void addElement(int value)
    { // Implements the addElement method to insert a new integer into the Sort class's dynamic array.

        if (size == capacity)
        {
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

        array[size] = value;
        size++;
    }

    void bubbleSort()
    { // Implements the Bubble Sort algorithm to sort the elements currently stored in the array.
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[i])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    void insertionSort()
    { // Implements the Insertion Sort algorithm to sort the elements in the array.
        // for (int i = 0; i < size - 1; i++)
        // {
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         if (i == 0)
        //         {
        //             if (array[j] < array[0])
        //             {
        //                 int temp = array[0];
        //                 array[0] = array[j];
        //                 array[j] = temp;
        //             }
        //         }
        //         else
        //         {
        //             if (array[j] < array[i])
        //             {
        //                 int z;
        //                 int temp = array[j];
        //                 array[j] = array[i];
        //                 for (int k = i - 1; k >= 0; k--)
        //                 {
        //                     if (temp < array[k])
        //                     {
        //                         array[i] = array[k];
        //                     }
        //                     z = k;
        //                 }
        //                 array[z] = temp;
        //             }
        //         }
        //     }
        // }

        
        for (int i = 1; i < size; i++)
        {
            int smallest;
            bool check = false;
            for (int k = i - 1; k >= 0; k--)
            {
                if ((array[i] < array[k]))
                {
                    smallest = k;
                    check = true;
                }
            }
            if (check)
            {
                int temp = array[i];
                for (int j =i-1; j >=smallest; j--)
                {
                    // arr[k+1] = temp;
                    array[j+1] = array[j];
                }
                array[smallest] = temp;
            }    
        }  
    }

    void selectionSort()
    { // Implements the Selection Sort algorithm to sort the elements in the array.
        for (int i = 0; i < size - 1; i++)
        {
            int smallest = array[i];
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[i])
                {
                    array[j] = array[i];
                }
                smallest = array[j];
            }
            cout << smallest << endl;
        }
        
    }

    void displayArray()
    { // Prints the elements of the array to the console.
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int getSize()
    { // Returns the size of array (no. of elements)
        return size;
    }

    int *getArray()
    { // Returns the integer array.
        return array;
    }
};

#endif
