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

data* g_head = NULL;
data* g_tail = NULL;

void printAll() {
	if (g_head == NULL) {
		return;
	}

	data* tmp = g_head;
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
	if (g_head == NULL) {
		return;
	}

	data* tmp = g_head;
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
	if (g_head == NULL) {
		g_head = node;
		g_tail = node;
		return 1;
	}
	else {
		g_tail->next = node;
		g_tail = node;
	}

	return -1;
}

data* stackPop() {

	if (g_head == NULL) {
		return NULL;
	}

	data* node = (data*)malloc(sizeof(data));
	memcpy(node, g_tail, sizeof(data));

	data* tmp = g_head;
	while (tmp->next != g_tail) {
		tmp = tmp->next;
	}
	free(g_tail);

	g_tail = tmp;
	g_tail->next = NULL;

	return node;
}

data* queuePop() {
	if (g_head == NULL) {
		return NULL;
	}
	data* node = (data*)malloc(sizeof(data));
	memcpy(node, g_head, sizeof(data));

	free(g_head);
	if (node->next != NULL) {
		g_head = node->next;
	}
	else {
		g_head = g_tail = NULL;
	}

	return node;

}

int main() {
	char name[20] = "";
	for (int idx = 0; idx < 10; ++idx) {
		sprintf(name, "test%2d", idx + 1);
		insertLast(idx, name);
		//printAll();
	}
	printAll();
	printf("\n==========stackPop===========\n");
	for (int idx = 0; idx < 5; ++idx) {
		data* tmp = stackPop();
		printf("poped (%3d, %10s)\n", tmp->num, tmp->name);
	}
	printf("\n=========queuePop===========\n");
	for (int idx = 0; idx < 5; ++idx) {
		data* tmp = queuePop();
		printf("poped (%3d, %10s)\n", tmp->num, tmp->name);
	}

	printAll();
	freeAll();
	return 0;
}