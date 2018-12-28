#include <stdio.h>

#include "src/my_list.h"

int main(int argc, char* argv[])
{
    int i;
    List my_list;

    init_list(&my_list);

    printf("Trying to remove an element from an empty list\n");
    remove_from_tail(&my_list);

    printf("\nTrying to print an empty list\n");
    print_list_of_ints(my_list);

    printf("\nInserting integers to a list\n");
    for(i = 0; i < 10; i++)
        insert_at_head(&my_list, i);

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nRemoving an element from the list\n");
    remove_from_head(&my_list);

    printf("Printing the list\n");
    print_list_of_ints(my_list);

}