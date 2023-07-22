// NOTE - you can create a singly/doubly linked list from scratch. Your submission will not be graded if implementation of singly/doubly linked list is not found.

// You will be given a linked list with 𝑁
//  elements. Following are some operations that can be performed on the linked list:

// KthNode K : Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to print the 𝐾𝑡ℎ
//  node of the linked list.
// Delete K : Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to delete the 𝐾𝑡ℎ
//  node of the linked list.
// Add K X: Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to Add the value 𝑋
//  to the 𝐾𝑡ℎ
//  node of the linked list.
// Subtract K X: Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to Subtract the value 𝑋
//  to the 𝐾𝑡ℎ
//  node of the linked list.
// Xor K : Print -1 if 𝐾
//  is greater than the length of the linked list. Otherwise in this operation you have to print the value of the xor of last 𝐾𝑡ℎ
//  nodes of the linked list.
// You will be given 𝑄
//  of the above mentioned operations to be performed on the linked list.

// Constraints:

// 1 ≤ 𝑁∗𝑄 ≤ 10^7
// 1 ≤ 𝐾 ≤ 10^5
// 1 ≤ Linked List Node value, X ≤ 10^9

// Input
// The first line contains 2 integers 𝑁
//  and 𝑄
//  denoting the length of the linked list and number of queries. The next line contains 𝑁
//  spaced integers denoting the elements of the linked list. Each of the following 𝑄
//  lines contain one of the operations to be performed on the linked list as mentioned in the problem.

// Output
// Print the output corresponding to the operations if any.

// input
// 10 9
// 3 10 3 3 5 7 1 2 8 6
// Delete 9
// KthNode 1
// Delete 4
// KthNode 6
// KthNode 5
// Delete 5
// KthNode 2
// Xor 7
// Xor 5

// output
// 3
// 1
// 7
// 10
// 10
// 3


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node* next;
};
struct node * insert(struct node* head, int n, int value){
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->data=value;

    struct node * temp = head;

    if(n==0){
        a->next=head;
        return a;
    }

    for(int i=0; i<n-1; i++){
        head=head-> next;
    }
    a->next=head->next;
    head->next=a;
    return temp;
}

int length(struct node *head){
    int c=0;
    while(head!=NULL){
        c+=1;
        head=head->next;
    }
    return c;
}

int kthnode(struct node * head, int k){
    if (k > length(head)){
        return -1;
    }
    k=k-1;
    for (int i=0; i<k; i++){
        head=head->next;
    }
    return head->data;
}
struct node * delete(struct node * head, int n){

    if(n>length(head))
    {
        printf("%d\n",-1); 
        return head;
    }

    n-=1;

    if(n==0){
        struct node * temp = head->next;
        free(head);
        return temp;
    }
    struct node * temp= head;
    for(int i=0; i<n-1; i++){
        head = head-> next;
    }
    struct node *temp1 = head->next;
    head->next=head->next->next;
    free(temp1);
    return temp;
}

void add(struct node * head, int n, int x){
    if (n>length(head))
    {
        printf("%d\n",-1); 
        return;
    }

    for(int i=1;i<n;i++){
        head=head->next;
    }
    head->data+=x;
}

void sub(struct node * head, int n, int x){
    if (n>length(head))
    {
        printf("%d\n",-1);
        return;
    }

    for(int i=1;i<n;i++){
        head=head->next;
    }
    head->data-=x;
}
int xor(struct node * head, int k){
    if(k>length(head)){
        return -1;
    }
    int a=0;
    int z=length(head);
    for(int i=0;i<z-k;i++){
        head=head->next;
    }
    while(head!=NULL){
        a=a^head->data;
        head=head->next;
    }
    return a;
}

int main(){
    struct node * l= NULL;
    
    int n,q;
    scanf("%d %d",&n,&q);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        l= insert(l,i,arr[i]);

    }
    char s[20];
    for (int i=0;i<q;i++){
        scanf("%s",s);

        if (s[0]=='D'){
            int k;
            scanf("%d",&k);
            l=delete(l,k);
            continue;
        }

        if (s[0]=='A'){
            int k,x;
            scanf("%d %d",&k,&x);
            add(l,k,x);
            continue;
        }
        if (s[0]=='S'){
            int k,x;
            scanf("%d %d",&k,&x);getchar();
            sub(l,k,x);
            continue;
        }
        if (s[0]=='X'){
            int k;
            scanf("%d",&k);
            printf("%d\n",xor(l,k));
            continue;
        }

        int k;
        scanf("%d",&k);
        printf("%d\n",kthnode(l,k));


    }
    return 0;
}