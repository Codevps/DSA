/*
linked list
#include <bits/stdc++.h>
using namespace std;
Singly linked list: =>
class Node
{
public:
    int data;
    Node *next;
    constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    destructor:
    ~Node()
    {
        int value = this->data;
        memory free
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
    insert at head/first pos:
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
    creating the node: =>
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    insert at tail/last pos:
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}
void deleteNode(Node *&head, int pos)
{
    Node *temp = head->next;

    if (pos == 1) //del head
    {
        Node *temp = head;
        head = head->next;
        memory free start node
        temp->next = NULL;
        delete temp;
    }
    else  //del middle or tail
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
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *head = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 15);
    print(head);
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPos(head, tail, 3, 22);
    print(head);
    insertAtPos(head, tail, 4, 25);
    print(head);
    deleteNode(head, 4);
    print(head);
    return 0;
}
*/
//------------------------------------------------------------

/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    constructor:
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    destructor:

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
        temp->next = head; //previous head value stored
        temp->prev = temp; //storing loc of itself coz now going to become a  head
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
        tail->next = temp; temp is new tail
        temp->prev = tail; old tail ka value
        tail = temp;       temp becomes new tail
    }
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    //if first pos:
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

    if last pos:
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    //insert in pos which is in between:
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
        deleting any middle node or last node
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

    tail
    insertAtTail(head, tail, 17);
    print(head);
    insertAtTail(head, tail, 18);
    print(head);
    insertAtTail(head, tail, 19);
    print(head);

    insert at certain pos:
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
circular linked list: only for singlylinked list:
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    constructor:
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    destructor:
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

//here only insert at tail will be used since there is no head to insert items.

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
        //element found: here temp is to be place ahead of curr;
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    //condition 1 if tail is empty:
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
        >= 2 linked List
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

//------------------------------------------------------------


//reverse linked list(singly)
void reverse(Node *&head, Node *curr, Node *prev){

     //basecase:
    if(curr == NULL){
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev; //point next to prev from basecase

}

Node* reverse1(Node *&head){
    //baseCase:
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *subHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return subHead;
}
Node* reverseLinkedList(Node *head)
{
    //using for loop :
    if(head == NULL || head->next == NULL){
        return head;
}
   //prev will be pointing to NULL
   Node *prev = NULL;
   Node *curr =  head;
   Node *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

    //recursion:for loop converted to linkedList.
    Node *curr =  head;
    Node *prev = NULL;
    reverse(head,curr,prev);
    return head;

    //recursion2:
    return reverse1(head);
}

//------------------------------------------------------------


// find the middle:
int getLength(Node *head){
    int len = 0;
    while(head !=NULL){
        len++;
        head = head->next;
}
    return len;
}
Node *findMiddle(Node *head) {

    //optimized:
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;
    }
    Node *slow = head;
    Node *fast = head->next;

    while(fast !=NULL){
        //{increment fast by 2 <fast->next->next> && increment slow with 1<slow->next> but also check if (fast->next == NULL) if yes then terminate  }
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow=slow->next;
    }
    return slow;



    //O(n) complexity: logic: middle will be half of full length of LL
    int len = getLength(head);
    int ans = (len/2);
    Node *temp = head;
    int cnt = 0;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;

}

//------------------------------------------------------------


reverse in k groups :**IMPORTANT**
Node* kReverse(Node* head, int k) {
    base case:
    if(head == NULL){
        return NULL;
    }
    //reverse 1st k Nodes:
    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = head;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //step 2: Recursion:
    if(next !=NULL){
        head->next = kReverse( next, k) ;
    }

    //step 3: return
    return prev;

}
//------------------------------------------------------------


// check if cycle is present or not::
bool detectLoop(Node *head)
{

    if (head == NULL)
    {
        return true;
    }

    map< Node *, bool> visited; //vector
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
//check cycle is present On space complexity
// floyd detect algorithm uses slow and fast method : slow travels in element while fast travels across two elements in one iteration.it reduces space complexity to O(n).
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {
//assuming that the given node is circular
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head); //calling above function

    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;

}

Node *removeLoop(Node *head)
{
    //floydDetect and getStarting node is used in this function
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head); //calling above function.

    if(startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }
    temp -> next = NULL;
    return head;
}

// sort 0,1,2:::problem On tc and O1 space complexity  with no data replacement
void insertTail(Node *&tail, Node *temp){
    tail->next = temp;
    tail = temp;
}
// no data replacement ::
Node* sortList(Node *head)
{

    Node *zerosh = new Node(-1);
    Node *zerost =zerosh;
    Node *onesh = new Node(-1);
    Node *onest = onesh;
    Node *twosh = new Node(-1);
    Node *twost = twosh;
    Node *temp = head;

    while(temp!= NULL){
        if(temp->data == 0){
            insertTail(zerost,temp);
}        else if(temp->data == 1){
            insertTail(onest,temp);
}        else if(temp->data == 2){
            insertTail(twost,temp);
}
        temp = temp->next;
}

//     merge:
    if(onesh != NULL)
  {  zerost->next = onesh->next;}
    else
    {zerost->next = twosh->next;}
    onest->next = twosh->next;
    twost->next = NULL;

    head = zerosh->next;
    delete zerosh;
    delete onesh;
    delete twosh;
    return head;

    //complexity of On ..sort 0 ,1 ,2:with data replacement::
//    	Node *temp = head;
//     int count = 0;
//     int count1 = 0;
//     int count2 = 0;
//     while(temp!=NULL){
//         if(temp->data == 0){
//             count++;
// 		}
//         else if(temp->data == 1){
//             count1++;
// 		}
//         else if(temp->data == 2){
//             count2++;
// 		}
// 		temp = temp->next;
// 	}
//     	temp = head;
//     while(temp!= NULL){
//         if(count != 0){
//           temp->data = 0;
//             count--;
// 		}
//          else if(count1 != 0){
//           temp->data = 1;
//             count1--;
// 			}
//     	else if(count2 != 0){
//           temp->data = 2;
//             count2--;
// 		}
//         temp = temp->next;
//     }
//     return head;
}


// merge sorted linked list::

Node<int> *merge(Node<int>* first, Node<int>* second){
       if(first->next==NULL){
       first->next=second;
       return first;
   }
    Node<int> *curr1 = first;
    Node<int> *next1 = curr1->next;
    Node<int> *curr2 = second;
    Node<int> *next2 = curr2->next;
    while(next1 != NULL && curr2 !=NULL){
        if((curr2->data >=curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next ;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first -> data <= second -> data ){
        merge(first, second);
    }
    else
    {
        merge(second, first);
    }
}
*/
