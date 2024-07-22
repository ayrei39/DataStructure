#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    LNode *link;
}LNode, *LinkList;

// 初始化一个长度为10的带有头节点的链表
LinkList initList() {
    // 创建头节点
    // LinkList head = (LNode *)malloc(sizeof(LNode));
    LinkList head = new LNode;
    head->data = 0; // 头节点数据域可以设置为0或者其他标志值
    head->link = nullptr;

    // 尾指针，初始化指向头节点
    LNode *tail = head;

    // 创建其余10个节点
    for (int i = 1; i <= 10; ++i) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = i; // 这里设置节点的数据域为i，你可以根据需要修改
        newNode->link = nullptr;
        tail->link = newNode; // 将新节点链接到链表的末尾
        tail = newNode;       // 更新尾指针
    }

    return head;
}

// 打印链表中的所有节点数据
void printList(LinkList head) {
    LNode *current = head->link;
    while (current) {
        std::cout << current->data << " ";
        current = current->link;
    }
    std::cout << std::endl;
}

// int findK(LinkList list, int k) {
//     int cnt = 0, res = 0;
//     bool flag = false;
//     LNode *p = list->link, *q = list->link;
//     while (p != nullptr) {
//         if (cnt >= k) {
//             q = q->link;
//             // printf("p: %d, q: %d \n",p->data,q->data);
//             res = q->data;
//
//             flag = true;
//         }
//         cnt ++;
//         p = p->link;
//     }
//     if (flag) {
//         cout << res <<endl;
//         return 1;
//     }
//     return 0;
//
// }

// answer
int findK(LinkList list, int k) {
    LNode *p = list->link, *q = list->link;
    int cnt = 0;
    while (p != NULL) {
        if (cnt < k) cnt ++;
        else q = q->link;
        p = p->link;
    }

    if (cnt < k) return 0;
    printf("%d\n",q->data);
    return 1;
}

int main() {

    // 初始化链表
    LinkList list = initList();
    // 打印链表
    printList(list);
    int k = 3;
    int res = findK(list, k);
    cout << "res: " << res;

    return 0;

}