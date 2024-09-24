// 2014全国试题41 13'

#include <cstddef>
#include <iostream>
using namespace std;

int res = 0;

typedef struct BiTNode {
  int weight;
  struct BiTNode *left, *right;
} BiTNode, *BiTree;

int preOrder(BiTree root, int deep) {
  if (root == NULL)
    return 0;
  if (root != NULL) {
    if (root->left == NULL && root->right == NULL)
      res += root->weight * deep;
    preOrder(root->left, deep + 1);
    preOrder(root->right, deep + 1);
  }

  return res;
}

int wpl(BiTree root) { return preOrder(root, 1); }

BiTree createNode(int weight) {
  BiTree newNode = (BiTNode *)malloc(sizeof(BiTNode));
  if (newNode != NULL) {
    newNode->weight = weight;
    newNode->left = NULL;
    newNode->right = NULL;
  }
  return newNode;
}

int main() {
  BiTree root = createNode(1);
  BiTree l = createNode(2);
  BiTree r = createNode(3);
  root->left = l;
  root->right = r;

  int wpls = wpl(root);
  cout << wpls << endl;
  return 0;
}
