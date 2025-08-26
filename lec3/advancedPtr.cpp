//
// Created by atlas on 8/26/25.
//

#include <iostream>

using namespace std;

void changeValue(int** num)
{
    *num = nullptr;
}

int main()
{
    int x = 10;
    int* p = &x;
    changeValue(&p);
    if (p == nullptr)
    {
        cout << "Pointer is null now!" << endl;
    }
}
