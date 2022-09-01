#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  const vector<int> SUPOJA_ANSWER[3] = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
  };
  vector<int> supojaCorrectCount(3, 0);
  for (int i=0; i<answers.size(); ++i) {
    for (int supojaIndex=0; supojaIndex<3; ++supojaIndex) {
      vector<int> supojaAnswer = SUPOJA_ANSWER[supojaIndex];
      int answerIndex = i % supojaAnswer.size();
      if (supojaAnswer[answerIndex] == answers[i]) {
          ++supojaCorrectCount[supojaIndex];
      }
    }
  }
  auto _max = max_element(
    supojaCorrectCount.begin(),supojaCorrectCount.end());
  for (int i=0; i<3; ++i) {
    if (supojaCorrectCount[i] == *_max) {
      answer.push_back(i+1);
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}

int main() {
  vector<int> answers = {1, 3, 2, 4, 2};
  vector<int> answer = solution(answers);
  for (int a : answer) {
    cout << a << " ";
  }
  cout << '\n';
  return 0;
}