// quick.cpp
//Andrew Hines
//9-13-2021
//This is the quick sort algorith implementation


#include "volsort.h"
#include <iostream>
using namespace std;

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
  l.head=qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
  if(head==NULL||head->next==NULL){//base case size=1
    return head;
  }
  Node* left=NULL;
  Node* right=NULL;
  Node* pivot=head;

  partition(head, pivot, left, right, numeric);//partitions the lists into left and right

  
  
  left=qsort(left, numeric);//recursively sorts the left

  
  
  
  right=qsort(right, numeric);//recursively sorts the right

  
  pivot->next=right;
  right=pivot;//This just makes sure the pivot is in the final list

  
  head=concatenate(left, right);//appends the lists together
  return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
  
  //SLow Fast Pointer
  //https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list
  right=NULL;
  left=NULL;
  
  Node* workingNode=head->next;//This node walks down the list and retrieves the nodes
  Node* lPusher=left;//These pusher nodes walk down the list setting ->next to NULL
  Node* rPusher=right;//Also contains each list
  while(workingNode!=NULL){//while the list exists
    if(numeric){
      if(workingNode->number < pivot->number){//If it is less
        if(left==NULL){//If left doesn't exist yet create it
          lPusher=workingNode;
          left=lPusher;
          workingNode=workingNode->next;
          lPusher->next=NULL;
        }
        else{//If Left exists, append it
          lPusher->next=workingNode;
          workingNode=workingNode->next;
          lPusher->next->next=NULL;
          lPusher=lPusher->next;
        }
      }
      //If it is greater or equal
      else{
        if(right==NULL){//IF right doesn't exist create it
          rPusher=workingNode;
          right=rPusher;
          workingNode=workingNode->next;
          rPusher->next=NULL;
        }
        else{//If right exists, append
          rPusher->next=workingNode;
          workingNode=workingNode->next;
          rPusher->next->next=NULL;
          rPusher=rPusher->next;
        }
      }   
    }
    else{
      if(workingNode->string < pivot->string){//If it is less
        if(left==NULL){//same as above
          lPusher=workingNode;
          left=lPusher;
          workingNode=workingNode->next;
          lPusher->next=NULL;
        }
        else{//same as above
          lPusher->next=workingNode;
          workingNode=workingNode->next;
          lPusher->next->next=NULL;
          lPusher=lPusher->next;
        }
      }
      //If it is greater or equal
      else{
        if(right==NULL){//same as above
          rPusher=workingNode;
          right=rPusher;
          workingNode=workingNode->next;
          rPusher->next=NULL;
        }
        else{//same as above
          rPusher->next=workingNode;
          workingNode=workingNode->next;
          rPusher->next->next=NULL;
          rPusher=rPusher->next;
        }
      }
    }
  }
}





Node *concatenate(Node *left, Node *right) {
  if(left==NULL){//If there is no left list then the right list is the full list
    return right;
  }
  if(right==NULL){//Vice Versa
    return left;
  }


  Node* end=left;//This node finds the end of left so that right can be appended to that node
  while(end->next!=NULL){
    end=end->next;
  }
  end->next=right;//appends
  return left;
}













