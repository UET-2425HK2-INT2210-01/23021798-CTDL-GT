#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    int size()
    {
        int cnt = 1;
        Node* loop = next->next;
        while (loop != NULL)
        {
            cnt++;
            loop = loop->next;
        }
        return cnt;
    }

    void exportEle()
    {
        cout << data << " ";
        Node* loop = next;

        while(loop != NULL)
        {
            cout << loop->data << " ";
            loop = loop->next;
        }
    }

    int solve()
    {
        int cnt = 0;
        Node* loop = next;
        int sum = data + loop->data + loop->next->data;

        if (sum == 0) cnt++;
        while (loop->next->next != NULL)
        {
            loop = loop->next;
            sum -= loop->prev->prev->data;
            sum += loop->next->data;
            if (sum == 0) cnt++;
        }
        return cnt;
    }
};

Node* createNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* addElement(Node* head, int data)
{
    Node* loop = head;
    while (loop->next != NULL)
    {
        loop = loop->next;
    }

    Node* temp = createNode(data);
    loop->next = temp;
    temp->prev = loop;
    return head;
}


int main()
{
    Node* list;
    int n; cin >> n;
    bool firstTime = true;
    while (n--)
    {
        int x; cin >> x;
        if (firstTime)
        {
            list = createNode(x);
            firstTime = false;
        }
        else
        {
            list = addElement(list, x);
        }
    }

    cout << list->solve();
}