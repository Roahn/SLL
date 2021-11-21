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

}
void InsertAtPos(PPNODE Head , int no ,int pos)
{
    if((pos<1)|| (pos>Count(*Head)+1))
    {
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

        for(int i = 1 ; i<pos;i++)
        {
            newn->next = temp->next;
            temp->next = newn;
        }
    }
}
int main()
{
///Singly Linear Linked List

    PNODE first = NULL;
    int ret =0;
  
    Display(first);
    InsertFirst(&first,10);
    InsertFirst(&first,10);
    InsertFirst(&first,10);
    InsertFirst(&first,10);
    InsertFirst(&first,10);
    
    Display(first);
    InsertAtPos(&first,20,2);
    InsertAtPos(&first,30,2);
    InsertAtPos(&first,50,2);
    InsertAtPos(&first,40,2);
    InsertAtPos(&first,560,2);
    InsertAtPos(&first,820,2);

    
    Display(first);
    ret =Count(first);
    cout<<"Number of elements are "<<ret;




}