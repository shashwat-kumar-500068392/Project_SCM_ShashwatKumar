#include <iostream>

using namespace std;


struct Node
{
    int sap;
    int rollno;
    struct Node *next;
};

struct Node *head =NULL;


struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

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

void count_()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}


void reverse_()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout<<"List Reversed"<<endl;
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


void create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}



void add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
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

void add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}

void add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}



void delete_element(int value)
{
    struct node *tmp, *q;
     /first element deletion/
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /Element deleted in between/
        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /last element deleted/
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
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



void doubly_linked_list()
{
    int choice, element, position;

    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout<<"List empty,nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            delete_element(element);
            cout<<endl;
            break;
        case 5:
            display_dlist();
            cout<<endl;
            break;
        case 6:
            count_();
            break;
        case 7:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            reverse_();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}




int main()
{
	cout<<endl;
	return 0;
}
