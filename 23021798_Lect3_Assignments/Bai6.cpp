#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (top == NULL) top = newNode;
        else
        {
            Node* loop = top;
            while (loop->next != NULL) loop = loop->next;

            loop->next = newNode;
        }
        size++;
    }

    void pop() {
        if (top == NULL) {
            return;
        }
        Node* loop = top;
        for (int i = 1; i < size - 2; i++)
        {
            loop =  loop->next;
        }
        Node* trash = loop->next;
        loop->next = NULL;
        delete trash;
        size--;
    }

    void print() {
        if (top == NULL) {
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
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
