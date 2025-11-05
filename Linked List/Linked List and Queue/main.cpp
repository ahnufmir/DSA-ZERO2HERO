#include "functions.h"

void task1()
{
    Queue s;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "======================== TASK 1 Menu =====================" << endl;
        cout << "1. Queue Element" << endl;
        cout << "2. Dequeue Element" << endl;
        cout << "3. Display Top Element" << endl;
        cout << "4. Clear Stack" << endl;
        cout << "5. Check Size" << endl;
        cout << "6. Print Queue" << endl;
        cout << "---------------------------" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the element value" << endl;
            cin >> data;
            s.enqueue(data);
            break;

        case 2:
            s.dequeue();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.clear();
            break;

        case 5:
            cout << "Size: " << s.getSize() << endl;
            break;

        case 6:
            s.printQueue();
            break;

        default:
            cout << "Invalid Index" << endl;
            break;
        }
        cout << "Do you want to execute this task again (y for yes, n for no)?" << endl;
        cin >> ch;
    }
}

void task2()
{
    LinkedQueue l;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "======================== TASK 2 Menu =====================" << endl;
        cout << "1. Enqueue Element" << endl;
        cout << "2. Dequeue Element" << endl;
        cout << "3. Display Front Element" << endl;
        cout << "4. Clear Queue" << endl;
        cout << "5. Check Size" << endl;
        cout << "6. Print Queue" << endl;
        cout << "---------------------------" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the element value" << endl;
            cin >> data;
            l.enqueue(data);
            break;

        case 2:
            l.dequeue();
            break;

        case 3:
            l.peek();
            break;

        case 4:
            l.clear();
            break;

        case 5:
            cout << "Size: " << l.getSize() << endl;
            break;

        case 6:
            l.printQueue();
            break;

        default:
            cout << "Invalid Index" << endl;
            break;
        }
        cout << "Do you want to execute this task again (y for yes, n for no)?" << endl;
        cin >> ch;
    }
}

int main()
{
    int task;
    cout << "Enter '1' for Task 1 and '2' for Task '2'" << endl;
    cin >> task;
    if (task == 1)
    {
        task1();
    }
    else if (task == 2)
        task2();
    else
        cout << "Invalid Input" << endl;
    return 0;
}
