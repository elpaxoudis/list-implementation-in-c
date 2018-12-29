#include <stdio.h>

#include "src/my_list.h"

int main(int argc, char* argv[])
{
    int i, *removed;
    List my_list;

    init_list(&my_list);

    printf("Trying to remove an element from an empty list\n");
    remove_from_tail(&my_list, sizeof(int));

    printf("\nTrying to print an empty list\n");
    print_list_of_ints(my_list);

    printf("\nInserting integers to a list\n");
    for(i = 0; i < 10; i++)
        insert_at_tail(&my_list, &i, sizeof(i));

    printf("Printing the list\n");
    print_list_of_ints(my_list);

    printf("\nRemoving an element from the list\n");
    removed = (int*) remove_from_tail(&my_list, sizeof(int));
    printf("Data was removed: %d\n", *removed);
    
    printf("Printing the list\n");
    print_list_of_ints(my_list);
}