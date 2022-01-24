#include<iostream>
using namespace std;
    
class node
{
    public:
    int data;
    node* next=NULL;
    
};

class QueueLinkList
{
	node* head;
    node* tail;
    
    //size of the link list 
    int size;  
    public:

    
        //constructors and destructors
        //constructors and destructors
        QueueLinkList() 
        {
            //QueueArray = new E[size];
            size=0;
            this->head=this->tail=new node();
        }
      
		void insert(int d) 
		{
			node* temp= new node();
			if(size==0)
			{
				this->head->data = d;
			  	this->head->data = this->tail->data;
				this->head->next=NULL;
				
			}
		
				else
				{
					temp=new node();
					temp->data=d;
					this->tail->next=temp;
					this->tail=temp;
					temp->next=NULL;
										
	        	}
			
                size++;
		}
		  
		int remov() 
		{
		    if(size==0)
		    {
		        cout<<"queue is empty...!!!"<<endl;
		    }
		    else
		    {
			    int temp=this->head->data;
		    	this->head=this->head->next;
		    	node* temp1=this->head;
		    	while(temp1!=this->tail->next)
		    	{
			       cout<<temp1->data<<" ";
			      temp1=temp1->next;
		    	}
		    	cout<<endl;
		    	size--;
		    	return temp;
		    }
			
		}
		 
		int length() 
		{
			return size;
		}
		 
		int FirstElement() 
		{
		    if(size==0)
		    {
		        cout<<"queue is empty...!!!"<<endl;
		    }
		    else
		    {
			    return this->head->data;
		    }
		}
		 
		void clearQueue()
		{
			this->tail=this->head=new node();
			size=0;
		}
		
		void display()
		{
			node* temp=this->head;
         	while(temp!=NULL)
           	{    
         	    cout<<temp->data<<" ";
          	    temp=temp->next;
          	}
            cout<<endl;
            cout<<"size of list = "<<size<<endl;
    	}
};


int main()
{

	QueueLinkList* A = new QueueLinkList();
    int n=-1;
    
    cout<<"0: to terminate the programme"<<endl<<"1: to know the length of queue"<<endl<<"2: to know the value of first location"<<endl<<
    "3: to insert the element in queue"<<endl<<"4: to remove the element from queue"<<endl<<"5: to clear the queue"<<
    endl<<"6: to display the values of queue"<<endl;
    while(n!=0)    
    {
        cout<<endl;
        cout<<"ENTER ANY NO. BETWEEN 0 TO 6: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
            	
                cout<<"length is : "<<A->length()<<endl;
                break;
            }   
            case 2:
            {
            	cout<<"first element is : "<<A->FirstElement()<<endl;
              	break;
            }
            case 3:
            {
            	int d;
            	cout<<"Enter the element to insert in queue: "<<endl;
            	cin>>d;
            	A->insert(d);
            	A->display();
            	break;
            }
            case 4:
            {
				cout<<"removed element is : "<<A->remov()<<endl;
				break;
			}
			case 5:
			{
				A->clearQueue();
				break;
			}
			case 6:
			{
				A->display();
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