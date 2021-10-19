//#include <string>
//#include <vector>
//#include <cstdio>
//
//using namespace std;
//
//typedef struct docu {
//    int priority;
//    bool is_target;
//    struct docu* prev;
//    struct docu* next;
//}docu;
//
//docu* g_tail;
//docu* g_head;
//
//void queue_push(int p, bool t) {
//    docu* node = new docu;
//    node->priority = p;
//    node->is_target = t;
//    node->next = NULL;
//    if (g_head == NULL) {
//        node->prev = NULL;
//        g_head = g_tail = node;
//    }
//    else {
//        node->prev = g_tail;
//        g_tail->next = node;
//        g_tail = node;
//    }
//}
//
//void queue_pop() {
//    if (g_head == NULL)  return;
//    if (g_tail == g_head) {
//        delete g_head;
//        g_tail = g_head = NULL;
//    }
//    else {
//        docu* tmp = g_head;
//        g_head = g_head->next;
//        g_head->prev = NULL;
//        delete tmp;
//    }
//}
//
//void pop_at_ptr(docu* target) {
//    if (g_head == g_tail) {
//        queue_pop();
//        return;
//    }
//    if (target == g_head) {
//        g_head = g_head->next;
//        g_head->prev = NULL;
//        delete target;
//        return;
//    }
//    if (target == g_tail) {
//        g_tail = g_tail->prev;
//        g_tail->next = NULL;
//        delete target;
//        return;
//    }
//    target->prev->next = target->next;
//    target->next->prev = target->prev;
//    delete target;
//}
//
//void pop_all() {
//    while (g_head) {
//        queue_pop();
//    }
//}
//
//void print_all() {
//    docu* node = g_tail;
//    int idx = 0;
//    while (node && idx < 20) {
//        ++idx;
//        printf("(%d, %d) ", node->priority, node->is_target);
//        node = node->prev;
//    }
//    printf("\n");
//}
//
//int solution(vector<int> priorities, int location) {
//    int answer = 0;
//    g_tail = g_head = NULL;
//    for (int idx = 0; idx < priorities.size(); ++idx) {
//        queue_push(priorities[idx], idx == location);
//    }
//
//    for (int cnt = 1; g_head; ++cnt) {
//        docu* now = g_head;
//        docu* node = g_head->next;
//        while (node) {
//            printf("cnt(%d).. %d..s\n", cnt, node->priority);
//            if (g_head->priority < node->priority) {
//                printf("cnt(%d).. %d..m\n", cnt, node->priority);
//                queue_push(g_head->priority, g_head->is_target);
//                queue_pop();
//                now = node;
//                break;
//            }
//            printf("(%d < %d)?\n", g_head->priority, node->priority);
//            node = node->next;
//        }
//        if (now->is_target) {
//            answer = cnt;
//            break;
//        }
//        pop_at_ptr(now);
//    }
//    pop_all();
//    return answer;
//}
//
//int main() {
//    vector<int> input_data1{ 1, 1, 1, 9 , 1, 1 };
//    int data2 = 0;
//    printf("%d\n", solution(input_data1, data2));
//    return 0;
//}