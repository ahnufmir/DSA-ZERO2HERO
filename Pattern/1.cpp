#include <iostream>
using namespace std;

        int recusriveFn(int n){
            if(n==1)
            return 1;
            return n*recusriveFn(n-1); 
        }


    int main()
    {
        int n;
        cout << "Enter a number you want to loop" << endl;
        cin >> n;
        int sum;
        sum = recusriveFn(n);
        cout << sum<< endl;

// Pattern of plus
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

// Pattern of plus
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
    //         if((i==0) || i == (rows-1))
    //             cout <<"1 ";
    //         else if(j==0 || j == (col-1))
    //             cout << "1 " ;
    //         else
    //             cout << "0 ";
    //     }
    //     cout << endl;

    // }

// Bubble Sort
//     int elements;
//     cout << "Enter the number of elements " << endl;
//     cin >> elements;
//     int arr[elements];
//     for (int i = 0; i < elements; i++)
//     {
//         cout << "Enter element " << i + 1 << endl;
//         cin >> arr[i];
//     }
//     for (int i = 0; i < elements - 1; i++)
//     {
//         for (int j = i + 1; j < elements; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     cout << "----Array :  " << endl;
//     for (int i = 0; i < elements; i++)
//     {
//         cout << arr[i] << endl;
//     }
      
    return 0;
}

