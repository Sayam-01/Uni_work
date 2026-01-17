#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_node(int value){
    struct node* newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Error Allocating Size.\n");
        return NULL;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_beg(struct node** head){
    int value;
    printf("Enter value: ");
    scanf("%i", &value);

    struct node* newNode = create_node(value);
    if(newNode == NULL) return;

    newNode->next = *head;

    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insert_end(struct node** head){
    int value;
    printf("Enter value: ");
    scanf("%i", &value);

    struct node* newNode = create_node(value);
    if(newNode == NULL) return;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insert_pos(struct node** head){
    int value, pos;
    printf("Enter value: ");
    scanf("%i", &value);
    printf("Enter position: ");
    scanf("%i", &pos);

    if(pos < 1){
        printf("Invalid position.\n");
        return;
    }

    struct node* newNode = create_node(value);
    if(newNode == NULL) return;

    if(pos == 1){
        free(newNode);
        insert_beg(head);
        return;
    }

    struct node* temp = *head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position is out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void delete_beg(struct node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;

    if(*head != NULL){
        (*head)->prev = NULL;
    }

    printf("%i deleted.\n", temp->data);
    free(temp);
}

void delete_end(struct node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    if(temp->next == NULL){
        printf("%i deleted.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("%i deleted.\n", temp->data);
    free(temp);
}

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
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("Position is out of range.\n");
        return;
    }

    struct node* delNode = temp->next;
    temp->next = delNode->next;

    if(delNode->next != NULL){
        delNode->next->prev = temp;
    }

    printf("%i deleted.\n", delNode->data);
    free(delNode);
}

void display_forward(struct node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while(head != NULL){
        printf("%i -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void display_backward(struct node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    while(head->next != NULL){
        head = head->next;
    }

    printf("Backward: ");
    while(head != NULL){
        printf("%i -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice;

    while(1){
        printf("\n===== Doubly Linked List Menu =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display forward\n");
        printf("8. Display backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: insert_beg(&head); break;
            case 2: insert_end(&head); break;
            case 3: insert_pos(&head); break;
            case 4: delete_beg(&head); break;
            case 5: delete_end(&head); break;
            case 6: delete_pos(&head); break;
            case 7: display_forward(head); break;
            case 8: display_backward(head); break;
            case 9:
                printf("Exiting...\n");
                printf("----By Sayam Shrestha-----\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
