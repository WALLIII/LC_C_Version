#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef struct {
    int *data;
    int front;
    int tail;
    int len;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *p = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    p->data = (int*)malloc(sizeof(int)*(k));
    p->front = -1;
    p->tail = -1;
    p->len = k;
    return p;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // 队列为空是头尾指针都指向-1，这是队列判空的唯一条件
    if(obj->front == -1 && obj->tail ==-1){
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // 当队列满的时候，尾指针再加1就会和头指针一样
    // 再考虑到尾指针再加一可能会从超过len，所以对len取余后再跟头指针比较
    if((obj->tail + 1) % obj->len == obj->front){
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    // 如果队列为空，那需要把头尾指针都从-1的位置搬到数组中
    if(myCircularQueueIsEmpty(obj)){
        obj->front++;
    }
    obj->tail = (obj->tail+1) % (obj->len);
    obj->data[obj->tail] = value;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    // 如果只剩下一个元素，那么出队后需要把头尾指针都退回到-1
    if(obj->front == obj->tail && obj->front != -1){
        obj->front = -1;
        obj->tail = -1;
    }
    else{
        obj->front = (obj->front+1) % obj->len;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return (obj->data[obj->front]);
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return (obj->data[obj->tail]);
}


int main(){
    MyCircularQueue *que = myCircularQueueCreate(3);
    if(myCircularQueueIsEmpty(que)){
        printf("circule is empty\n");
    }
    bool isSuccess = myCircularQueueEnQueue(que, 3);
    isSuccess = myCircularQueueEnQueue(que, 2);
    isSuccess = myCircularQueueEnQueue(que, 1);
    if(myCircularQueueIsEmpty(que)){
        printf("circule is empty\n");
    }
    else printf("circle is not empty\n");
    int value = myCircularQueueFront(que);
    printf("front: %d\n", value);
    value = myCircularQueueRear(que);
    printf("tail: %d\n", value);
    
    isSuccess = myCircularQueueDeQueue(que);
    value = myCircularQueueFront(que);
    printf("front: %d\n", value);
   
    isSuccess = myCircularQueueDeQueue(que);
    value = myCircularQueueFront(que);
    printf("front: %d\n", value);

    isSuccess = myCircularQueueDeQueue(que);
    value = myCircularQueueFront(que);
    printf("front: %d\n", value);
    if(myCircularQueueIsEmpty(que)){
        printf("circule is empty\n");
    }
    else printf("circle is not empty\n");

}