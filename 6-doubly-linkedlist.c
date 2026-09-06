#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *previousNode;
  struct node *nextNode;
};

typedef struct node * NODE;

NODE first = NULL;

NODE getNode() {

  NODE temp = (NODE) malloc(sizeof(struct node));

  if(!temp) {
    printf("\nMemory Allocation Failed.");
    exit(0);
  }

  return temp;
}

void display() {

  NODE temporaryNode = NULL;

  if(first == NULL) {
    printf("\nList is Empty.");
  } else {
    temporaryNode = first;
    printf("\nDisplaying List Elements:\n");
    while(temporaryNode != NULL) {
      printf("%d -> ", temporaryNode -> data);
      temporaryNode = temporaryNode -> nextNode;
    }
    printf("NULL");
  }
}

void displayReverse() {

  NODE temporaryNode;

  if(first == NULL) {
    printf("\nList is Empty.");
  } else {
    temporaryNode = first;
    while(temporaryNode -> nextNode != NULL) {
      temporaryNode = temporaryNode -> nextNode;
    }

    printf("\nDisplaying List (in Reverse):\n");

    while(temporaryNode != NULL) {
      printf("%d -> ", temporaryNode-> data);
      temporaryNode = temporaryNode -> previousNode;
    }
    printf("NULL");
  }
}

void insertFront() {

  int data;

  printf("\nEnter the element to insert: ");
  scanf("%d", &data);

  NODE temporaryNode = getNode();

  temporaryNode -> data = data;
  temporaryNode -> previousNode = NULL;
  temporaryNode -> nextNode = NULL;

  if(first == NULL) {
    first = temporaryNode;
  } else {
    first -> previousNode = temporaryNode;
    temporaryNode -> nextNode = first;
    first = temporaryNode;
  }
}

void insertPosition() {

  int position, element, count = 1;
  NODE temporaryNode, currentNode, nextNode;

  printf("Enter POSITION to insert: ");
  scanf("%d", &position);

  if(position < 0) {
    printf("\nInvalid position.");
    return;
  }

  printf("Enter the ELEMENT to insert: ");
  scanf("%d", &element);

  temporaryNode = getNode();

  temporaryNode -> data = element;
  temporaryNode -> previousNode = NULL;
  temporaryNode -> nextNode = NULL;

  if(first == NULL && position == 1) {
    first = temporaryNode;
  } else if(position == 1 && first != NULL) {
    first -> previousNode = temporaryNode;
    temporaryNode -> nextNode = first;
    first = temporaryNode;
  } else {
    currentNode = first;

    while(currentNode != NULL && count < position - 1) {
      currentNode = currentNode -> nextNode;
      count++;
    }

    if(currentNode == NULL) {
      printf("\nInvalid Position(current NULL)");
      return;
    }

    nextNode = currentNode -> nextNode;
    temporaryNode -> previousNode = currentNode;
    if(nextNode != NULL) {
      temporaryNode -> nextNode = nextNode;
      nextNode -> previousNode = temporaryNode;
    }
    currentNode -> nextNode = temporaryNode;

    // printf("-------------------");
    // printf("\n%d %d %d", currentNode -> data, currentNode, currentNode -> nextNode);
    // printf("\n%d %d %d %d", temporaryNode -> data, temporaryNode -> previousNode, temporaryNode, temporaryNode -> nextNode);
    // printf("\n%d %d %d %d", nextNode -> data, nextNode -> previousNode, nextNode, nextNode -> nextNode);
  }
}

void insertEnd() {

  int data;
  NODE currentNode, temporaryNode;

  currentNode = first;

  printf("Enter the element to insert: ");
  scanf("%d", &data);

  temporaryNode = getNode();
  temporaryNode -> data = data;
  temporaryNode -> previousNode = NULL;
  temporaryNode -> nextNode = NULL;

  while(currentNode == NULL) {

  }
}

void search() {

}

void main() {
  int quit = 0, choice;

  while(!quit) {
    printf("\n\n------------------------------------------");
    printf("\nChoose an Operation on DOUBLY LINKED List:\n");
    printf(" 1. Display\n 2. Display Reverse\n 3. Insert at Front\n 4. Insert at Position\n 9. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: display(); break;
      case 2: displayReverse(); break;
      case 3: insertFront(); break;
      case 4: insertPosition(); break;
      case 9: quit = 1; break;
      default: 
        printf("\nInvalid Choice.");
    }
  }
}