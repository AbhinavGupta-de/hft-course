// #include <bits/stdc++.h>
#include <iostream>

using namespace std;


class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString();

    // Parameterized constructor
    MyString(const char* str) {
        cout << "Parameterized Constructor\n";
        length = strlen(str);
        data = new char[length + 1];
        memcpy(data, str, length + 1);
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length), data(new char[length + 1]){
        cout << "Copy Constructor\n";
        memcpy(data, other.data,other.size());
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
        cout << "Move Constructor\n";
        other.data = nullptr;
        other.length = 0;
    }

    // Copy assignment
    MyString& operator=(const MyString& other) {
        cout << "Copy Assignment\n";
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment
    MyString& operator=(MyString&& other) noexcept {
        cout << "Move Assignment\n";
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Destructor
    ~MyString() {
        cout << "Destructor called for: " << (data ? data : "nullptr") << "\n";
        delete[] data;
    }

    // Print function
    void print() const {
        if (data)
            cout << data << "\n";
        else
            cout << "(empty)\n";
    }

    size_t size() const { return length; }
};


int main()
{
    cout << "=== Parameterized Constructor ===\n";
    MyString s1("Hello");
    s1.print();

    cout << "\n=== Copy Constructor ===\n";
    MyString s2 = s1; // Copy constructor
    s2.print();

    cout << "\n=== Move Constructor ===\n";
    MyString s3 = std::move(s1); // Move constructor
    s3.print();
    s1.print(); // Moved-from (empty)

    cout << "\n=== Copy Assignment ===\n";
    MyString s4("Temp");
    s4 = s2; // Copy assignment
    s4.print();

    cout << "\n=== Move Assignment ===\n";
    MyString s5("Old");
    s5 = std::move(s2); // Move assignment
    s5.print();
    s2.print(); // Empty

    return 0;
}
