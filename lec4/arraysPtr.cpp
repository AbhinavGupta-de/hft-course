//
// Created by atlas on 8/29/25.
//
#include <cstdint>
#include <iostream>


using namespace std;

int main()
{
    // need to create an array of array so basicaly array of array of pointers
    int n, m;
    cin >> n >> m;
    int** matrix;
    matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 100;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j || i + j == n - 1)
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
