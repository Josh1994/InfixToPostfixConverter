#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

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
  char infixArray[50];  
  char postfixArray[50];
  printf("Enter the inflix expression");
  fflush(stdin);
  gets(infixArray);

  convertToPostfix(infixArray, postfixArray);
  int i;
  for (i=0;i<strlen(infixArray);i++){
    printf("%c", postfixArray[i]);
  }
  return 0;
 /* int i;
  for(i = 0; i<20;i++){
    printf("%c", postfixArray[i]);
  }*/


 /*StackNodePtr head = NULL;
  int size;
  int element = 0;
  int counter = 0;

  scanf("%d",&size);
//  int empty = isEmpty(head);
//  printf ("%d", empty);
   while(counter<size){
      printf("Enter a number to push into the stack:");
     //
      scanf("%d",&element);

      push(&head,element); //&head is used because we are passing the pointer to stackNode's value
     	
      counter++;
    }
	printStack(head);
  char i = pop(&head);
  //char i = stackTop(head);
  printStack(head);*/
}
/*Convert the infix expression to postfix notation.*/
void convertToPostfix(char infix[],char postfix[]){
  StackNodePtr head = NULL;
  int i;
  int j;
  char c;
  //(6+2)*5-8/4
  push(&head,'(');
  printf("%d\n", strlen(infix));
  infix[strlen(infix)] = ')';
/*  printf("%c", infix[0]);
  printf("%c", infix[1]);
  printf("%c\n", infix[2]);
  printf("%c\n", postfix[0]);*/
  //while (head != NULL){
    for(i=0, j=0; i<= strlen(infix); i++){
       // printf("This is the infix checker");
       // printf("%c\n", infix[i]);fflush(stdout);
        if (isalnum(infix[i])){
         //printf("Entered isalnum\n");fflush(stdout);
          postfix[j] = infix[i];
         // printf("%c\n", infix[i]);fflush(stdout);
         // printf("%c\n", postfix[j]);fflush(stdout);
          j++;
          // Working fine
        }
        else if (infix[i] == '('){
         // printf("Entered 1st else\n");fflush(stdout);
          push(&head, infix[i]);
          printStack(head);
          //working fine
        }
        else if(isOperator(infix[i])==1){
          //printf("%c\n", infix[i]);fflush(stdout);
         // printf("Entered 2st else\n");fflush(stdout);
         // printf("%d\n",isOperator(stackTop(head)));fflush(stdout);
          // printf("%c\n", stackTop(head));
         // if(isOperator(stackTop(head)) == 1 ){
            //int counter = 1;
            
            while(precedence(stackTop(head), infix[i]) == 1 || precedence(stackTop(head), infix[i]) == 0){
             // printf("Entered 2st else prePop\n");fflush(stdout);
             // printf("%c\n",stackTop(head));
             // printf("%c\n", infix[i]);
            
              postfix[j]= pop(&head);
              j++;
             
              //head->data= c;
              //printf("%c\n",stackTop(head));
             // printf("%c\n", infix[i]);
             // printf("Entered 2st else pre incriment\n");fflush(stdout);
            }
           //printf("Entered 2st else afterwhile\n");fflush(stdout);
          //}
          //else{
          //printf("Entered 2st else postLoop\n");fflush(stdout);
         // printf("%c\n", infix[i]);
          push(&head, infix[i]);
          printStack(head);
          //}
       
          /*if (head == NULL){
            push(&head, infix[i]);
          }
          else if(head->data =='(' ){
            push(&head, infix[i]);
          }
          else if (precedence(stackTop(head), infix[i]) != 1){
            push(&head, infix[i]);
          }
          else{
            postfix[j]=pop(&head);
            j++;
            push(&head,infix[i]);
          }*/
        }
        else if(infix[i] == ')'){
          //printf("Entered 3st else\n");fflush(stdout);
          
          
          while( (stackTop(head)!= '(') && isOperator(head->data) == 1){
            postfix[j] = pop (&head);
            j++;
          }
          printStack(head);
          pop(&head);
          printStack(head);
          //working fine
        }
    }
 //}
  printf("Outside");fflush(stdout);
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
void push(StackNodePtr *topPtr, char value){

  //struct stackNode temp = malloc(sizeOf(StackNode));
 if (*topPtr == NULL){
 	//StackNodePtr *p= malloc (sizeof(StackNode));
 	//topPtr = p;
  *topPtr = malloc (sizeof(StackNode)); // topPtr is derefenced because StackNodePtr *topPtr is a pointer to 
                                        // the pointer to stackNode and we want to find out the value of the pointer
                                        // to stackNode only and create a memory space in it.
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
  //StackNodePtr = StackNodePtr->topPtr; //Go back to previous head
  char c;
  if (*topPtr == NULL){
    printf("Stack is empty \n");
  }
  else{
    c = (*topPtr)->data;
    StackNodePtr temp = (*topPtr)->nextPtr;
    free(*topPtr);
    *topPtr = temp; // go back to the previous head
  }
 // printf("Hello");fflush(stdout); // Checker to see where the method breaks
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
		printf("Empty List");  
  }
  else{
	while(current !=NULL){
		printf("%c\t", current->data);
		current=current->nextPtr;	
	}  
	printf("NULL \n");
  }
   
}