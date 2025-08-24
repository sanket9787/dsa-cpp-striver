#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }
    
};

void print(Node* &head){

   Node* temp = head;
   while(temp != NULL){
   cout<< temp->data<< " ";
   temp = temp->next;

   }
   cout<<endl;
}

void insert(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void reverse(Node* &head){
    Node *curr = head;
    Node *prev = NULL;
   
   while(curr != NULL){
     Node* temp = curr->next;
       curr->next = prev;
       prev = curr;
       curr = temp;
   }
   head = prev;
}

Node* reverseByRecursion(Node* &head){

    if(head == NULL || head -> next == NULL){
       return head;
    }
    
    int chotahead = reverseByRecursion(head -> next);
    head -> next -> next = head;
    head -> next =NULL;
    
    return chotahead;

}

int main(){
    Node* node1 = new Node(5);

    Node* head = node1;
    Node* tail = head;
     
    insert(tail,10);
    insert(tail,15);
    insert(tail,20);
    insert(tail,25);

    print(head);

    reverse(head);

    print(head);
    
}