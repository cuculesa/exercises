// Filename: accLL.cpp

#include<iostream>
#include<vector>
#include "accLL.h"
using namespace::std;

Node::Node(int value):_val(value),
                      _pNext(0){}

Node::Node(Node* newNode, int value):
                    _pNext(newNode),
                    _val(value){}

Node::~Node()
{
   // delete _pNext;
}

Node* Node::getNext()
{
 return _pNext;
}

bool Node::setNext(Node* nextNode)
{
 if(0 == nextNode) return false;
 _pNext = nextNode;
 return true;
}

LinkedList::LinkedList(): _pTail(0),
                          _pHead(0),
                          _numElems(0){}


void LinkedList::headAppend(int val)
{
 if(_pHead == 0)
 {
   _pHead = _pTail = new Node(val);
 }
 else
 {
   Node* newNode = new Node(val);
   newNode->_pNext = _pHead;
   _pHead = newNode;
 }
}

void LinkedList::createList(int numElems)
{
  cout<<"Insert "<<numElems<<" elements\n";
  int elem = 0;

  while(numElems--)
  {
    cin>>elem;
    //check if number entered is an int
    while(cin.fail())
    {
      cout<<"Not an int !"<<endl;
      cin.clear();
      cin.ignore(256,'\n');
      cin>>elem;
    }
    // elements will be added to the front
    //of the list, one by one.
    headAppend(elem);
  }
}

void LinkedList::setNumElems(int numElems)
{
 _numElems = numElems;
}

int LinkedList::getNumElems()
{
 return _numElems;
}

LinkedList::~LinkedList()
{
 //number of elems is necessary for malformed lists.
 while(_pHead && _numElems>0)
 {
  Node* tmp = _pHead->getNext();
  delete _pHead;
  _numElems--;
  _pHead = tmp;
 }
}

bool LinkedList::insertAfterNode(Node* afterNode, int val)
{
 if(afterNode != 0)
 {
   afterNode->_pNext = new Node(afterNode->_pNext, val);
   return true;
 }
 return false;
}

Node* LinkedList::getNode(int pos)
{
  Node *p = _pHead;
  while(pos--)
  {
   p = p ->_pNext;
  }
  return p;
}

bool LinkedList::createLoop(int fromPos1, int toPos2, int numElems)
{
 if ((fromPos1 >= toPos2) &&
    ((fromPos1 <= numElems) &&
     (toPos2   <= numElems)))
 {
  Node* someNode = getNode(fromPos1);
  someNode->setNext(getNode(toPos2));
  return true;
 }
 return false;
}

// Hare & tortoise algorithm
// if there is a loop, the hare will
// meet the tortoise at some point
// returns number of cycles
int LinkedList::isLooping(Node* head)
{
 if(0 == head) return false;

 Node* hare;
 Node* tortoise;
 hare = tortoise = head;
 int cycleLenght = 0;

 while(hare!=0)
 {
   hare = hare->_pNext;
   if(!hare) return 0; // if no cycles

   hare = hare->_pNext;
   tortoise = tortoise->_pNext;
   cycleLenght ++;

   if(hare == tortoise)
   {
     cout<<"cycle length is "<<cycleLenght<<endl;
     return cycleLenght;
   }
 }
}

bool LinkedList::traverseAndPrint()
{
 if (0==_pHead) {return false;}
 Node* p = _pHead;
 //knowing the number of elements
 //prevents an infinite loop in the malformed lists
 while((p!=0) && (_numElems--))
 {
  cout<<p->_val;
  if(p->_pNext != 0) cout<<" -> ";
  p = p->_pNext;
 }
 cout<<endl;
 return true;
}



int main()
{
 LinkedList l1;
 int numElems = 4;
 l1.setNumElems(numElems);
 l1.createList(numElems);

 if(!l1.traverseAndPrint())
 {
  cout<<"empty list"<<endl;
  return 1;
 }
 Node* head = l1.getNode(0);
 //create a loop
 if(!l1.createLoop(3, 1, numElems))
  {
   cout<<"invalid loop positions"<<endl;
   return 1;
  }

 if(l1.isLooping(head))
  {
   cout <<"malformed linked list "<<endl;
  }
 else cout<<"well formed linked list"<<endl;

 return 1;
}
