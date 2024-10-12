#include "../lib/singly-linked-list-int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Node *HEAD = create_node();
    HEAD->next = NULL;

    int choice;

    while (true) {
        printf("1) insert; 2) delete; 0) quit\n");
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

            printf("1) at start, 2) at end, 3) at specific position, 4) go "
                   "back\n");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                insert_node(HEAD, 0, new_node);
                break;
            case 2:
                insert_node(HEAD, -1, new_node);
                break;
            case 3: {
                int position;
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert_node(HEAD, position, new_node);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid option.\n");
                break;
            }
            break;
        }

        case 2: {
            printf("1) at start, 2) at end, 3) at specific position, 4) go "
                   "back\n");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                delete_node(HEAD, 0);
                break;
            case 2:
                delete_node(HEAD, -1);
                break;
            case 3: {
                int position;
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                delete_node(HEAD, position);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid option.\n");
                break;
            }
            break;
        }

        default:
            printf("err: unknown choice\n");
        }

        display_list(HEAD->next);
    }

    return 0;
}
