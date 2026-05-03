#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next_ptr;
}Node;
Node *head=NULL;

void printlist(){
        Node *temp = head;
        while(temp!=NULL){
            printf(" %d -> ", temp->data);
            temp=temp->next_ptr;
        }
        printf("NULL \n");
}


//Insert At Beginning
void insertatbeginning(int data)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next_ptr=head;
    head=new_node;
}

//Insert At END
void insertatend(int data)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next_ptr=NULL;

    //Case 1 -> List is empty
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    //Case 2 -> List is ot empty
    Node *last;
    last=head;
    while(last->next_ptr!=NULL)
    {
        last=last->next_ptr;
    }
    last->next_ptr=new_node;

}

//Insert After Value
void insertaftervalue(int target,int val)
{
    //Case1 ->List is empty
    //Case2 ->List is not empty
         
        //subcase1 -> Value doesnot exist
        //subcase2 -> Value exist
    
    //Case1
    if(head==NULL)
    {
        printf("List is empty\n");
    }

    //Case2
    Node *last=head;
    while(last!=NULL && last->data!=target)
    {
        last=last->next_ptr;
    }
    if(last==NULL) //No Target data found at the end
    {
        printf("Target does not exist.\n");
        return;
    }
    else
    {
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data=val;
        newnode->next_ptr=last->next_ptr;
        last->next_ptr=newnode;
    }
}

//Delete At begin
void deletebegin()
{
    //Case1 -> List is empty
    if(head==NULL)
    {
        printf("List is already empty\n");
        return;
    }
    //Case2 -> List is not empty
    else
    {
        Node *temp=head;
        head=temp->next_ptr;
        free(temp);
    }

}

//Delete At End
void deleteend()
{
    //Case1 ->List is empty
    if(head==NULL)
    {
        printf("List is already empty\n");
        return;
    }
    //Case2 ->List is not empty
    else
    {
        //Subcase1 -> List have only one element
        if(head->next_ptr==NULL)
        {
            Node *temp=head;
            head=temp->next_ptr;
            free(temp);
            return;
        }
        //Subcase2 -> list have more than one one element
        else
        {
            Node *last=head;
            Node *prev=last;
            last=last->next_ptr;
            while(last->next_ptr!=NULL)
            {
                prev=last;
                last=last->next_ptr;
            }
            prev->next_ptr=NULL;
            free(last);
        }

    }

}

//Delete value
void deletevalue(int val)
{
    //Case 1 ->list is empty
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    //Case 2 ->List has one element
    if(head->next_ptr==NULL)
    {
        Node *temp=head;
        if(temp->data==val)
        {
            head=temp->next_ptr;
            free(temp);
        }
        return;
    }

    //Case 3 ->List is full
    else
    {
        //subcase 1 -> val==head
        if(head->data==val)
        {
            Node *temp=head;
            head=temp->next_ptr;
            free(temp);
        }
        //subcase 2 -> val==last
        //subcase 3 -> anywhere else
        else
        {
            Node *last = head;
            Node *prev = last;
            last = last->next_ptr;

            while(last != NULL && last->data != val)
            {
                prev = last;
                last = last->next_ptr;
            }

            if(last == NULL)
            {
                printf("Data does not exist!!!!");
                return;
            }

            prev->next_ptr = last->next_ptr;
            free(last);
        }

    }
        

}

int main()
{
    printlist();
    insertatbeginning(4);
    printlist();
    insertatbeginning(8);
    printlist();
    insertatend(5);
    printlist();
    insertaftervalue(8,12);
    printlist();
    insertaftervalue(23,5);
    printlist();
    deletebegin();
    printlist();
    deletebegin();
    printlist();
    deleteend();
    printlist();
    deleteend();
    printlist();
    insertatbeginning(45);
    printlist();
    insertatbeginning(13);
    printlist();
    deletevalue(45);
    printlist();
    deletevalue(33);
    printlist();
    deletevalue(10000);
    printlist();
    
}




