#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using pp = pair<string, pair<string, int>>;

bool compare(const pp &a, const pp &b) {
  if (a.second.first == b.second.first) {
    if (a.second.second >= b.second.second) {
      return false;
    } else {
      return true;
    }
  } else if (a.second.first < b.second.first) {
    return true;
} else {
    return false;
  }
}

vector<string> solution(vector<string> files) {
  vector<string> answer;
  vector<pp> fileInfo;
  for (string fileName : files) {
    string head;
    string number;
    string tail;
    for (char c : fileName) {
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
      || c == ' ' || c == '.' || c == '-') {
        if (number.size() == 0) {
          head += c;
        } else {
          tail += c;
        }
      }
      if (c >= '0' && c <= '9') {
        if (tail.size() == 0) {
          number += c;                    
        } else {
          tail += c;
        }
      }
    }
    transform(head.begin(), head.end(), head.begin(), ::tolower);
    fileInfo.push_back({fileName, {head, stoi(number)}});
  }
  stable_sort(fileInfo.begin(), fileInfo.end(), compare);
  for (auto file : fileInfo) {
    answer.push_back(file.first);
  }
  return answer;
}

int main() {
  auto answer = solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-5 Tomcat"});
  for (auto a : answer) {
    cout << a << '\n';
  }
  return 0;
}