#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertAtBegining(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *a = new node(d);
    a->next = head;
    head = a;
}
void insertAtEnd(node *&head, int d)
{
    if (head == NULL)
    {
        insertAtBegining(head, d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}
void insertAtMiddle(node *&head, int d, int pos)
{
    if (head == NULL)
    {
        insertAtBegining(head, d);
        return;
    }
    if (pos == 0)
    {
        insertAtBegining(head, d);
        return;
    }
    if (pos == 1)
    {
        insertAtEnd(head, d);
        return;
    }
    node *temp = head;
    int jumps = 1;
    while (jumps < pos - 1)
    {
        temp = temp->next;
        jumps++;
    }
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
    return;
}
void deleteAtBegining(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *n = head->next;
    delete head;
    head = n;
}
void deleteAtEnd(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *tail = head;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    delete tail->next;
    tail->next = NULL;
}

node *reverselist(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *p = reverselist(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}
node *reverselistIt(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void midpoint(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
}
bool detectcycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            retu rn true;
        }
    }
    return false;
}
int main()
{
    node *head = NULL;
    insertAtBegining(head, 190);
    insertAtBegining(head, 9);
    insertAtMiddle(head, 10, 2);
    insertAtEnd(head, 10);
    print(head);
    deleteAtBegining(head);
    print(head);

    deleteAtEnd(head);
    print(head);
    insertAtBegining(head, 190);
    insertAtBegining(head, 9);
    insertAtMiddle(head, 10, 2);
    insertAtEnd(head, 10);
    cout << "reverse\n";
    print(reverselistIt(head));
    midpoint(head);
    node *p = reverselist(head);
    print(p);

    cout << detectcycle(head);

    return 0;
}