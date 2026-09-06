#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isFull() {
  if(rear == MAX - 1) {
    return 1;
  }
  return 0;
}

int isEmpty() {
  if(rear == -1 && front == -1) {
    return 1;
  }
  return 0;
}

void enqueue() {

  int element;

  if(!isFull()) {
    printf("\nEnter an element to insert: ");
    scanf("%d", &element);

    if(front == -1) {
      front++;
    }

    queue[++rear] = element;
  } else {
    printf("\nQueue is Full.");
  }

}

void dequeue() {

  if(!isEmpty()) {
    printf("%d Element is removed from the Queue.", queue[front++]);

    if(front > rear) {
      front = rear = -1;
    }

  } else {
    printf("Queue is Empty.");
  }
}

void peek() {
  if(!isEmpty()) {
    printf("%d Element is at front of the Queue.", queue[front]);
  } else {
    printf("\nQueue is Empty.");
  }
}

void display() {
  int i;

  if(!isEmpty()) {
    for(i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  } else {
    printf("\nQueue is Empty.");
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