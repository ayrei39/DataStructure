#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    LNode *next;
}LNode,*PNode;
const int N = 1000;
bool stu[N];
void func(PNode h) {
    LNode *p = h;
    while (p != nullptr) {
        int m = abs(p->next->data);
        // cout << m << '\n';
        if (stu[m]) {
            LNode *t = p->next;
            p->next = t->next;
            delete(t);
        }
        stu[m] = true;
        p = p->next;
    }
}

int main() {
    PNode head = new LNode;
    head->data = 0;
    head->next = nullptr;

    int arr[] = {21,-15,-15,-7,15};
    LNode *c = head;
    for (int i = 0; i < 5; i ++) {
        LNode *t = new LNode;
        t->data = arr[i];
        t->next = nullptr;
        c->next = t;
        c = t;
    }

    func(head);

    c = head->next;
    while (c != nullptr) {
        printf("%d ",c->data);
        c = c->next;
    }
     return 0;
}