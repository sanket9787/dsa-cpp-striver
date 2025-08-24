#include<iostream>
#include<map>
using namespace std;

class node {
   
  public:
  int data;
  node* next;

  node(int data){
     this->data = data;
     this->next = NULL;
  }

};

void insertAttail(node* &tail, int d){
      node* temp = new node(d);
      tail->next = temp;
      tail = temp;
}

void print(node* &head){

   node* temp = head;
   while(temp != NULL){
   cout<< temp->data<< " ";
   temp = temp->next;

   }
   cout<<endl;
}
// int middle(node* &head){
//      node* fast = head;
//      node* slow = head;
//      while(fast != NULL || fast->next != NULL){
//          fast = fast -> next ->next;
//          slow = slow-> next;
//      }
//      return slow->data;
// }

int middle(node* &head){
   node* fast = head->next;
   node* slow = head;
   while(fast != NULL )
   {
      fast = fast -> next ;
      if(fast != NULL){
         fast = fast->next;
      }
      slow = slow->next;
   }
   return slow -> data;
}

int main(){
  
   node* node1 = new node(10);
  
   node* head = node1;
   node* tail = node1;

  insertAttail(tail,20);
  insertAttail(tail,30); 
  insertAttail(tail,40);

  insertAttail(tail,50);
  insertAttail(tail,60);
  print(head);
  
  int ans = middle(head);
  cout << ans << endl;
}