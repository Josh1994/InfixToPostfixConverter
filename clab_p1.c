#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; // Pointer to StackNode


void convertToPostfix( char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);


int main(void){
  char infixArray[50];  
  char postfixArray[50];
  char name;
  printf("Enter the inflix expression: ");
  fflush(stdin);
  gets(infixArray);
  printf("The original expression is: ");
  printf("%s\n",infixArray);
  convertToPostfix(infixArray, postfixArray);
  printf("Here is the expression in postfix: \n");
  int i;
  for (i=0;i<strlen(infixArray);i++){
    printf("%c", postfixArray[i]);
  }
  return 0;
 
}
/*Convert the infix expression to postfix notation.*/
void convertToPostfix(char infix[],char postfix[]){
  StackNodePtr head = NULL;
  int i;
  int j;
  push(&head,'(');
  printf("%d\n", strlen(infix));
  infix[strlen(infix)] = ')';
  for(i=0, j=0; i<= strlen(infix); i++){
    if (isalnum(infix[i])){
      postfix[j] = infix[i];
      j++;
    }
    else if (infix[i] == '('){
      push(&head, infix[i]);
      printStack(head);
    }
    else if(isOperator(infix[i])==1){
      while(precedence(stackTop(head), infix[i]) == 1 || precedence(stackTop(head), infix[i]) == 0){
        postfix[j]= pop(&head);
        j++;
      }
      push(&head, infix[i]);
      printStack(head);
    }
    else if(infix[i] == ')'){
      while( (stackTop(head)!= '(') && isOperator(head->data) == 1){
        postfix[j] = pop (&head);
        j++;
      }
      printStack(head);
      pop(&head);
      printStack(head);
    }
  }
}
/*Determine if c is an operator.*/
int isOperator(char c){

  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'|| c=='^'){ // c == '^' exponential is missing because no base operator for it
    return 1;
  }
  else{
    return -1;
  }
}
/*Determine if the precedence of operator1 is less than, equal to, or greater than
the precedence of operator2. The function returns -1, 0 and 1, respectively.*/
int precedence(char operator1, char operator2){
//returns 1 if operator1 precedes operator2
// retruns -1 if operator2 precedes operator1
// returns 0 if both are on equal rank
  if ((operator1 == '*' || operator1 == '/' || operator1 == '%') && (operator2 == '-' || operator2 == '+')  ){
    return 1;
  }
  else if ((operator1 == '-' || operator1 == '+') && (operator2 == '-' || operator2 == '+') ){
    return 0;
  }
  else if (operator1 == '^' && (operator2 == '-' || operator2 == '+') ){
    return 1;
  }
  else if ((operator1 == '^')  && operator2 == '^' ){
    return 0;
  }
  else if (operator1 == '^' && (operator2 == '*' || operator2 == '/' || operator2 == '%') ){
    return 1;
  }
  else if ((operator1 == '*' || operator1 == '/' || operator1 == '%') && (operator2 == '*' || operator2== '/' || operator2 == '%')){
    return 0;
  }
  else {
    return -1;
  }
}
/*Push a value on the stack.*/
void push(StackNodePtr *topPtr, char value){ //*topPtr is pointer to pointer to stackNode
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
/*Pop a value off the stack.*/
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

/*Return the top value of the stack without popping the stack.*/
char stackTop(StackNodePtr topPtr){
  char top = topPtr->data;
  return top;
}
/*Determine if the stack is empty.*/
int isEmpty(StackNodePtr topPtr){
  if (topPtr == NULL){
    return 1;
  }
  else{
    return -1;
  }
}
/*Print the stack*/
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