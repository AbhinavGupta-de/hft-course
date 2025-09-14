//
// Created by atlas on 9/14/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <int N>
struct Factorial
{
    static constexpr int value = Factorial<N - 1>::value * N;
};

template <>
struct Factorial<0>
{
    static constexpr int value = 1;
};

int main()
{
    cout << "Factorial of 10 is: " << Factorial<10>::value << endl;
    cout << "Factorial of 0 is: " << Factorial<0>::value << endl;
}
