#include <iostream>

using namespace std;


struct Node
{
    int sap;
    int rollno;
    struct Node *next;
};

struct Node *head =NULL;


void insert_new_node_beg()
{
    struct Node *new_node = new struct Node();

    cout<<"Enter the student's SAP ID(last 5 digits) :"<<endl;
    int x;
    cin>>x;
    cout<<"\n\n"<<endl;
    new_node->sap=x;

    cout<<"Enter student's roll number(last 3 digits) :"<<endl;
    cin>>x;
    cout<<"\n\n"<<endl;
    new_node->rollno=x;

    new_node->next =NULL;

    new_node->next=head;
    head=new_node;

}



void insert_new_node_end()
{
    struct Node *new_node = new struct Node();

    cout<<"Enter the student's SAP ID(last 5 digits) :"<<endl;
    int x;
    cin>>x;
    cout<<"\n\n"<<endl;
    new_node->sap=x;

    cout<<"Enter student's roll number(last 3 digits) :"<<endl;
    cin>>x;
    cout<<"\n\n"<<endl;
    new_node->rollno=x;

    new_node->next =NULL;

    struct Node *temp;
    temp=head;

    while(temp->next != NULL)
    {
        temp= temp->next;
    }

    temp->next =new_node;

}



void display()
{
    struct Node *temp;
    temp=head;

    cout<<"The SAP ID's are :"<<endl;
    while(temp != NULL)
    {
        cout<<temp->sap<<"\t";
        temp=temp->next;
    }
    cout<<endl;

    temp=head;
    cout<<"The Roll number's are :"<<endl;
    while(temp != NULL)
    {
        cout<<temp->rollno<<"\t";
        temp=temp->next;
    }

    cout<<endl;

}




int noOfNodes()
{
    struct Node *temp;
    temp=head;
    int n=0;
    while(temp != NULL)
    {
        temp=temp->next;
        n=n+1;
    }
    return n;
}





void delete_beg()
{
    struct Node *temp;
    temp=head;
    head =head->next;
    free(temp);
}


void delete_end()
{
    struct Node *temp;
    temp=head;

    while(temp->next->next != NULL)
    {
        temp= temp->next;
    }

    struct Node *todel;
    todel= temp->next;
    temp->next = NULL;
    free(todel);
}


void delete_pos()
{
    cout<<"Enter the position of the node to be deleted\n\n"<<endl;
    int n;
    cin>>n;
    cout<<endl;
    int x=noOfNodes();
    if(n>x-1  || n<2)
    {
        cout<<"invalid option selected"<<endl;
    }
    else
    {
        struct Node *temp ;
        temp =head;
        int a=0;
        while(a <= n)
        {
            temp =temp ->next;
        }
        struct Node *todel;
        todel = temp->next;
        temp->next = temp ->next->next;
        free(todel);
    }

}



int noOfNodes()
{
    struct Node *temp;
    temp=head;
    int n=0;
    while(temp != NULL)
    {
        temp=temp->next;
        n=n+1;
    }
    return n;
}




void sort_list()
{
    struct Node *i;
    struct Node *j;

    for(i=head ; i->next != NULL ; i=i->next)
    {
        for(j=i->next ; j->next != NULL ; j=j->next)
        {
            if(i->rollno > j->rollno)
            {
                struct Node *temp;
                temp = i;
                i = j;
                j = temp;
            }
        }
    }
}



`



void display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}





void working_insert()
{
    do
    {
        cout<<"Give a numeric input according to the following scheme"<<endl;
        cout<<"1  : to insert a new Student detail at the beginning of the list"<<endl;
        cout<<"2  : to insert a new Student detail at the end of the list"<<endl;
        cout<<"3  : to display the Student details"<<endl;
        cout<<"4  : to exit"<<endl;


        int input=0;
        cin>>input;
        cout<<"\n\n"<<endl;


        while(input<1 || input>4)
        {
            cout<<"Kindly input a valid choice :"<<endl;
            cin>>input;
        }

        switch(input)
        {
            case 1: insert_new_node_beg();
            break;

            case 2: insert_new_node_end();
            break;

            case 3: display();
            break;

            case 4: cout<<"exiting"<<endl;
            return;
        }

    }while(1);


}



void working_delete()
{
    do
    {
        cout<<"Give a numeric input according to the following scheme"<<endl;
        cout<<"1  : to delete a Student detail at the beginning of the list"<<endl;
        cout<<"2  : to delete a Student detail at the end of the list"<<endl;
        cout<<"3  : to delete a Student detail at the given location of the list"<<endl;
        cout<<"4  : to display the Student details"<<endl;
        cout<<"5  : to exit"<<endl;


        int input=0;
        cin>>input;
        cout<<"\n\n"<<endl;


        while(input<1 || input>5)
        {
            cout<<"Kindly input a valid choice :"<<endl;
            cin>>input;
        }

        switch(input)
        {
            case 1: delete_beg();
            break;

            case 2: delete_end();
            break;

            case 3:delete_pos();
            break;

            case 4: display();
            break;

            case 5: cout<<"exiting"<<endl;
            return;
        }

    }while(1);


}

void working_extra()
{
    do
    {
        cout<<"Give a numeric input according to the following scheme"<<endl;
        cout<<"1  : to sort the given list"<<endl;
        cout<<"2  : to find the number of nodes list"<<endl;
        cout<<"3  : to display the Student details"<<endl;
        cout<<"4  : to exit"<<endl;


        int input=0;
        cin>>input;
        cout<<"\n\n"<<endl;


        while(input<1 || input>4)
        {
            cout<<"Kindly input a valid choice :"<<endl;
            cin>>input;
        }

        switch(input)
        {
            case 1: sort_list();
            break;

            case 2: noOfNodes();
            break;

            case 3: display();
            break;

            case 4: cout<<"exiting"<<endl;
            return;
        }

    }while(1);
}







void linked_list()
{
    do
    {
        cout<<"Give a numeric input according to the following scheme"<<endl;
        cout<<"1  : to select options for inserting"<<endl;
        cout<<"2  : to select options for deleting"<<endl;
        cout<<"3  : to select options for extra functions"<<endl;
        cout<<"4  : to exit"<<endl;


        int input=0;
        cin>>input;
        cout<<"\n\n"<<endl;


        while(input<1 || input>4)
        {
            cout<<"Kindly input a valid choice :"<<endl;
            cin>>input;
        }

        switch(input)
        {
            case 1: working_insert();
            break;

            case 2: working_delete();
            break;

            case 3:working_extra();
            break;

            case 4: cout<<"exiting"<<endl;
            return;
        }

    }while(1);
}






int main()
{
	cout<<endl;
	return 0;
}
