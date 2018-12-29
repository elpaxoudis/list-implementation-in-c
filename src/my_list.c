#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "my_list.h"

void init_list(List* a_list)
{
    *a_list = NULL;
}

void insert_at_head(List* a_list, const void *data, size_t bytes)
{
    Node *new_node;
    
    // allocate memory for our new node
    new_node = (Node*) malloc(sizeof(Node));

    // initialize new node
    new_node->data = malloc(bytes);
    memcpy(new_node->data, data, bytes);    

    // add new node at the front of the list
    new_node->next = *a_list;
    *a_list = new_node;
}

void insert_at_tail(List* a_list, const void *data, size_t bytes)
{
    Node *tmp, *new_node;

    // check for empty list
    if(*a_list == NULL)
        insert_at_head(a_list, data, bytes);
    else
    {
        // start from the head
        tmp = *a_list;

        // and find the last node
        while(tmp->next != NULL)
            tmp = tmp->next;

        // allocate memory for our new node
        new_node = (Node*) malloc(sizeof(Node));

        // initialize new node
        new_node->data = malloc(bytes);
        memcpy(new_node->data, data, bytes);

        // insert node
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
}

// void insert_at_pos(List *a_list, int data, int pos)
// {
//     int k;
//     Node *new_node, *tmp, *tmp2;

//     if(*a_list == NULL || pos == 1)
//         insert_at_head(a_list, data);
//     else
//     {
//         // allocate memory for our new node
//         new_node = (Node*) malloc(sizeof(Node));

//         // initialize new node
//         new_node->data = data;

//         // initialize
//         k = 2;
//         tmp = *a_list;
//         tmp2 = tmp->next;

//         // go to the end or until pos is found
//         while(tmp2 != NULL && k < pos)
//         {
//             tmp = tmp->next;
//             tmp2 = tmp2->next;
//             k++;
//         }

//         // insert node
//         new_node->next = tmp->next;
//         tmp->next = new_node;
//     }
// }

void* remove_from_head(List* a_list, size_t bytes)
{
    Node *tmp;
    void *data;

    // check for an empty list
    if(*a_list == NULL)
    {
        printf("Cannot remove anything from an empty list\n");
        return NULL;
    }

    // keep a reference to the first node
    tmp = *a_list;

    data = malloc(bytes);
    memcpy(data, tmp->data, bytes);

    // change list's head
    *a_list = tmp->next;

    // free memory
    free(tmp);

    return data;
}

void* remove_from_tail(List *a_list, size_t bytes)
{
    void *data;
    Node *tmp, *tmp2;

    // check for an empty list
    if(*a_list == NULL)
    {
        printf("Cannot remove anything from an empty list\n");
        return NULL;
    }

    // start from the head
    tmp = *a_list;
    data = malloc(sizeof(bytes));
    if(data == NULL)
        perror("Could not allocate memory\n");

    // check for only one node
    if(tmp->next == NULL)
    {
        memcpy(data, tmp->data, bytes);
        *a_list = NULL;
        free(tmp);
    }
    else
    {
        // go to the second from last node
        while(tmp->next->next != NULL)
            tmp = tmp->next;

        // get a reference to the last node
        tmp2 = tmp->next;
    
        memcpy(data, tmp2->data, bytes);
        tmp->next = NULL;
        free(tmp2);
    }

    return data;
}

// int remove_from_pos(List* a_list, int pos)
// {
//     int data, k;
//     Node *tmp, *tmp2;

//     if(*a_list == NULL)
//     {
//         printf("Could not remove from an empty list\n");
//         return 0;
//     }

//     if(pos == 1)
//         return remove_from_head(a_list);
//     else
//     {
//         // initialize
//         k = 2;
//         tmp = *a_list;
//         tmp2 = tmp->next;

//         // go to the end or until pos is found
//         while(tmp2 != NULL && k < pos)
//         {
//             tmp = tmp->next;
//             tmp2 = tmp2->next;
//             k++;
//         }

//         data = tmp2->data;
//         tmp->next = tmp2->next;
//         free(tmp2);
//         return data;
//     }
// }

void print_list_of_ints(List a_list)
{
    Node *tmp;

    if(a_list == NULL)
    {
        printf("Cannot print an empty list\n");
        return;
    }

    // start from the head
    tmp = a_list;

    // print every node from head to tail
    while(tmp != NULL)
    {
        printf("%d --> ", (int) *((int*) (tmp->data)));
        tmp = tmp->next;
    }
    printf("NULL\n");
}