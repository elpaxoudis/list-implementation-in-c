struct node {
    void* data;
    struct node* next;
};

typedef struct node Node;
typedef Node* List;

void init_list(List*);

void insert_at_head(List*, const void*, size_t);
void insert_at_tail(List*, const void*, size_t);
void insert_at_pos(List*, const void*, int, size_t);

void* remove_from_head(List*, size_t);
void* remove_from_tail(List*, size_t);
void* remove_from_pos(List*, int, size_t);