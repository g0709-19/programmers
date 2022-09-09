#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> slice(string s, string delimiter) {
  vector<string> sliced;
  size_t start = 0, end = 0;
  while ((end = s.find(delimiter, start)) != string::npos) {
    sliced.push_back(s.substr(start, end - start));
    start = end + 1;
  }
  sliced.push_back(s.substr(start));
  return sliced;
}

vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;
  unordered_map<string, vector<int>> scoreMap;
  for (string s : info) {
    auto sliced = slice(s, " ");
    // 일어날 수 있는 모든 경우의 수를 맵에 저장
    // key: 해당 설문으로 만들어질 수 있는 모든 쿼리문
    // value: 점수 리스트
    for (int lang=0; lang<2; ++lang) {
      for (int job=0; job<2; ++job) {
        for (int career=0; career<2; ++career) {
          for (int food=0; food<2; ++food) {
            string newQuery = 
              (lang == 0 ? "-" : sliced[0])
              + (job == 0 ? "-" : sliced[1])
              + (career == 0 ? "-" : sliced[2])
              + (food == 0 ? "-" : sliced[3]);
            if (scoreMap.find(newQuery) == scoreMap.end()) {
              scoreMap[newQuery] = vector<int>();
            }
            scoreMap[newQuery].push_back(stoi(sliced[4]));
          }
        }
      }
    }
  }
  // 이진 탐색(lower bound) 를 사용하기 전 필요한 정렬
  for (auto iter=scoreMap.begin(); iter!=scoreMap.end(); ++iter) {
    sort(iter->second.begin(), iter->second.end());
  }
  for (string s : query) {
    auto sliced = slice(s, " ");
    string scoreQuery = sliced[0] + sliced[2] + sliced[4] + sliced[6];
    int score = stoi(sliced[7]);
    int count = 0;
    // 쿼리문에 대응되는 설문이 있다면 점수 리스트에서 lower bound 로 그 점수를 탐색
    // lower bound 는 찾는 값이 없다면 찾는 값보다 큰 값 중 가장 작은 값을 반환함
    if (scoreMap.find(scoreQuery) != scoreMap.end()) {
      auto start = lower_bound(scoreMap[scoreQuery].begin(), scoreMap[scoreQuery].end(), score);
      if (start != scoreMap[scoreQuery].end()) {
        count += scoreMap[scoreQuery].end() - start;
      }
    }
    answer.push_back(count);
  }
  return answer;
}

int main() {
  vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
  vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
  vector<int> answer = solution(info, query);
  vector<int> check = {1, 1, 1, 1, 2, 4};
  for (int i=0; i<answer.size(); ++i) {
    cout << answer[i] << " == " << check[i] << " = " << (answer == check) << '\n';
  }
  return 0;
}