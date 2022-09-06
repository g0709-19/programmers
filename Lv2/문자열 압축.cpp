#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
  int answer = 1001;
  for (int k = 1; k <= s.size(); ++k) {
    int index = 0;
    int length = 0;
    while (index < s.size()) {
      int count = 1;
      bool isNotFound = false;
      string last = s.substr(index, k);
      for (index = index + k; index < s.size(); index += k) {
        string crop = s.substr(index, k);
        if (last == crop) {
          ++count;
          last = crop;
        }
        else {
          isNotFound = true;
          break;
        }
      }
      if (isNotFound || index >= s.size()) {
        length += last.size();
        if (count > 1) {
          ++length;
        }
      }
    }
    answer = min(answer, length);
  }
  return answer;
}

int main()
{
  // string s = "aabbaccc";
  string s = "xababcdcdababcdcd";
  int answer = solution(s);
  cout << "answer: " << answer << '\n';
  return 0;
}