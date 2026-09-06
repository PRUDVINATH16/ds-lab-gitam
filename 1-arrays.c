#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int checkIsArrayFull(int length)
{

  if (length >= 99)
  {
    printf("\n--------------------------------\n");
    printf("Array is full, First delete some elemens.");
    printf("\n--------------------------------\n");

    return 0;
  }

  return 1;
}
 
int checkIsArrayEmpty(int length) {
  if(length == 0) {
    printf("\n--------------------------------\n");
    printf("Array is empty");
    printf("\n--------------------------------\n");
    return 1;
  } 
  return 0;
}

int display(int array[], int length)
{

  if (length == 0)
  {
    printf("\n--------------------------------\n");
    printf("Array is empty.");
    printf("\n--------------------------------\n");

    return 0;
  }

  printf("\n--------------------------------\n");
  printf("Displaying array elements:\n");
  printf("[");
  for (int i = 0; i < length; i++)
  {
    printf(" %d,", array[i]);
  }
  printf("]");
  printf("\n--------------------------------\n");
}

int insertAtBeginning(int array[], int length)
{

  int isArrayFull;

  isArrayFull = checkIsArrayFull(length);
  if (!isArrayFull)
    return length;

  int element, temp;
  printf("\nEnter an element to insert: ");
  scanf("%d", &element);

  if (length == 0)
  {
    array[0] = element;
  }
  else
  {
    for (int i = length; i > 0; i--)
    {
      array[i] = array[i - 1];
    }
    array[0] = element;
  }

  printf("\n--------------------------------\n");
  printf("%d successfully inserted at postion 1.", element);
  printf("\n--------------------------------\n");

  return length + 1;
}

int insertAtPosition(int array[], int length)
{
  int isArrayFull = checkIsArrayFull(length), position, element;

  if (!isArrayFull)
    return length;

  printf("\nEnter the position you want to insert: ");
  scanf("%d", &position);

  // printf("pos: %d, len: %d, pos > len: %d", position, length, position > length + 1);
  if (position > length + 1)
  {
    printf("Invalid position, Array is just %d", length);
    return length;
  }

  if(position < 1) {
    printf("\n--------------------------------\n");
    printf("Inserting at this Position is not possible.");
    printf("\n--------------------------------\n");
    return length;
  }

  printf("\nEnter an element to insert: ");
  scanf("%d", &element);

  if (position == length + 1)
  {
    array[length] = element;
  }
  else
  {
    for (int i = length; i >= position; i--)
    {
      printf("i: %d, value: %d", i, array[i]);
      array[i] = array[i - 1];
    }

    array[position-1] = element;
  }

  printf("\n--------------------------------\n");
  printf("Element %d sucessfully inserted at position %d.", element, position);
  printf("\n--------------------------------\n");

  return length + 1;
}

int insertAtEnd(int array[], int length)
{
  int element;

  int isArrayFull = checkIsArrayFull(length);
  if(!isArrayFull) return length;

  printf("Enter an element to insert: ");
  scanf("%d", &element);

  array[length] = element;

  printf("\n--------------------------------\n");
  printf("Element %d successfully inserted at end of the Array.", element);
  printf("\n--------------------------------\n");

  return length + 1;
}

int deleteAtBeginning(int array[], int length)
{
  int isArrayEmpty = checkIsArrayEmpty(length), element;
  if(isArrayEmpty) return length;

  element = array[0];
  
  for(int i = 0; i < length; i++) {
    array[i] = array[i+1];
  }

  printf("\n--------------------------------\n");
  printf("Element %d is succesfully deleted from Beginning of the Array.", element);
  printf("\n--------------------------------\n");

  return length - 1;
}

int deleteAtPosition(int array[], int length)
{
  int isArrayEmpty = checkIsArrayEmpty(length);
  if(isArrayEmpty) return length;

  int position;
  printf("Enter the position you want to delete: ");
  scanf("%d", &position);

  if(position < 1 || position > length) {
    printf("\n--------------------------------\n");
    printf("Deletion at possible at this position.");
    printf("\n--------------------------------\n");

    return length;
  }

  printf("\n--------------------------------\n");
  printf("Element %d at position %d is deleted.", array[position-1], position);
  printf("\n--------------------------------\n");

  for(int i = position; i < length; i++) {
    array[i-1] = array[i];
  }

  return length -1;

}

int deleteAtEnd(int array[], int length)
{
  int isArrayEmpty = checkIsArrayEmpty(length);
  if(isArrayEmpty) return length;

  printf("\n--------------------------------\n");
  printf("Element %d successfully deleted from end of array.", array[length-1]);
  printf("\n--------------------------------\n");

  return length - 1;
}

int sortList(int array[], int length)
{
  int isArrayEmpty = checkIsArrayEmpty(length), temp;
  if(isArrayEmpty) return length;

  for(int i = length; i > 0; i--) {
    for(int j = 0; j < i-1; j++) {
      if(array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  printf("\n--------------------------------\n");
  printf("Array list is sorted:");
  display(array, length);
}

int searchElement(int array[], int length)
{
  int isArrayEmpty = checkIsArrayEmpty(length), target;
  if(isArrayEmpty) return length;

  printf("Enter the element you want to search: ");
  scanf("%d", &target);

  for(int i = 0; i < length; i++) {
    if(array[i] == target) {
      printf("\n--------------------------------\n");
      printf("Element found at position %d.", i+1);
      printf("\n--------------------------------\n");
      return 0;
    }
  }

  printf("\n--------------------------------\n");
  printf("Element not found in the array.");
  printf("\n--------------------------------\n");
}

void main()
{

  int quit = 1, length = 0, choice, array[SIZE];

  while (quit)
  {
    printf("\n ===========  CHOOSE AN OPERATION  ===========");
    printf("\n 1. Display\n 2. Insert at Beggining\n 3. Insert at Position\n 4. Insert at End\n 5. Delete at Beggining\n 6. Delete at Position\n 7. Delete at End\n 8. Sort\n 9. Search\n 10. Exit\n Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      display(array, length);
      break;
    case 2:
      length = insertAtBeginning(array, length);
      break;
    case 3:
      length = insertAtPosition(array, length);
      break;
    case 4:
      length = insertAtEnd(array, length);
      break;
    case 5:
      length = deleteAtBeginning(array, length);
      break;
    case 6:
      length = deleteAtPosition(array, length);
      break;
    case 7:
      length = deleteAtEnd(array, length);
      break;
    case 8:
      sortList(array, length);
      break;
    case 9:
      searchElement(array, length);
      break;
    case 10:
      exit(0);
    default:
      printf("\n Invalid choice, try Again...\n");
    }
  }
}