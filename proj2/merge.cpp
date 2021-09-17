//merge.cpp
//Andrew Hines
//9-12-2021
//This is the merge sort algorith implementation

#include "volsort.h"
#include <iostream>
using namespace std;



// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
  l.head=msort(l.head,numeric);
}

Node *msort(Node *head, bool numeric) {

  if(head==NULL||head->next==NULL){//base case size=1
    return head;
  }

  //Split the List
  Node* left=NULL;
  Node* right=NULL;
  split(head, left, right);
  
  left=msort(left, numeric);//recursively sorts left side
  right=msort(right, numeric);//recursively sorts right side
  
  
  head=merge(left, right, numeric);//Merges the sublists
  
  return head;
}



void split(Node *head, Node *&left, Node *&right) {
  Node* lNode=head;
  
  //Didn't use the Slow Fast Pointer Method because of reasons discussed in office hours with Ashley
  
  left=head;
  right=lNode->next;
  lNode->next=NULL;
}

Node *merge(Node *left, Node *right, bool numeric) {
  Node* newHead=NULL;//the temporary head of the new merged list
  Node* headSaver=NULL;//Saves the head between interations of the loop
  if(left==NULL&&right!=NULL){
    return right;//If there is no left list and there is a right list. right is head
  }
  if(right==NULL&&left!=NULL){//Vice versa
    return left;
  }
  if(numeric){//boolean to determine if sorting by string or int
    while(left!=NULL&&right!=NULL){
      if(newHead==NULL){//Determines if this is the first node being added to the list
        if(left->number < right->number){//If left > right
          newHead=left;
          headSaver=left;
          left=left->next;
        }
        else{//if Left=< Right
          newHead=right;
          headSaver=right;
          right=right->next;
        }
      }
      
      else{//Since list exists, append
        if(left->number < right->number){
          newHead->next=left;
          left=left->next;
          newHead=newHead->next;
        }
        else{
          newHead->next=right;
          right=right->next;
          newHead=newHead->next;
        }
      }
      
    }
  }
  else{//If it isn't numeric, the logic is the exact same, so I'll spare the comments
    while(left!=NULL&&right!=NULL){
      if(newHead==NULL){
        if(left->string < right->string){
          newHead=left;
          headSaver=left;
          left=left->next;
        }
        else{
          newHead=right;
          headSaver=right;
          right=right->next;
        }
      }
      else{
        if(left->string < right->string){
          newHead->next=left;
          left=left->next;
          newHead=newHead->next;
        }
        else{
          newHead->next=right;
          right=right->next;
          newHead=newHead->next;
        }
      }
      
    }
  }
  if(left==NULL){//If the left list is empty, append the rest of the right
    newHead->next=right;
  }
  if(right==NULL){//Vice Versa
    newHead->next=left;
  }
  return headSaver;
}







