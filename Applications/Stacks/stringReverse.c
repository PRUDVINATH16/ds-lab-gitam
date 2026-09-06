#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char stack[SIZE], str_word[SIZE], rev_word[SIZE];
int top = -1;

void push(char parenthesis)
{
  stack[++top] = parenthesis;
}

char pop()
{
  return stack[top--];
}

void main() {

  int i, j;

  printf("Enter a string: ");
  scanf("%[^\n]9s", &str_word);

  for(i = 0; str_word[i] != '\0'; i++) {
    push(str_word[i]);
  }

  j = 0;
  for(i = top; i > -1; i--) {
    rev_word[j] = pop();
    j++;
  }

  printf("Original String: %s\n", str_word);
  printf("Reversed String: %s", rev_word);

}