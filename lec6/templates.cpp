//
// Created by atlas on 9/13/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void appendHelloToId(T& obj)
{
    obj.id += " Hello";
}


// Here we use forwarding reference to accept both lvalue and rvalue
// && means universal reference
template <typename T>
void appendHelloWorldToId(T&& obj)
{
    obj.id += " Hello World";
}

struct Student
{
    string id;
};

int main()
{
    Student s1{"World"};
    appendHelloToId(s1);
    cout << s1.id << endl;
    appendHelloWorldToId(std::move(s1));
    cout << s1.id << endl;
}
