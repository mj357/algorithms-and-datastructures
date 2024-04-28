#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(std::vector<int> &vec) {
  for (int i = 1; i < vec.size(); i++) {
    int elem = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j] > elem) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = elem;
  }
}

int main() {
  vector<int> something = {4, 1, 245, 2, 8, 5, 1, 2, 3, 4, 5, 6, 7,
                           8, 9, 0,   1, 2, 3, 4, 5, 6, 7, 8, 9};
  insertion_sort(something);
  for (int i = 0; i < something.size(); i++) {
    cout << something[i] << endl;
  }
  return 0;
}
