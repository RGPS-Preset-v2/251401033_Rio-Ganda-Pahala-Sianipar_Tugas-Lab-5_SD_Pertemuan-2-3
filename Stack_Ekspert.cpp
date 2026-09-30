#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Klas Stack dengan Linked List
class StackLinkedList {
private:
    Node* top; // Pointer ke elemen teratas

public:
    StackLinkedList() {
        top = nullptr;
    }

    // Cek apakah stack kosong
    bool isEmpty() {
        return top == nullptr;
    }

    // Menambahkan elemen ke tumpukan (Push)
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push: " << value << endl;
    }

    // Menghapus elemen dari tumpukan (Pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Tumpukan kosong." << endl;
            return;
        }

        Node* temp = top;
        cout << "Pop: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    // Melihat elemen paling atas (Peek)
    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
        } else {
            cout << "Elemen teratas (Top): " << top->data << endl;
        }
    }

    // Menampilkan seluruh elemen tumpukan
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Isi Stack (Top -> Bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    StackLinkedList s;

    cout << "=== CHALLENGE 2: STACK MENGGUNAKAN LINKED LIST ===" << endl;
    s.push(100);
    s.push(200);
    s.push(300);
    s.display();

    s.peek();

    s.pop();
    s.display();

    return 0;
}