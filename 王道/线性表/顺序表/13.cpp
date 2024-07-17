// 2018

#include<iostream>
using namespace std;

void findMin(int a[], int len) {
    bool tmp[len+1];
    for (int i = 0; i < len+1; i++) {
        tmp[i] = false;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] >= 0 && a[i] < len+1) {
            tmp[a[i]] = true;
        }
    }
    for (int i = 1; i < len+1; i++) {
        if (tmp[i] == false) {
            cout << i << endl;
            return;
        }
    }
    cout << len+1 << endl;
}

int main(){
    int a1[] = {-5,3,2,3};
    int a2[] = {1, 2, 3};
    int x = 0;
    cin >> x;
    if (x == 1) {
        findMin(a1, 4);
    }
    else {
        findMin(a2, 3);
    }
    return 0;
}

// 时间：O(n) 空间：O(n)