// Attempt to make a generic linked list.
// TO BE CONTINUED (indev)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *next;
};

struct Node *create_node() {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
        printf("ERROR: failed to allocate memory for a node.\n");
    return ptr;
}

void free_nodes(struct Node *start) {
    struct Node *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
}

void display_list(struct Node *start, void (*fun)(void *)) {
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%d ", *(int *)(temp->data));
        temp = temp->next;
    }
    printf("\n");
}

int get_length(struct Node *start) {
    int length = 0;
    struct Node *temp = start;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

struct Node *get_node_at_position(struct Node *start, int position) {
    struct Node *temp = start;
    int limit = position < 0 ? get_length(start) + position : position;
    for (int i = 0; i < limit; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("No such position exists yet.\n");
            return NULL;
        }
    }
    return temp;
}

void insert_node(struct Node *start, int position, struct Node *node) {
    struct Node *temp = get_node_at_position(start, position);
    if (temp == NULL)
        return;
    struct Node *after = temp->next;
    temp->next = node;
    if (after != NULL) {
        node->next = after;
    }
}

void delete_node(struct Node *start, int position) {
    struct Node *temp = get_node_at_position(start, position);
    if (temp == NULL)
        return;
    struct Node *to_delete = temp->next, *after = to_delete->next;
    temp->next = to_delete->next;
    free(to_delete);
}
