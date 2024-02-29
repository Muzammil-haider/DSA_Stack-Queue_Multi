#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record{
	int Rollno;
	float Gpa;
	Record *next;
	Record *last;
};



void insert(Record **head){
	Record *ptr = (Record*)malloc(sizeof(Record));
	cout<<"Enter your Rollno: ";
	cin>>ptr->Rollno;
	cout<<"Enter your gpa: ";
	cin>>ptr->Gpa;
	if(*head==NULL){
		*head=ptr;
	}
	else{
		Record *curr=*head; 
		while(curr!=NULL){
		curr=curr->next;
		}
		curr->next=ptr;
	}
}
void inqueue(Record **head,Record **last)
{	Record *ptr = (Record*)malloc(sizeof(Record));
ptr->next=NULL;
	cout<<"Enter your Rollno: ";
	cin>>ptr->Rollno;
	cout<<"Enter your gpa: ";
	cin>>ptr->Gpa;


			 
		if(*head==NULL){
			*head=ptr;
			*last=ptr;
			
		}
		else{
			Record *curr=*last;
			
			curr->next=ptr;
			*last=curr->next;
			
			
		}
		
		
	


	
}
void dequeue(Record **head){
	
	if(*head!=NULL){
	Record *curr=*head;
	cout<<curr->Rollno;
	
	*head=curr->next;
	free(curr);
}
else{
	cout<<"Stack underflow";
}}
void search(Record**head){
	int tosearch;
	int count=0;
	cout<<"Enter Rollno to find";
	cin>>tosearch;
	Record *curr=*head;
   while(curr!=NULL){
   	if(tosearch==curr->Rollno){
   		cout<<curr->Rollno;
   		count=1;
   		break;
	   }
   	else{
   		curr=curr->next;
	   }
   	
   	
   }
   if(count==0){
   	cout<<"not found";
   }
}
void print(Record **head){
	Record *curr=*head;
   while(curr!=NULL){
   	
   		cout<<"Your Rollno: "<<curr->Rollno<<endl;
   		cout<<"Your gpa:"<<curr->Gpa<<endl;
   		curr=curr->next;
	   }
   	
   	
   }
int Delete(Record**head){
	int todelete;
	cout<<"What are you want to delete enter your rollno: ";
	cin>>todelete;
	Record*curr=*head;
	if(todelete==curr->Rollno){
		*head=curr->next;
		free(curr);
		return 0;
	}
	else{
		Record*prev=*head;
		curr=curr ->next;
		while(curr!=NULL){
			if(todelete==curr->Rollno){
				prev->next=curr->next;
				free(curr);
				
				return 0;
			}
			else{
				prev=prev->next;
				curr=curr->next;
			}
		}
		if(curr==NULL){
			cout<<"not found"<<endl;
		}
	}
}
void DeleteAll(Record**head){

Record*curr=*head;

while(curr!=NULL){

	*head=curr->next;
free(curr);
	curr=*head;
}
free(*head);
}


int main()
{
Record *head = NULL;
Record *last=NULL;
int y=1;

while(y<=7){
cout<<"What you want\nfor insert enter 1\nfor search enter 2\nfor print enter 3\nfor delete enter 4\nfor delete all enter 5 \nfor inqueue enter 6\nfor dequeue enter 7";

cin>>y;
if(y==1){
	insert(&head);
}
else if(y==2){
	search(&head);
}
else if(y==3){
	print(&head);
}
else if(y==4){
	Delete(&head);
}else if(y==5){
	DeleteAll(&head);
}
else if(y==6){
	inqueue(&head,&last);
}
else if(y==7){
	dequeue(&head);
}
else{
	cout<<"Invalid number";
}
}}

