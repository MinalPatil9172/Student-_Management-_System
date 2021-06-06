
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct Student
{
     int Roll_No;
     char Name[50];
     int Marks;
     int Age;
     struct Student *Next;
 }STUDENT,*PSTUDENT,**PPSTUDENT;//

void InsertFirst(PPSTUDENT Head,int roll_no,int iMarks_no,int iAge,char* name)
{   

      int i=0;
      PSTUDENT newn=NULL;
      newn=(PSTUDENT)malloc(sizeof(STUDENT));
      newn->Roll_No=roll_no;
      strcpy(newn->Name,name);
      newn->Marks=iMarks_no;
      newn->Age=iAge;
      newn->Next=NULL;

  
    if(*Head==NULL)
    {
        newn->Next=NULL;
        *Head=newn;
    }
    else
    {
        newn->Next=*Head;
        *Head=newn;
    
        
    }  
     

}
void InsertLast(PPSTUDENT Head,int roll_no,int iMarks_no,int iAge)
{
     int i=0;
    PSTUDENT newn=NULL;
    PSTUDENT Temp=*Head;
    newn=(PSTUDENT)malloc(sizeof(STUDENT));
    newn->Roll_No=roll_no;
    newn->Next=NULL;
    newn->Marks=iMarks_no;
    newn->Age=iAge;
  //  strcpy(newn->Name,str);
    if(*Head==NULL)
    {
        newn->Next=NULL;
        *Head=newn;
    }
    else
    { 
        while(Temp->Next!=NULL)
        {
            Temp=Temp->Next;
        }
        Temp->Next=newn;
    
    }  

}

void InsertAtPos(PPSTUDENT Head,int roll_no,int iMarks_no,int iAge,int ipos)
{

    int i=0,itemp=0;
    PSTUDENT newn=NULL;
    PSTUDENT Temp=*Head;
    newn=(PSTUDENT)malloc(sizeof(STUDENT));
    newn->Roll_No=roll_no;
    newn->Next=NULL;
    newn->Marks=iMarks_no;
    newn->Age=iAge; 
  //  itemp=(Count(*Head));
     PSTUDENT temp=*Head;
   printf("%d",itemp);
    if(*Head==NULL)
    {
        return;
       //InsertFirst(Head,roll_no,iMarks_no,iAge);
    } 
    else
   { 
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->Next;
        }
          newn->Next=temp->Next;
          temp->Next=newn;
        
   }    
       

}
void Display(PSTUDENT Head)
{   int i=0;
         printf("\t\tRoll No\t\tName\t\tMarks\t\tAge\n\n");
     printf("\n");
    while(Head!=NULL)
    {
        
      
       printf("\t\t%d",Head->Roll_No);
       printf("\t\t%s",Head->Name);
       printf("\t\t%d",Head->Marks);
       printf("\t\t%d\n",Head->Age);      

         Head=Head->Next;
    }
}
int  Count(PSTUDENT Head)
{
    
    int count=0;
    while(Head!=NULL)
    {
       count++;
       Head=Head->Next;

    }
     return count;

}
void DeleteAtPosition(PPSTUDENT Head,int pos)
{
       int i=0;
       PSTUDENT temp=NULL;
       temp=*Head;
       for(i=1;i<=pos-1;i++)
       {
           temp=temp->Next;
       }
       PSTUDENT target=temp->Next;
        temp->Next=target->Next;
        free(target);
}

void EditAge(PPSTUDENT Head,int roll_NO,int iAge)
{
    PSTUDENT Temp=*Head;
      int i=0;
      
          while((Temp->Roll_No)!=roll_NO)  
          {
             Temp=Temp->Next;

          }   
             Temp->Age=iAge;
}
void DispStuInfo(PSTUDENT Head,int Roll_No)
{
      while((Head->Roll_No)!=Roll_No)
      {
           Head=Head->Next;
      }
       printf("\t\tRoll No\t\tName\t\tMarks\t\tAge\n\n");
       printf("\t\t%d",Head->Roll_No);
       printf("\t\t%s",Head->Name);
       printf("\t\t%d",Head->Marks);
       printf("\t\t%d\n",Head->Age);
}

void EditMarks(PPSTUDENT Head,int roll_NO,int iMarks)
{
    PSTUDENT Temp=*Head;
      int i=0;

          while((Temp->Roll_No)!=roll_NO)  
          {
             Temp=Temp->Next;

          }   
             Temp->Marks=iMarks;

}
int main()
{
    int RollNo,iChoice=1,iMarks,iAge,insert_at_pos,iret=0,delete_at_pos;
    int Marks;
    char  Name[50];

    printf("\n============================== Student Management System =================================\n\n");
 
    PSTUDENT First=NULL;
   

    while(iChoice!=0)
    {
        printf("******************************************************************************************\n");
        printf("\t\t\t\tStudent Information:\n");
        printf("\t\t\t\t1: Add Student:\n");
        printf("\t\t\t\t2: Show All Students:\n");
        printf("\t\t\t\t3: Count Students\n");
        printf("\t\t\t\t4: Add at last Student information:\n");
        printf("\t\t\t\t5: Insert at position information of student:\n");
        printf("\t\t\t\t6: Delete at position\n");
        printf("\t\t\t\t7: Edit Age\n");
        printf("\t\t\t\t8: DisplyStuInfo\n");
        printf("\t\t\t\t9: Edit Marks of student\n");
        printf("\t\t\t\t10: Logout\n");
     

        printf("\n******************************************************************************************\n");
        
        printf("\nEnter your option:\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
        
             printf("Enter Roll No of student\n");
             scanf("%d",&RollNo);
             printf("Enter Name:\n"); 
             scanf(" %s",Name);
             printf("Enter Age of student\n");
             scanf("%d",&iAge);
             printf("Enter Marks of student\n");
             scanf("%d",&iMarks);
             
              printf("\n");
             InsertFirst(&First,RollNo,iMarks,iAge,Name);
             break;
          
          
            case 2:
             Display(First);
            break;

            case 3:
            iret=Count(First);
            printf("Total number of Students are:%d\n",iret);
            break;

            case 4:
            printf("Enter Roll No of student\n");
            scanf("%d",&RollNo);
            printf("Enter Age of student\n");
            scanf("%d",&iAge);
            printf("Enter Marks of student\n");
            scanf("%d",&iMarks);
            InsertLast(&First,RollNo,iMarks,iAge);
             break;

             case 5:
             printf("Enter position at which enter:");
             scanf("%d",&insert_at_pos);
             printf("Enter Roll No of student:\n");
             scanf("%d",&RollNo);
             printf("Enter Age of student\n");
             scanf("%d",&iAge);
             printf("Enter Marks of student\n");
             scanf("%d",&iMarks);
             InsertAtPos(&First,RollNo,iMarks,iAge,insert_at_pos);
             break;

             case 6:
             printf("Enter position at which enter:");
             scanf("%d",&delete_at_pos);
             DeleteAtPosition(&First,delete_at_pos);
             break;


             case 7:
             printf("Enter Roll No\n");
             scanf("%d",&RollNo);
             printf("Enter age you want to insert\n");
             scanf("%d",&iAge);
             EditAge(&First,RollNo,iAge);
             
             break;


             case 8:
              printf("Enter Roll No\n");
             scanf("%d",&RollNo);
             DispStuInfo(First,RollNo);
             break;

             case 9:
             printf("Enter Roll No\n");
             scanf("%d",&RollNo);
             printf("Enter Marks you want to insert\n");
             scanf("%d",&Marks);
             EditMarks(&First,RollNo,Marks);
             break;

             
             case 0:
             printf("Thank You!\n");
             break;


              default:
              printf("Enter valid case\n");
              break;
             

        }

    }

    return 0;
}
