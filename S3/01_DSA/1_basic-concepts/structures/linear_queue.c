#include <stdio.h>

int lq_enqueue(int *queue, int item, int *front, int *rear, int size) {
    if (*rear == size - 1) {
        // full
        return 0;
    }

    // if the queue is empty
    if (*front == -1 && *rear == -1) {
        *front = 0;
    }

    queue[++(*rear)] = item;
    return 1;
}

int lq_dequeue(int *queue, int *item, int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        // empty
        return 0;
    }

    *item = queue[*front];
    if (*front == *rear) {
        *front = *rear = -1; // reset to empty
    } else {
        (*front)++;
    }

    return 1;
}

int lq_display(int *queue, int front, int rear) {
    if (front != -1 && front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf(" %d", queue[i]);
        }
    } else {
        return 0;
    }
    printf("\n");
    return 1;
}
