//
// Created by atlas on 8/26/25.
//

#include <cstdint>
#include <iostream>

using namespace std;

void changeValue(int** num)
{
    *num = nullptr;
}

int main()
{
    // int x = 10;
    // int* p = &x;
    // changeValue(&p);
    // if (p == nullptr)
    // {
    //     cout << "Pointer is null now!" << endl;
    // }
    // int arr[3] = {1, 2, 3};
    // int* p = arr + 2; // valid, points "one past the end"
    // std::cout << (p == &arr[2]) << "\n"; // true
    //
    // // But dereferencing is UB:
    // std::cout << *p << "\n"; // ❌ undefined behavior

    char x = 42;
    char& ref = x;
    char* ptr = &x;

    std::cout << sizeof(ref) << " " << sizeof(ptr) << "\n";
}
