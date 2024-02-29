#include<iostream>
#include<stdlib.h>
using namespace std;
struct student{
	int Rollno;
	
	student *next;

};
struct Record{
	int  Courseno;
	Record *next;
	student *Student;

};




void insert(Record **head){
	Record *ptr = (Record*)malloc(sizeof(Record));
	cout<<"Enter course no. ";
	cin>>ptr->Courseno;
	ptr->next=NULL;
	ptr->Student=NULL;
	
	if(*head==NULL){
		*head=ptr;
		
	}
	else{
		Record *curr=*head; 
		while(curr->next!=NULL){
		curr=curr->next;
		}
		curr->next=ptr;
	}
}
void insertstudent(Record **head){
	student *ptr = (student*)malloc(sizeof(student));
	ptr->next=NULL;
	int temp;
	cout<<"Enter course no. ";
	cin>>temp;
	cout<<"Enter student Rollno.";
	cin>>ptr->Rollno;
	Record *course=*head; 
	while(course!=NULL){
		if(course->Courseno==temp){
			if(course->Student==NULL){
		            course->Student=ptr;
	                break;
		
	}
	else{
		student *curr= course->Student; 
		while(curr->next!=NULL){
		curr=curr->next;
		}
		curr->next=ptr;
		break;
	}
		}
		else{
		
		course=course->next;}
	}
	
}


void search(Record**head){
	int tosearch;
	int count=0;
	cout<<"Enter courseno. to find";
	cin>>tosearch;
	Record *curr=*head;
   while(curr!=NULL){
   	if(tosearch==curr->Courseno){
   		cout<<curr->Courseno<<endl;
   		cout<<"Found"<<endl;
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
void printcourse(Record **head){
	Record *curr=*head;
   while(curr!=NULL){
   	
   		cout<<"Your courseno.: "<<curr->Courseno<<endl;
   		
   		curr=curr->next;
	   }
   	
   	
   }
void print(Record **head){
		int temp;
	cout<<"Enter course no. ";
	cin>>temp;
	Record *curr=*head;
   while(curr!=NULL){
   		if(curr->Courseno==temp){
   			student *std=curr->Student;
   			while(std!=NULL){
   	
   		cout<<"Your Rollno: "<<std->Rollno<<endl;
   	
   		std=std->next;
	   }break;
		   }
   		else{
		   
   		
   		curr=curr->next;}
	   }
   	
   	
   }
int Delete(Record**head){
    int todelete;
	cout<<"What are you want to delete enter course no. ";
	cin>>todelete;
	Record*curr=*head;
	if(todelete==curr->Courseno){
		*head=curr->next;
		free(curr);
		return 0;
	}
	else{
		Record*prev=*head;
		curr=curr ->next;
		while(curr!=NULL){
			if(todelete==curr->Courseno){
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
int Deletestudent(Record**head){
    int todelete;
    int tosearch;
	cout<<"What are you want to delete enter course no. ";
	cin>>tosearch;
	cout<<"Enter rollno to delete:  ";
	cin>>todelete;
	Record*curr=*head;
	
		while(curr!=NULL){
			if(tosearch==curr->Courseno){
				student*std=curr->Student;
				if(todelete==std->Rollno){
					(curr)->Student=std->next;
					free(std);
		return 0;
	}else{
	
				student*prev=std;
				std=std->next;
				while(std!=NULL){
					if(todelete==std->Rollno){
						prev->next=std->next;
						free(std);
						return 0;
					}
					else{
						prev=prev->next;
						std=std->next;
					}
				}
			}
			
		}}
		if(curr==NULL){
			cout<<"not found"<<endl;
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
student *front = NULL;
int y=1;

while(y<=6){
cout<<"What you want\nfor insert enter 1\nfor insertstudent enter 2\nfor print enter 3\nfor delete enter 4\nfor deletestudent enter 5\nfor print courses enter 6 ";

cin>>y;
if(y==1){
	insert(&head);
}
else if(y==2){
	insertstudent(&head);
}
else if(y==3){
	print(&head);
}
else if(y==4){
	Delete(&head);
}else if(y==5){
	Deletestudent(&head);
}
else if(y==6){
	printcourse(&head);
}
else{
	cout<<"Invalid number";
}
}}
