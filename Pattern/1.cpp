#include <iostream>
using namespace std;

int main(){

    // int rows,col;
    // cout << "Enter the number of rows " << endl;
    // cin >> rows;
    // cout << "Enter the number of columns " << endl;
    // cin >> col;
    // int arr[rows][col];
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if((j==(col/2)))
    //             cout <<"1 ";
    //         else if(i==(rows/2))
    //             cout << "1 " ;
    //         else
    //             cout << "0 ";
    //     }
    //     cout << endl;
        
    // }

    int rows,col;
    cout << "Enter the number of rows " << endl;
    cin >> rows;
    cout << "Enter the number of columns " << endl;
    cin >> col;
    int arr[rows][col];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if((i==0) || i == (rows-1))
                cout <<"1 ";
            else if(j==0 || j == (col-1))
                cout << "1 " ;    
            else
                cout << "0 ";
        }
        cout << endl;
        
    }


    
}