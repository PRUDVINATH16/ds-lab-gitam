#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char stack[SIZE], postFixExpression[SIZE], inFixExpression[SIZE];
int top = -1, postFixPointer = -1;

char peek() {
  if(top != -1) {
    return stack[top];
  } else {
    return '#';
  }
}

void stackPush(char parenthesis)
{
  stack[++top] = parenthesis;
}

char stackPop()
{
  return stack[top--];
}

void postFixPush(char symbol)
{
  postFixExpression[++postFixPointer] = symbol;
}

int priority(char operator) {
  switch(operator) {
    case '^': return 3;
    case '*':
    case '/':
    case '%': return 2;
    case '+':
    case '-': return 1;
    case '#': return 0;
    case '(': return 0;
    default: printf("Invalid Expression!"); exit(0);
  }
}

void handleOperator(char ch) {
  int presentCharPriority = priority(ch);
  int topStackCharPriority = priority(peek());

  while(topStackCharPriority >= presentCharPriority) {
    postFixPush(stackPop());
    topStackCharPriority = priority(peek());
  }
  stackPush(ch);
}

void closedParenthesis() {

  char next;

  while((next = stackPop()) != '(') {
    postFixPush(next);
  }
}

void main() {
  
  int i = 0;
  char symbol;

  printf("Enter a Infix expression: ");
  scanf("%[^\n]9s", inFixExpression);

  for(i = 0; inFixExpression[i] != '\0'; i++) {

    symbol = inFixExpression[i];

    switch(symbol) {
      case '(': stackPush(symbol); break;
      case ')': closedParenthesis(); break;
      case '+':
      case '-':
      case '/':
      case '*':
      case '%':
      case '^': handleOperator(symbol); break;
      default: postFixPush(symbol);
    }
  }

  while(top != -1) {
    postFixPush(stackPop());
  }

  printf("Infix Expression: %s\n", inFixExpression);
  printf("Postfix Expression: %s", postFixExpression);

}