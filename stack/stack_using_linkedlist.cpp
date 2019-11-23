#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

};
class stack {
public:
	Node* head;
	Node* node = new Node();
	int length;
	stack() {
		head = NULL;
	}
	void insert(int data) {
		Node* node = new Node();
		node->data = data;
		node->next = this->head;
		this->head = node;
		this->length++;
	}
	void display() {
		Node* head = this->head;
		int i = 1;
		while (head) {
			std::cout << i << ": " << head->data << std::endl;
			head = head->next;
			i++;
		}
	}
	void push() {

		if (node == NULL) {
			cout << "Cant insert coz of no elements";
		}
		else {
			cout << "Enter an element to push";
			int data;
			cin >> data;
			if (head == NULL) {
				node->data = data;
				node->next = NULL;
				head = node;
			}
			else {
				node->data = data;
				node->next = head;
				head = node;
			}
			cout << "item pushed \n";


		}
	}
	void pop()
	{
		if (head == NULL) {
			return;
		}

		Node* preptr = new Node();
		node = head;
		while (node->next != NULL) {
			preptr = node;
			node = node->next;
		}
		preptr->next = NULL;
		delete node;
	}
};
int main() {
	stack s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.pop();
	s.pop();
	s.display();
}