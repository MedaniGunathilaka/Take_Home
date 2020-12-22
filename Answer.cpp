#include<stdio.h>
#include<malloc.h>
#include<conio.h>
int begin;
int end_address;
int size;
int hole;
int id;


struct node{
	int start_address;
	int end_address;
	int hole;
	int id;
	struct node *next;
};


struct node* start=NULL;
struct node* ptr;

struct node memory ={400,2560,1,-1,NULL};

int create_list(int first,int last,int hole,int id){
	struct node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->start_address=first;
	newnode->end_address=last;
	newnode->hole=hole;
	newnode->id=id;
	
	if(start==NULL){
		newnode->next=NULL;
		start=newnode;	
		return 1;	
	}else{
		ptr=start;
		while(ptr->next!=NULL){
			if(ptr->hole==1 && (ptr->end_address-ptr->start_address)>(last-first)){
				ptr->id=id;
				ptr->hole=hole;
				return 1;
			}
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=NULL;
	}
	if(end_address>memory.end_address){
		return 0;
	}
	
}

void terminate(int id){
	ptr=start;
	while(ptr->id!=id){
		ptr=ptr->next;
	}
	ptr->hole=1;
}

int print(struct node *start){
	ptr=start;
	if(ptr==NULL){
		printf("List is empty\n");
	}else{
			while(ptr!=NULL){
				if(ptr->end_address<memory.end_address){
					printf("\n");
					printf("\nBegin address : %d\n",ptr->start_address);
					printf("End address : %d\n",ptr->end_address);
					printf("Hole : %d\n",ptr->hole);
					printf("Id : %d\n",ptr->id);
					ptr=ptr->next;
				}else{
					return 0;
				}
			}	
		}
	
	printf("\n");
}

int main(){
	printf("--===SELECT YOUR OPTION===--\n");
	printf("Enter 1 to Allocation memory\n");
	printf("Enter 2 to Terminate memory\n");
	printf("Enter 3 to Print the details of allocation\n");
	printf("Enter 4 to Exit\n");
	printf("--=========================--\n");	
	printf("Note that your size of the memory should be less than 2160k\n\n");
	int x,val;
	do{
		printf("Enter the option : ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Enter the id : ");
				scanf("%d",&id);
				printf("Enter the size of allocation : ");
				scanf("%d",&size);
				printf("\n");
				begin=memory.start_address;
				end_address= begin+size-1;
				hole=0;
				val=create_list(begin,end_address,hole,id);
				if(val==0){
					printf("\nNo enough memory location\n");
					
					printf("\nEnter 2 to Select Terminate\n");
					printf("Enter 4 to Exit from the program\n");
				
					do{
						printf("Enter the option : ");
						scanf("%d",&x);
						
						switch(x){
							case 1:
								printf("Enter the id : ");
								scanf("%d",&id);
								printf("Enter the size of allocation : ");
								scanf("%d",&size);
								printf("\n");
								begin=memory.start_address;
								end_address= begin+size-1;
								hole=0;
								val=create_list(begin,end_address,hole,id);
					
								if(end_address+1<memory.end_address){
									memory.start_address=end_address+1;	
								}
								break;
							case 2:
								printf("Enter the id : ");
								scanf("%d",&id);
								printf("\n");
								terminate(id);
								break;
							case 3:
								print(start);
								break;
							case 4:
								return 0;
								break;
							default:
								printf("Wrong input\n");
						}	
					}while(x!=4);
					getch();
				}
				if(end_address+1<memory.end_address){
					memory.start_address=end_address+1;	
				}
				break;
			case 2:
				printf("Enter the id : ");
				scanf("%d",&id);
				printf("\n");
				terminate(id);
				break;
			case 3:
				print(start);
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Wrong input\n");
		}
	}while(x != 4);
	getch();
	return 0;
}
