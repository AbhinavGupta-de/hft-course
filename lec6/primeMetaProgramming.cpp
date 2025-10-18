// Online C++ compiler to run C++ program online
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

template <int A, int B>
struct isDivisible {
    static constexpr int value = (A % B) ? isDivisible<A, B - 1>::value :1;
};

template <int A>
struct isDivisible<A, 1> {
    static constexpr int value = false;
};


template <int A>
struct isPrime {
    static constexpr bool value = !isDivisible<A, A/2>::value;
};

template <>
struct isPrime<0> {
    static constexpr bool value = false;
};

template <>
struct isPrime<1> {
    static constexpr bool value = false;
};

template <>
struct isPrime<2> {
    static constexpr bool value = true;
};


int main()
{
    cout << "isPrime<0>::value = " << isPrime<0>::value << endl;
    cout << "isPrime<1>::value = " << isPrime<1>::value << endl;
    cout << "isPrime<2>::value = " << isPrime<2>::value << endl;
    cout << "isPrime<3>::value = " << isPrime<3>::value << endl;
    cout << "isPrime<4>::value = " << isPrime<4>::value << endl;
    cout << "isPrime<17>::value = " << isPrime<17>::value << endl;
    cout << "isPrime<100>::value = " << isPrime<100>::value << endl;
    cout << "isPrime<97>::value = " << isPrime<9781>::value << endl;


    return 0;
}