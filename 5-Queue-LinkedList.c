#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* link;
};

typedef struct node* NODE;

NODE front = NULL, rear = NULL;

NODE getNode() {
  NODE temp = NULL;

  temp = (NODE) malloc(sizeof(struct node));

  if(temp == NULL) {
    printf("Memory Allocation failed.");
    exit(0);
  }
}

int isEmpty() {
  if(front == NULL && rear == NULL) {
    return 1;
  }
  return 0;
}

void enqueue() {

  int element;
  NODE temp;

  printf("Enter an element to insert: ");
  scanf("%d", &element);

  temp = getNode();
  temp -> data = element;
  temp -> link = NULL;

  if(front == NULL && rear == NULL) {
    front = rear = temp;
  } else {
    rear -> link = temp;
    rear = temp;
  }
}

void dequeue() {

  if(!isEmpty()) {

    if(front == rear) {
      front = NULL;
      rear = NULL;
    } else {
      front = front -> link;
    }

  } else {
    printf("Queue is Empty.");
  }
}

void peek() {
  if(!isEmpty()) {
    printf("Element %d is at first position.", front->data);
  } else {
    printf("Queue is Empty.");
  }
}

void display() {
  if(!isEmpty()) {
    NODE temp = front;

    while(temp != NULL) {
      printf("%d ", temp -> data);
      temp = temp -> link;
    }
  } else {
    printf("Queue is Empty.");
  }
}

void main() {
  int choice, quit = 0;

  while(!quit) {
    printf("\n========== Choose the Operation ==========");
    printf("\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit");
    printf("\nEnter you choice: ");
    scanf("%d", &choice);

    switch (choice)
    {

      case 1: enqueue(); break;

      case 2: dequeue(); break;

      case 3: peek(); break;

      case 4: display(); break;

      case 5: 
        quit = 1;
        printf("\nProgram Execution Finished.");
        break;

      default:
        printf("\nInvalid Choice.");
        break;

    }
  }
}