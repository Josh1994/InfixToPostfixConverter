#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct stackNode {
int data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; // Pointer to StackNode

int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main(){
  char charArray[50];
  printf("Print expression: ");
  gets(charArray);
  int answer = evaluatePostfixExpression(charArray);
  printf("The value of the expression is: %d\n", answer);
  return 0;
}

/*Evaluate the postfix expression*/
int evaluatePostfixExpression(char *expr){
  int i;
  int opp1;
  int opp2;
  int answer=0;
  StackNodePtr head = NULL;
  expr[strlen(expr)] = '\0'; // adds \0 to the end of expression
  for(i=0; i < strlen(expr); i++){
  /*Push its integer value onto the stack (the integer value of a digit character is its
    value in the computer’s character set minus the value of '0' in the computer’s
    character set). */
   if(isalnum(expr[i]) ){
      push(&head, expr[i] - '0');
      printStack(head);
    }
    /*Pop the two top elements of the stack into variables x and y. 
      Calculate y operator x.
      Push the result of the calculation onto the stack*/
    else if(expr[i] == '+' || expr[i] == '-' || expr[i]  == '*' || expr[i] == '/' || expr[i] == '%'|| expr[i] =='^'){
      opp1 = pop(&head);
      printStack(head);
      opp2 = pop(&head);
      printStack(head);
      int result = calculate(opp1, opp2, expr[i]);
      push(&head, result);
      printStack(head);
      answer = result;
    }
    /*When the null character is encountered in the expression, pop the top value of the
      stack. This is the result of the postfix expression. */
    else if(expr[i] == '\0'){
      answer = pop(&head);
      printStack(answer);
    } 
  }
  return answer;
}

/*Evaluate the expression op1 operator op2.*/
int calculate(int op1, int op2, char operator){
  if(operator == '+'){
    return (op2+op1);
  }
  else if(operator == '-'){
    return(op2-op1);
  }
  else if(operator == '*'){
    return(op2*op1);
  }
  else if(operator == '/'){
    return(op2/op1);
  }
  else if(operator == '%'){
    return(op2%op1);
  }
  else if(operator == '^'){
    int result = pow(op1, op2); // op1^op2
    return result;
  }
}

/*Push a value on the stack*/
void push(StackNodePtr *topPtr, int value){
  if (*topPtr == NULL){
  *topPtr = malloc (sizeof(StackNode)); // topPtr is derefenced because StackNodePtr *topPtr is a pointer to 
                                        // the pointer to stackNode and we want to find out the value of the pointer
                                        // to stackNode only and create a memory space in it.
  (**topPtr).data =value;
  (**topPtr).nextPtr=NULL;
  }
  else{
  StackNodePtr tmp = malloc(sizeof(StackNode));
  tmp->data = value; 
  tmp->nextPtr = *topPtr;
  *topPtr = tmp;
  }
}

/*Pop a value off the stack. */
int pop(StackNodePtr *topPtr){
  int c;
  if (*topPtr == NULL){
    printf("Stack is empty \n");
  }
  else{
    c = (*topPtr)->data;
    StackNodePtr temp = (*topPtr)->nextPtr;
    free(*topPtr);
    *topPtr = temp;
  }
  return c;
}

/*Determine if the stack is empty. */
int isEmpty(StackNodePtr topPtr){
  if (topPtr == NULL){
    return 1;
  }
  else{
    return -1;
  }
}

/*Print the stack. */
void printStack(StackNodePtr topPtr){
  StackNodePtr current;
  current = topPtr;
  if(current == NULL){
    printf("The stack is empty\n");  
  }
  else{
  while(current !=NULL){
    printf("%d\t", current->data);
    current=current->nextPtr; 
  }  
  printf("NULL \n");
  }
}