// 2015全国试题41 13'

#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *link;
} Node;

// 初始化函数，相当于构造函数
Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->data = value;
    newNode->link = NULL;
  }
  return newNode;
}

void deleteSame(Node *head, int n) {
  bool st[n + 1];
  Node *p = head;
  while (p->link) {
    int i = abs(p->link->data);
    if (st[i] == false) {
      st[i] = true;
      p = p->link;
    } else {
      Node *q = p->link->link;
      p->link = q;
    }
  }
}

int main() {
  Node *head = (Node *)malloc(sizeof(Node));

  int a[] = {21, -15, -15, -15, -7, 1, 1, 1, 1, 15};

  Node *t = head;
  for (int i = 0; i < 10; i++) {
    Node *newNode = createNode(a[i]);
    t->link = newNode;
    t = t->link;
  }

  deleteSame(head, 30);

  t = head->link;
  while (t) {
    cout << t->data << ' ';
    t = t->link;
  }

  return 0;
}
