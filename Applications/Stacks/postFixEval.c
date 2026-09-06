#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define SIZE 10

char stack[SIZE], postFixExpression[SIZE];
int top = -1;

int pop() {

  if(top == -1) {
    printf("Invalid Expression!");
    exit(0);
  }

  printf("\n Stack popped %d", stack[top]);

  return stack[top--];
}

void push(int num) {

  if(top == SIZE-1) {
    printf("Memory Allocation Failed!");
    exit(0);
  }

  printf("\n Stack got pushed %d", num);

  stack[++top] = num;
}

int calculate(int first, int second, char operator)
{
  switch(operator) {
    case '+': return second + first;
    case '-': return second - first;
    case '*': return second * first;
    case '/': return second / first;
    case '%': return second % first;
    case '^': return pow(second, first);
  }
}

int isOperator(char symbol) {

  if(isdigit(symbol)) {
    return 0;
  }

  switch(symbol) {
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%': 
    case '^': return 1;
    default: 
      printf("Invalid Expression!!");
      exit(0);
  }

}

int main() {

  int i;

  printf("Enter an postFix Expression: ");
  scanf("%s", postFixExpression);

  for(i = 0; postFixExpression[i] != '\0'; i++) {

    char symbol = postFixExpression[i];
    
    if(isOperator(symbol)) {
      int rightOperand = pop();
      int leftOperand = pop();
      push(calculate(rightOperand, leftOperand, symbol));
    } else {
      push(symbol - '0');
    }
  }

  if(top != 0) {
    printf("Invalid Expression!");
  } else {
    printf("\nResult: %d", stack[top]);
  }

  return 0;
}