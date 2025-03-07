#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int maxCapacity;
    int top;
    int size;

public:
    Stack(int capacity) {
        maxCapacity = capacity;
        arr = new int[capacity];
        top = -1;
        size = 0;
    }

    void push(int x) {
        if (top == maxCapacity - 1) {
            return;
        }
        top++;
        arr[top] = x;
        size++;
    }

    void pop() {
        if (top == -1) {
            return;
        }
        top--;
        size--;
    }

    void print() {
        if (top == -1) {
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.push(5);
    s.print();
    return 0;
}
