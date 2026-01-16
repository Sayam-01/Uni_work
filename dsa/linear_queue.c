#include <stdio.h>
#include <stdlib.h>

struct queue{
    //array to store queue elements
    int *arr;
    //size of the array
    int size;
    //maximum number of elements a queue can hold
    int capacity;
};

//function to create the queue
struct queue* create_queue(int capacity){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->size = 0;
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

//func to check if the queue is empty
int isEmpty(struct queue* q){
    return q->size == 0;//returns 1 if true
}

//function to check if the queue is full
int isFull(struct queue* q){
    return q->size == q->capacity;//returns 1 if true
}

//func to enqueue
//enqueue adds the element at the rear
void enqueue(struct queue* q){
    if (isFull(q)){
        printf("The queue is full.\n");
        return;
    }
    int value;
    printf("Please enter the value to be inserted: ");
    scanf("%i", &value);

    q->arr[q->size] = value;
    q->size++;
}

//func to dequeue
//dequeue removes the element from the front
void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("The queue is empty.\n");
        return;
    }
    int value = q->arr[0];
    for(int i = 1; i < q->size; i++){
        q->arr[i-1] = q->arr[i];
    }
    q->size--;
    printf("%i is removed from the queue.\n", value);
}

//func to display the queue
void display(struct queue* q){
    if(isEmpty(q)){
        printf("The queue is empty.\n");
        return;
    }

    printf("The elements in queue are: ");
    for(int i = 0; i < q->size; i++){
        printf("%i ", q->arr[i]);
    }
}

int main(){
    int x;
    printf("Please enter the capacity of queue: ");
    scanf("%i",&x);

    //create the queue
    struct queue* qu = create_queue(x);

    int choice = 0;
    while(choice !=4){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%i", &choice);

        switch(choice){
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
                printf("Please enter a valid choice: ");
        }
    }

    printf("\n----By Sayam Shrestha-----\n");

    free(qu->arr);
    free(qu);
    return 0;
}