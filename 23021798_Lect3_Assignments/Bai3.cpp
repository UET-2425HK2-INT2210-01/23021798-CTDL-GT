#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int maxCapacity;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) {
        maxCapacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void push(int x) {
        if (size == maxCapacity) {
            return;
        }
        rear = (rear + 1) % maxCapacity;
        arr[rear] = x;
        size++;
    }

    void pop() {
        if (size == 0) {
            return;
        }
        front = (front + 1) % maxCapacity;
        size--;
    }

    void print() {
        if (size == 0) {
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % maxCapacity;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    q.print();
}