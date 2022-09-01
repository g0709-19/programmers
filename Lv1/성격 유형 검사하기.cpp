#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> score;
    for (int surveyIndex=0; surveyIndex<survey.size(); ++surveyIndex) {
      string surveyItem = survey[surveyIndex];
      if (choices[surveyIndex] < 4) {
        score[surveyItem[0]] += 4 - choices[surveyIndex];
      } else if (choices[surveyIndex] > 4) {
        score[surveyItem[1]] += choices[surveyIndex] - 4;
      }
    }

    vector<pair<char, char>> items = {
      {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}
    };
    for (pair<char, char> item : items) {
      if (score[item.first] >= score[item.second]) {
        answer += item.first;
      } else if (score[item.first] < score[item.second]) {
        answer += item.second;
      }
    }
    return answer;
}

int main() {
  vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
  vector<int> choices = {5, 3, 2, 7, 5};
  string answer = solution(survey, choices);
  cout << answer << '\n';
  return 0;
}