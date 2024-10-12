#include <stdio.h>

#define SIZE 5

int enqueue(int *queue, int item, int *front, int *rear, int size) {
    // the queue is full
    if ((*rear + 1) % size == *front) {
        printf("Queue is full!\n");
        return 0;
    }

    // if the queue is empty
    if (*front == -1 && *rear == -1) {
        *front = *rear = 0;
    } else {
        *rear = (*rear + 1) % size;
    }

    queue[*rear] = item;
    return 1;
}

int dequeue(int *queue, int *item, int *front, int *rear, int size) {
    if (*front == -1 && *rear == -1) {
        printf("Nothing left to be dequeued\n");
        return 0;
    }

    *item = queue[*front];

    if (*front == *rear) {
        *front = *rear = -1; // reset to empty
    } else {
        *front = (*front + 1) % size;
    }

    return 1;
}

void display(int *queue, int front, int rear, int size) {
    if (front != -1 && rear != -1) {
        int i = front;
        while (i != rear) {
            printf(" %d", queue[i]);
            i = (i + 1) % size;
        }
        printf(" %d", queue[rear]);
    } else {
        printf(" (empty)");
    }
    printf("\n");
}

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
            dequeue(queue, &item, &front, &rear, size);
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

        display(queue, front, rear, size);
    } while (choice != 3);

    return 0;
}
