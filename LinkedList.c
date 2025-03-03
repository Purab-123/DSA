#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListType{
    int data;
    struct ListType*next;
}LISTNODE;
LISTNODE *Head;

typedef struct List{
    char data[20];
    struct List*next;
}LISTNOD;
LISTNOD*charHead;

void InitList();
void fnMenu(int*ch);
void InsertList();
void DisplayList(LISTNODE*Head);
int DeleteFirstNode();
int DeleteLastNode();
int LinearSearch(int LSnum);
int MaxList();
int DeleteGivenNo(int given);
int CountNodes(LISTNODE*Head);
void OrderedList(int Num);
void InsertCharNode(char str[20]);
void DisplaycharNode(LISTNOD*charHead);


void main()
{
    int ch,i,N,Num,delfirst,dellast,found,LSnum,max,given,count;
    char str[20];
     InitList();
    printf("\nProgram to create a menu driven program for opertation in linked list\n");
    fnMenu(&ch);
    while(ch){
        switch (ch)
        {
        case 1:
         printf("How many nos ?");
         scanf("%d",&N);
         for(i=0;i<N;i++){
         printf("Enter number:");
         scanf("%d",&Num);
         InsertList(Num); 
         }
         fnMenu(&ch);
       break;
            case 2:
             DisplayList(Head);
             fnMenu(&ch);
            break;
                case 3:
                 if(Head ==NULL){
                     printf("List is empty!\n");
                      return;
                    }
                 delfirst=DeleteFirstNode();
                 printf("Deleted number:%d\n",delfirst);
                 printf("List after deleting first node\n");
                 DisplayList(Head);
                 fnMenu(&ch);
                break;
                    case 4:
                     if(Head ==NULL){
                     printf("List is empty!\n");
                     return;
                     }
                     dellast=DeleteLastNode();
                     printf("Deleted number:%d\n",dellast);
                     printf("List after deleting last node\n");
                     DisplayList(Head);
                     fnMenu(&ch);
                    break;
                        case 5:
                         if(Head ==NULL){
                         printf("List is empty!\n");
                         return;
                         }
                         printf("Enter Search Number:");
                         scanf("%d",&LSnum);
                         found=LinearSearch(LSnum);
                         if (found != -1) {
                         printf("Element %d is found in the list.\n",LSnum);
                         } else {
                         printf("Element %d is not found in the list.\n", LSnum);
                         }
                         fnMenu(&ch);
                        break;
                            case 6:
                             if(Head ==NULL){
                             printf("List is empty!\n");
                             return;
                             }
                             max=MaxList();
                             printf("Maximum number is:%d",max);
                             fnMenu(&ch);
                            break;
                              case 7:
                                 if(Head ==NULL){
                                 printf("List is empty!\n");
                                 return;
                                 }
                                 printf("What's the number for deletion:");
                                 scanf("%d",&given);
                                 DeleteGivenNo(given);
                                 printf("\nList after deletion of %d\n",given);
                                 DisplayList(Head);
                                 fnMenu(&ch);
                              break;
                              case 8:
                                 count=CountNodes(Head);
                                 printf("Number of Nodes:%d",count);
                                 fnMenu(&ch);
                              break;
                              case 9:
                                 printf("Enter the number to insert in the list:\n");
                                 scanf("%d",&Num);
                                 OrderedList(Num);
                                 printf("List after insertion\n");
                                 DisplayList(Head);
                                 fnMenu(&ch);
                               break;
                               case 10:
                                 printf("How many names?");
                                 scanf("%d",&N);
                                 for(i=0;i<N;i++){
                                 printf("Enter string:");
                                 scanf("%s",str);
                                 InsertCharNode(str);
                                 }
                                 DisplaycharNode(charHead);
                                 fnMenu(&ch);
                               break;
                               case 11:
                                 printf("Enter a char string\n");
                                 scanf("%s",str);
                                 InsertCharNode(str);
                                 printf("List after insertion\n");
                                 DisplaycharNode(charHead);
                                 fnMenu(&ch);
                                 break;
                                   case 12:
                                   exit(1);
                                   break;
         default:
         printf("Enter a valid choice\n");
        fnMenu(&ch);
            break;
        }
    }
}
void InitList()
{
    Head=NULL;
    charHead=NULL;
}

void fnMenu(int*ch)
{
  printf("\n\t\t\t\t\t\t\t\t\tLINKED LIST OPERTIONS\n\n");
  printf("1.Create List of Numbers\n");
  printf("2.Display List of Numbers\n");
  printf("3.Delete First Node(Numbers)\n");
  printf("4.Delete Last Node(Numbers)\n");
  printf("5.Linear Search(Numbers)\n"); 
  printf("6.Maximum Number\n");
  printf("7.Delete Given Number\n");
  printf("8.Count Nodes(Numbers)\n");
  printf("9.Ordered Linked List(Numbers)\n");
  printf("10.Create LinkList for strings\n");
  printf("11.Insert Ordered Linked List for strings\n");
  printf("12.EXIT\n");
  printf("Enter your choice:");
  scanf("%d",ch);
}

void InsertList(int Num)
{
    LISTNODE*prev,*curr,*next,*Node;
    Node=(LISTNODE*)malloc(sizeof(LISTNODE));
    Node->data=Num;
    Node->next=NULL;

    if(Head==NULL){
        Head=Node;
        return;
    }
    curr=Head;
    
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=Node;
}

void DisplayList(LISTNODE*Head)
{
    if(Head==NULL){
        printf("No List Found!!\n");
        return;
    }
    LISTNODE*Curr;
    Curr=Head;
    while(Curr!=NULL)
    {
        printf("%d->",Curr->data);
        Curr=Curr->next;
    }
    printf("NULL\n");
}

int DeleteFirstNode()
{
    LISTNODE*curr;
    int Num;
    curr=Head;
    Head=Head->next;
    Num=curr->data;
    free(curr);
    return Num;

}

int DeleteLastNode()
{
    LISTNODE*curr,*prev;
    int Num;
    curr=Head;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
    return Num;
}

int LinearSearch(int LSnum)
{ 
  LISTNODE*curr;
  curr=Head;
  int found=-1;
  while(curr!=NULL){
    if(LSnum==curr->data){
        return 1;
    }
    curr=curr->next;
  }
  return -1;
}

int MaxList ()
{
   LISTNODE*curr;
   curr=Head;
   int max;
   max=curr->data;
   while(curr!=NULL){
    if(curr->data>max){
        max=curr->data;
     }
    curr=curr->next;
   }
   return max;
}

int DeleteGivenNo(int given)
{
   LISTNODE*curr,*prev;
   curr=Head;
   if(curr->data==given){
    Head=Head->next;
    free(curr);
    return -1;
   }
   prev=NULL;
   while(curr!=NULL){
    if(curr->data==given){
         prev->next=curr->next;
        free(curr);
        return 0;
    }else{
     prev=curr;
     curr=curr->next;
   }
   }
   printf("The given number %d was not found in the list.\n",given);
   return -1;
}

int CountNodes(LISTNODE*Head)
{  
    LISTNODE*curr;
    int count=0;
    curr=Head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}

void OrderedList(int Num) 
{
    LISTNODE*curr,*prev,*Node;
    Node=(LISTNODE*)malloc(sizeof(LISTNODE));
    Node->data=Num;
    Node->next=NULL;
    if(Head==NULL){
        Head=Node;
        return;
    }
    if(Num<=Head->data){
        Node->next=Head;
        Head=Node;
        return;
    }
    curr=Head;
    prev=NULL;
    while(curr!=NULL && curr->data<=Num){
            prev=curr;
            curr=curr->next;
        }
        prev->next=Node;
        Node->next=curr;
    }

void InsertCharNode(char str[20])
{
    LISTNOD*curr,*prev,*Node;
    Node=(LISTNOD*)malloc(sizeof(LISTNOD));
    strcpy(Node->data,str);
    Node->next=NULL;
    if(charHead==NULL){
        charHead=Node;
        return;
    }

    if(strcmp( charHead->data,str)>0){
        Node->next= charHead;
        charHead=Node;
        return;
    }

    curr=charHead;
    while(curr!=NULL&&strcmp(curr->data,str)<=0){
        prev=curr;
        curr=curr->next;
    }
    prev->next=Node;
    Node->next=curr;
}
void DisplaycharNode(LISTNOD*charHead)
{
    LISTNOD*curr;
    curr=charHead;
    while(curr!=NULL){
       printf("%s->",curr->data);
       curr=curr->next;
    }
    printf("NULL\n");

}    
    

