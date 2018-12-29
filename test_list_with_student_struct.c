#include <stdio.h>
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

    get_input(&student_list);

    print_from_list(student_list, &print_student);
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