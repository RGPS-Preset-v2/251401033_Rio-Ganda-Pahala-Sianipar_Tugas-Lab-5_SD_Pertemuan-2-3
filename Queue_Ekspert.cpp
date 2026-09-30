#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLinkedList {
private:
    Node* front; // Pointer ke elemen depan
    Node* rear;  // Pointer ke elemen belakang

public:
    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueue: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Antrean kosong." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeue: " << front->data << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
        } else {
            cout << "Elemen terdepan (Front): " << front->data << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Isi Queue (Front -> Rear): ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    QueueLinkedList q;

    cout << "=== CHALLENGE 1: QUEUE MENGGUNAKAN LINKED LIST ===" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    return 0;
}