#include <stdio.h>

#define SIZE 5

int stack[SIZE], top = -1;

int isFull() {
  if(top == SIZE - 1) {
    printf("Stack Overflow!");
    return 1;
  } else {
    return 0;
  }
}

int isEmpty() {
  if(top == -1) {
    printf("Stack Underflow! or Empty!");
    return 1;
  } else {
    return 0;
  }
}

void push() {

  if(!isFull()) {

    int element;

    printf("Enter an element to push into stack: ");
    scanf("%d", &element);

    stack[++top] = element;
  }
}

void pop() {

  if(!isEmpty()) {
    printf("%d Element is popped form stack: ", stack[top--]);
  }
}

void peek() {

  if(!isEmpty()) {
    printf("%d element is at top of stack.", stack[top]);
  }

}

void display() {
  if(!isEmpty()) {
    printf("Stack:");
    for(int traversePointer = top; traversePointer > - 1; traversePointer--) {
      printf("\n[%d]", stack[traversePointer]);
      if(traversePointer == top) {
        printf(" <- top");
      }
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