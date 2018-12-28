struct node {
    int data;
    struct node* next;
};

typedef struct node Node;
typedef Node* List;

void init_list(List*);

void insert_at_head(List*, int);
void insert_at_tail(List*, int);
void insert_at_pos(List*, int, int);

int remove_from_head(List*);
int remove_from_tail(List*);
int remove_from_pos(List*, int);

void print_list_of_ints(List);