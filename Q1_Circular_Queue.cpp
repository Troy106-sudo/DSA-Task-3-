#include <iostream>
using namespace std;

const int MAX = 5;

class CircularQueue {
    int items[MAX];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() const { return front == -1; }
    bool isFull() const { return (rear + 1) % MAX == front; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        items[rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << items[front] << " removed.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << '\n';
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; q.enqueue(value); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}