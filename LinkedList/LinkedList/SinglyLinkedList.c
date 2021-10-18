
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MX 30
#define NAMESZ 20

typedef struct SData {
	int num;
	char name[NAMESZ];
	struct data* next;
}data;

data* gHead = NULL;
data* gTail = NULL;

void printAll() {
	if (gHead == NULL) {
		return;
	}

	data* tmp = gHead;
	int idx = 0;
	printf("\n==========printAll============\n");
	while (tmp != NULL) {
		if (idx % 5 == 0) {
			printf("\n");
		}
		printf("(%d, %s)\t", tmp->num, tmp->name);
		tmp = tmp->next;
	}
	printf("\n=============================\n");
}

void freeAll() {
	if (gHead == NULL) {
		return;
	}

	data* tmp = gHead;
	data* tmp2 = (data*)malloc(sizeof(data));
	while (tmp->next != NULL) {
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

int insertLast(int num, char* name) {
	data* node = (data*)malloc(sizeof(data));

	node->next = NULL;
	node->num = num;
	if (name != NULL) {
		strcpy(node->name, name);
	}

	//ÃÊ±â
	if (gHead == NULL) {
		gHead = node;
		gTail = node;
		return 1;
	}
	else {
		gTail->next = node;
		gTail = node;
	}

	return -1;
}

data* stackPop() {

	if (gHead == NULL) {
		return NULL;
	}

	data* node = (data*)malloc(sizeof(data));
	memcpy(node, gTail, sizeof(data));

	data* tmp = gHead;
	while (tmp->next != gTail) {
		tmp = tmp->next;
	}
	free(gTail);

	gTail = tmp;
	gTail->next = NULL;

	return node;
}

data* queuePop() {
	if (gHead == NULL) {
		return NULL;
	}
	data* node = (data*)malloc(sizeof(data));
	memcpy(node, gHead, sizeof(data));

	free(gHead);
	if (node->next != NULL) {
		gHead = node->next;
	}
	else {
		gHead = gTail = NULL;
	}

	return node;

}

data* findWithNum(int num) {
	if (gHead == NULL) {
		return NULL;
	}
	data* node = gHead;
	while (node != NULL) {
		if (node->num == num) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

data* findWithName(char* name) {
	if (gHead == NULL) {
		return NULL;
	}
	data* node = gHead;
	while (node != NULL) {
		if (strcmp(node->name, name) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int removeAtWithNum(int num) {
	if (gHead == NULL) {
		return 0;
	}
	data* curNode = gHead;
	data* preNode = NULL;
	while (curNode) {
		if (curNode->num == num) {
			if (curNode == gHead) {
				gHead = curNode->next;
			}
			if (curNode == gTail) {
				gTail = preNode;
			}
			if (preNode != NULL) {
				preNode->next = curNode->next;
			}
			free(curNode);
			return 1;
		}
		preNode = curNode;
		curNode = curNode->next;
	}
	return -1;
}

int removeAtWithName(char* name) {
	if (gHead == NULL) {
		return 0;
	}
	data* preNode = NULL;
	data* curNode = gHead;
	while (curNode) {
		if (strcmp(curNode->name, name) == 0) {
			if (curNode == gHead) {
				gHead = curNode->next;
			}
			if (curNode == gTail) {
				gTail = preNode;
			}
			if (preNode != NULL) {
				preNode->next = curNode->next;
			}
			free(curNode);
			return 1;
		}
		preNode = curNode;
		curNode = curNode->next;
	}
	return -1;
}

int addAtWithNum(int targetNum/*, int inputNum, char* inputName*/) {
	if (gHead == NULL) {
		return 0;
	}
	data* curNode = gHead;
	while (curNode) {
		if (curNode->num == targetNum) {
			data* node = (data*)malloc(sizeof(data));
			strcpy(node->name, "mytest num");
			node->num = 123;

			node->next = curNode->next;
			if (curNode == gTail) {
				gTail = node;
			}
			curNode->next = node;

			return 1;
		}
		curNode = curNode->next;
	}
	return -1;


}

int addAtWithName(char* targetName) {
	if (gHead == NULL) {
		return 0;
	}
	data* curNode = gHead;
	while (curNode) {
		if (strcmp(curNode->name, targetName) == 0) {
			data* node = (data*)malloc(sizeof(data));
			node->next = curNode->next;
			node->num = 312;
			strcpy(node->name, "mytestNameAdd");

			if (curNode == gTail) {
				gTail = node;
			}
			curNode->next = node;
			return 1;
		}
		curNode = curNode->next;
	}
	return -1;
}

void testStackPop() {
	printf("\n==========StackPopTest===========\n");
	for (int idx = 0; idx < 5; ++idx) {
		data* tmp = stackPop();
		printf("poped (%3d, %10s)\n", tmp->num, tmp->name);
	}
}

void testQueuePop() {
	printf("\n=========QueuePopTest===========\n");
	for (int idx = 0; idx < 5; ++idx) {
		data* tmp = queuePop();
		printf("poped (%3d, %10s)\n", tmp->num, tmp->name);
	}
}

void testFindWithNum() {
	data* tmp;
	tmp = findWithNum(5);
	if (tmp != NULL) {
		printf("find successed\n");
	}
	else {
		printf("find failed\n");
	}

	tmp = findWithNum(55);
	if (tmp != NULL) {
		printf("find successed\n");
	}
	else {
		printf("find failed\n");
	}
}

void testFindWithName() {
	data* tmp;
	tmp = findWithName("test 1");
	if (tmp != NULL) {
		printf("find successed\n");
	}
	else {
		printf("find failed\n");
	}

	tmp = findWithName("test 151");
	if (tmp != NULL) {
		printf("find successed\n");
	}
	else {
		printf("find failed\n");
	}
}

void testAddAtWithNum() {
	printf("add data at num 3");
	printAll();
	if (addAtWithNum(3) == 1) {
		printf("Add successfully\n");
		printAll();
	}
	else {
		printf("Add failed\n");
		printAll();
	}

	printf("add data at num 13");
	printAll();
	if (addAtWithNum(13) == 1) {
		printf("Add successfully\n");
		printAll();
	}
	else {
		printf("Add failed\n");
		printAll();
	}
}

void testAddAtWithName() {
	printf("add data at test 1");
	printAll();
	if (addAtWithName("test 1") == 1) {
		printf("Add successfully\n");
		printAll();
	}
	else {
		printf("Add failed\n");
		printAll();
	}

	printf("add data at test A");
	printAll();
	if (addAtWithName("test A") == 1) {
		printf("Add successfully\n");
		printAll();
	}
	else {
		printf("Add failed\n");
		printAll();
	}

}

void testRemoveAtWithNum() {
	printf("remove data at num 3");
	printAll();
	if (removeAtWithNum(3) == 1) {
		printf("Remove successfully\n");
		printAll();
	}
	else {
		printf("Remove failed\n");
		printAll();
	}

	printf("remove data at num 13");
	printAll();
	if (removeAtWithNum(13) == 1) {
		printf("Remove successfully\n");
		printAll();
	}
	else {
		printf("Remove failed\n");
		printAll();
	}
}

void testRemoveAtWithName() {
	printf("remove data at test 1");
	printAll();
	if (removeAtWithName("test 1") == 1) {
		printf("Remove successfully\n");
		printAll();
	}
	else {
		printf("Remove failed\n");
		printAll();
	}

	printf("remove data at test A");
	printAll();
	if (removeAtWithName("test A") == 1) {
		printf("Remove successfully\n");
		printAll();
	}
	else {
		printf("Remove failed\n");
		printAll();
	}
}

int main() {
	char name[20] = "";

	//InsertData
	for (int idx = 0; idx < 10; ++idx) {
		sprintf(name, "test%2d", idx + 1);
		insertLast(idx, name);
		//printAll();
	}
	//printAll();

	//Stack Pop Test
	//testStackPop();

	//Queue Pop Test
	//testQueuePop();

	//find With Num Test
	//testFindWithNum();

	//find With Name Test
	//testFindWithName();

	//Add At Test
	testAddAtWithNum();
	testAddAtWithName();

	//Remove At Test
	//testRemoveAtWithNum();
	//testRemoveAtWithName();

	//printAll();
	freeAll();
	return 0;
}

#endif