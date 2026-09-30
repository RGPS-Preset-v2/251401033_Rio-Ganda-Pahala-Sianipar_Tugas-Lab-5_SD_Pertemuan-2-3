#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (front == nullptr) { // Jika antrean masih kosong
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == nullptr) {
        cout << "Antrean kosong!\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr) rear = nullptr; // Reset jika habis
}

void display() {
    Node* temp = front;
    cout << "Queue: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 -> 20 -> 30 -> NULL

    dequeue();
    display(); // Output: 20 -> 30 -> NULL

    return 0;
}