#include<stdio.h>
#include<stdlib.h>

typedef struct TreeType{
    int data;
    struct TreeType*Left;
    struct TreeType*Right;
}TREE;

TREE*Root=NULL;

void fnMenu(int*ch);
void InsertTreeNode(int num);
void Preorder(TREE*Root);
void Inorder(TREE*Root);
void Postorder(TREE*Root);
int BinarySearch(int target);
int Min(TREE*Root);
int Max(TREE*Root);
int  IsLeaf(int leaf);
void LeafNode(TREE*Root);


int main()
{
    int num,N,ch,target,min,max,leaf,result,bin;
    printf("Program to implement Tree Data Structure and use different traversal methods\n");
    while(ch)
    {
     switch(ch){
        case 1:
        printf("Enter number of Nodes\n");
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            printf("\nEnter Number: ");
            scanf("%d",&num);
            InsertTreeNode(num);
        }
        fnMenu(&ch);
        break;
        case 2:
          Preorder(Root);
          fnMenu(&ch);
          break;
          case 3:
          Inorder(Root);
          fnMenu(&ch);
          break;
          case 4:
          Postorder(Root);
          fnMenu(&ch);
          break;
          case 5:
          printf("\nEnter Target: ");
          scanf("%d",&target);
          bin=BinarySearch(target);
          if(bin==1){
            printf("\nElement %d is found",target);
          }else{
            printf("\nElement %d not found",target);
          }
          fnMenu(&ch);
          break;
          case 6:
          min=Min(Root);
          printf("\nMinimum Number of Tree is %d",min);
          fnMenu(&ch);
          break;
          case 7:
          max=Max(Root);
          printf("\nMaximum Number of Tree is %d",max);
          fnMenu(&ch);
          break;
          case 8:
          printf("\nEnter a num to check if it is a leaf node");
          scanf("%d",&leaf);
          result=IsLeaf(leaf);
          if(result){
            printf("\nTrue");
          }else{
            printf("\nFalse");
          }
          fnMenu(&ch);
          break;
          case 9:
           LeafNode(Root);
           fnMenu(&ch);
           break;
          case 10:
          printf("Exiting...");
          exit(1);
          break;
          default:
          printf("\nEnter a valid choice");
          fnMenu(&ch);
          break;
     }
    }
    

}

void fnMenu(int*ch)
{
  printf("\n\t\t\tTREE DATA STRUCTURE\n");
  printf("1.Insert Tree Node\n");
  printf("2.Preorder Traversal\n");
  printf("3.Inorder Traversal\n");
  printf("4.Postorder Traversal\n");
  printf("5.Binary Search\n");
  printf("6.Minimum Number\n");
  printf("7.Maximum Number\n");
  printf("8.Check Leaf Node\n");
  printf("9.Print Leaf Node\n");
  printf("10.EXIT\n");
  printf("Enter choice:");
  scanf("%d",ch);
}

void InsertTreeNode(int num)
{
    TREE*prev,*curr,*Node;
    Node=(TREE*)malloc(sizeof(TREE));
    Node->data=num;
    Node->Left=NULL;
    Node->Right=NULL;

    if(Root==NULL){
        Root=Node;
        return;
    }
    curr=Root;
    while(curr){
        if(num<curr->data){
            prev=curr;
            curr=curr->Left;
        }else{
            prev=curr;
            curr=curr->Right;
        }
    }

    if(num<prev->data){
        prev->Left=Node;
    }else{
        prev->Right=Node;
    }
}

void Inorder(TREE*Root)
{
    if(Root){
        Inorder(Root->Left);
        printf("%d\t",Root->data);
        Inorder(Root->Right);
    }
}

void Preorder (TREE*Root)
{
    if(Root){
        printf("%d\t",Root->data);
        Preorder(Root->Left);
        Preorder(Root->Right);
    }
}

void Postorder(TREE*Root)
{
    if(Root){
        Postorder(Root->Left);
        Postorder(Root->Right);
        printf("%d\t",Root->data);
    }
}

int BinarySearch(int target)
{
    TREE*curr=Root;
    int found=0;
    while(curr){
        if(target==curr->data){
            found=1;
            return found;
        }else{
            if(target<curr->data){
                curr=curr->Left;
            }else{
                curr=curr->Right;
            }
        }
    }
}

void LeafNode(TREE*Root)
{
    if(Root){
        if(Root->Left==NULL && Root->Right==NULL){
            printf("%d\t",Root->data);
        }
        LeafNode(Root->Left);
        LeafNode(Root->Right);
    }
}

int IsLeaf(int leaf)
{
    TREE*prev,*curr;
    curr=Root;
    while(curr){
        if(leaf==curr->data){
            if(curr->Left==NULL &&curr->Right==NULL){
                return 1;
            }else{
                return 0;
            }
        }else if(leaf<curr->data){
            curr=curr->Left;
        }else{
            curr=curr->Right;
        }
    }
}

int Max(TREE*Root)
{
    TREE*curr;
    curr=Root;
    while(curr->Right){
        curr=curr->Right;
    }
    return curr->data;
}

int Min(TREE*Root)
{
    TREE*curr;
    curr=Root;
    while(curr->Left){
        curr=curr->Left;
    }
    return curr->data;
}
