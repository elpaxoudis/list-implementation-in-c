test_with_student: test_list_with_student_struct.c src/my_list.c src/output_helpers.c
	gcc -o test_list_with_student_struct test_list_with_student_struct.c src/my_list.c src/output_helpers.c

test_at_head: test_list_at_head.c src/my_list.c src/output_helpers.c
	gcc -o test_at_head test_list_at_head.c src/my_list.c src/output_helpers.c

test_at_tail: test_list_at_tail.c src/my_list.c src/output_helpers.c
	gcc -o test_at_tail test_list_at_tail.c src/my_list.c src/output_helpers.c

test_at_pos: test_list_at_pos.c src/my_list.c src/output_helpers.c
	gcc -o test_at_pos test_list_at_pos.c src/my_list.c src/output_helpers.c

clean:
	rm test_at* test_with*

all: test_at_head test_at_tail test_at_pos