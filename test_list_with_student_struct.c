#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/output_helpers.h"

typedef struct student {
    int id;
    char *first_name;
    char *last_name;
} Student;

void print_student(const void* student);
void get_input(List *a_list);

int main(int argc, char* argv[])
{
    List student_list;

    init_list(&student_list);

    get_input(&student_list);

    print_from_list(student_list, &print_student);
}

void get_input(List *a_list)
{
    int menu_choice, id;
    char buf[256];

    Student *new_student;

    printf("1. Insert new student\n0. Exit\n\n");
    scanf("%d", &menu_choice);

    while(menu_choice != 0)
    {
        if(menu_choice == 1)
        {
            new_student = (Student*) malloc(sizeof(Student));

            // read id
            printf("Please give student's ID:\n");
            scanf("%d", &id);
            new_student->id = id;

            // read first name
            printf("Please give student's first name:\n");
            scanf("%s", buf);
            new_student->first_name = (char*) malloc(strlen(buf));
            memcpy(new_student->first_name, buf, strlen(buf));

            // read last name
            printf("Please give student's last name:\n");
            scanf("%s", buf);
            new_student->last_name = (char*) malloc(strlen(buf));
            memcpy(new_student->last_name, buf, strlen(buf));
        }

        printf("DONE!\n\n");
        printf("1. Insert new student\n0. Exit\n\n");
        scanf("%d", &menu_choice);
    }    
}

void print_student(const void* student)
{
    Student student_cpy;
    
    memcpy(&student_cpy, &student, sizeof(Student));

    printf("Student ID: %d\nFirst Name: %s\nLast Name: %s\n\n",
        student_cpy.id,
        student_cpy.first_name,
        student_cpy.last_name
    );
}