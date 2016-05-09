#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; // Pointer to StackNode

int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main(){
  return 0;
}

/*Evaluate the postfix expression*/
int evaluatePostfixExpression(char *expr){

}

/*Evaluate the expression op1 operator op2.*/
int calculate(int op1, int op2, char operator){
  if(operator == '+'){
    return (op1+op2);
  }
  else if(operator == '-'){
    return(op1-op2);
  }
  else if(operator == '*'){
    return(op1*op2);
  }
  else if(operator == '/'){
    return(op1/op2);
  }
  else if(operator == '%'){
    return(op1%op2);
  }
  else if(operator == '^'){
    int result = pow(op1, op2); // op1^op2
    return result;
  }
}

/*Push a value on the stack*/
void push(StackNodePtr *topPtr, char value){
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
char pop(StackNodePtr *topPtr){
  char c;
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
    printf("%c\t", current->data);
    current=current->nextPtr; 
  }  
  printf("NULL \n");
  }
}