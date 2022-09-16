#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> toIntVector(string s) {
  vector<vector<int>> intVector;
  int begin = 0;
  while ((begin = s.find('{', begin+1)) != string::npos) {
    int end = s.find('}', begin);
    string numbers = string(s.begin()+begin+1, s.begin()+end);
    stringstream ss(numbers);
    string temp;
    vector<int> tempVector;
    while (getline(ss, temp, ',')) {
      tempVector.push_back(stoi(temp));
    }
    intVector.push_back(tempVector);
  }
  return intVector;
}

bool compareIntVector(vector<int> &a, vector<int> &b) {
  return a.size() < b.size();
}

vector<int> solution(string s) {
  vector<int> answer;
  vector<vector<int>> intVector = toIntVector(s);
  sort(intVector.begin(), intVector.end(), compareIntVector);
  for (auto set : intVector) {
    for (auto num : set) {
      if (find(answer.begin(), answer.end(), num) == answer.end()) {
        answer.push_back(num);
      }
    }
  }
  return answer;
}

int main() {
  vector<string> sets = {
    "{{2},{2,1},{2,1,3},{2,1,3,4}}",
    "{{1,2,3},{2,1},{1,2,4,3},{2}}",
    "{{20,111},{111}}",
    "{{123}}",
    "{{4,2,3},{3},{2,3,4,1},{2,3}}"
  };
  vector<vector<int>> answers = {
    {2, 1, 3, 4},
    {2, 1, 3, 4},
    {111, 20},
    {123},
    {3, 2, 4, 1}
  };
  for (int i=0; i<sets.size(); ++i) {
    string set = sets[i];
    vector<int> answer = answers[i];
    vector<int> myAnswer = solution(set);
    bool isEqual = true;
    for (int j=0; j<answer.size() && j<myAnswer.size(); ++j) {
      if (answer[j] != myAnswer[j]) {
        isEqual = false;
        break;
      }
    }
    for (auto m : myAnswer) {
      cout << m << " ";
    }
    cout << (isEqual ? "O" : "X") << '\n';
  }
  cout << '\n';
  return 0;
}