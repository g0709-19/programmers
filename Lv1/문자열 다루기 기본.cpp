#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(string s) {
    return (s.size() == 4 || s.size() == 6) && regex_match(s, regex("\\d+"));
}

int main() {
  if ((solution("a234") == false) && (solution("1234") == true)) {
    cout << "테스트 통과\n";
  } else {
    cout << "테스트 실패\n";
  }
  return 0;
}