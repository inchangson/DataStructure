#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX_HEAP 100
#define NULL_ELEM {0, 0}
#define TOP 1

#define TRUE 1
#define FALSE 0 

typedef struct Elem{
	int idx;
	int num;
}Elem;

typedef struct Heap{
	int sz;
	Elem* data;
}Heap;

void Init(Heap* h){
	h->sz = 0;
	h->data = (Elem*)malloc(sizeof(Elem) * MX_HEAP);
}

int IsEmpty(Heap* h){
	if(h->sz == 0)	return TRUE;
	else	return FALSE; 
}

int IsFull(Heap* h){
	if(h->sz == MX_HEAP - 1)	
		return TRUE;
	else
		return FALSE;
}

int Cmp(Elem* e1, Elem* e2){
	if(e1->idx < e2->idx){
		return 1;
	}else if(e1->idx == e2->idx){
		return 0;
	}else{//e1->idx > e2->idx
		return -1;
	}
}

void mySwap(Elem* e1, Elem*e2){
	Elem* tmp;
	tmp->idx = e1->idx;
	tmp->num = e1->num;
	e1->idx = e2->idx;
	e1->idx = e2->num;
	e2->idx = tmp->idx;
	e2->num = tmp->num;
}

int Push(Heap* h, Elem e){
	if(IsFull(h))	return FALSE;
	
	h->data[++h->sz] = e;
	
	int cur = h->sz;
	while(cur != TOP){
		int parent = cur / 2;
		if(Cmp(&h->data[parent], &h->data[cur]) > 1){
			mySwap(&h->data[parent], &h->data[cur]);
			cur = parent;
		}else{
			break;
		}
	}
}

Elem Pop(Heap* h, bool* bRslt){
	if(IsEmpty(h)){
		Elem tmp = {0, 0};
		*bRslt = false;
		return tmp;//tmp;
	}
	*bRslt = true;
	Elem retElem = h->data[TOP];
	h->data[TOP] = h->data[h->sz--];
	//h->data[h->sz] = 0; h->sz--;
	
	int cur = TOP;
	int child1, child2;
	while(cur < h->sz){
		child1 = cur * 2;
		child2 = cur * 2 + 1;
		
		//rsltChild만 정하고 최종으로 비교만 해준다. 
		rsltChild;
		if(child1 > h->sz){
			break;
		}else if(child2 > h->sz){
			//child1 만 비교
			if(Cmp(&h->data[cur], &h->data[child1]) == 1){
				mySwap(&h->data[cur], &h->data[child1]);
				cur = child1;
			}else{
				break;
			}
		}else{
			//둘 다 비교
			if(Cmp(&h->data[cur], &h->data[child1]) == 1){
				mySwap(&h->data[cur], &h->data[child1]);
				cur = child1;
			}else if(Cmp(&h->data[cur], &h->data[child2]) == 1){
				mySwap(&h->data[cur], &h->data[child2]);
				cur = child2;
			}else{
				break;
			}
		}
	}
	
	return retElem;
}

void Free(Heap* h){
	free(h->data);
}

void printHeap(Heap* h){
	printf("\n===========heap===============\n");
	for(int idx = 1; idx <= h->sz; ++idx){
		if(idx % 5 == 0)	printf("\n");
		printf("(%5d, %5d)\t", h->data[idx].idx, h->data[idx].num);
	}
	printf("\n");
}

int main(){
	int T, N;
	scanf("%d", &T);
	for(int testCase = 1; testCase <= T; ++testCase){
		scanf("%d", &N);
		
		Elem* testData;
		testData = (Elem*)malloc(sizeof(Elem) * N);
		
		Heap h;
		Init(&h);
		int rp = 0;
		for(int i = 1; i <= N; ++i){
			Elem val;
			val.num = i;
			srand(i);
			val.idx = rand() % (10 * N);
			Push(&h, val);
			testData[rp++] = val;
		}
		
		printf("\n======test data=============\n");
		for(int idx = 0; idx < rp; ++idx){
			if(idx % 5 == 0)	printf("\n");
			printf("(%5d, %5d)\t", testData[idx].idx, testData[idx].num);
		}
		printf("\n");
		
		printHeap(&h);
		printf("\n======================\n");
		/*
		while(!IsEmpty(&h)){
			bool bRslt = false;
			Elem tmp = Pop(&h, &bRslt);
			if(bRslt)
				printf("(%5d, %5d)\t", tmp.idx, tmp.num);
			else
				printf("ASSERTION: POP FAIL\n");
		}*/			
		free(testData);
		Free(&h);
	}
}

