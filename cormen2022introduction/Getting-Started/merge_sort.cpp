#include <exception>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(std::vector<int> &vec) { throw new exception; }

// does not properly work because of c++ things i think
void merge(std::vector<int> &vec, int p, int q, int r) {
  // A[p,r] = A[p,q] ++ A[q+1,r]
  int nl = q - p + 1;
  int nr = r - q;
  int left[nl];
  int right[nr];

  for (int i = 0; i < nl; i++) {
    int tmp = vec[i];
    left[i] = tmp;
  }
  for (int i = 0; i < nr; i++) {
    int tmp = vec[i + q + 1];
    right[i] = tmp;
  }

  int li = 0;
  int ri = 0;
  for (int i = 0; i < r - p; i++) {
    if (i > nl or i > nr) {
      break;
    }
    if (left[li] <= right[ri]) {
      vec[i] = left[li];
      li++;
    } else {
      vec[i] = right[ri];
      ri++;
    }
  }
  while (li < nl) {
    vec[li + ri] = left[li];
    li++;

  }
  while (ri < nr) {
    vec[li + ri] = right[ri];
    ri++;
  }
}

// compile with `g++ --std=c++11`
int main() {
  vector<int> something = {4, 1, 245, 2, 8, 5, 1, 2, 3, 4, 5, 6, 7,
                           8, 9, 0,   1, 2, 3, 4, 5, 6, 7, 8, 9};
  // merge_sort(something);
  // for (int i = 0; i < something.size(); i++) {
  //   cout << something[i] << endl;
  // }

  vector<int> merge_test = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
  merge(merge_test, 0, 4, merge_test.size() - 1);
  for (int i = 0; i < merge_test.size(); i++) {
    cout << merge_test[i] << endl;
  }

  return 0;
}
