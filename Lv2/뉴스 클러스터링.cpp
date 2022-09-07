#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char getLowerCase(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - ('A' - 'a');
  } else {
    return c;
  }
}

bool isAlphabet(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

vector<string> getSlicedByTwo(string s) {
  vector<string> slicedSet;
  for (int i=0; i<s.size(); ++i) {
    string sliced = s.substr(i, 2);
    if (isAlphabet(sliced[0]) && isAlphabet(sliced[1])) {
      slicedSet.push_back(
        string({getLowerCase(sliced[0]), getLowerCase(sliced[1])})
      );
    }
  }
  return slicedSet;
}

int getIntersectionSize(vector<string> set1, vector<string> set2) {
  vector<string> smaller;
  vector<string> bigger;
  if (set1.size() > set2.size()) {
    bigger = set1;
    smaller = set2;
  } else {
    bigger = set2;
    smaller = set1;
  }
  
  int intersectionSize = 0;
  for (string token : smaller) {
    auto iter = find(bigger.begin(), bigger.end(), token);
    if (iter != bigger.end()) {
      ++intersectionSize;
      *iter = "\0";
    }
  }
  return intersectionSize;
}

int solution(string str1, string str2) {
  int answer = 0;
  vector<string> slicedStr1 = getSlicedByTwo(str1);
  vector<string> slicedStr2 = getSlicedByTwo(str2);
  if (slicedStr1.size() != 0 || slicedStr2.size() != 0) {
    int intersectionSize = getIntersectionSize(slicedStr1, slicedStr2);
    int unionAmount = slicedStr1.size() + slicedStr2.size() - intersectionSize;
    answer = intersectionSize / (double)unionAmount * 65536;
  } else {
    answer = 65536;
  }
  return answer;
}

int main() {
  // string str1 = "FRANCE";
  // string str2 = "french";
  // string str1 = "aa1+aa2";
  // string str2 = "AAAA12";
  string str1 = "E=M*C^2";
  string str2 = "e=m*c^2";
  int answer = solution(str1, str2);
  cout << answer << '\n';
  return 0;
}