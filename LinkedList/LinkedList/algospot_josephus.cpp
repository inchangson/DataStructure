#include <stdio.h>
#include <stdlib.h>

typedef struct soldier {
	int num;
	struct soldier* prev;
	struct soldier* next;
}soldier;

soldier* g_head;

void init_data() {
	g_head = NULL;
}

void append_data(int num) {
	soldier* node = (soldier*)malloc(sizeof(soldier));
	node->num = num;
	node->prev = NULL;
	node->next = g_head;

	if (g_head == NULL) {
		g_head = node;
		g_head->prev = node;
		g_head->next = node;
	}
	else {
		g_head->prev->next = node;
		node->prev = g_head->prev;
		g_head->prev = node;
	}
}

void remove_data_with_ptr(soldier* target) {
	if (target == g_head) {
		g_head = target->next;
		if (target == g_head)	g_head = NULL;
	}
	if (target->next == NULL || target->prev == NULL) {
		free(target);
		return;
	}
	target->next->prev = target->prev;
	target->prev->next = target->next;
	free(target);
}

void make_soldier_list(int cnt) {
	for (int idx = 1; idx <= cnt; ++idx) {
		append_data(idx);
	}
}

soldier* get_next_turn(soldier* cur_node, int steps) {
	soldier* next_node = cur_node;
	while (steps) {
		next_node = next_node->next;
		--steps;
	}
	return next_node;
}

void print_soldiers() {
	soldier* cur_node = g_head;
	soldier* next_node = NULL;
	int idx = 0;
	while (cur_node) {
		next_node = cur_node->next;
		printf("%3d ", cur_node->num);
		if (cur_node == g_head->prev)	break;
		cur_node = next_node;
	}
	printf("\n");
}

void kill_soldiers(int cnt, int steps) {
	soldier* cur_node = g_head;
	soldier* next_node = NULL;
	while (cnt > 2) {
		next_node = get_next_turn(cur_node, steps);
		remove_data_with_ptr(cur_node);
		cur_node = next_node;
		--cnt;
	}
}

void free_all() {
	while (g_head) {
		remove_data_with_ptr(g_head);
	}
}


int main() {
	int c, n, k;
	scanf("%d", &c);
	for (int idx = 1; idx <= c; ++idx) {
		init_data();
		scanf("%d %d", &n, &k);
		make_soldier_list(n);
		kill_soldiers(n, k);
		printf("%d %d\n", g_head->num, g_head->next->num);
		free_all();
	}
	return 0;
}