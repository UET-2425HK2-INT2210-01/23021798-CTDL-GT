#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int size(Node* head)
{
    Node* p = head;
    int count = 0;
    while (p != NULL)
    {
        count++; p = p->next;
    }
    return count;
}

Node* createNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* insert(Node* head, int p, int x)
{
    Node* temp = createNode(x);
    if (p == 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node* loop = head;
    if (p == size(head))
    {
        while (loop->next != NULL)
        {
            loop = loop->next;
        }
        loop->next = temp;
    }
    else
    {
        for (int i = 0; i < p - 1; i++)
        {
            loop = loop->next;
        }
        temp->next = loop->next;
        loop->next = temp;
    }
    return head;
}

Node* deleteEle(Node* head, int p)
{
    if (p == 0)
    {
        head = head->next;
        return head;
    }
    Node* loop = head;
    if (p == size(head) - 1)
    {
        while (loop->next->next != NULL)
        {
            loop = loop->next;
        }
        Node* trash = loop->next;
        delete trash;
        loop->next = NULL;
    }
    else
    {
        for (int i = 0; i < p - 1; i++)
        {
            loop = loop->next;
        }
        Node* trash = loop->next;
        loop->next = loop->next->next;
        delete trash;
    }
    return head;
}

void print(Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Node* list;
    int n; cin >> n;
    bool firstTime = true;
    while (n--)
    {
        string s; cin >> s;
        if (s.compare("insert") == 0)
        {
            int p, x; cin >> p >> x;
            if (firstTime)
            {
                list = createNode(x);
                firstTime = false;
            }
            else list = insert(list, p, x);
        }
        else if (s.compare("delete") == 0)
        {
            int p; cin >> p;
            list = deleteEle(list, p);
        }
        print(list);
    }
}