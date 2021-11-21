#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE ,* PNODE ,**PPNODE;

void DeleteFirst(PPNODE Head )
{
    if(*Head == NULL)
    {
        return;
    }
    PNODE temp = *Head;

    *Head = (*Head)->next;
    delete temp;


}
void DeleteLast(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    PNODE temp = *Head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next =NULL;

}


void InsertFirst(PPNODE Head , int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;

    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
};



void InsertLast(PPNODE Head , int no)
{
    PNODE newn = new NODE;
    newn ->data = no;
    newn->next=NULL;

    if(*Head  == NULL)
    {
        delete newn;
        InsertFirst(Head ,  no);
    }
    else
    {
        PNODE temp = *Head;
        while(temp->next != NULL)
        {
            temp =(temp)->next;
        }
        temp->next = newn;
    }


}

void Display(PNODE Head)
{
    while(Head!= NULL)
    {
        cout<<"|"<< Head->data<<"|->";
        Head = Head->next;
    }
    cout<<"NULL\n";
}
int Count(PNODE Head)
{
    int count = 0;
     while(Head!= NULL)
    {
        count++;
        Head = Head->next;
    }
    return count;
    
}


void DeleteAtPos(PPNODE Head , int pos)
{

   if((pos<1)|| (pos>Count(*Head)+1))
    {
        cout<<"Please Enter correct position\n";
        return;
    }
    if(*Head == NULL)
    {
        DeleteFirst(Head);
    }
    else if (pos == Count(*Head)+1)
    {
        DeleteLast(Head);
    }
    else
    {
     
        PNODE temp = *Head;
       
        for(int i = 1 ; i<pos-1;i++)
        {
           temp = temp->next;
        }
        PNODE tobedeleted =temp->next;
        temp->next = temp->next->next;
        delete tobedeleted;

         
    }

}
void InsertAtPos(PPNODE Head , int no ,int pos)
{
    if((pos<1)|| (pos>Count(*Head)+1))
    {
        cout<<"Please Enter correct position\n";
        return;
    }
    if(*Head == NULL)
    {
        InsertFirst(Head,no);
    }
    else if (pos == Count(*Head)+1)
    {
        InsertLast(Head,no);
    }
    else
    {
        PNODE newn = new NODE;
        PNODE temp = *Head;
        newn->next =NULL;
        newn ->data = no;

        for(int i = 1 ; i<pos-1;i++)
        {
           temp = temp->next;
        }
         newn->next = temp->next;
            temp->next = newn;
    }
}
int main()
{
///Singly Linear Linked List

    PNODE first = NULL;
    int ret =0;
    int choice =1;
    int no= 0;
    int pos = 0;
    bool flag= true;
  
    while(flag)
    {
        cout<<"Enter choice\n";
       cout<<"Enter 1 for Insert At First position\n";
       cout<<"Enter 2 for Insert At Last position\n";
       cout<<"Enter 3 for Insert at desired position\n";
       cout<<"Enter 4 fot Delete at first position\n";
       cout<<"Enter 5 for Delete at last position\n";
       cout<<"Enter 6 for Delete at desired position\n";
       cout<<"Enter  7 to Display\n";
        cout<<"Enter choice\n";
        cin>>choice;
       switch (choice)
       {
       case 1:
            cout<<"Enter number\n";
            cin>>no;
           InsertFirst(&first , no);
           break;
       case 2:
            cout<<"Enter number\n";
            cin>>no;
           InsertLast(&first , no);
           break;
       case 3:
            cout<<"Enter number\n";
            cin>>no;
            cout<<"Enter Position\n";
            cin>>pos;
            InsertAtPos(&first , no,pos);
           break;
       case 4:
           DeleteFirst(&first);
           break;
       case 5:
           DeleteLast(&first);
           break;
       case 6:
            cout<<"Enter Position\n";
            cin>>pos;
           DeleteAtPos(&first,pos);
           break;
        case 7:
            Display(first);
           
           break;
       case 0:
            flag =false;
           break;
       
       default:
            cout<<"Please Enter correct option\n";
           break;
       }
    }
    //ret =Count(first);
    //cout<<"Number of elements are "<<ret;




}