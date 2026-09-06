#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char stack[SIZE], expression[SIZE];
int top = -1;

void push(char parenthesis)
{
  stack[++top] = parenthesis;
}

char pop()
{
  return stack[top--];
}

int isMatched(char currentParen, char poppedParen)
{
  if (currentParen == ')' && poppedParen == '(')
  {
    return 1;
  }
  else if (currentParen == '}' && poppedParen == '{')
  {
    return 1;
  }
  else if (currentParen == ']' && poppedParen == '[')
  {
    return 1;
  }

  return 0;
}

void main()
{

  char poppedParen;
  int i;

  printf("Enter the parenthesis expression: ");
  scanf("%9s", expression);

  for (i = 0; expression[i] != '\0'; i++)
  {
    if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
    {
      push(expression[i]);
    }
    else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
    {

      poppedParen = pop();
      if (!isMatched(expression[i], poppedParen))
      {

        printf("!! Unbalanced Expression");
        exit(0);
      }
    }
    else
    {
      printf("Invalid Charcter. %d, %c", expression[i], expression[i]);
    }
  }

  if (top == -1)
  {
    printf("Balanced Expression.");
  }
  else
  {
    printf("!! Unbalanced Expression");
  }
}
