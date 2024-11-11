struct node {
    int data;
    struct node *next;
};

struct node *create_node();
void input_node_data(struct node *ptr);
void free_nodes(struct node *start);

void display_list(struct node *start);
int get_length(struct node *start);
struct node *get_node_at_position(struct node *start, int position);

void insert_node(struct node *start, int position, struct node *node);
void delete_node(struct node *start, int position);

void reverse_list(struct node **start);
void reverse_by_chunks(struct node **start, int chunk_size);
