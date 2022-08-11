#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtspecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;

    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    // cout<<" Hellow world"<<endl;

    if (head == NULL)
    {
        head = newNode;
        // cout<<head->Next<<" "<<head->value<<endl;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
};

void reversePrint(Node *n)
{
    if (n == NULL)
        return;

    reversePrint(n->Next);

    cout << n->value << " ";
}

void insertAtHead(Node *&head, int val)
{
    // s1 new Node creation
    Node *newNode = new Node(val);

    // s2 Update of Newnode -> Next
    newNode->Next = head;

    // s3 update of head
    head = newNode;
}

int countLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void display(Node *n)
{

    // cout<<n->Next<<endl;
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";

        n = n->Next;
    }
    cout << endl
         << endl;
}

int searchvalueforUnique(Node *&head, int key)
{

    Node *temp = head;
    int count = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }

    return count;
}

void searchByvalueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout<<count<<" ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    if (flag == 0)
    {
        cout << "The searched value is not yet in the list " << endl;
    }
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
        cout << endl;
    }
}

Test searchByvalueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int count = 1, k = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void searchByValueUnique(Node *&head, int searchValue, int value)
{
    // step 1: Search The position of the search value;
    int position;
    position = searchvalueforUnique(head, searchValue);

    // step 2: Insert the value of specific position;
    insertAtspecificPosition(head, position + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the link list " << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }

        Node *delnode = temp->Next;
        temp->Next = NULL;
        delete delnode;
    }
    else
    {
        // head is Null;
        if (temp == NULL)
        {

            cout << "There is no value in the link list " << endl;
        }
        // Head is tail
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;

    if (position <= countLength(head))
    {

        if (position == 1)
        {
            deletionAtHead(head);
        }

        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        // if (position > countLength(head))
        // {
        cout << "Position Out of Bound" << endl;
        // }
        // else
        // {
        //     cout << "There is no value in the link list" << endl;
        // }
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    // find the position of the value
    int position;
    position = searchvalueforUnique(head, value);
    // delete the node at that position
    if (position == -1)
    {
        cout << "Value not Found in the linked List" << endl;
    }

    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The link list is empty " << endl;
        return head;
    }

    Node *next = head->Next;

    while (1)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
        {
            break;
        }

        next = next->Next;
    }
    return prev;
}

int main()
{

    Node *head = NULL;
    // cout<<head<<endl;

    int n;
    cout << "Choice 1:  Insertion at head" << endl
         << "Choice 2:  Insertion at Tail" << endl
         << "choice 3: Insert At Specific position " << endl
         << "Choice 4: Search a value (Unique List)" << endl
         << "Choice 5: search a value (Duplication Enabeld List)" << endl
         << "Choice 6: Insertion after a specific value (Unique List)" << endl
         << "Choice 7: Deletion At Head " << endl
         << "Choice 8: Deletion At Tail " << endl
         << "Choice 9: Deletion At a Specific Position " << endl
         << "Choice 10: Deletion  by value (Unique List) " << endl
         << "Choice 11: Reverse in NON Recursive Way " << endl
         << "Choice 0: Exit" << endl
         << endl
         << endl;

    cout << "Next Choice : ";
    int choice, value, position;
    cin >> choice;

    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter The Value : ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter The Value : ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter The Desire Position : ";
            cin >> position;
            cout << "Enter the value ";
            cin >> value;
            insertAtspecificPosition(head, position, value);
        case 4:
            cout << "Enter the for searching value ";
            cin >> value;
            position = searchvalueforUnique(head, value);
            if (position != -1)
            {
                cout << "The Number is  at position : " << position << endl;
            }
            else
            {
                cout << "The nunber is yet in the list" << endl;
            }
            break;
        case 5:
            cout << "Enter the for searching value ";
            cin >> value;
            //   cout<<"The Number is  at position : ";
            //   searchByvalueDuplicate(head,value);
            // if(position != -1){
            //     cout<<"The Number is  at position : "<<position<<endl;
            // }
            // else{
            //     cout<<"The nunber is yet in the list"<<endl;
            // }

            Test T;
            T = searchByvalueDuplicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The Searched value is not yet in the list. " << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The value  is found  at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ",";
                }
                cout << endl;
            }
            break;

        case 6:
            cout << "Enter The value to Search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter The value to Insert: ";
            cin >> value;
            searchByValueUnique(head, searchValue, value);
            break;

        case 7:
            deletionAtHead(head);
            break;

        case 8:
            deletionAtTail(head);
            break;

        case 9:
            if (head == NULL)
            {
                cout << "There is no value in the link list " << endl;
                break;
            }
            cout << "Enter the Desired Position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;
        case 10:
            cout << "Enter the value to delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        case 11:
            head = reverseNonRecursive(head);

        default:
            break;
        }
        cout << "Next Choice : ";
        cin >> choice;
    }

    // insertAtTail(head, 1);
    // insertAtTail(head, 5);
    // insertAtTail(head, 8);
    // insertAtTail(head, 9);
    // insertAtTail(head, 10);

    // Node* second=new Node();
    // Node* third=new Node();
    // Node* fourth=new Node();

    // head->value=1;
    // second->value=5;
    // third->value=8;
    // fourth->value=9;
    // des uthese sala late
    //  head->Next=second;
    //  second->Next=third;
    //  third->Next=fourth;
    //  fourth->Next=NULL;

    cout << "Link List : ";
    display(head);

    cout << "Length of Link List : " << countLength(head) << endl;

    // reversePrint(head);
    
   

    return 0;
}
