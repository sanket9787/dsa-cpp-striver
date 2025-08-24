#include<iostream>
#include<map>
using namespace std;



class node {
    public :
    int data;
    node* next;
    node* prev;


    node(int data){
       this->data = data;
       this->next = NULL;
       this->prev = NULL;
    }
    
};

void insertAtbeg(node* &head,int data){

    node* temp = new node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
  
}

void inserAttail(node* &tail,int data){
    node*temp = new node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtany(node* &head,node* &tail,int data,int pos){
    

  



    node* temp = head;
    int cnt= 1;
    while(cnt<pos-1){
        temp= temp->next;
        cnt++;
    }

    //insert at last 
    if(temp -> next == NULL){
        inserAttail(tail,data);
        
    }

    node* newNode = new node(data);

    newNode-> next = temp -> next;
    temp-> next -> prev = newNode;
    temp->next = newNode;
    newNode -> prev = temp;

}



void print(node* &head){
   node* temp = head ;
   
   while(temp != NULL){
       cout<< temp->data<<" ";
       temp= temp->next;
       
   }
   cout<<endl;

}

int main(){
    
   node* node1 = new node(10);
   
   node* head = node1;
   node* tail = node1;
   
   inserAttail(tail , 20);
   inserAttail(tail , 30); 
   inserAttail(tail , 40);

   print(head);

   insertAtany(head,tail, 35, 4);
   print(head);



}