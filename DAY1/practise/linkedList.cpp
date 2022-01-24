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
    void remov(int data){
        if(!this->head)
            return;
        else if(data == this->head->val){
            this->head = this->head->next;
            return;
        }
        else{
            Node* temp = this->head;
            Node* temp1 = temp->next;
            while(temp1){
                
                if(temp1->val == data){
                    
                    if(temp1 == this->tail){
                        temp = this->tail;
                        temp->next = NULL;
                    }
                    else{
                        temp->next = temp1->next;
                        temp1->next = NULL;
                    }
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
    }
};

void printLinkedList(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }cout<<endl;
}
int main(){
    int n,t;
    singlyLL* list = new singlyLL();    //creating object list of class singlyLL
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        list->append(t);    //adding elements to linked list
    }
    int opt;    
    while(opt!=0){
    cout<<"Select options: 0: To exit program\n1: Appending new node to the list with given value\n2: Removing node of specific value\n3: Print linked list\n";
    cin>>opt;
    switch (opt)
    {
        case 1:{
            cin>>t;
            list->append(t);    
            printLinkedList(list->head);
            break;
        }
        case 2:{
            cin>>t;
            list->remov(t);
            printLinkedList(list->head);
            break;
        }
        case 3:{
            printLinkedList(list->head);
            break;
        }
        default:
            break;
    }
   }
   
    return 0;
}