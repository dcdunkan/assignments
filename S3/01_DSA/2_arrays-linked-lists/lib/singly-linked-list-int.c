#include "../lib/singly-linked-list-int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node *create_node() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("ERROR: failed to allocate memory for a node.\n");
    return ptr;
}

void input_node_data(struct node *ptr) {
    printf("Enter an integer for the data part: ");
    scanf("%d", &(ptr->data));
}

void free_nodes(struct node *start) {
    struct node *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
}

void display_list(struct node *start) {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int get_length(struct node *start) {
    int length = 0;
    struct node *temp = start;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

struct node *get_node_at_position(struct node *start, int position) {
    struct node *temp = start;
    int length = get_length(start);
    int limit = position < 0 ? get_length(start) + position : position;
    if (limit < 0 || limit > length) {
        printf("No such index exists.\n");
        return NULL;
    }
    for (int i = 0; i < limit; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("No such position exists yet.\n");
            return NULL;
        }
    }
    return temp;
}

void insert_node(struct node *start, int position, struct node *node) {
    struct node *temp = get_node_at_position(start, position);
    if (temp == NULL)
        return;
    struct node *after = temp->next;
    temp->next = node;
    if (after != NULL) {
        node->next = after;
    }
}

void delete_node(struct node *start, int position) {
    struct node *temp = get_node_at_position(start, position);
    if (temp == NULL)
        return;
    struct node *to_delete = temp->next, *after = to_delete->next;
    temp->next = to_delete->next;
    free(to_delete);
}

// NOTE: START must be the very first item in the list, not the HEAD
// that points to the first item.
// NOTE: This can also be done by just splitting by chunks with
// chunk size as the length of the list.
void reverse_list(struct node **start) {
    // No elements or only one element => already reversed!
    if (*start == NULL || (*start)->next == NULL)
        return;
    struct node *prev = NULL, *current = *start, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *start = prev;
}

/* Guide: Geeks For Geeks */
void reverse_by_chunks(struct node **start, int chunk_size) {
    // `new_head` references the kth node of the group (or the last node if
    // there is no kth node), a.k.a, the new head of the reversed group.
    struct node *current = *start, *new_head = NULL, *prev_group_tail = NULL;

    while (current != NULL) {
        struct node *group_head = current;
        struct node *prev = NULL, *next = NULL;
        int count = 0; //  Keep track how many nodes we have passed.

        while (current != NULL && count < chunk_size) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // `prev` from now on means, the last node of the reversed group,
        // or the first node before reversing the group. That's why its
        // being linked to the first node of the next group.

        // Kth of the group is going to be the new head of the
        // group when we reverse it by chunks.
        if (new_head == NULL)
            new_head = prev;

        // Create the link between previous group and current group.
        // To the tail of the previous group to the head of the current group.
        if (prev_group_tail != NULL)
            prev_group_tail->next = prev;

        prev_group_tail =
            group_head; // New tail is the first one of the group before
        // reversing the chunk.
    }

    *start = new_head;
}
