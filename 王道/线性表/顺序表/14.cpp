// 2020

// D = 2L

// answer
#include<iostream>
using namespace std;
int min_D = __INT_MAX__;
int findMinofTrip(int a[], int b[], int c[], int l1, int l2, int l3){
    int i = 0, j = 0, k = 0;
    int tmp = 0;
    while(i < l1 && j < l2 && k < l3){
        tmp = abs(a[i] - b[j]) + abs(b[j] - c[k]) + abs(c[k] - a[i]);
        if(tmp < min_D){
            min_D = tmp;
        }
        if (a[i] < b[j] && a[i] < c[k]) i++;
        else if (b[j] < a[i] && b[j] < c[k]) j++;
        else k++;
    }
    return min_D;
}

int main(){
    int a[] = {-1,0,9};
    int b[] = {-25,-10,10,11};
    int c[] = {2,9,17,30,41};

    cout << findMinofTrip(a, b, c, 3, 5, 5) << endl;
    return 0;
}
