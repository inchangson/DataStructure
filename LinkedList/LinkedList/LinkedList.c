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
	data* tmp = g_head;
	while (tmp->next != NULL) {
		printf("===\n");
		printf("(%d, %s)\n", tmp->num, tmp->name);
		printf("===\n");
		tmp = tmp->next;
	}
}

int insert(int num, char* name) {
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
		data* tmp = g_head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = node;
		g_tail = node;
	}

	return -1;
}
void freeAll() {
	data* tmp = g_head;
	data* tmp2;
	while (tmp->next != NULL) {
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
int main() {
	char name[20] = "";
	for (int idx = 0; idx < 5; ++idx) {
		sprintf(name, "test%2d", idx + 1);
		insert(idx, name);
	}
	printAll();
	freeAll();
	return 0;
}