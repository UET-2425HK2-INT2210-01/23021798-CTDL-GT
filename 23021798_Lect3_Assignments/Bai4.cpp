#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    int size;

public:
    Queue() {
        head = NULL;
        size = 0;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* loop = head;
            while (loop->next != NULL) {
                loop = loop->next;
            }
            loop->next = newNode;
        }
        size++;
    }

    void pop() {
        if (head != NULL) {
            Node* trash = head;
            head = head->next;
            delete trash;
            size--;
        }
    }

    void print() {
        Node* loop = head;
        while (loop != NULL) {
            cout << loop->data << " ";
            loop = loop->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    q.print();
    return 0;
}