#include<iostream>
#include<vector>
using namespace std;
    
class node
{
    public:
    int data;
    node* next=NULL;

};

class StackLinkList
{
	node* head;
    node* tail;
    
    //size of the link list 
    int size;  
    public:

    StackLinkList(){
        this->head = this->tail = new node();
    }

    void Push(int el){

        node* temp = new node();
        temp->data = el;
        temp->next = NULL;
        if(!this->head){
            this->head = temp;
        }
        else{
            this->tail->next = temp;
            tail = temp;
        }
    }

    void Pop(){
        if(!this->head){
            return;     // underflow!!
        }
        node* temp=this->head;
        while(temp->next != this->tail)
        {
            temp = temp->next;
        }
        this->tail = temp;
        this->tail->next = NULL;
    }
    int getMax(){
        node* temp = this->head;
        int mx = -1;
        while(temp){
            if(mx<temp->data)
                mx = temp->data;
            temp = temp->next;
        }
        return mx;
    }
};

int main(){
    StackLinkList* Stack = new StackLinkList();
    vector<int> maxElements;
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int query;
        cin>>query;
        switch (query)
        {
            case 1:
            {
                int x;
                cin>>x;
                Stack->Push(x);
                break;
            }
            case 2:
            {
                Stack->Pop();
                break;
            }
            case 3:
            {
                maxElements.push_back(Stack->getMax());
                break;
            }
            default:
                break;
        }
    }cout<<endl;
    for(int i=0; i<maxElements.size(); i++)
        cout<<maxElements[i]<<endl;
    
    return 0;
}