#include <stdio.h> 

struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; 

//Convert the infix expression to postfix notation.
void convertToPostfix( char infix[], char postfix[]);
//Determine if c is an operator.
int isOperator(char c);
//Determine if the precedence of operator1 is less than, equal to, or greater than
//the precedence of operator2. The function returns -1, 0 and 1, respectively.
int precedence(char operator1, char operator2);
//Push a value on the stack.
void push(StackNodePtr *topPtr, char value);
//Pop a value off the stack.
char pop(StackNodePtr *topPtr);
//Return the top value of the stack without popping the stack.
char stackTop(StackNodePtr topPtr);
//Determine if the stack is empty.
int isEmpty(StackNodePtr topPtr);
//Print the stack. 
void printStack(StackNodePtr topPtr);


int main(void){
  int infixArray[10];
  int 
  console.log 
  return 0;
}

void convertToPostfix( char infix[], char postfix[]){

}

int isOperator(char c){
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){ // c == '^' exponential is missing cuz no base operator for it
    return 1;
  }
  else{
    return 0;
  }
}

int precedence(char operator1, char operator2){
  //returns false if operator1 doesn't precede operator2
  if ((operator1 == '-' || operator1 == '+') && (operator2 == '*' || operator2 == '/' || operator2 == '%') ){
    return -1;
  }
  //returns true if operator2 precede operator1
  else if ((operator1 == '*' || operator1 == '/' || operator1 == '%') && (operator2 == '-' || operator2 == '+')  ){
    return 1;
  }
  // returns 0 if both operators are equal precedence
  else {
    return 0;
  }
}

void push(StackNodePtr *topPtr, char value){

}

char pop(StackNodePtr *topPtr){

}

char stackTop(StackNodePtr topPtr){

}

int isEmpty(StackNodePtr topPtr){

}

void printStack(StackNodePtr topPtr){

}