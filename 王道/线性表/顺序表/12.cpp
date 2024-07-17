// 2013

#include<iostream>
using namespace std;

// void findMainDiagonal(int a[], int len) {
//     int num[len];
//     for (int i = 0; i < len; i++){
//         num[i] = 0;
//     }
//     int max = -1, p = 0;
//     for (int i = 0; i < len; i++) {
//         num[a[i]] ++;
//         if (num[a[i]] > max) {
//             max = num[a[i]];
//             p = a[i];
//         }
//     }
//     if (max > len / 2) {
//         cout << p << endl;
//     }
//     else {
//         cout << -1;
//     }

// }

// int main() {
//     int a1[] = {0,5,5,3,5,7,5,5};
//     int a2[] = {0,5,5,3,5,1,5,7};

//     int x = 0;
//     cin >> x;
//     if (x == 1) {findMainDiagonal(a1, 8);}
//     else {findMainDiagonal(a2, 8);}

//     return 0;
// }

// 时间：O(n) 空间：O(n)

// answer
/*
从a[0]开始设为可能的众数，如果遇到相同的数，则count++，否则count--，
如果count为0再--，则说明该数小于一半，不可能为众数；则将num设为当前数，count设为1，继续统计。
*/
// 时间：O(n) 空间：O(1)
int Majority(int a[], int len){
    int count = 1, num = a[0];
    for(int i = 1; i < len; i++){
        if(a[i] == num){
            count++;
        } else {
            if (count > 0) count --; 
            else {
                num = a[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i = 0; i < len; i++) {
        if(a[i] == num) count++;
    }
    if(count > len / 2) return num;
    return -1;
}

int main() {
    int a1[] = {0,5,5,3,5,7,5,5};
    int a2[] = {0,5,5,3,5,1,5,7};

    int x = 0;
    cin >> x;

    if (x == 1) {cout << Majority(a1, 8);}
    else {cout << Majority(a2, 8);}

    return 0;
}