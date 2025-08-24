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
 
    //destructor
  ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtbeg(node* &head,int d){
   node* temp = new node(d);
   temp->next = head;
   head = temp;

}

void insertAttail(node* &tail, int d){
      node* temp = new node(d);
      tail->next = temp;
      tail = temp;
}

void inseratposition(node* &head,node* &tail,int pos,int data)
{
   //insert at start 
   if(pos == 1){
      insertAtbeg(head,data);
      return;
  }


   node* temp = head;
   int cnt = 1;
   while(cnt<pos-1){
      temp = temp->next;
      cnt++;
   }
   if(temp->next == NULL){
      insertAttail(tail,data);
      return;
   }

   node* insertatpos = new node(data);
   insertatpos->next = temp->next;
   temp->next = insertatpos;

}

void deleteNode(int pos, node* &head)
{  
   if(pos == 1){
      node* temp = head;
      head = head->next;
      
      temp->next = NULL;
      delete temp;
   }
   
   else{
    node* curr = head;
    node* temp = head;
    int cnt=1;
    while(cnt<pos){
       temp = curr;
       curr = curr->next;
       
       cnt++;
                }
 
        temp -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

   }
    
}


void print(node* &head){

   node* temp = head;
   while(temp != NULL){
   cout<< temp->data<< " ";
   temp = temp->next;

   }
   cout<<endl;
}

int main(){
  
   node* node1 = new node(10);
   cout<< node1->data<< " " << node1->next<<endl;
  
   node* head = node1;
   node* tail = node1;
   print(head);

  insertAttail(tail,20);
  print(head);

  insertAttail(tail,30);
  print(head);
   
  inseratposition(head,tail,1,25);
  print(head);
  
  deleteNode(4,head);
  print(head);

}




