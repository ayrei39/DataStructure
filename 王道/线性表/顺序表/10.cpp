// 2010真题

// #include <iostream>
// using namespace std;

// int a[10] = {1,2,3,4,5,6,7,8,9,10};

// void movePosition(int p) {
//     int temp[p];
//     for (int i = 0; i < 10; i ++){
//         if (i < p) {
//             temp[i] = a[i];
//         }
//         if (i < 10 - p) {
//             a[i] = a[i + p];
//         }
//         if (i >= 10 - p) {
//             a[i] = temp[i - (10 - p)];
//         }
//     }
// }

// int main() {
//     int p = 0;
//     cin >> p;
//     movePosition(p);
//     for (int i = 0; i < 10; i ++) {
//         cout << a[i] << " ";
//     }
//     return 0;
// }
// 时间： O(n) 空间： O(p)

// answer
// 从0-p 的翻转；从p-n的翻转; 整个数组翻转；
// 时间： O(n) 空间： O(1)

#include<iostream>
using namespace std;

void Reverse(int a[], int l, int r) {
    int i, tmp;
    for (i = 0; i < (r - l + 1) / 2; i++) {
        tmp = a[l + i];
        a[l + i] = a[r - i];
        a[r - i] = tmp;
    }
}

void Converse(int a[], int n, int p) {
    Reverse(a, 0, p - 1);
    Reverse(a, p, n - 1);
    Reverse(a, 0, n - 1);
    
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int p = 0;
    cin >> p;
    Converse(a, 10, p);
    for (int i = 0; i < 10; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}