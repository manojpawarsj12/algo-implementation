#include<iostream>
#include<vector>
using namespace std;
class Stack {

private:
	int maxSize;
	vector<int> v;
	int top;
public:
	Stack(int size) {
		this->maxSize = size;
		this->v.reserve(this->maxSize);
		this->top = -1;
	}

	void push(int j) {
		if (!(this->isFull())) {
			this->v[++this->top] = j;
		}
		else {
			cout << "stack is full" << endl;
		}

	}

	int pop() {
		if (!(this->isEmpty())) {

			return this->v[this->top--];
		}
		else {
			cout << "\nstack is empty" << endl;
			cout << "StackOverflow " << endl;
		}
	}

	int peak() {
		return this->v[this->top];
	}
	bool isEmpty() {
		return (this->top == -1);
	}

	bool isFull() {
		return (this->top == this->maxSize - 1);
	}

};

int main() {

	Stack s(10);

	s.push(10);
	s.push(20);
	cout << s.pop();
	cout << "\n" << s.pop();
	s.push(40);
	cout << "\n" << s.pop();

}