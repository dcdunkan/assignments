#include "../lib/singly-linked-list-int.h"
#include <stdbool.h>
#include <stdio.h>

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

int main() {
    struct node *HEAD = create_node();
    HEAD->next = NULL;

    int choice;

    while (true) {
        printf("1) insert; 2) reverse nodes; 0) quit\n");
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
            int chunk_size;
            printf("Enter chunk size: ");
            scanf("%d", &chunk_size);
            // reverse_list(&HEAD->next);
            reverse_by_chunks(&HEAD->next, chunk_size);
            break;
        }

        default:
            printf("err: unknown choice '%d'\n", choice);
        }

        display_list(HEAD->next);
    }

    return 0;
}
