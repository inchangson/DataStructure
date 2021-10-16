//doubly linked list implement
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define NAMESZ 20
#define INPUTSZ 10

typedef struct data {
	int num;
	char name[NAMESZ];
	struct data* before;
	struct data* next;
}data;

data* gHead = NULL;
data* gTail = NULL;

void addDataLast(int num, char* name) {
	data* node = (data*)malloc(sizeof(data));
	node->num = num;
	strcpy(node->name, name);
	node->before = NULL;
	node->next = NULL;

	if (gHead == NULL) {
		gHead = node;
		gTail = node;
	}
	else {
		gTail->next = node;
		node->before = gTail;
		gTail = node;
	}
}

void addDataFirst(int num, char* name) {
	data* node = (data*)malloc(sizeof(data));
	node->num = num;
	strcpy(node->name, name);
	node->before = NULL;
	node->next = NULL;

	if (gHead == NULL) {
		gHead = node;
		gTail = node;
	}
	else {
		gHead->before = node;
		node->next = gHead;
		gHead = node;
	}
}

void printAllForward() {
	if (gHead == NULL) {
		return;
	}

	printf("\n====== print forward ======");
	data* node = gHead;
	int idx = 0;
	while (node != NULL) {
		if (idx % 5 == 0)	printf("\n");
		printf("(%d,%s)\t", node->num, node->name);
		node = node->next;
		++idx;
	}
}

void printAllBackward() {
	printf("\n====== print backward ======");
	data* node = gTail;
	int idx = 0;
	while (node) {
		if (idx % 5 == 0)	printf("\n");
		printf("(%d,%s)\t", node->num, node->name);
		node = node->before;
		++idx;
	}
}

void freeAll() {
	data* tmpNode;
	data* node;
	node = gHead;
	while (node) {
		tmpNode = node;
		free(tmpNode);
		node = node->next;
	}
}

data* popAtWithNum(int tNum) {
	if (gHead == NULL) {
		return NULL;
	}

	data* lNode = gHead;
	data* rNode = gTail;

	for (lNode&& rNode) {
		if (lNode->num == tNum) {

		}

		if (rNode->num == tNum) {

		}
	}
}

data* popAtWithName() {

}

data* popFirst() {


}

data* popLast() {

}

data* popAtWithNum() {

}

void testPopAtWithName() {

}

void testPopFirst() {

}

void testPopLast() {

}

int main() {

	for (int idx = 0; idx < INPUTSZ; ++idx) {

		char buf[NAMESZ];

		//	sprintf(buf, "testFirst%2d", idx + 1);

		//	addDataFirst(idx + 1, buf);

		sprintf(buf, "testLast%2d", idx + 1);

		addDataLast(idx + 1, buf);

	}



	//	printAllForward();

	//	printAllBackward();



	testPopAtWithNum();

	testPopAtWithName();



	testPopFirst();

	testPopLast();



	freeAll();



	return 0;

}