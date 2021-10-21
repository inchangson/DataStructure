#include <cstdio>
#include <cstdlib>

#define QUEUE_MX 1000

typedef struct Elem{
	int num;	
}Elem;

typedef struct Queue{
	int front;
	int rear;
	int sz;
	Elem* queueData;
}Queue;

void Init(Queue* q){
	q->front = q->rear = 0;
	q->sz = QUEUE_MX;
	q->queueData = (Elem*)malloc(sizeof(Elem) * q->sz);		
}

int IsEmpty(Queue* q){
	return q->front == q->rear;
}

int IsFull(Queue* q){
	return (q->rear + 1) % q->sz == q->front;
}

int Enqueue(Queue* q, Elem e){
	if(IsFull(q))	return -1;
	q->rear = (q->rear + 1) % q->sz;
	q->queueData[q->rear] = e;
}

Elem Dequeue(Queue* q, bool* rslt){
	if(IsEmpty(q)){
		*rslt = false;
		return {0};
	}
	*rslt = true;
	q->front = (q->front + 1) % q->sz;
	return q->queueData[q->front];
}

Elem Top(Queue* q, bool* rslt){
	if(IsEmpty(q)){
		*rslt = false;
		return {0};
	}
	*rslt = true;
	int tmpIdx = (q->front + 1) % q->sz;
	return  q->queueData[tmpIdx];
}

void Print(Queue* q){
	if(IsEmpty(q))	return;
	int idx = q->front;
	printf("\n========Print Start=======\n");
	do{
		idx = (idx + 1) % q->sz;
		printf("%d ", q->queueData[idx].num);
	}while(idx != q->rear);
	printf("\n");
	printf("==========Print End========\n");
}

int main(){
	int T;
	int N;
	scanf("%d", &T);
	for(int testCase = 1; testCase <= T; ++testCase){
		scanf("%d", &N);
		Queue testQueue;
		Init(&testQueue);
		for(int i = 0; i < N; ++i){
			Elem value;
			value.num = i * i;
			//scanf("%d", &value);
			Enqueue(&testQueue, value);
		}		
		printf("#%d ", testCase);
		
		Print(&testQueue);
		
		while(!IsEmpty(&testQueue)){
			Elem value;
			bool rslt;
			value = Dequeue(&testQueue, &rslt);
			if(rslt){
				printf("%d ", value.num);
			}
		}
		printf("\n");
	}
	return 0;	
}
