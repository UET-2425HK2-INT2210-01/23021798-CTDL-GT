#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(NULL) {}
};

class Linkedlist {
	Node* head;
	
	public:
	Linkedlist() : head(NULL) {}

	void append(int x)
	{
		Node* newNode = new Node(x);
		if (head == NULL)
		{
			head = newNode;
		}

		else
		{
			Node* loop = head;
			while (loop->next != NULL)
			{
				loop = loop->next;
			}
			loop->next = newNode;
		}
	}

	int search(int x)
	{
		Node* loop = head;
		int count = 1;
		while(loop != NULL)
		{
			if (loop->data == x)
			{
				break;
			}
			loop = loop->next;
			count++;
		}
		return count;
	}

	void reverse()
	{
		Node* prev = NULL;
		Node* curr = head;
		Node* next = NULL;
		while(curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;

		Node * loop = head;
		while (loop != NULL)
		{
			cout << loop->data << " ";
			loop = loop->next;
		}
	}
};


int main()
{
	Linkedlist list;
	int n; cin >> n;
	while(n--)
	{
		string s; cin >> s;
		if (s.compare("append") == 0)
		{
			int x; cin >> x;
			list.append(x);
		}
		else if (s.compare("search") == 0)
		{
			int x; cin >> x;
			int ans = list.search(x);
			if (ans) cout << ans;
			else cout << "NO";
			cout << endl;
		}
		else if (s.compare("reverse") == 0)
		{
			list.reverse();
			cout << endl;
		}

	}
}