#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int value){
    if(top == SIZE - 1)
    printf("Stack Overflow \n");
    else{
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}
void pop(){
    if(top == -1)
    printf("stack underflow\n");
    else{
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}
void display(){
    if(top == -1)
    printf("stack elements:");
    for(int i = top; i>=0; i--)
    printf("%d", stack[i]);
    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    return 0;

}