#include <stdio.h> 
#include <stdlib.h>

struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; // this is the pointer in the list


void convertToPostfix( char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);


int main(void){
 /*) int infixArray[10];  
  int postfixArray[10];
  convertToPostfix(infixArray, postfixArray);
  printStack(StackNodePtr);
  return 0; */
  StackNodePtr head = NULL;
  int size;
  int element = 0;
  int counter = 0;
  printf("Enter the number of stack elements:");
  scanf("%d",&size);
 
  printf("--- Push elements into the linked stack ---\n");
    while(counter<size){
      printf("Enter a number to push into the stack:");
     //
      scanf("%d",&element);

      push(&head,element);
     	
      counter++;
    }
	printStack(head);
}
/*Convert the infix expression to postfix notation.*/
void convertToPostfix( char infix[], char postfix[]){

}
/*Determine if c is an operator.*/
int isOperator(char c){
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){ // c == '^' exponential is missing because no base operator for it
    return 1;
  }
  else{
    return 0;
  }
}
/*Determine if the precedence of operator1 is less than, equal to, or greater than
the precedence of operator2. The function returns -1, 0 and 1, respectively.*/
int precedence(char operator1, char operator2){
//returns 1 if operator1 precedes operator2
// retruns 0 if operator2 precedes operator1
// returns 0 if both are on equal rank
  if ((operator1 == '*' || operator1 == '/' || operator1 == '%') && (operator2 == '-' || operator2 == '+')  ){
    return 1;
  }
  else if ((operator1 == '-' || operator1 == '+') && (operator2 == '*' || operator2 == '/' || operator2 == '%') ){
    return -1;
  }
  else if (operator1 == '^' && (operator2 == '-' || operator2 == '+') ){
    return 1;
  }
  else if ((operator1 == '-' || operator1 == '+')  && operator2 == '^' ){
    return -1;
  }
  else if (operator1 == '^' && (operator2 == '*' || operator2 == '/' || operator2 == '%') ){
    return 1;
  }
  else if ((operator1 == '*' || operator1 == '/' || operator1 == '%') && operator2 == '^' ){
    return -1;
  }
  else {
    return 0;
  }
}
/*Push a value on the stack.*/
void push(StackNodePtr *topPtr, char value){

  //struct stackNode temp = malloc(sizeOf(StackNode));
 if (*topPtr == NULL){
 	//StackNodePtr *p= malloc (sizeof(StackNode));
 	//topPtr = p;
	printf("Hello");fflush(stdout);
  *topPtr = malloc (sizeof(StackNode));
  
  (**topPtr).data =value;
  (**topPtr).nextPtr=NULL;
  }
  else{
  StackNodePtr tmp = malloc(sizeof(StackNode));
  //topPtr = (struct StackNode *)malloc(sizeof(StackNode));
 // if (topPtr == NULL){printf("temp stackNode is NULL"); }
  tmp->data = value; 
  //tmp->nextPtr = malloc(sizeof(StackNode)); // temp is now connected to previous head
  tmp->nextPtr = *topPtr;
  *topPtr = tmp; // let the new temp be pointed
  }
}
/*Pop a value off the stack.*/
char pop(StackNodePtr *topPtr){
  /*struct stackNode temp = StackNodePtr;
  StackNodePtr = StackNodePtr->topPtr; //Go back to previous head
  free(temp);
  return StackNodePtr;*/
  //int i = topPtr->data;
  //topPtr = topPtr-> nextPtr; // go back to the previous head
  return 1;
}

/*Return the top value of the stack without popping the stack.*/
char stackTop(StackNodePtr topPtr){
  return topPtr->data;
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
  StackNodePtr *current;
  current = topPtr;
  if(topPtr == NULL){
		printf("Empty List");  
  }
  else{
	while(topPtr !=NULL){
		printf("%d\t", (*current)->data);
		current=(*current)->nextPtr;	
	}  
	printf("NULL \n");
  }
   
}