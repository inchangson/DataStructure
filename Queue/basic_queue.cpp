#include <cstdio>

#define MX 100

typedef struct info{
	int num;
}info;

int front = 0;
int rear = 0;
info queue[MX];

int is_empty(){
	return front == rear;
}

int is_full(){
	return rear == MX - 1;
}

void enqueue(info i){
	if(is_full())	return;
	queue[++rear] = i;
}

info dequeue(){
	if(is_empty())	return {0};
	return queue[++front];
}

int main(){
	for(int idx = 0; idx < MX / 2; ++idx){
		info i = { idx };
		enqueue(i);
		print_queue();
	}
	printf("=====================\n");
	while(!is_empty()){
		info i = dequeue();
		printf("outed num : %3d\n", i.num);
		print_queue();
	}
	
	return 0;
}
