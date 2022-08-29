#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> front, pair<int, double> back) {
  if (front.second < back.second) {
    return false;
  } else if (front.second == back.second) {
    return !(front.first > back.first);
  } else {
    return true;
  }
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  vector<int> fail(N+1, 0);
  vector<int> tried(N+1, 0);
  for (int userPos : stages) {
    for (int stage=1; stage<=N; ++stage) {
      if (userPos >= stage) {
        ++tried[stage];
      }
    }
    if (userPos != N+1) {
      ++fail[userPos];
    }
  }
  vector<pair<int, double>> failities;
  for (int stage=1; stage<=N; ++stage) {
    double faility = fail[stage] / (double)tried[stage];
    failities.push_back({stage, faility});
  }
  sort(failities.begin(), failities.end(), compare);
  for (auto faility : failities) {
    answer.push_back(faility.first);
  }
  return answer;
}

int main() {
  vector<int> stages = {4, 4, 4, 4, 4};
  int N = 4;
  vector<int> answer = solution(N, stages);
  for (auto a : answer) {
    cout << a << ' ';
  }
  cout << '\n';
  return 0;
}