#include<iostream>
using namespace std;

//node for singly linked list
class Node{
    public:
    int val;
    Node* next;

    //constructor
    Node(int data) {
            this->val = data;
            this->next = NULL;
    }
};

class singlyLL{
    public:
    Node *head;
    Node *tail;
    
    singlyLL(){
        this->head = NULL;
        this->tail = NULL;
    }

    void append(int data){

        Node* temp = new Node(data);
        if(!this->head)
            this->head = temp;
        else
            this->tail->next = temp;

        this->tail = temp;
    }  

};

void printLinkedList(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}
int main(){
    int n,t;
    singlyLL* list = new singlyLL();    //creating object list of class singlyLL
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        list->append(t);    //adding elements to linked list
    }
   
    printLinkedList(list->head);
    return 0;
}