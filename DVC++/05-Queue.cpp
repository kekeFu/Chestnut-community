#include <stdio.h>
#include <stdlib.h>
struct Queue{
	int *data;
	int capacity;
	int front;
	int rear;
};
void init(struct Queue *pq, int capacity){
	pq->capacity = capacity;
	pq->data = (int*)malloc(sizeof(int)*(capacity+1));
	pq->front = pq->rear;
}
int isFull(const struct Queue *pq){
	if((pq->rear + 1) % (pq->capacity+1)== pq->front){
		return 1;
	}else {
		return 0;
	}
}
int enQueue(struct Queue *pq, int x){
	if(isFull(pq)) {
		return 0;
	}else{
		pq->data[pq->rear] = x;
		pq->rear= (pq->rear +1) % (pq->capacity+1);
		return 1;
	}
}
int deQueue(struct Queue *pq, int *px){
	if(isFull(pq)){
		return 0;
	}else{
		*px = pq->data[pq->front];
		pq->front = (pq->front+1)%(pq->capacity+1);
		return 1;
	}
}

int main(){
	struct Queue q;
	init(&q, 5);
	enQueue(&q, 11);
	enQueue(&q, 1);
	enQueue(&q, 12);
	enQueue(&q, 13);
	enQueue(&q, 14);
	enQueue(&q, 12);
	int x;
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	deQueue(&q, &x);
	printf("%d\n",x);
	return 0;
}
 
