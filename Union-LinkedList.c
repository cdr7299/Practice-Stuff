
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node *copy(struct Node *head1)
{
    // code here
    struct Node *newList = NULL;
    struct Node *newTail = NULL;
    while (head1 != NULL)
    {
        if (newList == NULL)
        {
            newList = (struct Node *)malloc(sizeof(struct Node));
            newList->data = head1->data;
            newList->next = NULL;
            newTail = newList;
        }
        else
        {
            //Add a function to check copy
            newTail->next = (struct Node *)malloc(sizeof(struct Node));
            newTail = newTail->next;
            newTail->data = head1->data;
            newTail->next = NULL;
        }
        head1 = head1->next;
    }
    return newList;
}

struct Node *unionList(struct Node *head1, struct Node *head2)
{

    struct Node *temp_list = copy(head1);
    // printList(temp_list);
    struct Node *temp_node;
    int flag = 0;
    struct Node * head1_reset = head1;
    while (head2 != NULL){
        printf("Searchhing for data %d\n", head2->data);
        while (head1 != NULL)
        {
            printf("Current element: %d \n", head1->data );
            if (head1->data == head2->data)
            {
                printf("found data %d \n",head2->data);
                flag = 1;
                break;
            }
            head1=head1->next;
        }
        if(flag == 0){
            temp_node = (struct Node* )malloc (sizeof(struct Node));
            temp_node->next = temp_list;
            temp_node->data = head2->data;
            temp_list = temp_node;
        }
        printList(temp_list);
        head2= head2->next;
        head1= head1_reset;
    }
    printList(temp_list);
}

int main()
{
    /* Start with the empty list */
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *temp = NULL;

    //list1
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 5);
    push(&head1, 1);
    push(&head1, 9);
    // push(&head1, 2);
    push(&head1, 8);

    //list2
    push(&head2, 1);
    push(&head2, 5);
    push(&head2, 7);
    push(&head2, 11);

    printList(head1);
    printList(head2);

    unionList(head1, head2);
    // temp = copy(head1);
    // printList(temp);
    return 0;
}
