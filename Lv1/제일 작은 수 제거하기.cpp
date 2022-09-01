#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() > 1) {
        auto minItem = min_element(arr.begin(), arr.end());
        arr.erase(minItem);
    } else {
        arr[0] = -1;
    }
    return arr;
}

int main() {
  vector<int> arr = {4, 3, 2, 1};
  vector<int> answer = solution(arr);
  for (int item : answer) {
    cout << item << ' ';
  }
  cout << '\n';
  return 0;
}