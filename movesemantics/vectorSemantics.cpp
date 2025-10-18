#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MyVector
{
    vector<int> data;

public:
    MyVector()
    {
        cout << "Default Constructor\n";
        data = vector<int>{1, 2, 3};
    }

    MyVector(const MyVector& other)
    {
        cout << "Copy Constructor\n";
        data = other.data;
    }

    MyVector(MyVector&& other)
    {
        cout << "Move Constructor\n";
        data = std::move(other.data);
    }

    MyVector& operator=(const MyVector& other)
    {
        cout << "Copy Assignment\n";
        data = other.data;
        return *this;
    }

    MyVector& operator=(MyVector&& other)
    {
        cout << "Move Assignment\n";
        data = std::move(other.data);
        return *this;
    }

    ~MyVector()
    {
        cout << "Destructor\n";
        data.clear();
    }

    void print() const
    {
        for (auto i : data)
            cout << i << " ";
        cout << "\n";
        cout << "Size: " << data.size() << "\n";
    };
};

int main()
{
    cout << "---- Create a ----\n";
    MyVector a;
    a.print();// Default Constructor

    cout << "---- Copy construct b from a ----\n";
    MyVector b = a;                 // Copy Constructor
    b.print();
    a.print();


    cout << "---- Move construct c from a (std::move) ----\n";
    MyVector c = std::move(a);      // Move Constructor
    c.print();
    a.print();

    cout << "---- Default construct d ----\n";
    MyVector d;                     // Default Constructor
    d.print();

    cout << "---- Copy assign d = b ----\n";
    d = b;                          // Copy Assignment
    d.print();
    b.print();

    cout << "---- Move assign d = std::move(c) ----\n";
    d = std::move(c);               // Move Assignment
    d.print();
    c.print();

    cout << "---- Put objects into std::vector ----\n";
    std::vector<MyVector> vec;
    vec.push_back(b);               // Copy Constructor (push_back with lvalue)
    vec.push_back(std::move(d));    // Move Constructor (push_back with rvalue)

    cout << "---- Print vector ----\n";
    a.print();
    b.print();
    c.print();
    d.print();

    cout << "---- Exiting main ----\n";
    return 0;
}