// NOTE - you have to create a singly linked list from scratch. Your submission will not be graded if implementation of singly linked list is not found.

// You will be given a linked list with 𝑁
//  elements. Following are some operations that can be performed on the linked list:

// Reverse : in this operation you have to reverse the linked list.
// Print : in case of an empty linked list print "EMPTY". Otherwise you have to print the linked list.
// Length : in this operation you have to print the length of the linked list.
// KthNode K : Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to print the 𝐾𝑡ℎ
//  node of the linked list.
// Delete K : Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to delete the 𝐾𝑡ℎ
//  node of the linked list.
// You will be given 𝑄
//  of the above mentioned operations to be performed on the linked list.

// Constraints:

// 1≤𝑁∗𝑄≤107
// 1≤𝐾≤105
// 1≤
//  Linked List Node value ≤109
// Input
// The first line contains 2 integers 𝑁
//  and 𝑄
//  denoting the length of the linked list and number of queries. The next line contains 𝑁
//  spaced integers denoting the elements of the linked list. Each of the following 𝑄
//  lines contain one of the operations to be performed on the linked list as mentioned in the problem.

// Output
// Print the output corresponding to the operations if any.


// input
// 3 2
// 1 4 2
// KthNode 1
// Print


// output
// 1
// 1 4 2 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * delFront(struct Node *head)
{
    struct Node *temp = head; //temp stores the address of the head
    head = head -> next; //stores the address of the next node in head
    free(temp);

    return head;
}

struct Node * insertFront(struct Node *head, int x)
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head -> data = x;
        head -> next = NULL;
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp -> next = head -> next;
        head -> next = temp;
        head -> data = x;
    }

    return head;
}

struct Node * insertRear(struct Node *head, int x)
{
    if (head == NULL)
        return insertFront(head, x);
    else
    {
        struct Node *temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = (struct Node *)malloc(sizeof(struct Node));
        temp -> next -> data = x;
        temp -> next -> next = NULL;
    }
    return head;
}

struct Node * reverse(struct Node *head)
{
    struct Node * curr = head, * prev = NULL, * temp;

    while (curr != NULL)
    {
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp; 
    }

    return prev;
}
int main()
{
    struct Node *head = NULL;

    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        head = insertRear(head, temp);
    }

    for(int i = 0; i < q; i++)
    {
        char operation[10];
        int k;
        scanf(" %s", &operation);

        if(strcmp(operation, "KthNode") == 0 || strcmp(operation, "Delete") == 0)
        {
            scanf("%d", &k);
        }

        //each function
        if(strcmp(operation, "Delete") == 0)
        {
            int len;
            if(head == NULL)
                len = 0;
            else
            {
                len = 1;
                struct Node * temp = head;
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                    len += 1;
                }
                //printf("%d\n", len);
            }  
            if(k > len)
                printf("-1\n");
            else
            {
                if(k == 1)
                {
                    head = delFront(head);
                }
                else
                {
                    struct Node * temp = head;
                    for(int j = 1; j < k-1; j++)
                    {
                        temp = temp -> next;
                    }   
                    struct Node * pTemp1 = temp -> next;
                    temp -> next = pTemp1 -> next;
                    free(pTemp1);
                }
            } 
        }
        else if(strcmp(operation, "Length") == 0)
        {
            if(head == NULL)
                printf("0\n");
            else
            {
                int i = 1;
                struct Node * temp = head;
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                    i += 1;
                }

                    printf("%d\n", i);
            }
        }
        else if(strcmp(operation, "Print") == 0)
        {
            struct Node *temp = head;

            if(head == NULL)
            {
                printf("EMPTY\n");
            }
            else
            {
                while((temp -> next != NULL))
                {
                    printf("%i ", temp -> data);
                    temp = temp -> next;
                }
                printf("%d", temp -> data);
                printf("\n");
            }
        }
        else if (strcmp(operation, "Reverse") == 0)
        {
            head = reverse(head);
        }
        else if(strcmp(operation, "KthNode") == 0)
        {
            int len;
            if(head == NULL)
                len = 0;
            else
            {
                len = 1;
                struct Node * temp = head;
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                    len += 1;
                }
            }  
            if(k > len)
                printf("-1\n");
            else
            {
                struct Node * temp = head;
                for(int j = 1; j < k; j++)
                {
                    temp = temp -> next;
                }
                printf("%d\n", temp->data);
            } 
        }
    }

    return 0;
}
