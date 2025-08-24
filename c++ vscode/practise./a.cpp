#include<iostream>
#include <stdio.h>
using namespace std;

class node {
   public : 
   int data;
   node* next;

   node(int data){
   	 this->data = data;
   	 this->next = NULL;
   }
};

void insertbeg(node* head, int d){
    
    node* temp = new node(d);
    temp->next= head;
    head = temp;

}

void print(node* &head){
   node* temp = head;
   while(temp->next !=NULL){
   	cout << temp->data<<" ";
   	temp = temp->next;

   }
   cout << endl;

}

int main()
{
    //    Write your code here
node* node1 = new node(5);

node* head = node1;
node* tail = node1;

insertbeg(head ,6);
print(head);


}