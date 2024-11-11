#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

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
    struct node *temp = start;
    do {
        struct node *deleted = temp;
        temp = temp->next;
        free(deleted);
    } while (start != temp);
}

void display_list(struct node *start) {
    if (start == NULL) {
        printf("(The list is empty)");
        return;
    }
    struct node *temp = start;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

int get_length(struct node *start) {
    if (start == NULL) {
        return 0;
    }
    int length = 0;
    struct node *temp = start;
    do {
        length++;
        temp = temp->next;
    } while (temp != start);
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
    if (temp == NULL) {
        return;
    }

    struct node *after = temp->next;
    temp->next = node;
    if (after != NULL) {
        node->next = after;
    } else {
        node->next = temp;
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

int main() {
    struct node *HEAD = create_node();
    HEAD->next = HEAD;

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
            struct node *new_node = create_node();
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
