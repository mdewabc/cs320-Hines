// stl.cpp
//Andrew Hines
//9-12-2021
//This is the quick sort algorith implementation

#include "volsort.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void stl_sort(List &l, bool numeric) {
  //makes a node to set to the head of the list
  Node* temp;
  vector<Node*> inVect;
  temp=l.head;
  //Pushes the list into the vector

  while(temp!=NULL){
    inVect.push_back(temp);
    temp=temp->next;
  }
  
  
  
  if(numeric){//sorts the vector if it is numeric
    sort(inVect.begin(), inVect.end(), node_number_compare);
  }
  else{//Sorts it if sorting by string
    sort(inVect.begin(), inVect.end(), node_string_compare);
  }
  
  
  
  for(unsigned int i=0;i<inVect.size()-1;i++){//Reorder's the pointers in order of the vector
    temp=inVect.at(i);
    temp->next=inVect.at(i+1);
  }
  
  
  
  l.head=inVect.at(0);//Sets the head
  inVect.at(inVect.size()-1)->next=NULL;//Makes the list have an end
  
}

bool node_number_compare(const Node *a, const Node *b){//String comparison function for sort()
  return(a->number < b->number);
} 

bool node_string_compare(const Node *a, const Node *b){//Int comparison function for sort()
  return(a->string < b->string);
}

