#include <iostream>
using namespace std;

void recusriveFn(int n, int sum){
    if(n<=0)
    return;
    
    cout << sum << endl;
    recusriveFn(n-1, sum+=n);
}


int main()
{
    int n;
    cout << "Enter a number you want to loop" << endl;
    cin >> n;
    int sum;
    recusriveFn(n,sum=0);
    cout << sum << endl;

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

