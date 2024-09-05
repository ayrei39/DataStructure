// 2010全国试题42 13'

#include <algorithm>
#include <iostream>
using namespace std;

// 初始化函数，相当于构造函数
// Node *createNode(int value) {
//   Node *newNode = (Node *)malloc(sizeof(Node));
//   if (newNode != NULL) {
//     newNode->data = value;
//     newNode->link = NULL;
//   }
//   return newNode;
// }

void leftMove(int arr[], int n, int p){
    reverse(arr, arr + p);
    reverse(arr+p, arr +n);
    reverse(arr, arr + n);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int p = 3, n = 9;

    leftMove(arr, n, p);

    for(int i = 0; i < n; i ++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
