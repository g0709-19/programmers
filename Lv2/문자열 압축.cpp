#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getLengthOfNumber(int num) {
  int length = 1;
  while (num >= 10) {
    ++length;
    num /= 10;
  }
  return length;
}

int solution(string s) {
  int answer = 1001;
  for (int k = 1; k <= s.size(); ++k) {
    int index = 0;
    int length = 0;
    while (index < s.size()) {
      int count = 1;
      bool isNotFound = false;
      string last = s.substr(index, k);
      // 연속되는 중복 문자열이 있는지 검사
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
      // 중복 문자열 없거나 모든 문자열을 검사했으면 길이 저장
      if (isNotFound || index >= s.size()) {
        length += last.size();
        if (count > 1) {
          length += getLengthOfNumber(count);
        }
      }
    }
    answer = min(answer, length);
  }
  return answer;
}

int main()
{
  string s = "aabbaccc";
  int answer = solution(s);
  cout << "answer: " << answer << '\n';
  return 0;
}