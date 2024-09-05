// 2010全国试题42 13'

#include <algorithm>
#include <iostream>
using namespace std;

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
