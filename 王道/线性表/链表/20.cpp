#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}NODE;

void initList(NODE *h);
void printList(NODE *h);
NODE* reverseList(NODE *h);

void mergeLists(NODE *L1, NODE *L2) {
    NODE *p1 = L1;
    // cout << p1->data << endl;
    NODE *p2 = L2;
    // cout << p2->data << endl;
    while (p1 && p2) {
        NODE *temp1 = p1->next;
        NODE *temp2 = p2->next;
        p1->next = p2;
        if (temp1 == nullptr) break;
        p2->next = temp1;
        p1 = temp1;
        p2 = temp2;
    }
}

void func(NODE *head) {
    // NODE *l = head, *r = head;


    NODE *slow = head;
    NODE *fast = head;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast->next != nullptr) fast = fast->next;
    }
    // while (fast->next && fast->next->next) {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // r = l->next;
    // l->next = nullptr;
    // NODE *t1, *t2 = nullptr;
    // while (r != nullptr) {
    //     t1 = r->next;
    //     r->next = t2;
    //     t2 = r;
    //     r = t1;
    // }

    // 分割链表并反转第二部分
    NODE *L1 = head->next;
    NODE *L2 = slow->next;
    slow->next = nullptr;
    L2 = reverseList(L2);

    // 合并两部分
    mergeLists(L1, L2);
}

int main() {
    // 创建测试链表
    NODE head = {0, nullptr};
    NODE *tail = &head;
    initList(tail);
    printList(tail);

    func(tail);

    printList(tail);

    return 0;
}

void initList(NODE *h) {

    NODE *tmp = h;
    for (int i = 1; i <= 9; i ++) {
        NODE *newNode = new NODE{i, nullptr};
        tmp->next = newNode;
        tmp = newNode;
    }
}

void printList(NODE *h) {
    NODE *current = h->next;
    while (current != nullptr) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

NODE* reverseList(NODE *head) {
    NODE *prev = nullptr;
    NODE *current = head;
    
    while (current) {
        NODE *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}