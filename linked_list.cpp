#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *ptr, *newnode;

// for appending kth node of linked list
struct Node *NewHead;

// for finding intersection of two linked list
// for mergering linked list
struct Node *head1;
struct Node *head2;
struct Node *result = NULL;

// FUNCTION TO ADD NEW NODE AT STARTING OF SINGLE_LINKED-LIST
struct Node *singly_linked_list_insert_start()
{

    int value;
    newnode = new Node;
    if (newnode == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        cout << "Enter the value to insert\n";
        cin >> value;
        newnode->data = value;
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    cout << value << " added successfully\n";
}

// FUNCTION TO DELETE A NODE FROM STARTING OF SINGLE_LINKED_LIST
struct Node *singly_linked_list_delete_start()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        cout << "UnderFlow";
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        cout << "Node Deleted\n";
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
        cout << "Element deleted successfully\n";
    }
}

// FUNCTION TO ADD NEW NODE IN THE MIDDLE OF SINGLE_LINKED_LIST
struct Node *singly_linked_list_insert_middle()
{
    struct Node *p = head;
    int value, i = 0;
    int position;
    newnode = new Node;
    cout << "Enter the value to insert and position where you want to insert the node\n";
    cin >> value >> position;
    if (newnode == NULL)
    {
        cout << "OverFlow\n";
    }
    else
    {
        if (head == NULL)
        {
            head->next = NULL;
            head = newnode;
        }
        else
        {
            while (i != position - 1)
            {
                p = p->next;
                i++;
            }
            newnode->data = value;
            newnode->next = p->next;
            p->next = newnode;
        }
    }
    cout << value << " added successfully\n";
}

// FUNCTION TO DELETE A NODE FROM MIDDLE OF SINGLE_LINKED_LIST
struct Node *singly_linked_list_middle_delete()
{
    struct Node *p = head;
    struct Node *cur, *prev;
    int index;
    if (head == NULL)
    {
        cout << "Empty list\n";
    }
    else
    {
        cout << "Enter the index:\n";
        cin >> index;
        while (index != 1)
        {
            prev = cur;
            cur = cur->next;
            index--;
        }
        prev->next = cur->next;
    }
    cout << "Element deleted successfully\n";
}

// FUNCTION TO ADD NEW NODE IN THE END OF SINGLE_LINKED_LIST
void singly_linked_list_insert_end()
{
    int value;
    newnode = new Node;
    struct Node *p = head;
    if (newnode == NULL)
    {
        cout << "Overflow\n";
    }
    else
    {
        cout << "Enter the value to insert\n";
        cin >> value;

        newnode->data = value;
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newnode;
            newnode->next = NULL;
        }
    }
}

// FUNCTION TO ADD NEW NODE IN THE END OF SINGLE_LINKED_LIST
struct Node *single_linked_list_delete_end()
{
    struct Node *p = head;
    struct Node *q = head->next;
    if (p == NULL)
    {
        printf("UnderFLow");
    }
    else if (head->next == head)
    {
        head == NULL;
        free(head);
    }
    else
    {
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
    }

    cout << "Element deleted successfully\n";
}

// FUNCTION TO REVERCE THE SINGLY_LINKED_LIST
struct Node *reverse_single_linked_list()
{
    struct Node *prevNode, *curNode;

    if (head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while (head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        cout << "SUCCESSFULLY REVERSED LIST\n";
    }
}

// PUT_ALL_EVEN_NODES_AFTER_ODD_NODES IN SINGLE_LINKED_LIST
struct Node *PUT_ALL_EVEN_NODES_AFTER_ODD_NODES()
{
    struct Node *odd = head;
    struct Node *even = head->next;
    struct Node *evenstart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenstart;
    if (odd->next != NULL)
    {
        even->next == NULL;
    }
    cout << "Done successfully you can check\n";
}

// FUNCTION FOR TAKING INPUT FOR MERGING TWO GIVEN LINKED LIST
struct Node *merge_input()
{
    int n, m;
    int i, j;

    printf("Enter the number of elements in linked list 1\n");
    scanf("%d", &n);
    printf("Enter the elements in first linked list\n");
    for (i = 0; i < n; i++)
    {
        head1 = singly_linked_list_insert_start();
    }
    printf("Enter the number of elements in linked list 2\n");
    scanf("%d", &m);
    printf("Enter the elements in second linked list\n");
    for (j = 0; j < m; j++)
    {
        head2 = singly_linked_list_insert_start();
    }
}

// FUNCTION FOR MERGING TWO LINKED LIST
struct Node *mergeSortedLists(struct Node *head1, struct Node *head2)
{

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head2;

    if (head1->data < head2->data)
    {
        head1->next = mergeSortedLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeSortedLists(head1, head2->next);
        return head2;
    }
    return result;
}

// remove_duplicate_sorted_singly_linked_list
struct Node *remove_duplicate_elements_sorted_single_linked_list()
{
    Node *current = head;
    Node *next_next;
    if (current == NULL)
    {
        return head;
    }
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
    cout << "Duplicate elements are removed successfully:\n";
}

// remove_duplicate_unsorted_singly_linked_list
struct Node *remove_duplicate_elements_unsorted_single_linked_list()
{
    struct Node *ptr1, *ptr2, *del;
    ptr1 = head;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                del = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(del);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
}

// FIND THE MIDDLE ELEMENT OF SINGLE_LINKED_LIST
struct Node *Middle_element_single_linked_list()
{
    struct Node *fast = head;
    struct Node *slow = head;
    if (head == NULL)
    {
        return head;
    }

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
    }
    cout << "The middle element of linked list is " << slow->data << " ";
}

// FUNCTION TO FIND THE LENGTH OF LINKED LIST
int length_linked_list()
{
    int length = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    // cout << "The length of linked list is " << length;
    return length;
}
// APPENDING LAST KTH NODES TO START OF LINKED LIST
struct Node *append_kth_nodes_to_start_of_linked_list()
{
    struct Node *NewHead;
    struct Node *NewTail;
    struct Node *Tail = head;
    int k;
    cout << "Enter the value of k\n";
    cin >> k;
    int count = 1;
    int lenght = length_linked_list();
    k = k % lenght;

    while (Tail->next != NULL)
    {
        if (count == lenght - k)
        {
            NewTail = Tail;
        }
        if (count == lenght - k + 1)
        {
            NewHead = Tail;
        }
        count++;
        Tail = Tail->next;
    }
    NewTail->next = NULL;
    Tail->next = head;
    cout << "Task done successfully\n\n";

    return NewHead;
}

//FIND THE INTERSECTION OF LINKED LIST
 struct Node * Intersection_linked_list()
 {

}

// Transeverce of single_linked_list
struct Node *transeverce_single_linked_list(struct Node *head)
{
    cout << "The single linked list is:\n";
    ptr = head;
    if (head == NULL)
    {
        cout << "EMPTY LIST\n";
    }
    else
    {

        while (ptr != NULL)
        {
            cout << "->" << ptr->data;
            ptr = ptr->next;
        }
    }
}

// FUNCTION FOR SINGLE LINKED LIST
struct Node *single_linked_list()
{

    int choice;

    printf("WELCOME TO SINGLE_LINKED_LIST\n");

    while (1)
    {
        cout << "\n..............MENU..............\n";
        cout << "\n1) Insertion at starting:\n";
        cout << "2) Insertion at middle:\n";
        cout << "3) Insertion at end:\n";

        cout << "4) Deletion at starting:\n";
        cout << "5) Deletion at middle:\n";
        cout << "6) Deletion at end\n";
        cout << "7) Transversal of linked list\n";
        cout << "8) Searching in single linked list\n";
        cout << "9) Reverse a single linked list\n";
        cout << "10) PUT ALL EVEN NODES AFTER ODD NODES\n";
        cout << "11) Remove all the even nodes of singly_linked_list\n";
        cout << "12) Merge two linked list\n";

        cout << "13) Remove duplicate elements from the sorted singly_linked_list\n";
        cout << "14) Remove duplicate elements from the unsorted singly_linked_list\n";
        cout << "15) Middle element of linked list\n";

        cout << "16) Length of linked list\n";
        cout << "17) Append kth nodes to start of linked list\n";
        cout << "18) Intersection of two linked list\n";
        cout << "19) Exit from single linked list\n";
        cout << "20) Go back to main menu of linked list\n";

        cout << "\nEnter your choice:\n";
        cin >> choice;
        // system("cls");
        switch (choice)
        {

        case 1:
            singly_linked_list_insert_start();
            break;
        case 2:
            singly_linked_list_insert_middle();
            break;
        case 3:
            singly_linked_list_insert_end();
            break;

        case 4:
            singly_linked_list_delete_start();
            break;

        case 5:
            singly_linked_list_middle_delete();
            break;

        case 6:
            single_linked_list_delete_end();
            break;

        case 7:
            transeverce_single_linked_list(head);
            break;

            // case 8:
            //     search_singly_linked_list();
            //     break;

        case 9:
            reverse_single_linked_list();
            break;
        // case 11:
        //     delete_odd_nodes_singly_linked_list();
        //     break;
        case 10:
            PUT_ALL_EVEN_NODES_AFTER_ODD_NODES();
            break;

        case 12:
            merge_input();
            result = mergeSortedLists(head1, head2);
            cout << "Merged Linked List in Sorted Order : ";
            transeverce_single_linked_list(head);
            break;

        case 13:
            remove_duplicate_elements_sorted_single_linked_list();
            break;

        case 14:
            remove_duplicate_elements_unsorted_single_linked_list();
            break;

        case 15:
            Middle_element_single_linked_list();
            break;
        case 16:
            length_linked_list();
            break;
        case 17:
            transeverce_single_linked_list(append_kth_nodes_to_start_of_linked_list());
            break;
        case 18:
            Intersection_linked_list();
            break;
        case 19:
            exit(0);
            //  case 14:
            // main();
            // break;
        default:
            break;
        }
    }
}

int main()
{

    int choice;
    // clrscr();

    while (1)

    {
        cout << "..............MENU..............";
        cout << "\n1. Singly linked list\n";
        cout << "2. Doubly linked ist\n";
        cout << "3. Circular linked list\n";
        cout << "Please enter your choice:";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            single_linked_list();
            break;
            // case 2:
            //     double_linked_list();
            //     break;
            // case 3:
            //     circular_linked_list();
            //     break;

        default:
            cout << "Wrong choice entered, Please enter again\n";
        }
    }
    return 0;
}