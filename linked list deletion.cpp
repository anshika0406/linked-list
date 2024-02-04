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
  Node * head;
public:
  LinkedList ()
  {				// constructor
    head = NULL;
  }
  int calcSize ();
  void deleteStart ();
  void deleteEnd ();
  void deletePos (int pos);
  void display ();
  void insert (int data);
};

void LinkedList::deleteStart ()
{
  Node *temp = head;

  // if there are no nodes in Linked List can't delete
  if (head == NULL)
    {
      cout<<"Linked List Empty, nothing to delete";
      return;
    }

  cout << "\nValue Deleted: " << temp->data;

  // move head to next node
  head = head->next;
  free (temp);
}

void LinkedList::deleteEnd ()
{
  Node *temp = head;
  Node *previous;

  // Can't delete from empty Linked List
  if (head == NULL)
    {
      cout << ("Empty List, can't delete");
      return;
    }

  // if Linked List has only 1 node 
  if (temp->next == NULL)
    {
      cout << "\nValue Deleted: " << head->data;
      head = NULL;
      return;
    }

  // else traverse to the last node
  while (temp->next != NULL)
    {
      // store previous link node as we need to change its next val
      previous = temp;
      temp = temp->next;
    }

  // Curr assign 2nd last node's next to Null
  previous->next = NULL;

  cout << "\nValue Deleted: " << temp->data;
  // delete the last node
  free (temp);
  // 2nd last now becomes the last node
}

void LinkedList::deletePos (int n)
{
  Node *temp = head;
  Node *previous;


  int size = calcSize ();

  if (n < 1 || n > size)
    {
      cout << "\nEnter valid position\n";
      return;
    }

  // if first node has to be deleted 
  if (n == 1)
    {
      deleteStart ();
      return;
    }

  //traverse till the nth node 
  while (--n)
    {
      // store previous link as we need to change its next val 
      previous = temp;
      temp = temp->next;
    }

  // previous node's next changed to nth node's next
  previous->next = temp->next;
  cout << "\nValue deleted: " << temp->data;

  free (temp);
}

int LinkedList::calcSize ()
{

  Node *node = new Node ();
  node = head;

  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void LinkedList::insert (int data)
{

  Node *newNode = new Node ();

  newNode->data = data;
  newNode->next = head;

  // assigned head to newNode
  head = newNode;
}

void LinkedList::display ()
{

  Node *node = new Node ();
  node = head;

  cout << "\n";

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int main ()
{

  LinkedList *list = new LinkedList ();
  list->insert (10);
  list->insert (20);
  list->insert (30);
  list->insert (40);
  list->insert (50);
  list->insert (60);
  list->insert (70);

  list->display ();

  list->deleteStart ();
  list->display ();

  list->deleteEnd ();
  list->display ();

  // delete 4th node
  list->deletePos (4);
  list->display ();

  // delete the 1st node
  list->deletePos (1);
  list->display ();

  list->deletePos (-2);		
  list->deletePos (10);		
}
