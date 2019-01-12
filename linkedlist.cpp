#include <iostream>
using namespace std;

class node{
public:
//data
int data;
//pointer for the next node
node*next;//like pointer to int=int *pointer
//construct that makes pointer to null
node(){
      next=NULL;
      }
};	
	class linkedlist{
	//head +circle which are linked to each other 
	//head
	//circle which is of node type pointer
	public:
	node*head;
	node*tail;

	//construct
	linkedlist(){
	head=NULL;
	tail=NULL;
	}
	
	//linked circle  

	//insert
	void insert 
	(int value){
	//if 1st node added
	node * temp=new node;
	//insert value in the node
	temp->data=value;
	//1st node only present
	if(head==NULL)
	    head=temp;
	else{
	     //for the last addition   
	    tail->next=temp;
	}
	tail=temp;
	}
	void  insertAt(int pos ,int value){
	//reach the value before the position
	node*current=head;
	int i=1;
	while(i<pos-1){
	    i++;
	    current=current->next;
	}
	//create a node
	node*temp=new node;
	temp->data=value;
	//moving ptr like magic!
	temp->next=current->next;
	current->next=temp;
	}
	
	//del the last element
	void del(){
	//store  tail in temp
	node*temp=tail;
	//before tail has to point to null
	node*current=head;
	while(current->next!=tail){
	    current=current->next;
	}
	current->next=NULL;
	//update tail
	tail=current;
	//delete the temp
	}



	//del at a point
	void deleteAt(int pos){
	//delete the position
	node * current = head;
	int i = 1;
	while(i< pos){
	  i++;
	  current = current->next;
	  }
	//reach the place before the position
	node * current2 = head;
	int j = 1;
	while(j<pos-1){
	   j++;
	current2 = current2->next;
	  }
	//delete the node
	current2->next = current->next;
	delete current;
	}



	//counting
	int countItems(){
	node*current=head;
	int i=0;
	while(current!=NULL){
	    current=current->next;
	    i++;
	}
	cout<<"items number is :"<<i<<endl;

	}


	//display
	void display(){
	node*current=head;
	while(current!=NULL){
	    cout<<current->data<<"->";
	    current=current->next;
	}
	 cout<<endl;
	  
	}

	};

//main function
int main()
{
linkedlist l1;
l1.insert(11);
l1.insert(22);
l1.insert(33);
l1.insert(44);
l1.insert(55);
l1.display();
l1.countItems();
cout<<endl;
l1.insertAt(4,23);
l1.display();
cout<<endl;
l1.deleteAt(5);
l1.display();
cout<<endl;
l1.countItems();
l1.del();
l1.display();
l1.countItems();
return 0;
}

