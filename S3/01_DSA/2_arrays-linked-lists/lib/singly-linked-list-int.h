struct Node {
    int data;
    struct Node *next;
};

struct Node *create_node();
void input_node_data(struct Node *ptr);
void free_nodes(struct Node *start);

void display_list(struct Node *start);
int get_length(struct Node *start);
struct Node *get_node_at_position(struct Node *start, int position);

void insert_node(struct Node *start, int position, struct Node *node);
void delete_node(struct Node *start, int position);

void reverse_list(struct Node **start);
void reverse_by_chunks(struct Node **start, int chunk_size);
