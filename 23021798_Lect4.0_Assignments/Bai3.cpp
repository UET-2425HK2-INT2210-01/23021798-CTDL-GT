#include <iostream>
#include <string>
using namespace std;
							// Bài 3
class node {
public:
	char data;
	node *next;
	node();
	node(char d);
};

node::node() {
	data = -1;
	next = NULL;
};

node::node(char d) {
	data = d;
	next = NULL;
};

class stack {
private:
	node *pHead;
	int count;
public:
	stack();

	void push(char d);

	node *pop();

	int top();

	bool isEmpty();

	int size();
};

stack::stack() {
	pHead = NULL;
	count = 0;
};

void stack::push(char d) {
	if (pHead == NULL)
	{
		pHead = new node(d);
		if (pHead != NULL)
			++count;
	}
	else
	{
		node *pTemp = pHead;
		pHead = new node(d);
		if (pHead != NULL)
		{
			pHead->next = pTemp;
			++count;
		}
	}
};

node* stack::pop() {
	if (pHead != NULL)
	{
		node *pTemp = pHead;
		pHead = pHead->next;
		pTemp->next = NULL;
		--count;
		return pTemp;
	}
	return NULL;
};

int stack::top() {
	if (pHead != NULL)
		return pHead->data;
	return -1;
};

bool stack::isEmpty() {
	if (pHead == NULL)
		return true;
	return false;
};

int stack::size() {
	return count;
};

int main()
{
    string s;
    cin >> s;
    stack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' ||
            s[i] == '[' ||
            s[i] == '{')
        {
            st.push(s[i]);
        }
        if (s[i] == ')' && st.top() == '(' ||
            s[i] == ']' && st.top() == '[' ||
            s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
    }
    if (st.isEmpty()) cout << "Valid";
    else cout << "Invalid";
}


