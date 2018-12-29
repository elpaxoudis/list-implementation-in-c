#include <stdio.h>

#include "output_helpers.h"

void print_from_list(List a_list, void (*print)(const void*))
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
        print(tmp->data);
        tmp = tmp->next;
    }
}

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