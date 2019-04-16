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


int main()
{
	cout<<endl;
	return 0;
}
