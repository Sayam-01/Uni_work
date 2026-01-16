#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

//function to create linked node
struct node* create_node(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Error Allocating size\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

//function to insert at beginning
void insert_beg(struct node** head){
    int value;
    printf("Enter Value: ");
    scanf("%i", &value);

    struct node* newNode = create_node(value);
    newNode->next = *head;
    *head = newNode;
}

//function to insert at certai position
void insert_pos(struct node** head){
    int value, pos;
    printf("Enter value: ");
    scanf("%i",&value);
    printf("Enter position: ");
    scanf("%i",&pos);

    if(pos < 1){
        printf("Invalid position\n");
        return;
    }

    struct node* newNode = create_node(value);
    if(pos==1){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    //loop to go the position using temp
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//function to insert at end
void insert_end(struct node** head){
    int value;
    printf("Enter value: ");
    scanf("%i",&value);

    struct node* newNode = create_node(value);

    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

//func to delete from beginning
void delete_beg(struct node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }

    /*
    temp is used here so that we can still access
    the node after deleting it 
    this is important so that we can free that node
    this prevents memory leak 
    */
    struct node* temp = *head;
    *head = (*head)->next;
    printf("%i deleted.\n", temp->data);
    free(temp);
}

//func to delete at certain position
void delete_pos(struct node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    int pos;
    printf("Enter position: ");
    scanf("%i", &pos);

    if(pos < 1){
        printf("Invalid position.\n");
        return;
    }

    if(pos == 1){
        delete_beg(head);
        return;
    }

    struct node* temp = *head;
    for(int i = 1; i < pos -1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp->next == NULL || temp == NULL){
        printf("Position is out of range.\n");
        return;
    }

    struct node* delNode = temp->next;
    temp->next = delNode->next;
    printf("%i deleted.\n", delNode->data);
    free(delNode);
}

//func to delete at end
void delete_end(struct node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }

    if((*head)->next == NULL){
        printf("%i deleted.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    printf("%i deleted.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

//func to display list
void display(struct node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("Singly Linked List: ");
    while(head != NULL){
        printf("%i -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice;

    while (1) {
        printf("\n===== Singly Linked List Menu =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_beg(&head);
                break;
            case 2:
                insert_end(&head);
                break;
            case 3:
                insert_pos(&head);
                break;
            case 4:
                delete_beg(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                delete_pos(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("\nExiting program...\n");
                printf("----By Sayam Shrestha-----\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

