#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *nextLink;
};

typedef struct node NODE;

NODE *getNode()
{
  NODE *temp = (NODE *)malloc(sizeof(NODE));

  if (temp == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }

  return temp;
}

void display(NODE *first)
{
  NODE *temp = first;
  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is Empty.");
    printf("\n--------------------------------\n");
  }
  else
  {
    printf("\n--------------------------------\n");
    while (temp != NULL)
    {
      // printf("Temp: %d, Temp(Next): %d", temp, temp -> nextLink);
      printf("%d -> ", temp->data);
      temp = temp->nextLink;
    }
    printf("NULL");
    printf("\n--------------------------------\n");
  }
}

NODE *insertAtBeginning(NODE *first)
{
  // printf("%d", first);
  int element;
  NODE *temp;

  printf("Enter an element to insert: ");
  scanf("%d", &element);

  if (first == NULL)
  {
    first = getNode();
    first->data = element;
    first->nextLink = NULL;
  }
  else
  {
    temp = getNode();
    temp->data = element;

    temp->nextLink = first;
    // printf("\nFirst Before: %d\n", first);
    // printf("\nTemp Next Link: %d\n", temp->nextLink);
    first = temp;
    // printf("\nFirst After: %d\n", first);

    // free(temp);
  }
  printf("\n--------------------------------\n");
  printf("\n%d inserted at beginning of List.\n", element);
  printf("\n--------------------------------\n");
  return first;
}

NODE *insertAtPosition(NODE *first)
{
  int position, element, count = 1;
  NODE *temp, *current;

  printf("\nEnter the position where you want to insert the node: ");
  scanf("%d", &position);

  if (position < 1)
  {
    return first;
  }

  if (position == 1)
  {
    first = insertAtBeginning(first);
    return first;
  }
  else
  {
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);

    temp = getNode();
    current = first;

    temp->data = element;
    temp->nextLink = NULL;

    while (current != NULL && count < position - 1)
    {
      current = current->nextLink;
      count++;
    }

    if (current == NULL && position > count)
    {
      printf("\n--------------------------------\n");
      printf("Invalid position to insert.");
      printf("\n--------------------------------\n");
      return first;
    }

    temp->nextLink = current->nextLink;
    current->nextLink = temp;

    printf("\n--------------------------------\n");
    printf("%d inserted at position %d successfully.", element, position);
    printf("\n--------------------------------\n");
    return first;
  }
}

NODE *insertAtEnd(NODE *first)
{
  int element;
  NODE *temp, *current;

  printf("Enter an element to insert: ");
  scanf("%d", &element);

  if (first == NULL)
  {
    first = getNode();
    first->data = element;
    first->nextLink = NULL;
  }
  else
  {
    temp = getNode();
    temp->data = element;
    current = first;

    while (current->nextLink != NULL)
    {
      current = current->nextLink;
    }

    current->nextLink = temp;
    temp->nextLink = NULL;
  }
  printf("\n--------------------------------\n");
  printf("\n%d inserted at end of List.\n", element);
  printf("\n--------------------------------\n");
  return first;
}

NODE *deleteAtBeginning(NODE *first)
{
  int element;
  NODE *temp = first;

  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is Empty.");
    printf("\n--------------------------------\n");
    return first;
  }

  element = first->data;
  first = first->nextLink;
  free(temp);
  printf("\n--------------------------------\n");
  printf("Element %d at first position is deleted successfully.", element);
  printf("\n--------------------------------\n");

  return first;
}

NODE *deleteAtPosition(NODE *first)
{
  int position, element, counter = 1;
  NODE *previous = NULL, *current = first;

  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is Empty.");
    printf("\n--------------------------------\n");
    return first;
  }

  printf("Enter the position to delete: ");
  scanf("%d", &position);

  if (position == 1)
  {
    element = first->data;
    first = first->nextLink;
    free(current);
  }
  else
  {

    while (current->nextLink != NULL && counter < position)
    {
      previous = current;
      current = current->nextLink;
      counter++;
    }

    if (position > counter)
    {
      printf("\n--------------------------------\n");
      printf("Invalid position.");
      printf("\n--------------------------------\n");

      return first;
    }

    if (current->nextLink == NULL && counter == position)
    {
      element = current->data;
      previous->nextLink = NULL;
    }
    else
    {
      element = current->data;
      previous->nextLink = current->nextLink;
    }
    free(current);
  }

  printf("\n--------------------------------\n");
  printf("%d at position %d is deleted succesfully.", element, position);
  printf("\n--------------------------------\n");

  return first;
}

NODE *deleteAtEnd(NODE *first)
{
  NODE *current = first, *temp;
  int element;

  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is Empty.");
    printf("\n--------------------------------\n");
    return first;
  }

  if (current->nextLink == NULL)
  {
    element = current->data;
    first = NULL;
    printf("\n--------------------------------\n");
    printf("The only element %d is deleted successfully.", element);
    printf("\n--------------------------------\n");

    free(current);

    return first;
  }

  while (current->nextLink->nextLink != NULL)
  {
    current = current->nextLink;
  }

  temp = current->nextLink;
  element = current->nextLink->data;
  current->nextLink = NULL;
  free(temp);

  printf("\n--------------------------------\n");
  printf("Element %d at last position is deleted successfully.", element);
  printf("\n--------------------------------\n");

  return first;
}

int searchElement(NODE *first)
{

  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is empty.");
    printf("\n--------------------------------\n");
    return 0;
  }

  int target, count = 1;
  NODE *current = first;

  printf("Enter an element to search: ");
  scanf("%d", &target);

  while (current != NULL)
  {

    if (current->data == target)
    {
      printf("\n--------------------------------\n");
      printf("Element %d found at position %d", target, count);
      printf("\n--------------------------------\n");
      return 0;
    }

    count++;
    current = current->nextLink;
  }

  printf("\n--------------------------------\n");
  printf("Element %d not found in the list.", target);
  printf("\n--------------------------------\n");

  return 0;
}

int findLength(NODE *first)
{
  int count = 0;

  while (first != NULL)
  {
    first = first->nextLink;
    count++;
  }

  return count;
}

NODE *sortList(NODE *first)
{

  if (first == NULL)
  {
    printf("\n--------------------------------\n");
    printf("List is empty.");
    printf("\n--------------------------------\n");

    return first;
  }

  int length = findLength(first), dataTemp, outterLoopLength, innerLoopLength;
  NODE *temp;

  // printf("length: %d", length);
  outterLoopLength = length;
  while (outterLoopLength)
  {

    temp = first;
    innerLoopLength = outterLoopLength - 1;

    // printf("temp: %d, tempNextLInk: %d, first: %d", temp, temp->nextLink, first);

    while (innerLoopLength)
    {
      // printf("\ntempData: %d, tempNextdata: %d.\n", temp->data, temp->nextLink->data);

      if (temp->data > temp->nextLink->data)
      {
        dataTemp = temp->data;
        temp->data = temp->nextLink->data;
        temp->nextLink->data = dataTemp;
      }

      temp = temp->nextLink;
      innerLoopLength--;
      printf("Inner: %d, Outter: %d", innerLoopLength, outterLoopLength);
    }


    printf("Inner: %d, Outter: %d", innerLoopLength, outterLoopLength);
    outterLoopLength--;
  }

  printf("\n--------------------------------\n");
  printf("List is sorted!");
  display(first);

  return first;
}

void main()
{

  NODE *first = NULL;
  int quit = 1, choice;

  while (quit)
  {
    printf("\n ===========  CHOOSE AN OPERAION  ===========");
    printf("\n 1. Display\n 2. Insert at Beginning\n 3. Insert at Position\n 4. Insert at End\n 5. Delete at Beginning\n 6. Delete at Position\n 7. Delete at End\n 8. Search\n 9. Sort\n 10. Exit\n Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      display(first);
      break;
    case 2:
      first = insertAtBeginning(first);
      break;
    case 3:
      first = insertAtPosition(first);
      break;
    case 4:
      first = insertAtEnd(first);
      break;
    case 5:
      first = deleteAtBeginning(first);
      break;
    case 6:
      first = deleteAtPosition(first);
      break;
    case 7:
      first = deleteAtEnd(first);
      break;
    case 8:
      searchElement(first);
      break;
    case 9:
      first = sortList(first);
      break;
    case 10:
      exit(0);
    default:
      printf("\n Invalid choice, try Again...\n");
    }
  }
}