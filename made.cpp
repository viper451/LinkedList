#include<stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;
struct ll_node
    {
        int data;
         ll_node *next;
    };
int traverse( ll_node *list,int count1);
ll_node *insert( ll_node *list, int value)
{
     ll_node *help_ptr = list;
     ll_node *pNew =new ll_node();
    pNew->data = value;
    pNew->next = NULL;
    if (list == NULL || list->data > value)
    {
        pNew->next = list;
        list = pNew;
        return list;
    }
    while(help_ptr->next != NULL && help_ptr->next->data < value)
        help_ptr = help_ptr->next;
    pNew->next = help_ptr->next;
    help_ptr->next = pNew;
    return list;

}
void display( ll_node *list)
{
     ll_node *help_ptr = list;
    if(list==NULL)
    {
        printf("List is empty");
    }
    while (help_ptr!= NULL)
    {
        printf("%d   ", help_ptr->data);
        help_ptr = help_ptr->next;
    }
    printf("\n");
}
ll_node *delete1( ll_node *list, int target)
{
     ll_node *help_ptr, *node2delete;
    help_ptr = list;
    if(list==NULL)
    {
        printf("The list is empty");
         return list;
    }
    if (help_ptr != NULL)
    {
        if (help_ptr->data == target)//If there is one node in the list
        {
            list = help_ptr->next;
            free(help_ptr);
            return list;
        }
        while (help_ptr->next != NULL)//If there are more then one node int the list
        {
            if (help_ptr->next->data == target)//We need not go to the delete node we just want the previous node  of delete one
            {
                node2delete = help_ptr->next;
                help_ptr->next = help_ptr->next->next;
                free(node2delete);
                return list;
            }
            help_ptr = help_ptr->next;
        }
        printf("Number not found");
    }
    return list;
}
int count( ll_node *list)
{
    int count=0;
     ll_node *help_ptr = list;
    if(list==NULL)
    {
        count=0;
    }
    while (help_ptr!= NULL)
    {
        count++;
        help_ptr = help_ptr->next;
    }
       return count;
}
ll_node *reverse( ll_node *list)
{
     ll_node* help_ptr;
    ll_node* follow;
     ll_node* ahead;
    help_ptr=list;
    follow=ahead=NULL;
    while (help_ptr!= NULL)
    {
        ahead=help_ptr->next;//TO SAVE THE NEXT NODE NCOZ WE GONNA LOSE THE NEXT NODE LINK IN NEXT 2 STEP
        help_ptr->next=follow;
        follow=help_ptr;
        help_ptr=ahead;
    }
    list=follow;
    while(list!=NULL)
    {
        printf("%d ",list->data);
        list=list->next;
    }
    return list;
}

ll_node *insertchoice(ll_node *list,int number,int position)
{
       ll_node *help_ptr = list;
       ll_node *temp1 =new ll_node();
       temp1->data=number;
       temp1->next=NULL;
       if(position==1)
       {
          temp1->next=list;
          list=temp1;
          return list;
       }
       else{
          ll_node *temp2 =new ll_node();
          for(int i=0;i<position-2;i++)
          {
              help_ptr=help_ptr->next;
          }
          temp2=help_ptr->next;
          temp1->next=temp2;
          help_ptr->next=temp1;
          return list;
       }
}
int middle(ll_node *list)
{
    int count1=count(list);
    count1=count1/2;
    int value=traverse(list,count1);//TO CALL THE TRAVERSE FUNCTION WE NEED TO DECLARE THE FUNCRION GLOBALLY TO ACCES IT// 
    return value;
}
int traverse( ll_node *list,int count1)
{
    ll_node *help_ptr = list;
    if(list==NULL)
    {
        printf("List is empty");
    }
   for(int i=0;i<count1;i++)
   {
       help_ptr=help_ptr->next;
   }
   return help_ptr->data;

}
ll_node *deletechoice(ll_node *list,int position)
{
    ll_node *temp1 = list;
  if(position==1)
  {
      list=list->next;
      free(temp1);
      return list;
  }
  else{
      ll_node *temp2=new ll_node();
      for(int i=0;i<position-2;i++) //this will point to (n-1)th node
      {
          temp1=temp1->next;
      }
      temp2=temp1->next;
      temp1->next=temp2->next;
      free(temp2);
      return list;
  }
}

void lastfirst(ll_node *list)
{
     ll_node *help_ptr = list;
     ll_node *help = list;
    ll_node *first=help_ptr;
    ll_node *last=NULL;
    while(help_ptr->next->next!=NULL)
    {
        help_ptr=help_ptr->next;
    }


    help_ptr=last->next;
    last->next=NULL;
    help_ptr->next=first;
   
    
    cout<<first->data<<endl;
    cout<<last->data<<endl;
}
int main()
{
    int choice, number,position;
     ll_node *myList = NULL;

    do{
    printf("\nMenu:");
    printf("\nPress 1 to insert a node ");
    printf("\nPress 2 to delete a node");
    printf("\nPress 3 to view the linked list");
    printf("\nPress 4 to check the number of nodes");
    printf("\nPress 5 to reverse the list");
    printf("\nPress 6 to exit");
    printf("\nPress 7 to insert element at your position");
    printf("\nPress 8 to delete element at your position");
    printf("\nPress 9 to get middle element in linked list");
    printf("\nPress 10 to put last element to first");
    printf("\nEnter your number: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:{
            number=0;
                printf("Enter data for next node:  ");
                scanf("%d", &number);
                if (number !=-1)
                   myList = insert(myList, number);
            break;
    }
    case 2:
    {
            number=0;
                printf("Enter number that you wish to delete:  ");
                scanf("%d", &number);
                myList = delete1(myList, number);
            break;
    }
    case 3:{
        display(myList);
        break;}
    case 4:{
     int val=count(myList);
     cout<<val<<endl;
        break;}
    case 5:{
        myList=reverse(myList);
        
        break;}
    case 6:{
        printf("Exit");
        break;}
    case 7:{
          number=0;
          position=0;
                printf("Enter data for next node:  ");
                scanf("%d", &number);
                printf("Enter position for next node:  ");
                scanf("%d", &position);
                if (number !=-1)
                   myList = insertchoice(myList, number,position);
            break;}
    case 8:{
        position=0;
        printf("ENTER POSITION WHERE U WANT TO DELETE THE NODE");
        scanf("%d", &position);
        myList = deletechoice(myList,position);
        break;}
    case 9:
    {
       int num=middle(myList);
       cout<<num<<endl;
    break;
    }
    case 10:
    {
        lastfirst(myList);
        printf("HII");
        while(myList!=NULL)
        {
           printf("%d ",myList->data);
           myList=myList->next;
           printf("HII");
        }
        break;
    }
    default:{
        printf("Please enter valid number");
        break;
    }
    }
    }while(choice!=6);
}