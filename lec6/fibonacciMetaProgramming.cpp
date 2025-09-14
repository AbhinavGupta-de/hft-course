//
// Created by atlas on 9/14/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <long long N>
struct Fibonacci
{
    static constexpr long long value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};


template <>
struct Fibonacci<0>
{
    static constexpr long long value = 0;
};

template <>
struct Fibonacci<1>
{
    static constexpr long long value = 1;
};

int main()
{
    cout << "Fibonacci of 10 is: " << Fibonacci<10>::value << endl;
    cout << "Fibonacci of 0 is: " << Fibonacci<0>::value << endl;
    cout << "Fibonacci of 1 is: " << Fibonacci<1>::value << endl;
    cout << "Fibonacci of 5 is: " << Fibonacci<5>::value << endl;
    cout << "Fibonacci of 15 is: " << Fibonacci<15>::value << endl;
    cout << "Fibonacci of 20 is: " << Fibonacci<80>::value << endl;
    return 0;
}
