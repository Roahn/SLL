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
    cout<<"\n";
}
int main()
{
///Singly Linear Linked List

    PNODE first = NULL;
  
    InsertLast(&first,10);
    InsertLast(&first,20);
    InsertLast(&first,30);
    InsertLast(&first,40);
    InsertLast(&first,50);
    Display(first);
    DeleteFirst(&first);

    Display(first);





}