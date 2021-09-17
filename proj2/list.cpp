//Andrew Hines
//9-12-2021
//This is the list class used in each of the sorting algorithms




#include "volsort.h"
#include <string>
#include <iostream>

using namespace std;




List::List() {
  head = nullptr;
}

//some code and ideas taken from https://stackoverflow.com/questions/2265967/writing-a-linkedlist-destructor
//User "sharptooth"

List::~List() {
  Node* temp=head;
  while(head->next!=NULL){
    temp=temp->next;
    delete head;
    head=temp;
  }
  delete temp;
}
//End stack overflow code

void List::push_front(const std::string &s){
  Node* temp=new Node;//Creates a node
  temp->string= s;
  temp->number = stoi(s);
  temp->next = NULL;//fills the node with the passed paramaters
  if(head!=NULL){
    temp->next = head;
  }
  head = temp;//links head to temp and makes temp the new head
}

void dump_node(Node *n){//utility function
  Node* temp=n;
  cout <<"Number: "<< temp->number <<endl;
  cout <<"String: "<< temp->string <<endl;
  cout<<endl;
  temp=temp->next;
}

