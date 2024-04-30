#include <exception>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// does not properly work because of c++ things i think
void merge(std::vector<int> &vec, int p, int q, int r) {
  // A[p,r] = A[p,q] ++ A[q+1,r]
  int nl = q - p + 1;
  int nr = r - q;
  int left[nl];
  int right[nr];

  for (int i = 0; i < nl; i++) {
    int tmp = vec[p + i];
    left[i] = tmp;
  }
  for (int i = 0; i < nr; i++) {
    int tmp = vec[i + q + 1];
    right[i] = tmp;
  }

  int li = 0;
  int ri = 0;
  int ki = p;
  while (li < nl and ri < nr) {
    if (left[li] <= right[ri]) {
      vec[ki++] = left[li++];
    } else {
      vec[ki++] = right[ri++];
    }
  }
  while (li < nl) {
    vec[ki++] = left[li];
    li++;
  }
  while (ri < nr) {
    vec[ki++] = right[ri];
    ri++;
  }
}

void merge_sort(std::vector<int> &vec, int p, int r) {
  if (p >= r) {
    return;
  }
  int q = floor((p + r) / 2);
  merge_sort(vec, p, q);
  merge_sort(vec, q + 1, r);
  merge(vec, p, q, r);
}

// compile with `g++ --std=c++11`
int main() {
  vector<int> something = {4, 1, 245, 2, 8, -12,    1, 2, -20, 40, 5,  -600, 7,
                           8, 9, 0,   1, 2, 102030, 4, 5, 6,   7,  14, 9};

  merge_sort(something, 0, something.size() - 1);
  for (int i = 0; i < something.size(); i++) {
    cout << something[i] << endl;
  }

  // vector<int> merge_test = {2, 3, 5, 8, 9, -200, 0, 1, 3, 6};
  // merge(merge_test, 0, 4, merge_test.size() - 1);
  // cout << "\n" << endl;
  // for (int i = 0; i < merge_test.size(); i++) {
  //   cout << merge_test[i] << endl;
  // }

  return 0;
}
