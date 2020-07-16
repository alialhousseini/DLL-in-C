#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node
{
	char name[50];
	char type[50];
	int revenue;
	int sal;
	int pop;
	char country[50];
	struct node* prev;
	struct node* next;
}node;

int parseInt(char number[50])
node* createNode(char name[50],char type[50],int rev,int sal,int pop,char country[50])
void addNode(node**root, node* added)
node* creatDLL(char filename[50])
node* searchByName(node* root, char name[50])
void removeNode(node** root, char name[50])
int findRank(node* root,node* target)
void updateRevenue(node** root,char name[50],int newRev)
void rankInfo(node* root, char name[50], node**pred, node** succ, int* rank)
void updateFile(node* root,char filename[50])
void printMenu()
void choice1(node** root)
void choice2(node** root)

void choice3(node* root)

void choice4(node** root)

void choice5(node** root)

void choice6(node* root)

void debugging(node* root)

void startInteractions()



int parseInt(char number[50])
{
	int i=0;
	int j=0;
	char c = number[0];
	char new[50];
	while(c!='\0')
	{
		if(c!=',' && c!='$' && c!='-')
			new[j++] = c;
		i++;
		c = number[i];
	}
	new[j] = '\0';
	i = atoi(new);
	if(number[0] == '-')
		i = -i;
	return i;
}


node* createNode(char name[50],char type[50],int rev,int sal,int pop,char country[50])
{
	node* n = (node*) malloc(sizeof(node));
	strcpy(n->name,name);
	strcpy(n->type,type);
	n->revenue = rev;
	n->sal = sal;
	n->pop = pop;
	strcpy(n->country,country);
	n->next = NULL;
	n->prev = NULL;
	return n;
}




void addNode(node**root, node* added)
{
	if(*root == NULL)
		*root = added;
	else
	{
		if((*root)->revenue <= added->revenue)
		{
			node* temp = *root;
			*root = added;
			(*root)->next = temp;
			(*root)->prev = temp->prev;
			temp->prev = *root;
		}
		else if((*root)->next == NULL)
		{
			(*root)->next = added;
			added->prev = *root;
		}
		else
			addNode(&((*root)->next),added);
	}
}


node* creatDLL(char filename[50])
{
	FILE* f = fopen(filename,"r");
	if(!f)
	{
		printf("Error opening the file!");
		exit(1);
	}
	
	char name[50];
	char type[50];
	int rev;
	int sal;
	int pop;
	char country[50];

	char dollar;
	char temp[50];

	node* root = NULL;

	while(!feof(f))
	{
		fgets(name,50,f);
		fgets(type,50,f);
		name[strlen(name)-2] = '\0';
		type[strlen(type)-2] = '\0';

		fgets(temp,50,f);
		temp[strlen(temp)-2] = '\0';
		rev = parseInt(temp);

		fgets(temp,50,f);
		temp[strlen(temp)-2] = '\0';
		sal = parseInt(temp);

		fgets(temp,50,f);
		temp[strlen(temp)-2] = '\0';
		pop = parseInt(temp);

		fgets(country,50,f);
		country[strlen(country)-2] = '\0';

		addNode(&root,createNode(name,type,rev,sal,pop,country));
		fgets(temp,50,f);

	}

	fclose(f);
	return root;
}


node* searchByName(node* root, char name[50])
{
	if(root == NULL)
	{
		printf("The company is not found!\n");
		return NULL;
	}
	else
	{
		if(strcmp(name,root->name) == 0)
			return root;
		return searchByName(root->next,name);
	}

}

void removeNode(node** root, char name[50])
{
	node* target = searchByName(*root,name);
	if(target!=NULL)
	{
		if(target == *root)
		{
			node* temp = (*root)->next;
			free(*root);
			*root = temp;
			(*root)->prev = NULL;
		}

		else
		{
			node* prev = target->prev;
			node* next = target->next;
			free(target);
			prev->next = next;
			next->prev = prev;
		}
	}
}

int findRank(node* root,node* target)
{
	if(target == root)
		return 1;
	return(1+findRank(root->next,target));
}

void updateRevenue(node** root,char name[50],int newRev)
{
	node* target = searchByName(*root,name);
	if(target!=NULL)
	{
		node* new = createNode(target->name,target->type,newRev,target->sal,target->pop,target->country);
		removeNode(root,target->name);
		addNode(root,new);
	}
}

void rankInfo(node* root, char name[50], node**pred, node** succ, int* rank)
{
	node* target = searchByName(root,name);
	if(target!=NULL)
	{
		*pred = target->prev;
		*succ = target->next;
		*rank = findRank(root,target);
	}
}

void updateFile(node* root,char filename[50])
{
	FILE* f = fopen(filename,"w");
	if(f==NULL)
	{
		printf("Error opening the file!");
		exit(1);
	}
	while(root!=NULL)
		{
			fprintf(f, "%s\n%s\n$%d\n$%d\n%d\n%s\n------------------------------\n",root->name,root->type,root->revenue,root->sal,root->pop,root->country);
			root = root->next;
		}
	fclose(f);
}


void printMenu()
{
	printf("Please choose a number for the corresponding action:\n");
	printf("1. Create a doubly linked list for the file data\n");
	printf("2. Update the revenues of a company\n");
	printf("3. Get ranking information about a company\n");
	printf("4. Remove a company from ranking\n");
	printf("5. Add a new company to the list\n");
	printf("6. Quit\n");
}


void choice1(node** root)
{
	printf("\n");
	*root = creatDLL("ListOfCompanies.txt");
	printf("\n");
}

void choice2(node** root)
{
	printf("\n");
	char name[50];
	char temp[50];
	int newRev;
	printf("Please enter the name of the company:\n");
	scanf("%s",name);
	printf("Please enter the new revenue:\n");
	scanf("%s",temp);
	newRev = parseInt(temp);
	updateRevenue(root,name,newRev);
	printf("\n");
}

void choice3(node* root)
{
	printf("\n");
	char name[50];
	printf("Please enter the name of the company:\n");
	scanf("%s",name);
	int rank;
	node* succ = NULL;
	node* pred = NULL;

	rankInfo(root,name,&pred,&succ,&rank);

	if(pred == NULL && succ == NULL)
		return;
	printf("Rank:%d\n",rank);
	printf("Predecessor: %s\n",pred->name);
	printf("Successor: %s\n", succ->name);
	printf("\n");
}

void choice4(node** root)
{
	printf("\n");
	char name[50];
	printf("Please enter the name of the company:\n");
	scanf("%s",name);
	removeNode(root,name);
	printf("\n");
}

void choice5(node** root)
{
	printf("\n");
	char temp[50];
	char name[50];
	char type[50];
	int revenue;
	int sal;
	int pop;
	char country[50];
	printf("Please enter the name of the new company:\n");
	scanf("%s",name);
	if(searchByName(*root,name)!=NULL)
	{
		printf("The company is already listed!\n");
		return;
	}
	else
		printf("So you can proceed!\n");

	printf("Please enter the type of the company:\n");
	scanf("%s",type);
	printf("Please enter the revenues of the company:\n");
	scanf("%s",temp);
	revenue = parseInt(temp);
	printf("Please enter the profit of the company:\n");
	scanf("%s",temp);
	sal = parseInt(temp);
	printf("Please enter the population of the company:\n");
	scanf("%s",temp);
	pop = parseInt(temp);
	printf("Please enter the country of the company:\n");
	scanf("%s",country);

	addNode(root,createNode(name,type,revenue,sal,pop,country));
	printf("\n");

}

void choice6(node* root)
{
	printf("\n");
	updateFile(root,"ListOfCompanies.txt");
	printf("Your modifications are successfully saved.\n");
	exit(0);
}



void debugging(node* root)
{
	if(root == NULL)
		return;
	printf("%s, %d, ",root->name,root->revenue);
	if(root->next!=NULL)
		printf("%s, ",root->next->name);
	if(root->prev!=NULL)
		printf("%s, ",root->prev->name);
	printf("\n");
	debugging(root->next);
}

void startInteractions()
{
	printf("\nHello User!\n");
	node* root = NULL;
	int i=-1;
	while(1==1)
	{
		printMenu();
		scanf("%d",&i);
		while(i<1 || i>6 || (i!=1 && root == NULL))
		{
			if(i == 7)
				break;
			if(i<1 || i>6)
				printf("Please choose a valid choice!\n");
			else
				printf("You can't proceed while the list is empty!\n");
			scanf("%d",&i);
		}

		if(i==1)
			choice1(&root);
		if(i==2)
			choice2(&root);
		if(i==3)
			choice3(root);
		if(i==4)
			choice4(&root);
		if(i==5)
			choice5(&root);
		if(i==6)
			choice6(root);
		if(i==7)
			debugging(root);

	}

}


void main()
{
	startInteractions();
}