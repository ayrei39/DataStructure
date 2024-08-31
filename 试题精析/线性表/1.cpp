// 2019全国试题41 13'

#include <cstddef>
#include <iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
} NODE;

// 初始化函数，相当于构造函数
NODE *createNode(int value) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  if (newNode != NULL) {
    newNode->data = value;
    newNode->next = NULL;
  }
  return newNode;
}

NODE *ReverseLink(NODE *head) {
  NODE *prev = nullptr;
  NODE *curr = head;

  while (curr) {
    NODE *new_node = curr->next;
    curr->next = prev;
    prev = curr;
    curr = new_node;
  }

  return prev;
}

NODE *func(NODE *head) {
  NODE *p = head, *q = head;
  while (q->next != nullptr) {
    p = p->next;
    q = q->next;
    if (q->next != nullptr)
      q = q->next;
  }

  NODE *r = p->next;
  p->next = nullptr;

  // NODE *c = r;
  // while (c) {
  //   printf("%d-", c->data);
  //   c = c->next;
  // }
  // printf("\n");

  r = ReverseLink(r);

  NODE *l = head->next,*t = head;
  while(l){
      t->next = l;
      l = l->next;
      t = t->next;
      if(r){
          t->next = r;
          r = r->next;
          t = t->next;
      }
  }

return head;
}

int main() {
  NODE *head = (NODE *)malloc(sizeof(NODE));

  NODE *t = head;
  int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
  for (int i = 0; i < 8; i++) {
    t->next = createNode(arr[i]);
    t = t->next;
  }

  NODE *c = func(head);
  c = c->next;
  while (c) {
    printf("%d ", c->data);
    c = c->next;
  }

  return 0;
}
