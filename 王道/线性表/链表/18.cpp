#include <iostream>
using namespace std;

typedef struct LNode {
    char data;
    LNode *next;
}LNode, *LinkList;

// 题目要求简化，只要匹配到第一个匹配字符，后续默认匹配
LNode* findMerge(LinkList str1, LinkList str2) {
    LNode *t = str1->next;
    int l1 = 0, l2 = 0;
    while (t != nullptr) {
        l1 ++;
        t = t->next;
    }
    t = str2->next;
    while (t != nullptr) {
        l2++;
        t = t->next;
    }

    LNode *p = str1->next, *q = str2->next;
    while (l1 > l2) {
        p = p->next;
        l1 --;
    }
    while (l2 > l1) {
        q = q->next;
        l2 --;
    }

    while (p != nullptr && p->data != q->data) {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main() {
    LinkList str1 = new LNode();
    str1->data = ' ';
    str1->next = nullptr;

    LinkList str2 = new LNode();
    str2->data = ' ';
    str2->next = nullptr;

    char s1[] = "loading", s2[] = "being";
    LNode *c = str1;
    for (int i = 0; s1[i]; i ++) {
        LNode *newNode = new LNode;
        newNode->data = s1[i];
        newNode->next = nullptr;
        c->next = newNode;
        c = newNode;
    }
    c = str2;
    for (int i = 0; s2[i]; i ++) {
        LNode *newNode = new LNode;
        newNode->data = s2[i];
        newNode->next = nullptr;
        c->next = newNode;
        c = newNode;
    }

    LNode *res = findMerge(str1, str2);
    cout << res->data;

    return 0;
}