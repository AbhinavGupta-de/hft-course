//
// Created by atlas on 8/30/25.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    explicit Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Deleted Node: " << data << endl;
    }
};

Node* createLinkedList(int n)
{
    const auto head = new Node(0);
    Node* current = head;

    for (int i = 1; i < n; i++)
    {
        current->next = new Node(i);
        current = current->next;
    }

    return head;
}

void printLinkedList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main()
{
    Node* head = createLinkedList(1000);
    printLinkedList(head);
    deleteLinkedList(head);
    return 0;
}
