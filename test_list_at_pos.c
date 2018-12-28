#include <stdio.h>

#include "src/my_list.h"

int main(int argc, char* argv[])
{
    int i;
    List my_list;

    init_list(&my_list);

    // printf("Trying to remove an element from an empty list\n");
    // remove_from_tail(&my_list);

    printf("\nTrying to print an empty list\n");
    print_list_of_ints(my_list);

    printf("\nInserting integers to a list\n");
    for(i = 0; i < 10; i++)
        insert_at_pos(&my_list, i, i + 1);

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nInsert a node at 3d position\n");
    insert_at_pos(&my_list, 555, 3);

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nRemoving the 3d element from the list\n");
    remove_from_pos(&my_list, 3);

    printf("Printing the list\n");
    print_list_of_ints(my_list);

}