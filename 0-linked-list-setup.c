#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

typedef struct node NODE;

NODE* getNode() {
  NODE *temp = (NODE*) malloc(sizeof(NODE));
  return temp;
}

void display(NODE *first) {
  
}

NODE *insertAtBeginning(NODE *first) {
  
}

NODE *insertAtPosition(NODE *first) {
  
}

NODE *insertAtEnd(NODE *first) {
  
}

void deleteAtBeginning(NODE *first) {
  
}

void deleteAtPosition(NODE *first) {
  
}

void deleteAtEnd(NODE *first) {
  
}

void sortList(NODE *first) {

}

void searchElement(NODE *first) {

}


void main() {

  NODE *first = NULL;
  int quit = 1, choice;


  while(quit) {
    printf("\n ===========  CHOOSE AN OPERAION  ===========");
    printf("\n 1. Display\n 2. Insert at Beggining\n 3. Insert at Position\n 4. Insert at End\n 5. Delete at Beggining\n 6. Delete at Position\n 7. Delete at End\n 8. Search\n 9. Sort\n 10. Exit\n Your Choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: display(first); break;
      case 2: insertAtBeginning(first); break;
      case 3: insertAtPosition(first); break;
      case 4: insertAtEnd(first); break;
      case 5: deleteAtBeginning(first); break;
      case 6: deleteAtPosition(first); break;
      case 7: deleteAtEnd(first); break;
      case 8: sortList(first); break;
      case 9: searchElement(first); break;
      case 10: exit(0);
      default: printf("\n Invalid choice, try Again...\n");
    }
  }
}