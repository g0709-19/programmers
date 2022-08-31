#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i<n; ++i) {
        int combined = arr1[i] | arr2[i];
        string binary = "";
        for (int j=0; j<n; ++j) {
            binary += " ";
        }
        int binaryIndex = n - 1;
        while (combined != 0) {
            binary[binaryIndex] = (combined % 2 == 1 ? '#' : ' ');
            --binaryIndex;
            combined /= 2;
        }
        answer.push_back(binary);
    }
    return answer;
}

int main() {
  int n = 5;
  vector<int> arr1 = {9, 20, 28, 18, 11};
  vector<int> arr2 = {30, 1, 21, 17, 28};
  vector<string> answer = solution(n, arr1, arr2);
  for (string s : answer) {
    cout << s << '\n';
  }
  return 0;
}