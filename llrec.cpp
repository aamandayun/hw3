#include "llrec.h"

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  if(!head){
    smaller=nullptr;
    larger = nullptr;
    return;
  }

  Node* current = head;
  head = head->next;

  Node* newsmall = nullptr;
  Node* newlarge = nullptr;
  llpivot(head, newsmall, newlarge, pivot);

  if(current->val<=pivot){
    current->next = newsmall;
    smaller = current;
    larger = newlarge;

  }else{
    current->next = newlarge;
    larger = current;
    smaller = newsmall;
  }


}

/*
int main(){
	Node* list = nullptr;
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 42);

  cout <<"reached"<<endl;

  return 0;
}

*/