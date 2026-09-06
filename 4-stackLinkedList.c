#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

typedef struct node* NODE;

NODE top = NULL;

NODE getNode() {

  NODE temp = (NODE) malloc(sizeof(struct node));

  if(temp == NULL) {
    printf("Memory Allocation failed!");
  }

  return temp;
}

int isFull() {
  return 0;
}

int isEmpty() {
  if(top == NULL) {
    printf("Stack Underflow! or Empty!");
    return 1;
  } else {
    return 0;
  }
}

void push() {

  int element;

  NODE temp = getNode();

  if(temp == NULL) {
    printf("Stack Overflow!");
  }

  printf("Enter an element to push into stack: ");
  scanf("%d", &element);

  temp -> link = top;
  temp -> data = element;

  top = temp;

}

void pop() {

  if(!isEmpty()) {
    printf("%d Element is popped form stack: ", top->data);
    top = top -> link;
  }
}

void peek() {

  if(!isEmpty()) {
    printf("%d element is at top of stack.", top->data);
  }

}

void display() {
  if(!isEmpty()) {
    printf("Stack:");

    NODE current = top;

    while(current != NULL) {
      printf("\n[%d]", current -> data);
      if(current == top) {
        printf("<- top");
      }
      current = current -> link;
    }
  }
}

void main() {

  int choice, quit = 0;

  while(!quit) {
    printf("\n\n---------- Enter your choice ----------\n");
    printf(" 1. Push\n 2. Pop \n 3. Peek \n 4. Display\n 5. Exit");
    printf("\n Option Number: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1 : push(); break;
      case 2 : pop(); break;
      case 3 : peek(); break;
      case 4 : display(); break;
      case 5 : quit = 1; break;
      default: printf("Invalid Input!!");
    }
  }

}