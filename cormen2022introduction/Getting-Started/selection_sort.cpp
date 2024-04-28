#include <iostream>
#include <vector>

using namespace std;

void selection_sort(std::vector<int> &vec) {
  // do this n - 1 times
  for (int i = 0; i < vec.size() - 1; i++) {
    int elem = vec[i];
    int smallest_idx = i;
    // swap smallest elment of vec[0:n] with vec[i]
    for (int j = i; j < vec.size(); j++) {
      if (vec[j] < vec[smallest_idx]) {
        smallest_idx = j;
      }
    }
    vec[i] = vec[smallest_idx];
    vec[smallest_idx] = elem;
  }
}

// compile with `g++ --std=c++11`
int main() {
  vector<int> something = {4, 1, 245, 2, 8, 5, 1, 2, 3, 4, 5, 6, 7,
                           8, 9, 0,   1, 2, 3, 4, 5, 6, 7, 8, 9};
  selection_sort(something);
  for (int i = 0; i < something.size(); i++) {
    cout << something[i] << endl;
  }
  return 0;
}
