/* 

		   LAB Session 2 Data Structure
By : 
  
  Nama : I Putu Krisna Dharma Saputra
  NIM  : 2301924353
  
*/

//Header File
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//Deklarasi Struct
struct rice_node{
	char type[50];
	int weight;
	struct rice_node *next;
};

struct rice_node *top = NULL;

//Deklarasi Fungsi
void add_stock();
void sell();
void rice_stock();

//fungsi main
int main(){
	int choice;
	
	do{
	system("cls");	
		printf("BLUE RICE STOCK\n");
		printf("^^^^^^^^^^^^^^^\n\n");
		rice_stock();
		printf("\n\n\nOption :\n");
		printf("1. Stock Rice Sack\n");
		printf("2. Sell Rice \n");
		printf("3. Exit\n\n");			
		printf(">> Input your choice : ");
	    fflush(stdin);
		scanf("%d",&choice);
			
		switch (choice){
			case 1 :{
				add_stock();
				break;
			}
			case 2 :{
				sell();
				break;
			}
    	}
    
    }while(choice !=3);
    
	system("cls");
 
	printf("\nThanks for Using This Program");	
  	getch();
  	
  	return 0;
}

//Fungsi Tampilan Rice Stock pada main menu	
void rice_stock(){
	struct rice_node *temp = NULL;
	temp = (struct rice_node*)malloc(sizeof(struct rice_node));
	temp = top;
	
	printf("  Rice Stock (STACK)\n\n");
	
	while(temp != NULL){
		if(temp == top){
			printf("[ %6s grain : %4d kg(s) ] -> [top]\n",temp->type,temp->weight);
		}
		else{
			printf("[ %6s grain : %4d kg(s) ]\n",temp->type,temp->weight);
	    }
		temp = temp->next;
	}
	
}

//Fungsi Push (Single Linked List)
int push(char *type, int weight){
	
	struct rice_node *temp = NULL;
	temp = (struct rice_node*)malloc(sizeof(struct rice_node));
	
	if(!temp){
		printf("\n\nHeap Overflow");
		return 0;
	}
	
	strcpy(temp->type,type);
	temp->weight = weight;
	
	if(top == NULL){
		temp->next = NULL;
	}
	else{
		temp->next = top;
	}
	top = temp;
	return 0;
	
}

//Fungsi menu ke 1 yaitu Stock Rice Sack
void add_stock(){
	char type[100];
	int weight;
	if(max_data() == 1){
		
		//Input rice type
		do{
		
			printf("\n\nInput Rice Type [long/medium/short] grain: ");
			fflush(stdin);
		    gets(type);
			if(strcmp(type, "long") !=0 && strcmp(type, "medium") !=0 && strcmp(type, "short") !=0){
				printf("\n      		Please choose appropriate type !\n ");
				getch();
			}
			
		}while(strcmp(type, "long") !=0 && strcmp(type, "medium") !=0 && strcmp(type, "short") !=0);
		
		//input rice weight
		do{
			
			printf("\nInput Weight of The Rice Sack [10..100 kg(s)]: ");
			scanf("%d",&weight);
		
			if(weight < 10 || weight > 100){
				printf("\n  Weight must be between 10 and 100 \n\n");
				getch();
			}
			
		}while(weight < 10 || weight > 100);
		
		push(type,weight);
		printf("\n	--- Add Rice Sack Success ---");
		getch();
	}
	else{
		printf("\n	--- The Rice Storage is Full ---");
		getch();
	}
}

int max_data(){
	int count=1;
	struct rice_node *temp = NULL;
	temp = (struct rice_node*)malloc(sizeof(struct rice_node));
	
	temp = top;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	
	if(count <= 10){
		return 1;
	}else{
		return 0;
	}
	getch();
}
		
// Fungsi menu ke 2 Sell
void sell(){
	struct rice_node *temp = NULL;
	
	temp = (struct rice_node*)malloc(sizeof(struct rice_node));

	if(top == NULL){
		printf("\n\n --- The Rice Storage is Empty ---");
		getch();
	}
	else{
		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);
		printf("--- Sell Rice Sack Success ---");
		getch();
	}
}







