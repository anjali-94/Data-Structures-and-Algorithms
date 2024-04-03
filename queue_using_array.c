#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int r;
    int f;
    int *arr;

};

int isfull(struct queue *q)
{
    if(q->r == q->size-1 && q->f == -1){
       return 1;
    }
    else{
        return 0;
        }
}

int isempty(struct queue *q)
{
    if(q->r == q->f){
       return 1;
    }
    else{
        return 0;
        }
}

void enqueue(struct queue *q, int val) {
    if(isfull(q)){
        printf("queue is full");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a=-1;
    if(isempty(q)){
        printf("queue is empty");
    }
    else{
        q->f++;
         a = q->arr[q->f];
    }
    return a;
}

void display(struct queue *q) {
    for(int i=0;i<=q->r;i++) {
        printf("Element at index %d is %d\n",i,q->arr[i]);
    }
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 2;
    q->r = q->f = -1; //empty stack
    q->arr = (int *)malloc(q->size*sizeof(int));  //dynamic memory
    if(isempty(q)) {
        printf("queue is empty\n");
    }

    //enqueue elements
    enqueue(q,12);
    enqueue(q,15);

    //dequeue elements
    printf("dequeuing element %d\n",dequeue(q));
    printf("dequeuing element %d\n",dequeue(q));


     if(isfull(q)) {
        printf("queue is full\n");
    }

    
    return 0;
}