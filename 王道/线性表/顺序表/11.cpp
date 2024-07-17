// 2021真题

// 先合并，再求中位数

// answer
/*
1. 2个数组分别求中位数a,b
2. if a == b -> a
3. if a < b -> A取后半截，B取前半截
4. if a > b -> A取前半截，B取后半截
4. 递归 直到len(A,B) == 1 ,res = a,b较小值
*/
// 时间复杂度：O(log(n)) 空间复杂度：O(1)

#include<iostream>
#include <windows.h>
using namespace std;

void findMiddle(int *A, int *B, int len) {
    int l1 = 0, l2 = 0, r1 = len - 1, r2 = len - 1;
    while (l1 < r1 && l2 < r2) {
        int mid1 = (l1 + r1) / 2;
        int mid2 = (l2 + r2) / 2;
        if (A[mid1] == B[mid2]) {
            cout << A[mid1] << endl;
            return;
        }

        if (A[mid1] < B[mid2]) {
            // 截取时需要考虑长度的奇偶
            if((r1 - l1 + 1) % 2 == 1){
                l1 = mid1;
                r2 = mid2;
            } else {
                l1 = mid1 + 1;
                r2 = mid2;
            }
        } else {
            if((r1 - l1 + 1) % 2 == 1){
                r1 = mid1;
                l2 = mid2;
            } else {
                r1 = mid1;
                l2 = mid2 + 1;
            }
        }
    }
    cout << min(A[l1], B[l2]) << endl;
}

int main() {
    int s1[] = {11,13,15,17,19};
    int s2[] = {2,4,6,8,20};

    findMiddle(s1, s2, 5);
    
    return 0;
}

// 方法二： 双指针顺序遍历，遍历次数=总长度的一半， 时间复杂度：O(n) 空间复杂度：O(1)