#include "../lib/singly-linked-list-int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// a_prev and b_prev is expected to be the immediately previous nodes
// of a and b, the nodes to be swapped.
void swap_nodes(struct node *start, struct Node *a_prev, struct Node *b_prev) {
    struct node *a = a_prev->next, *a_next = a->next, *b = b_prev->next,
                *b_next = b->next;
    if (a == NULL || b == NULL)
        return;

    if (a_prev != NULL)
        a_prev->next = b;
    else
        *start = *b;

    if (b_prev != NULL)
        b_prev->next = a;
    else
        *start = *a;

    struct node *temp = b->next;
    b->next = a->next;
    a->next = temp;
}

void swap_nodes_at_position(struct node *start, int x, int y) {
    if (x == y)
        return;
    swap_nodes(start, get_node_at_position(start, x),
               get_node_at_position(start, y));
}

int main() {
    struct node *HEAD = create_node();
    HEAD->next = NULL;

    int choice;

    while (true) {
        printf("1) insert; 2) swap nodes; 0) quit\n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Freeing the linked list from the memory\n");
            free_nodes(HEAD);
            printf("Exited successfully\n");
            return 0;
        }

        switch (choice) {
        case 1: {
            struct node *new_node = create_node();
            new_node->next = NULL;     // set it as the end.
            input_node_data(new_node); // populate the data
            insert_node(HEAD, -1, new_node);
            break;
        }

        case 2: {
            int x, y;
            printf("Enter two indices to be swapped: ");
            scanf("%d %d", &x, &y);
            int length = get_length(HEAD);
            if (x >= 0 && x < length && y >= 0 && y < length)
                swap_nodes_at_position(HEAD, x, y);
            else
                printf("error: Invalid indices specified.\n");
            break;
        }

        default:
            printf("err: unknown choice\n");
        }

        display_list(HEAD->next);
    }

    return 0;
}
