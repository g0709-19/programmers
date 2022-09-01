#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> apeachInfo;
pair<int, vector<int>> higherCase = {0, vector<int>(1, -1)};

void find(int scoreIndex, int arrow, vector<int> lionInfo) {
  if (scoreIndex == 11) {
    lionInfo[scoreIndex-1] += arrow;

    int apeachScore = 0;
    int lionScore = 0;
    for (int score=10; score>=0; --score) {
      int scoreIndex = 10 - score;
      int apeachCount = apeachInfo[scoreIndex];
      int lionCount = lionInfo[scoreIndex];
      if (apeachCount != 0 || lionCount != 0) {
        if (apeachCount >= lionCount) {
          apeachScore += score;
        } else {
          lionScore += score;
        }
      }
    }
    if (lionScore > apeachScore) {
      int difference = lionScore - apeachScore;
      if (difference > higherCase.first) {
        higherCase = {difference, lionInfo};
      } else if (difference == higherCase.first) {
        for (int score=0; score<=10; ++score) {
          int scoreIndex = 10 - score;
          if (higherCase.second[scoreIndex] < lionInfo[scoreIndex]) {
            higherCase = {difference, lionInfo};
            break;
          }
        }
      }
    }

    lionInfo[scoreIndex-1] -= arrow;
  } else {
    if (arrow > apeachInfo[scoreIndex]) {
      int usedArrow = apeachInfo[scoreIndex] + 1;
      lionInfo[scoreIndex] += usedArrow;
      find(scoreIndex+1, arrow-usedArrow, lionInfo);
      lionInfo[scoreIndex] -= usedArrow;
    }
    find(scoreIndex+1, arrow, lionInfo);
  }
}

vector<int> solution(int n, vector<int> info) {
  vector<int> answer;
  apeachInfo = info;
  find(0, n, vector<int>(11, 0));
  answer = higherCase.second;
  return answer;
}

int main() {
  int n = 10;
  vector<int> apeachInfo = {0,0,0,0,0,0,0,0,3,4,3};
  vector<int> lionInfo = solution(n, apeachInfo);
  for (int lionScore : lionInfo) {
    cout << lionScore << ' ';
  }
  cout << '\n' << countRecr << '\n';
  return 0;
}