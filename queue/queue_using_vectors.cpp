#include<iostream>
#include<vector>
using namespace std;
class Queue
{
private:
	    int maxsize;
		int front; 
		int rear;
		int add;
	    vector<int> a;
public:
	Queue(int size)
	{
		this->maxsize = size;
		this->a.reserve(this->maxsize);
		this->front = -1;
		this->rear = -1;
	}
	void enqueue() {
		if (!(this->isOverflow())) {
			if (this->front == -1)
			{
				this->front = 0;
				cout << "Insert element \n";
				cin >> this->add;
					this->rear += 1;
					this->a[this->rear] = add;
			}
			
		}
		else
		{
			cout << "Queue is full";
		}
	}
	void dequeue() {
		if (!(this->isUnderflow()))
		{
			cout << "deleted element from queue is \n" << this->a[this->front];
			this->a.erase(this->a.begin()+this->front);
			this->front += 1;
		}
		else
		{
			cout << "stack is underflow \n";
		}
	}

	bool isUnderflow()
	{
		if (this->front == -1 || this->front > this->rear) {
			return true;
		}
		else
		{
			return false;
		}

	}

	bool isOverflow() {
		if (this->rear == this->maxsize - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	void display()
	{
		for (int i = 0; i < this->maxsize; i++) {
			cout << this->a[i];
		}
	}


};
int main()
{ 
	int size;
	cout << "enter size of stack \n";
	cin >> size;
	Queue Q(size);
		int choice;
		while (1)
		{
			cout<<"1.Insert element to queue \n";
			cout<<"2.Delete element from queue \n";
			cout<<"3.Display all elements of queue \n";
			cout<<"4.Quit \n";
			cout<<"Enter your choice : \n";
			cin>>choice;
			switch (choice)
			{
			case 1:
				Q.enqueue();
				break;
			case 2:
				Q.dequeue();
				break;
			case 3:
				Q.display();
				break;
			case 4:
				exit(1);
			default:
				cout<<"Wrong choice \n";
				break;
			} 
		} 
	} 