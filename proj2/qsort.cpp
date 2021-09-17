// qsort.cpp
//Andrew Hines
//9-12-2021
//This is the qsort algorith implementation


#include "volsort.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;





void qsort_sort(List &l, bool numeric) {

  //makes a node to set to the head of the list
  Node* temp;
  temp=l.head;//set temp to the head

  vector<Node*> myVect;//Vector of Node*
  while(temp!=NULL){//While the list isn't empty, feed it into the vector.
    myVect.push_back(temp);
    temp=temp->next;
  }
  if(numeric){//sorts the vector if it is numeric
    qsort(&myVect[0], myVect.size(),sizeof(Node*), c_node_number_compare);//qsort call
    for(unsigned int i=0;i<myVect.size()-1;i++){//Reorder's the pointers of the list in order of the vector
      temp=myVect[i];
      temp->next=myVect[i+1];
    }
  }
  else{  
    qsort(&myVect[0], myVect.size(),sizeof(Node*), c_node_string_compare);
    for(unsigned int i=0;i<myVect.size()-1;i++){//Reorder's the pointers
      temp=myVect[i];
      temp->next=myVect[i+1];
    }  
  }
  l.head=myVect[0];//Sets the head
  myVect[myVect.size()-1]->next=NULL;//Makes the list have an end

}
int c_node_number_compare(const void *a, const void *b){
  const Node *aNode=*(const Node**)a;//casting
  const Node *bNode=*(const Node**)b;
  return(aNode->number - bNode->number);
} 

int c_node_string_compare(const void *a, const void *b){
  const Node *aNode=*(const Node**)a;//casting
  const Node *bNode=*(const Node**)b;
  return strcmp(aNode->string.c_str(), bNode->string.c_str());
  
}



