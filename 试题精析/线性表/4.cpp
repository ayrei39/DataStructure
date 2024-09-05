// 2011全国试题42 15'

#include <algorithm>
#include <iostream>
using namespace std;

int findMid(int a1[], int a2[], int n) {
  int l1 = 0, l2 = 0, r1 = n - 1, r2 = n - 1;
  int m1, m2;
  while (l1 < r1 || l2 < r2) {
    m1 = (l1 + r1) >> 1;
    m2 = (l2 + r2) >> 1;
    if (a1[m1] == a2[m2])
      return a1[m1];

    if (a1[m1] > a2[m2]) {
      if ((l1 + r1) % 2 == 0) {
        r1 = m1;
        l2 = m2;
      } else {
        r1 = m1;
        l2 = m2 + 1;
      }
    } else {
      if ((l1 + r1) % 2 == 0) {
        l1 = m1;
        r2 = m2;
      } else {
        l1 = m1 + 1;
        r2 = m2;
      }
    }
  }

  return (a1[l1] < a2[l2]) ? a1[l1] : a2[l2];
}

int main() {
  int a1[] = {1, 2, 3, 4, 5, 6};
  int a2[] = {7, 8, 9, 10, 11, 12};

  int res = findMid(a1, a2, 6);
  cout << res;

  return 0;
}
