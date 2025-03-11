#include <iostream>
using namespace std;

struct Node {
	int data;
	int priority;
	Node* next;
	Node* prev;
	Node(int x, int p) : data(x), priority(p), next(NULL), prev(NULL) {}
};

class PriorityQueue {
	Node* head;
	int size;
	public:
	PriorityQueue() : head(NULL), size(0) {}

	void enqueue(int x, int p)
	{
		Node* newNode = new Node(x, p);
		if (head == NULL)
		{
			head = newNode;
		}

		else
		{
			Node* loop = head;

			bool done = false;
			for (int i = 0; i < size; i++)
			{
				if (newNode->priority > loop->priority)
				{
					newNode->next = loop;
					newNode->prev = loop->prev;
					loop->prev = newNode;
					if (head->priority < newNode->priority) head = newNode;

					done = true;
					break;
				}

				if (!done && size - i == 1)
				{
					loop->next = newNode;
					newNode->prev = loop;
				}
				loop = loop->next;
			}
		}
		size++;
	}

	void dequeue()
	{
		Node* trash = head;
		head = head->next;
		delete trash;
		size--;
	}

	void print()
	{
		Node* loop = head;
		while(loop)
		{
			cout << "(" <<  loop->data << ", " << loop->priority << ");" << ' ';
			loop = loop->next;
		}
		cout << endl;
	}
};

int main()
{
	PriorityQueue q;
	q.enqueue(10, 2);
	q.enqueue(5, 3);
	q.enqueue(7, 1);
	q.dequeue();
	q.enqueue(8, 5);
	q.print(); 
}