#include <iostream>
#include <stdlib.h>


using namespace std;

//struct Node for singly linked list

struct Node
{
    int sap;
    int rollno;
    struct Node *next;
};

struct Node *head =NULL;

// struct node for doubly linked list

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

//struct node_ for binary search tree

struct node_
{
    int info;
    struct node_ *left;
    struct node_ *right;
}*root;


/*
The functions implementing the singly linked list start here
*/



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



/*
Functions implementing doubly linked list start here
*/



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
     /*first element deletion*/
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
        /*Element deleted in between*/
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
     /*last element deleted*/
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



/*
Functions implementing doubly linked list start here
*/



void find(int item, node_ **par, node_ **loc)
{
    node_ *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}





void insert(node_ *tree, node_ *newnode)
{
    if (root == NULL)
    {
        root = new node_;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
}
 





void case_a(node_ *par, node_ *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
 



void case_b(node_ *par, node_ *loc)
{
    node_ *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}
 



void case_c(node_ *par, node_ *loc)
{
    node_ *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
 




void preorder(node_ *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}





void inorder(node_ *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}
 


void postorder(node_ *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}
 




void display__(node_ *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display__(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->info;
        display__(ptr->left, level+1);
    }
}



void del(int item)
{
    node_ *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}




/*
Intermediate functions calling functions implementing linked list start here
*/



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


/*
Intermediate function calling functions implementing singly linked list start here
*/

void linked_list()
{
    cout<<endl<<"----------------------------"<<endl;
    cout<<endl<<"Operations on Singly linked list"<<endl;
    cout<<endl<<"----------------------------"<<endl;
    cout<<endl;
    cout<<endl;
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


/*
Intermediate function calling functions implementing doubly linked list start here
*/


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



/*
Intermediate function calling functions implementing binary search tree start here
*/



void binary_search_tree()
{
	int choice, num;
    
    node_ *temp;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node_;
            cout<<"Enter the number to be inserted : ";
	    cin>>temp->info;
            insert(root, temp);
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            del(num);
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            inorder(root);
            cout<<endl;
            break;
	case 4:
            cout<<"Preorder Traversal of BST:"<<endl;
            preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of BST:"<<endl;
            postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display BST:"<<endl;
            display__(root,1);
            cout<<endl;
            break;
        case 7:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}



/*
Function calling the functions implementing singly linked list, doubly 
linked list and binary search tree start here
*/



void ask_choice()
{
    do
    {
        cout<<"Give a numeric input according to the following scheme"<<endl;
        cout<<"1  : to use singly linked list"<<endl;
        cout<<"2  : to use doubly linked list"<<endl;
        cout<<"3  : to use binary search tree"<<endl;
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
            case 1: linked_list();
            break;

            case 2: doubly_linked_list();
            break;
            
            case 3: binary_search_tree();
            break;

            case 4: cout<<"exiting"<<endl;
            return;
        }  

    }while(1);
}



/*
int main to run the program
*/

int main()
{
    ask_choice();
    return 0;
}

