#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
};

// create circular queue
struct queue* create_queue(int capacity) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

// check if empty
int isEmpty(struct queue* q) {
    return q->size == 0;
}

// check if full
int isFull(struct queue* q) {
    return q->size == q->capacity;
}

// enqueue operation
void enqueue(struct queue* q) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }

    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;

    printf("%d inserted into queue.\n", value);
}

// dequeue operation
void dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    printf("%d removed from queue.\n", value);
}

// display queue
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int index = q->front;

    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[index]);
        index = (index + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int cap;
    printf("Enter capacity of queue: ");
    scanf("%d", &cap);

    struct queue* qu = create_queue(cap);

    int choice = 0;
    while (choice != 4) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(qu);
                break;
            case 2:
                dequeue(qu);
                break;
            case 3:
                display(qu);
                break;
            case 4:
                printf("EXITING QUEUE OPERATIONS\n");
                break;
            default:
                printf("Please enter a valid choice:");
        }
    }

    free(qu->arr);
    free(qu);

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}
