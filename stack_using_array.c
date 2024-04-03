#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr; //integer pointer by help of which we allocate dynamic memory
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1) {
        return 1;
    }
    else{
        return 0;
    }
}

int isFULL(struct stack *ptr){
    if(ptr->top == ptr->size-1) {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int value){
    if(isFULL(ptr)) {
        printf("Stack Overflow, cannot push %d to the stack\n",value);
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top] = value;
    }

}

int pop(struct stack *ptr){
    if(isEmpty(ptr)) {
        printf("Stack Overflow,,cannot pop from the stack\n");
        return -1;
    }
    else{
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
    }
}

int peek(struct stack *ptr, int i){
    int arrayInd = ptr->top -i +1;
    if(arrayInd <0) {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int stackTop(struct stack *s){
    return s->arr[s->top];
}
int stackBottom(struct stack *s){
    return s->arr[0];
}

int main() {
    //struct stack s;
    //s.size = 80;
    //s.top = -1;
    //s.arr = (int *)malloc(s.size*sizeof(int));

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1; //empty stack
    s->arr = (int *)malloc(s->size*sizeof(int)); //dynamic memory
    //printf(" before pushing,, EMPTY: %d\n",isEmpty(s)); 
    //printf(" before pushing ,,FULL:%d\n",isFULL(s));
    push(s,6);
    push(s,5);
    push(s,1);
    push(s,2);
    push(s,7);
    push(s,16);
    push(s,15);
    push(s,13);
    push(s,23);
    push(s,73);
    push(s,37);
   
   // printf("after pushing,, EMPTY:%d\n",isEmpty(s)); 
    //printf("after pushing,, FULL:%d\n",isFULL(s)); 

   // printf("popped %d from the stack\n",pop(s)); //last in first out

   for(int i = 1;i<= s->top-1;i++) {
    printf("the value at position %d is %d\n",i,peek(s,i));
   }
    //printf("the topmost element of a stack is %d\n",stackTop(s));
    //printf("the most bottom element of a stack is %d\n",stackBottom(s));

    return 0;

}


