// Filename: accLL.h

#include<iostream>
#include<vector>
using namespace::std;

class Node
{
 friend class LinkedList;
 private:
  int _val;
  Node* _pNext;

 public:
  Node(int value);
  Node(Node* newNode, int value);
  bool setNext(Node* nextNode);
  Node* getNext();
  ~Node();
};

class LinkedList
{
 private:
  Node* _pHead;
  Node* _pTail;
  int _numElems;
 public:
  LinkedList();
  ~LinkedList();

  void createList(int numElems);
  void setNumElems(int elems);
  int getNumElems();
  void headAppend(int val);
  bool insertAfterNode(Node* afterNode, int val);
  Node* getNode(int pos);

  bool createLoop(int fromPos1, int toPos2, int numElems);
  int isLooping(Node* head);

  bool traverseAndPrint();
};


