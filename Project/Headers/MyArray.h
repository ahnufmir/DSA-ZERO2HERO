#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
private:
    T *data;
    int size;
    int capacity;

public:
    MyArray()
    {
        size = 0;
        capacity = 5;
        data = new T[capacity];
    }
    MyArray(int cap)
    {
        size = 0;
        capacity = cap;
        data = new T[capacity];
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
            for (int i = 0; i < size; i++)
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
        cout << "    SIZE = " << size << endl;
        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size += 1;
        cout << "    NEW SIZE = " << size << endl;
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
    T getValueAtIndex(int index)
    {
        return data[index];
    }
    void insertAt(int index, T value)
    {
        if (index >= 0 && index <= size)
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
            cout << "    SIZE = " << size << endl;
            for (int i = size; i > index; i--)
            {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size += 1;
            cout << "    NEW SIZE = " << size << endl;
        }
        else
            cout << "Error" << endl;
    }

    bool check(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    void removeAt(int index)
    {
        if (index >= 0 && index < size)
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
            cout << "    SIZE = " << size << endl;
            for (int i = index; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size -= 1;
            cout << "    NEW SIZE = " << size << endl;
        }
        else
            cout << "Error" << endl;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << endl;
        }
    }
    void sortArray(bool asc)
    {
        if (asc)
        {
            for (int h = 0; h < size - 1; h++)
            {
                for (int i = 0; i < size; i++)
                {
                    if (data[i] > data[i + 1])
                    {
                        int temp = data[i + 1];
                        data[i + 1] = data[i];
                        data[i] = temp;
                    }
                }
            }
        }
        else
        {
            for (int h = 0; h < size - 1; h++)
            {
                for (int i = 0; i < size - h - 1; i++)
                {
                    if (data[i] < data[i + 1])
                    {
                        int temp = data[i + 1];
                        data[i + 1] = data[i];
                        data[i] = temp;
                    }
                }
            }
        }
    }
    void bubbleSort()
    { // Implements the Bubble Sort algorithm to sort the elements currently stored in the array.
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (data[i] > data[j])
                {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
    void heapify(int size, int i) // Max Heaping
    {
        int left = 2 * i + 1;  // Left child of parent
        int right = 2 * i + 2; // Right child of parent
        int largest = i;       // Supposing the first element to be largest

        if (left < size && data[largest] < data[left])
        {
            largest = left; // Making the left index the largest
        }
        if (right < size && data[largest] < data[right])
        {
            largest = right; // Making the right index the largest
        }
        if (largest != i)
        {
            T temp = data[i];
            data[i] = data[largest]; // Swapping the largest element with the ith element
            data[largest] = temp;
            heapify(size, largest); // Doing recursion for the remaining elements
        }
    }
    void heapSort()
    {
        int s = size;
        for (int i = (s / 2) - 1; i >= 0; i--)
        {
            heapify(s, i); // Building max heap
        }
        while (s > 1)
        {
            T temp = data[s - 1];
            data[s - 1] = data[0]; // Swapping first element with last
            data[0] = temp;
            s--; // Decreasing size as left part of array is being sorted
            for (int i = (s / 2) - 1; i >= 0; i--)
            {
                heapify(s, i); // (Min) heaping the left unsorted right array
            }
        }
    }
    void removeDuplicates()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (data[i] == data[j])
                {
                    cout << "    SIZE = " << size << endl;
                    for (int k = j; k < size - 1; k++)
                        data[k] = data[k + 1];
                }
                size -= 1;
                i -= 1;
                cout << "    NEW SIZE = " << size << endl;
            }
        }
    }
void countSort()
{
    if (size <= 1) return;

    int biggestNo = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > biggestNo) biggestNo = data[i];
    }
 
    T *countArray = new T[biggestNo + 1];
    for (int i = 0; i < biggestNo + 1; i++) {
        countArray[i] = 0;
    }
    
  
    for (int i = 0; i < biggestNo + 1; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (data[j] == i) count++;
        }
        countArray[i] = count;
    }
    
  
    T *positionArray = new T[biggestNo + 1];
    for (int h = 0; h < biggestNo + 1; h++) {
        if (h == 0) {
            positionArray[h] = countArray[h];
        } else {
            positionArray[h] = countArray[h] + positionArray[h - 1];
        }
    }
    
  
    T *finalArray = new T[size];
    for (int k = (size - 1); k >= 0; k--) {
        int index = positionArray[data[k]] - 1;
        positionArray[data[k]] = index;
        finalArray[index] = data[k];
    }
    
    for (int l = 0; l < size; l++) {
        data[l] = finalArray[l];
    }

    delete[] countArray;
    delete[] positionArray;
    delete[] finalArray;
}
    void reverse()
    {
        for (int i = 0; i < size / 2; i++)
        {
            T temp = data[i];
            data[i] = data[size - i - 1];
            data[size - i - 1] = temp;
        }
    }
    friend ostream &operator<<(ostream &out, const MyArray<T> &obj)
    {
        for (int i = 0; i < obj.size; i++)
        {
            out << obj.data[i] << endl;
        }
        return out;
    }
    T &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        cout << "Invalid index or out of boundary access" << endl;
        static T dummy{};
        return dummy;
    }
    bool operator==(const MyArray &obj) const
    {
        bool check = true;
        if (this->size != obj.size)
        {
            check = false;
        }
        else if (this->size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (this->data[i] != obj.data[i])
                {
                    check = false;
                }
            }
        }
        return check;
    }
    MyArray<T> operator+(const MyArray<T> &obj)
    {
        int newSize = this->size + obj.size;
        MyArray<T> newArr;
        for (int i = 0; i < this->size; i++)
        {
            newArr.append(this->data[i]);
        }
        // int index;
        for (int j = 0; j < newSize; j++)
        {
            newArr.append(obj.data[j]);
        }
        return newArr;
    }
    void menu()
    {
        cout << "============ MENU ====================" << endl;
        cout << "0. Display " << endl;
        cout << "1. Append at Index " << endl;
        cout << "2. Remove at Index " << endl;
        cout << "3. Sorting " << endl;
        cout << "4. Remove Duplicates " << endl;
        cout << "5. Reverse " << endl;
        cout << "6. << Operator Overloading " << endl;
        cout << "7. [] Operator Overloading " << endl;
        cout << "8. == Operator Overloading " << endl;
        cout << "9. + Operator Overloading " << endl;
        cout << "--------------------------------------" << endl;
    }
};

#endif
