#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
    int data[MAX];
    int front, rear;

public:
    Queue() : front(0), rear(-1) {}

    bool isEmpty() const { return rear < front; }
    bool isFull() const { return rear == MAX - 1; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        data[++rear] = value;
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << data[front++] << " dequeued.\n";
        if (front > rear) {
            front = 0;
            rear = -1;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; ++i) cout << data[i] << " ";
        cout << '\n';
    }
};

int main() {
    Queue q;
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