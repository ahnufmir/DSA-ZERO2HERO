#include "MyArray.h"

int main(){
    MyArray<int> obj;
    char choice = 'y';

    while (choice == 'y')
    {
        int select;
        cout << "===================== MENU =====================" << endl;
        cout << "Append Element (press 1)" << endl;
        cout << "Prepend Element (press 2)" << endl;
        cout << "Display All Elements (press 3)" << endl;
        cout << "Get Current Size Element (press 4)" << endl;
        cout << "Get Current Capacity Element (press 5)" << endl;
        cin >> select;

        if(select == 1){
            int value;
            cout << "Enter the value " << endl;
            cin >> value;
            obj.append(value);   // Append function
        }
        
        else if(select == 2){
            int value;
            cout << "Enter the value " << endl;
            cin >> value;
            obj.prepend(value);   // Prepend Function
        }

        else if(select == 3){
            obj.display();    // Display Function
        }

        else if(select == 4){
            cout << obj.get_size() << endl;       // Get Size Function
        }

        else if(select == 5){
            cout << obj.get_capacity()  << endl;       // Get Capacity Function
        }
 
        cout << "Do you want to do this stuff again? "<< endl;
        cin >> choice;
        
    }
    

}