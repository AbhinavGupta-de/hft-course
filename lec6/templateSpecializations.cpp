//
// Created by atlas on 9/14/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void appendHelloToId(T&& obj)
{
    obj.id += " Hello";
}

template <typename T>
void appendHelloToId(T* obj)
{
    obj->id += " Hello";
}

void appendHelloToId(char ch)
{
    cout << ch << " Hello";
}


struct Student
{
    string id;
};

int main()
{
    // here we passing a lvalue, so T is deduced to Student&
    Student s1{"World"};
    appendHelloToId(s1);
    cout << s1.id << endl;

    // here we are passing a pointer, so T is deduced to Student*
    Student s2{"Everyone"};
    appendHelloToId(&s2);
    cout << s2.id << endl;

    // here we are passing a rvalue, so T is deduced to Student &&
    Student&& s3{"Everybody"};
    appendHelloToId(s3);
    cout << s3.id << endl;

    // here we are passing a char, so T is deduced to char
    appendHelloToId('A');
}
