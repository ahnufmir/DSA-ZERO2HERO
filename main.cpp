#include "MyArray.h"

int main()
{
    MyArray<int> obj;

    char ch = 'y';

    while (ch == 'y')
    {
        obj.menu();
        int n;
        cin >> n;
        if (n == 1)
        {
            int index, value;
            cout << "Enter index and value" << endl;
            cin >> index >> value;
            obj.insertAt(index, value);
        }
        if (n == 2)
        {
            int index;
            cout << "Enter index and value" << endl;
            cin >> index;
            obj.removeAt(index);
        }
        if (n == 0)
        {
            obj.display();
        }
        if (n == 3)
        {
            bool b;
            int n;
            cout << "Press 0 for descending order sorting and 1 for ascending order sorting " << endl;
            cin >> n;
            if (n == 1)
            {
                b = true;
                obj.sortArray(b);
            }
            else if (n == 0)
            {
                b = false;
                obj.sortArray(b);
            }
        }
        if (n == 5)
        {
            obj.removeDuplicates();
        }   
        if (n == 6)
        {
            cout << obj << endl;
        }
        if (n == 7)
        {
            obj[0] = 50;
            cout << obj[0] << endl;
        }
        if (n == 8)
        {
            MyArray<int> arr1;
            MyArray<int> arr2;
            arr1.append(1);
            arr1.append(2);
            arr2.append(1);
            arr2.append(2);
            if (arr1 == arr2)
            cout << "Both arrays are equal" << endl;
            else
            cout << "Both arrays are not equal" << endl;
        }
        if (n == 9)
        {
            MyArray<int> arr1;
            MyArray<int> arr2;
            arr1.append(1);
            arr1.append(2);
            arr1.append(3);
            arr2.append(4);
            arr2.append(5);
            MyArray<int> arr3 = arr1 + arr2;
            cout << arr3 << endl;
        }
        
        cout << "Do you want to continue " << endl;
        cin >> ch;
    }

    return 0;
}
