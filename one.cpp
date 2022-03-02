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

//------------------------------------------------------------
// circular linked list: only for singlylinked list:
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
        this->next = NULL;
    }
    // destructor:
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << val << " deleted" << endl;
    }
};

// here only insert at tail will be used since there is no head to insert items.

void insertT(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *node1 = new Node(d);
        tail = node1;
        node1->next = tail;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    //condn 1 if tail is empty:
        if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
void deleteNode(Node *&tail, int d)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != d)
        {
            prev = curr;
            curr = curr->next;
        }
        //single node linked list:
        if(curr == prev){
           tail =NULL;
        }
        // >= 2 linked List
        if (tail == curr)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;
    insertT(tail, 1, 3);
    print(tail);
    insertT(tail, 3, 6);
    print(tail);
    insertT(tail, 6, 8);
    print(tail);
    insertT(tail, 8, 10);
    print(tail);
    insertT(tail, 10, 12);
    print(tail);
    insertT(tail, 6, 9);
    print(tail);
    deleteNode(tail, 9);
    print(tail);
    deleteNode(tail, 12);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
}
*/