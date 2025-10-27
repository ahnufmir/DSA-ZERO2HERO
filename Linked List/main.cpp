#include "ll.h"

int main()
{
    List l;

    char ch = 'y';
    while (ch == 'y')
    {
        int choice;
        cout << "============= MENU ================" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Update Element" << endl;
        cout << "4. Get Value from Index" << endl;
        cout << "5. Checking Count Occurrences of value" << endl;
        cout << "6. Display" << endl;
        cout << "------------------------" << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            int value, index;
            cout << "Enter a value at specific index" << endl;
            cin >> value >> index;
            l.insertAtIndex(index, value);
            break;

        case 2:
            int data;
            cout << "Enter a value" << endl;
            cin >> data;
            l.search(data);
            break;

        case 3:
            int value, index;
            cout << "Enter a value and index" << endl;
            cin >> value >> index;
            l.updateAtIndex(index, value);
            break;

        case 4:
            int data;
            cout << "Enter a value" << endl;
            cin >> data;
            l.getAtIndex(data);
            break;

        case 5:
            int data;
            cout << "Enter a value" << endl;
            cin >> data;
            l.countOccurrences(data);
            break;

        case 6:
            l.printList();
            break;

        default:
            cout << "Invalid Index" << endl;
            break;
        }
    }
}
