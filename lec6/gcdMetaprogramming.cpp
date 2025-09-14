//
// Created by atlas on 9/14/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <int A, int B>
struct GCD
{
    static constexpr int value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0>
{
    static constexpr int value = A;
};

int main()
{
    cout << GCD<1, 1>::value << endl;
    cout << "GCD of 4 and 8 is: " << GCD<4, 8>::value << endl;
    cout << "GCD of 8 and 4 is: " << GCD<8, 4>::value << endl;
    cout << "GCD of 48 and 18 is: " << GCD<48, 18>::value << endl;
    cout << "GCD of 56 and 98 is: " << GCD<56, 98>::value << endl;
    cout << "GCD of 101 and 10 is: " << GCD<101, 10>::value << endl;
    return 0;
}
