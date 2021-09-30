#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[30];
    char rollno[20];
    char semester[20];
    char branch[20];
    struct student *next;
};
typedef struct student list;
list *start,*temp;
FILE *fp,*tmp;
void base();
int createList(int n);
void search(list*);
void update(list*);
void insert(list**,int,int);
void delrec(list*);
void traverse(list*);
void save(list*);
list* ReadListIn(list*);
list* ReadNextFromFile(list*,FILE*);
int main()
{
    base();
    return 0;
}
void base(){
start=NULL;
int b,c,n,pos;
start=ReadListIn(start);
 do
 {
  printf("\n\t-----------------------Select your choice-----------------------\n");
  printf("\n\t1. CREATE THE RECORDS\n\t2. INSERT A RECORD\n\t3. DISPLAY\n\t4. SEARCH\n\t");
  printf("5. DELETE A RECORD \n\t6. UPDATE A RECORD\n\t7. REPORT GENERATION\n");
  printf("\t8. SAVE\n\t9. EXIT");
  printf("\n\t----------------------------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
    printf("Enter no. of records to create nodes\n");
    scanf("%d",&n);
    b=createList(n);
      break;
  case 2:
      printf("Enter pos of records to insert node\n");
      scanf("%d",&pos);
      insert(start,pos,b);
      break;
  case 3:
      traverse(start);
    break;
  case 4:
      search(start);
      break;
  case 5:
      delrec(start);
      break;
  case 6:
    update(start);
    break;
  case 7:
      report(start);
    break;
  case 8:
      save(start);
    break;
  case 9:
      exit(0);
   default:
       printf("xxxx-Invalid Input-xxxx\n");
 }
}while (c != 10);
}
int createList(int n)
{
int i;
for(i=0;i<n;i++){
    list *newnode=(list *)malloc(sizeof(list));
    printf("ROLL NO.: ");
    fflush(stdin);
    gets(newnode->rollno);
    printf("Name: ");
    gets(newnode->name);
    printf("Semester: ");
    gets(newnode->semester);
    printf("Branch: ");
    gets(newnode->branch);
    printf("The record is sucessfully added\n");
    newnode->next=NULL;
	if(start==NULL){
		start=newnode;
	}
	else{
		newnode->next=start;
		start=newnode;
	}
}
return i;
}
list* getNode(void)
{
    list *newNode = (list*)malloc(sizeof(list));
    fflush(stdin);
    gets(newNode->rollno);
    gets(newNode->name);
    gets(newNode->branch);
    gets(newNode->semester);
    newNode->next = NULL;
    return newNode;
}
void insert(list** current, int pos,int size)
{
    if (pos < 1 || pos > size+ 1)
        printf("Invalid position!");
    else {

        while (pos--) {
            if (pos == 0) {
                list* temp = getNode();
                temp->next = *current;
                *current = temp;
            }
            else
              current = &(*current)->next;
        }
        size++;
    }
}
void traverse(list *p)
{
	printf("Roll number\t\tName\t\tSemester\t\tBranch\n");
	while(p){
		printf("%10s	%12s	%12s	%20s\n",p->rollno,p->name,p->semester,p->branch);
		p=p->next;
	}
}
void search(list *p){
	char rollno[20];
	fflush(stdin);
	printf("\n Enter roll number to be searched :");
	gets(rollno);
	while(p){
		if(strcmp(rollno,p->rollno)==0){
			printf("Record Found!!Details are as follows:\n\n");
			printf("Roll number\t\tName\t\tSemester\t\tBranch\n");
			printf("%10s	%12s	%12s	%20s\n",p->rollno,p->name,p->semester,p->branch);
			return;
		}
		p=p->next;
	}
  printf("No student with roll no %s found!!\n\n",rollno);
}
void update(list *p){
	char rollno[20];
	fflush(stdin);
	printf("\n Enter roll number which needs to be updated :");
	gets(rollno);
	while(p){
		if(strcmp(rollno,p->rollno)==0){
			printf("Enter Updated Roll number: ");
			gets(p->rollno);
			printf("Enter Updated Name : ");
			gets(p->name);
			printf("Enter Updated Semester: ");
			gets(p->semester);
			printf("Enter Updated Branch : ");
			gets(p->branch);
			printf("Record Updated\n");
			return;
		}
		p=p->next;
	}
	printf("No students with roll no %s Found",rollno);
}
void delrec(list *p)
{
	temp=p;
	char rollno[20];
	if(p==NULL)
	{
		printf("\n Linked list is already empty!!");
		return;
	}
	fflush(stdin);
	printf("\nEnter roll number for which record has to be deleted- ");
	gets(rollno);
	if(strcmp(rollno,p->rollno)==0)
	{
		start=start->next;
		free(p);
		printf("\n Record Deleted !!");
	}
	else{
		while(strcmp(rollno,p->rollno)!=0)
		{
			temp=p;
			p=p->next;
			if(!p)
			{
				printf("No student Found for the given roll number %s\n",rollno);
				return;
			}
		}
		temp->next=p->next;
		free(p);
		printf("\n Record Deleted !!");
	}
}
void report(list *p){
	int count=0,choice;
	char s[20];
	printf("\nPress 1 and enter for Report Based on semester\n");
    printf("\nPress 2 and enter for Report Based on branch\n");
	scanf("%d",&choice);
switch(choice){
   case 1:
            printf("\nYou have chosen for Report Based on semester\n");
            fflush(stdin);
            printf("Enter semester : ");
            gets(s);
            while(p){
                if(strcmp(s,p->semester)==0)
                {
                    count++;
                    printf("Roll Number : %s\n",p->rollno);
                    printf("Name : %s\n",p->name);
                    printf("Semester : %s\n",p->semester);
                    printf("Branch : %s\n\n",p->branch);
                    p=p->next;
                }
            }
                printf("Total number of students enrolled for %s semester are %d\n\n",s,count);
	break;
   case 2:
            printf("\nYou have chosen for Report Based on branch\n");
            fflush(stdin);
            printf("Enter branch : ");
            gets(s);
            printf("\n\n");
            while(p){
                if(strcmp(s,p->branch)==0)
                {
                    count++;
                    printf("Roll Number : %s\n",p->rollno);
                    printf("Name : %s\n",p->name);
                    printf("Semester : %s\n",p->semester);
                    printf("Branch : %s\n\n",p->branch);
                    p=p->next;
                }
            }
            printf("Total number of students in %s semester are %d\n\n",s,count);
	break;
   default:
        printf("Invalid Input\n");
    break;
}
}
void save(list *p){
	FILE *fp;
	fp = fopen("myLinkedList.txt", "wb+");
	if(fp != NULL) {
		list *holdNext = NULL;
		while(p){
			holdNext = p->next;
			p->next = NULL;
			fseek(fp, 0, SEEK_END);
			fwrite(p, sizeof(*p), 1, fp);
			p->next = holdNext;
			holdNext = NULL;
			p = p->next;
		}
		fclose(fp);
		printf("File saved Successfuly\n");
	}
	else {
		printf("Nothing to save in file\n");
	}
}
list* ReadListIn(list *p){
	FILE *fp;
	fp = fopen("myLinkedList.txt", "rb");
	if(fp != NULL) {
		p = NULL;
		fseek(fp, 0, SEEK_END);
		long fileSize = ftell(fp);
		rewind(fp);
		int numEntries = (int)(fileSize / (sizeof(list)));
		int i;
		for( i = 0; i < numEntries; i++) {
			fseek(fp, (sizeof(list) * i), SEEK_SET);
			p = ReadNextFromFile(p, fp);
		}
	}  else {
		printf("Nothing to show in file.Create one first to perform operations\n");
	}
	return p;
}
list* ReadNextFromFile(list *p, FILE *fp) {
	if(p == NULL) {
		p = (list*)malloc(sizeof(list));
		fread(p, sizeof(list), 1, fp);
		p->next = NULL;
	} else {
		list *index = p;
		list *newp = (list*)malloc(sizeof(list));
		while(index->next != NULL) {
			index = index->next;
		}
		fread(newp, sizeof(list), 1, fp);
		index->next = newp;
		newp->next = NULL;
	}
	return p;
}

