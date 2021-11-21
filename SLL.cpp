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
    cout<<"\n";
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
int main()
{
///Singly Linear Linked List

    PNODE first = NULL;
    int ret =0;
  
    InsertLast(&first,10);
    InsertLast(&first,20);
    InsertLast(&first,30);
    InsertLast(&first,40);
    InsertLast(&first,50);
    Display(first);
    DeleteFirst(&first);

    Display(first);
    DeleteLast(&first);
    Display(first);
    ret =Count(first);
    cout<<"Number of elements are "<<ret;




}