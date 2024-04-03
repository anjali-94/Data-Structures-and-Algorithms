#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty() {
    if (top == -1) {
        return 1;
    }
    else
        return 0;
}

int isfull(){
    if(top == MAXSIZE) {
        return 1;
    }
    else
        return 0;
}

int peek() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1; 
    }
    return stack[top];
}

int pop() {
    int data;
    if(isempty()){
        printf("could not retrieve data, stack is empty");
    }

    else{
        data = stack[top];
        top = top-1;
        return data;
    }
}

int push(int data) {
    if(isfull()){
        printf("could not insert data, stack is full\n");
    }

    else{
        top = top+1;
        stack[top] = data;
    }

}

int main() {
    
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    
    printf("Element at top of the stack: %d\n",peek());
    /*printf("Elements before popping: ");
    for(int i = 0; i<=top;i++){
        printf("%d ",stack[i]);
    }*/

    while(!isempty()) {
        int data = pop();
        printf("\n%d ", data);
    }
    //printf("\nElement popped out: %d", pop());
    //printf("\nElement popped out: %d", pop());
    //printf("\nElement popped out: %d\n", pop());
    //printf("Elements left after popping: ");
    /*for(int i = 0; i<=top;i++){
        printf("%d ",stack[i]);
    }*/

    printf("\nStack full: %s\n", isfull()?"true":"false");
    printf("Stack empty: %s\n", isempty()?"true":"false");

    return 0;

}