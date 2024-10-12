#include "../lib/singly-linked-list-int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// a_prev and b_prev is expected to be the immediately previous nodes
// of a and b, the nodes to be swapped.
void swap_nodes(struct Node *a_prev, struct Node *b_prev) {
    struct Node *a = a_prev->next, *a_next = a->next, *b = b_prev->next,
                *b_next = b->next;
    printf("\n%d %d\n", a->data, b->data);
    // a_prev->next = b;
    // b_prev->next = a;
    // a->next = b_next;
    // b->next = a_next;
}

void swap_nodes_at_position(struct Node *start, int x, int y) {
    swap_nodes(get_node_at_position(start, x), get_node_at_position(start, y));
}

int main() {
    struct Node *HEAD = create_node();
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
            struct Node *new_node = create_node();
            new_node->next = NULL;     // set it as the end.
            input_node_data(new_node); // populate the data
            insert_node(HEAD, -1, new_node);
            break;
        }

        case 2: {
            swap_nodes_at_position(HEAD, 0, 1);
            break;
        }

        default:
            printf("err: unknown choice\n");
        }

        display_list(HEAD->next);
    }

    return 0;
}
