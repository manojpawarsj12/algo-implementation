#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

};
class linkedlist
{
public: int length;
	  Node* head;
	  linkedlist() {
		  this->length = 0;
		  this->head = NULL;

	  }
	  void insert_begining(int data) {
		  Node* node = new Node();
		  node->data = data;
		  node->next = this->head;
		  this->head = node;
		  this->length++;
	  }
	  void insert_end(int data)
	  {
		  Node* node = new Node();
		  Node* temp = new Node();
		  if (node == NULL)
		  {
			  cout << "Unable to create memnory \n ";
		  }
		  else
		  {
			  node->data = data;
			  node->next = NULL;
			  temp = head;
			  while (temp->next != NULL)
			  {
				  temp = temp->next;
			  }
			  temp->next = node;
			  cout << "inserted successfully \n";
		  }
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
	  void insert_pos(int data, int pos)
	  {
		  Node* prev = new Node();
		  Node* curr = new Node();
		  Node* node = new Node();
		  node->data = data;

		  int tempPos = 0;   

		  curr = head;      
		  if (head != NULL)
		  {
			  while (curr->next != NULL && tempPos != pos)
			  {
				  prev = curr;
				  curr = curr->next;
				  tempPos++;
			  }
			  if (pos == 0)
			  {
				  cout << "Adding at Head! \n " << endl;
				  insert_begining(data);
			  }
			  else if (curr->next == NULL && pos == tempPos + 1)
			  {
				  cout << "Adding at Tail! \n" << endl;
				  insert_end(data);
			  }
			  else if (pos > tempPos + 1)
			  {
				  cout << " Position is out of bounds \n " << endl;
			  }

			  else
			  {
				  prev->next = node;
				  node->next = curr;
				  cout << "Node added at position:  " << pos << "\n";
			  }
		  }
		  else
		  {
			  head = node;
			  node->next = NULL;
			  cout << "Added at head as list is empty!\n" << endl;
		  }
	  }
	  void delete_begining() {
		  if (head == NULL) {
			  return;
		  }
		  Node* temp = head;
		  head = head->next;
		  delete  temp;
		   
	  }

	  void delete_end() {
		  if (head == NULL) {
			  return;
		  }
		  Node* ptr = new Node();
		  Node* preptr = new Node();
		  ptr = head;
		  while (ptr->next != NULL) {
			  preptr = ptr;
			  ptr = ptr->next;
		  }
		  preptr->next = NULL;
		  delete ptr;
	  }
	  
	  void delete_pos(int pos) {
		  if (head == NULL) {
			  return;
		  }
		  Node* temp = new Node();
		  Node* temp1 = new Node();
		  if (pos == 0)
		  {
			  head= temp->next;    
			  delete temp;
			  return;
		  }
		  
		  for (int i = 0; i < pos - 1 && temp != NULL; i++) {
			  temp = temp->next;
		  }
		  if (temp == NULL || temp->next == NULL) {
			  return;
		  }
		  temp1->next = temp->next;
		  delete temp;
	  }
	  void sort() {
		  {
			  Node* ptr = new Node();
			  Node* s = new Node();
			  int value;
			  if (head == NULL)
			  {
				  cout << "The List is empty" << endl;
				  return;
			  }
			  ptr = head;
			  while (ptr != NULL)
			  {
				  for (s = ptr->next; s != NULL; s = s->next)
				  {
					  if (ptr->data > s->data)
					  {
						  value = ptr->data;
						  ptr->data = s->data;
						  s->data = value;
					  }
				  }
				  ptr = ptr->next;
			  }
		  }
	  }
	  void search()
	  {
		  int value, pos = 0;
		  bool flag = false;
		  if (head == NULL)
		  {
			  cout << "List is empty" << endl;
			  return;
		  }
		  cout << "Enter the value to be searched: ";
		  cin >> value;
		  Node* s = new Node();
		  s = head;
		  while (s != NULL)
		  {
			  pos++;
			  if (s->data == value)
			  {
				  flag = true;
				  cout << "Element " << value << " is found at position " << pos << endl;
			  }
			  s = s->next;
		  }
		  if (!flag)
			  cout << "Element " << value << " not found in the list" << endl;
	  }

};
int main()
{
	linkedlist a;
	int choice,data,pos;
	while(1)
	{
		cout << endl << "---------------------------------" << endl;
		cout << endl << "Operations on singly linked list" << endl;
		cout << endl << "---------------------------------" << endl;
		cout << "1.Insert Node " << endl;
		cout << "2.Insert node at last" << endl;
		cout << "3.Insert node at position" << endl;
		cout << "4.Delete Linked List" << endl;
		cout << "5. Delete Linked List at end" << endl;
		cout << "6. Delete Linked List at given position" << endl;
		cout << "7. sort list elements" << endl;
		cout << "8.display all elements" << endl;
		cout << "9. Search for element " << endl;
		cout << "10.Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Inserting Node at Beginning: " << endl;
			cout << "enter a int value" << endl;
			cin >> data;
			a.insert_begining(data);
			cout << endl;
			break;
		case 2:
			cout << "Inserting Node at Last: " << endl;
			cout << "enter a int value" << endl;
			cin >> data;
			a.insert_end(data);
			cout << endl;
			break;
		case 3:
			cout << "Inserting Node at a given position:" << endl;
			cout << "enter a int value and position" << endl;
			cin >> data>>pos;
			a.insert_pos(data, pos);
			cout << endl;
			break;
		case 7:
			cout << "Sort Link List: " << endl;
			a.sort();
			a.display();
			cout << endl;
			break;
		case 4:
			cout << "Delete a node: " << endl;
			a.delete_begining();
			break;
		case 5:
			cout << "Delete Node at End" << endl;
			a.delete_end();
			cout << endl;
			break;
		case 6:
			cout << "Delete Node at given position " << endl;
			cout << "enter position to delete" << endl;
			cin >> pos;
			a.delete_pos(pos);
			cout << endl;
			break;
		case 8:
			cout << "Display elements of link list" << endl;
			a.display();
			cout << endl;
			break;
		case 9:
			a.search();
			break;
		case 10:
			cout << "Exiting..." << endl;
			exit(1);
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}

	return 0;
}
	