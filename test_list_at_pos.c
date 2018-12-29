#include <stdio.h>

#include "src/output_helpers.h"

int main(int argc, char* argv[])
{
    int i, new_item, *removed;
    List my_list;

    init_list(&my_list);

    printf("Trying to remove an element from an empty list\n");
    remove_from_pos(&my_list, 1, sizeof(int));

    printf("\nTrying to print an empty list\n");
    print_list_of_ints(my_list);

    printf("\nInserting integers to a list\n");
    for(i = 0; i < 10; i++)
        insert_at_pos(&my_list, &i, i + 1, sizeof(i));

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nInsert a node at 3d position\n");
    new_item = 555;
    insert_at_pos(&my_list, &new_item, 3, sizeof(new_item));

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nRemoving the 3d element from the list\n");
    removed = (int*) remove_from_pos(&my_list, 3, sizeof(int));
    printf("Data was removed: %d\n", *removed);
    
    printf("Printing the list\n");
    print_list_of_ints(my_list);

}