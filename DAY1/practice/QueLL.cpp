#include<iostream>
using namespace std;
   
//node class for creating node for linked list
class node
{
    public:
    int data;
    node* next = NULL;
    
};

//class for creating linked list
class QueueLinkList
{
	node* head;
	node* tail;
    
	//size of the link list 
	int size;  
	public:

    	//constructor
        QueueLinkList() 
        {
            size=0;
            this->head = this->tail=new node();
        }
      	
	//function to insert an element in the queue
	void Enqueue(int d) 
	{
		node* temp = new node();
		if(size == 0)
		{
			this->head->data = d;
			this->head->data = this->tail->data;
			this->head->next = NULL;

		}

		else
		{
			temp = new node();
			temp->data = d;
			this->tail->next = temp;
			this->tail = temp;
			temp->next = NULL;

		}

		size++;
	}
	
	//removes element from the queue
	int Dqueue() 
	{
		int temp = this->head->data;
		this->head = this->head->next;
		node* temp1 = this->head;
		size--;
		return temp;
	    

	}
	
	//returns the current length of the queue
    	int Length()
	{
		return size;
	}
	
	//returns the current head element
	int FirstElement() 
	{
		return this->head->data;
	    
	}
	
	//clears the entire queue
	void clearQueue()
	{
		this->tail=this->head = new node();
		size=0;
	}
	
	//display all the elements of of the queue
	void Display()
	{
		node* temp = this->head;
		while(temp != NULL)
		{    
		    cout<<temp->data<<" ";
		    temp = temp->next;
		}
		cout<<endl;
		cout<<"size of queue = "<<size<<endl;
	}
	
};

void PrintInstruction(){
	    //possible operations
    	cout<<"0: to terminate the programme"<<endl<<"1: to know the length of queue"<<endl<<"2: to know the value of first location"<<endl<<
    	"3: to insert the element in queue"<<endl<<"4: to remove the element from queue"<<endl<<"5: to clear the queue"<<
    	endl<<"6: to display the values of queue"<<endl<<"7: to print the instruction"<<endl;
}

int main()
{

	QueueLinkList* Q = new QueueLinkList();	//creating object of class QueueLinkList
	int n = -1;
	
	PrintInstruction();
	
	//infinite loop untill the user enters '0'.
	while(n != 0)    
	{
		cout<<endl;
		cout<<"ENTER ANY NO. BETWEEN 0 TO 6: ";
		cin>>n;
		switch(n)
		{
			case 0:
				exit(0);
		    
			case 1:
			{
				cout<<"length is : "<<Q->Length()<<endl;
				break;
			}   
			case 2:
			{
			    if(Q->Length() <= 0)
				cout<<"queue is empty...!!!"<<endl;
			    else
				cout<<"first element is : "<<Q->FirstElement()<<endl;
			    break;

			}
			case 3:
			{
				int d;
				cout<<"Enter the element to insert in the queue: ";
				cin>>d;
				Q->Enqueue(d);
				break;
			}
			case 4:
			{
			    if(Q->Length() <= 0)
				cout<<"queue is empty...!!!"<<endl;
			    else
				cout<<"removed element is : "<<Q->Dqueue()<<endl;
			    break;
			}
			case 5:
			{
				Q->clearQueue();
				break;
			}
			case 6:
			{
				Q->Display();
				break;
			}
			case 7:
			{
				PrintInstruction();
				break;
			}
			default:
			{
				cout<<"method doesn't exists..!!!"<<endl;
				break;
			}

		}
	}
	return 0;
}
