#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct FlightType{
    char Fname[10];
    char Airline[20];
    char destination[20];
    char Status[20];
    char arrivaltime[10];
    char GateNo[10];
}FLIGHT;
typedef struct QType{
    FLIGHT F;
    struct QType*next;
}QNODE;

QNODE*Front,*Rear;

void InitQueue();                    //Function Prototype
void Enqueue(FLIGHT F);              
void Display(FLIGHT F);
FLIGHT Dequeue(FLIGHT F);
void fnbuffer(int*ch);
void fnstatus(int*status);
void fngate(int*gate);

int main()
{
    int ch, status, gate;
    InitQueue();
    FLIGHT F;
    FLIGHT f1={"UA123", "United Arab", "New York (JFK)", "On Time", "10:30 AM", "Gate A1"};
    FLIGHT f2={"DL456", "Delta", "London (LHR)", "Delayed", "11:00 AM", "Gate B2"};
    FLIGHT f3={"AA789", "American", "Los Angeles (LAX)", "Boarding", "12:15 PM", "Gate C3"};

    Enqueue(f1);
    Enqueue(f2);
    Enqueue(f3);
    fnbuffer(&ch);
    while(ch){
        switch(ch){
            case 1:
             printf("\nEnter Flight Details");
             printf("\nEnter Flight Name: ");
             scanf("%s",F.Fname);
             printf("\nEnter AirLine Name: ");
             getchar();
             fgets(F.Airline,sizeof(F.Airline),stdin);
             F.Airline[strcspn(F.Airline,"\n")]=0;
          
             printf("\nEnter Flight Destination: ");
             fgets(F.destination,sizeof(F.destination),stdin);
              F.destination[strcspn(F.destination,"\n")]=0;
        
             fnstatus(&status);
             switch(status){
                case 1:
                 strcpy(F.Status,"On Time");
                break;
                case 2:
                 strcpy(F.Status,"Delayed");
                 break;
                 case 3:
                 strcpy(F.Status,"Boarding");
                 default:
                 printf("\nInvalid status choice");
                 fnstatus(&status);
                 break;

             }

             printf("\nEnter Flight Arrival Time : ");
             getchar();
             fgets(F.arrivaltime,sizeof(F.arrivaltime),stdin);
              F.arrivaltime[strcspn(F.arrivaltime,"\n")]=0;
          
             fngate(&gate);
             switch(gate){
                case 1:
                strcpy(F.GateNo,"Gate D4");
                break;
                case 2:
                strcpy(F.GateNo,"Gate E5");
                break;
                case 3:
                strcpy(F.GateNo,"Gate F6");
                break;
                case 4:
                strcpy(F.GateNo,"Gate G7");
                break;
                case 5:
                strcpy(F.GateNo,"Gate H8");
                break;
                case 6:
                strcpy(F.GateNo,"Gate I9");
                break;
                case 7:
                strcpy(F.GateNo,"Gate J10");
                break;
                default:
                printf("\nEnter a valid Gate Number");
                fngate(&gate);
                break;
             }
              Enqueue(F);
             fnbuffer(&ch);
            break;
            case 2:
             printf("Next flight departing:\n");
             FLIGHT nextflight=Dequeue(F);
             Display(F);
             fnbuffer(&ch);
             break;
             case 3:
               Display(F);
               fnbuffer(&ch);
               break;
               case 4:
                 printf("Exiting...");
                 exit(1);
                 break;
                 default:
                 printf("Enter a valid choice");
                 fnbuffer(&ch);
                 break;
        }
    }
  

    return 0;
}
void InitQueue()    //Function Definition
{
    Front=NULL;
    Rear=NULL;
    return;
}
void Enqueue(FLIGHT F)
{
    QNODE*flight;
    flight=(QNODE*)malloc(sizeof(QNODE));
    flight->F=F;
    flight->next=NULL;

  if(Front==NULL){
    Front=flight;
    Rear=flight;
    return;
  }
  Rear->next=flight;
  Rear=flight;
  return;
} 

void Display(FLIGHT F)
{
    QNODE*curr=Front;
    if(Front==NULL){
        printf("No flights available.\n");
        return;
    }
    printf("\n\t\t\tFlight Information\n");
   while(curr){
    printf("%s|%s|%s|%s|%s|%s|\n",curr->F.Fname,curr->F.Airline,curr->F.destination,curr->F.Status,curr->F.arrivaltime,curr->F.GateNo);
   curr=curr->next;
   }

}

FLIGHT Dequeue(FLIGHT F)
{
    FLIGHT empty={"","","","","",""};
   if(Front==NULL){
    printf("Queue is Empty.No flights to dequeue.\n");
    return empty;
   }
   QNODE*temp=Front;
   FLIGHT depart=Front->F;
   Front=Front->next;
   free(temp);

  return depart;
}
void fnbuffer(int*ch)
{
    printf("\n\t\t\tENQUEUE && DEQUQEUE BUFFER FOR FLIGHTS");
    printf("\n1.FLIGHT INCOMING");
    printf("\n2.FLIGHT DEPARTURE");
    printf("\n3.DISPLAY");
    printf("\n4.EXIT");
    printf("\nEnter choice ");
    scanf("%d",ch);
}
void fnstatus(int*status)
{
 printf("\nWhat's the status of Flight");
 printf("\n1.On Time");
 printf("\n2.Delayed");
 printf("\n3.Boarding");
 printf("\nChoose from the options ");
 scanf("%d",status);

}
void fngate(int*gate)
{
 printf("\nWhich Gate Number is the Flight arriving at?");
 printf("\n1.D4");
 printf("\n2.E5");
 printf("\n3.F6");
 printf("\n4.G7");
 printf("\n5.H8");
 printf("\n6.I9");
 printf("\n7.J10");
 printf("\nChoose from the options ");
 scanf("%d",gate);

}