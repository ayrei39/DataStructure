// 2012全国试题42 13'

#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

typedef struct node {
  char data;
  struct node *next;
} Node;

// 初始化函数，相当于构造函数
Node *createNode(char value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->data = value;
    newNode->next = NULL;
  }
  return newNode;
}

Node *equalEnd(Node *str1, Node *str2) {
  int len1 = 0, len2 = 0;
  Node *t1 = str1->next, *t2 = str2->next;

  while (t1) {
    len1++;
    t1 = t1->next;
  }
  while (t2) {
    len2++;
    t2 = t2->next;
  }

  int d = len1 - len2;
  Node *p = str1->next, *q = str2->next;
  if (d > 0) {
    while (d) {
      p = p->next;
      d--;
    }
  } else {
    while (d) {
      q = q->next;
      d++;
    }
  }

  Node *res = NULL;
  bool flag = true;
  while (p && q) {
    if (p->data == q->data) {
      if (flag) {
        res = p;
      }
      flag = false;
    } else {
      res = NULL;
      flag = true;
    }
    p = p->next;
    q = q->next;
  }

  return res;
}

int main() {
  Node *str1 = (Node *)malloc(sizeof(Node));
  Node *str2 = (Node *)malloc(sizeof(Node));

  string s1 = "loading", s2 = "being";

  Node *t = str1;
  for (int i = 0; s1[i]; i++) {
    Node *newNode = createNode(s1[i]);
    t->next = newNode;
    t = t->next;
  }
  t = str2;
  for (int i = 0; s2[i]; i++) {
    Node *newNode = createNode(s2[i]);
    t->next = newNode;
    t = t->next;
  }

  Node *res = equalEnd(str1, str2);

  while (res) {
    cout << res->data << ' ';
    res = res->next;
  }

  return 0;
}
