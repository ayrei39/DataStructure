// 2009全国试题42 13'

#include <cstddef>
#include <iostream>
#include <ratio>
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

int func(Node *list, int k){
    if (list -> link == NULL) return 0;

    int res = 0, i = 1;
    Node *temp = list -> link;

    while (i < k && temp != NULL) {
        temp = temp -> link;
        i ++;
    }

    if (temp == NULL) return 0;

    Node *q = list -> link;
    while (temp != NULL) {
        temp = temp -> link;
        res = q -> data;
        q = q -> link;
    }

    printf("%d\n", res);
    return 1;
}

int main() {
  Node *head = (Node *)malloc(sizeof(Node));

  Node *t = head;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  for (int i = 0; i < 8; i++) {
    t->link = createNode(arr[i]);
    t = t->link;
  }

  int res = func(head, 7);
  cout << res << '\n';

  return 0;
}
