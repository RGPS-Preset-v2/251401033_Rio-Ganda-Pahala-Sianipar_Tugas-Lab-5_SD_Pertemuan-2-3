#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top; // Sambungan node baru ke node lama
    top = newNode;       // Geser top ke node baru
}

void pop() {
    if (top == nullptr) {
        cout << "Stack kosong!\n";
        return;
    }
    Node* temp = top;
    top = top->next; // Geser top ke node di bawahnya
    delete temp;
}

void display() {
    Node* temp = top;
    cout << "Stack: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // Output: 30 -> 20 -> 10 -> NULL (karena 30 paling atas)

    pop();
    display(); // Output: 20 -> 10 -> NULL

    return 0;
}