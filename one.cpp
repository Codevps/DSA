/*
// linked list
#include <bits/stdc++.h>
using namespace std;
// Singly linked list: =>
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor:
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    // insert at head/first pos:
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // creating the node: =>
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    // insert at tail/last pos:
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}
void deleteNode(Node *&head, int pos)
{
    Node *temp = head->next;

    if (pos == 1) // del head
    {
        Node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else // del middle or tail
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    // print(head);
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 15);
    // print(head);
    Node *tail = node1;
    // print(head);
    insertAtTail(tail, 12);
    // print(head);
    insertAtTail(tail, 15);
    // print(head);
    insertAtPos(head, tail, 3, 22);
    // print(head);
    insertAtPos(head, tail, 4, 25);
    print(head);
    deleteNode(head, 4);
    print(head);
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor:
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor:

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head; // previous head value stored
        temp->prev = temp; // storing loc of itself coz now going to become a  head
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp; // temp is new
        temp->prev = tail; // old tail ka value
        tail = temp;       // tail value old to new
    }
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    // if first pos:
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // if last pos:
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // insert in pos which is in between:
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->next->prev = curr->prev;
        //see if this is right or
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    // head:
    insertAtHead(head, tail, 11);
    print(head);
    insertAtHead(head, tail, 12);
    print(head);
    insertAtHead(head, tail, 13);
    print(head);

    // tail
    insertAtTail(head, tail, 17);
    print(head);
    insertAtTail(head, tail, 18);
    print(head);
    insertAtTail(head, tail, 19);
    print(head);

    // insert at certain pos:
    insertAtPos(head, tail, 4, 20);
    print(head);
    insertAtPos(head, tail, 5, 21);
    print(head);
    insertAtPos(head, tail, 6, 22);
    print(head);
    deleteNode(5, head);
    print(head);
    return 0;
}
*/