#include <cstdio>
#include <cstdlib>

#define MX 100
#define BOOL int
typedef struct elem{
	int num;
}elem;

typedef struct _circular_queue{
	int front;
	int rear;
	int sz;
	elem* data;
}Queue;

void init_queue(Queue *q){
	q->front = 0;
	q->rear = 0;
	q->sz = MX;
	q->data = (elem*)malloc(sizeof(elem) * MX);
} 

BOOL is_empty(Queue* q){
	return q->front == q->rear;
}

BOOL is_full(Queue* q){
	return	(q->rear + 1) % q->sz == q->front;	
}

void enqueue(Queue* q, elem e){
	if(is_full(q))	return;
	q->rear = (q->rear + 1) % q->sz;
	q->data[q->rear] = e;
}

elem dequeue(Queue* q){
	if(is_empty(q))	return {0};	
	q->front = (q->front + 1) % q->sz;
	return q->data[q->front];
}

void print_queue(Queue* q){
	if(is_empty(q))	return;
	
	int idx = q->front + 1;
	while(idx != q->front){
		printf("idx : %3d\n", q->data[idx]);
		if(idx == q->rear)	break;
		idx = (idx + 1) % q->sz;
	}
	printf("\n");
}

int main(){
	Queue q;
	init_queue(&q);
	for(int idx = 0; idx < MX / 8; ++idx){
		elem e = { idx };
		enqueue(&q, e);
		//print_queue(&q);
	}
	printf("=====================\n");
	while(!is_empty(&q)){
		elem e = dequeue(&q);
		printf("outed num : %3d\n", e.num);
		print_queue(&q);
	}
	
	return 0;
}
