#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList() { // constructor
        head = NULL;
    }
        int calcSize();
        void insertStart(int data);
        void insertLast(int data);
        void insertPosition(int pos, int data);
        void display();
};

void LinkedList::insertStart(int data){

    Node* newNode = new Node();
    
    // assign data value
    newNode->data = data;
    // change the next node of this newNode 
    // to current head of Linked List
    newNode->next = head;

    //changing the new head to this freshly entered node
    head = newNode;

}

void LinkedList::insertLast(int data){

    Node* newNode = new Node();

    newNode->data = data;
    // since this will be the last node so it will point to NULL
    newNode->next = NULL;

    //need this if there is no node present in linked list at all
    if(head==NULL){
        head = newNode;
        return;
    }

    struct Node* temp = head;

    // traverse to the last node of Linked List
    while(temp->next!=NULL)
        temp = temp->next;

    // assign last node's next to this newNode
    temp->next = newNode;
}

int LinkedList::calcSize(){
    
    Node* node = new Node();
    node = head;
    
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void LinkedList::insertPosition(int n, int data)
{
    int size = calcSize();

    // Can only insert after 1st position
    // Can't insert if position to insert is greater than size of Linked List
    if( n < 1 || size < n)
    {
        cout << "Not Valid position to insert" << endl; 
    } 
    else { 

        Node* temp = head; 
        Node* newNode = new Node(); 

        newNode->data = data;
        newNode->next = NULL;

        // traverse till the nth node
        while(--n)
            temp=temp->next;
        
        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

void LinkedList::display(){
    
    Node* node = new Node();
    node = head;
    
    //as linked list will end when Node is Null
    while(node!=NULL){
        cout << node->data << " "; node = node->next;
    }
    cout << endl; 
} 

int main()
{ 
    LinkedList* list = new LinkedList(); 
    list->insertStart(5);
    list->insertStart(10);
    list->insertStart(15);

    list->insertLast(20);
    list->insertLast(25);
    list->insertLast(30);
    list->insertLast(35);

    // Inserts after 3rd position
    list->insertPosition(3, 100);

    list->display(); 
    return 0;  
}