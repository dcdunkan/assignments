#include <stdio.h>

int main() {
    int size;
    printf("enter the size of the queue: ");
    scanf("%d", &size);

    int queue[size];
    int front = -1, rear = -1;

    int choice = 0;
    do {
        printf("choose an operation\n");
        printf("[1: enqueue, 2: dequeue, 3: quit]: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int item;
            printf("enter the item to enqueue: ");
            scanf("%d", &item);
            enqueue(queue, item, &front, &rear, size);
            break;
        }
        case 2: {
            int item;
            dequeue(queue, &item, &front, &rear);
            printf("dequeued %d\n", item);
            break;
        }
        case 3: {
            return 0;
        }
        default:
            printf("unknown option: %d\n", choice);
            return 0;
        }

        display(queue, front, rear);
    } while (choice != 3);

    return 0;
}
