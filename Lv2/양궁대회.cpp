#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> apeachInfo;
pair<int, vector<int>> higherCase = {0, vector<int>(1, -1)};

int getScoreDifferenceWithApeach(vector<int> &ryanInfo) {
  int apeachScore = 0;
  int ryanScore = 0;
  for (int scoreIndex=0; scoreIndex<=10; ++scoreIndex) {
    const int SCORE = 10 - scoreIndex;
    if (apeachInfo[scoreIndex] != 0 || ryanInfo[scoreIndex] != 0) {
      if (apeachInfo[scoreIndex] >= ryanInfo[scoreIndex]) {
        apeachScore += SCORE;
      } else {
        ryanScore += SCORE;
      }
    }
  }
  return ryanScore - apeachScore;
}

void find(int scoreIndex, int remainedArrows, vector<int> ryanInfo) {
  if (scoreIndex == 11 || remainedArrows == 0) {
    ryanInfo[scoreIndex - 1] += remainedArrows;
    // 점수차 계산
    int difference = getScoreDifferenceWithApeach(ryanInfo);
    if (difference > 0) {
      if (difference == higherCase.first) {
        // 가장 낮은 점수 큰 쪽으로
        for (int lowerScoreIndex=10; lowerScoreIndex>=0; --lowerScoreIndex) {
          if (ryanInfo[lowerScoreIndex] > higherCase.second[lowerScoreIndex]) {
            higherCase = {difference, ryanInfo};
            break;
          } else if (ryanInfo[lowerScoreIndex] < higherCase.second[lowerScoreIndex]) {
            break;
          }
        }
      } else if (difference > higherCase.first) {
        higherCase = {difference, ryanInfo};
      }
    }
    ryanInfo[scoreIndex - 1] -= remainedArrows;
  } else {
    if (remainedArrows > apeachInfo[scoreIndex]) {
      ryanInfo[scoreIndex] += (apeachInfo[scoreIndex] + 1);
      find(scoreIndex + 1, remainedArrows - apeachInfo[scoreIndex] - 1, ryanInfo);
      ryanInfo[scoreIndex] -= (apeachInfo[scoreIndex] + 1);
    }
    find(scoreIndex + 1, remainedArrows, ryanInfo);
  }
}

vector<int> solution(int n, vector<int> info) {
  apeachInfo = info;
  find(0, n, vector<int>(11, 0));
  return higherCase.second;
}

int main() {
  int n = 9;
  vector<int> apeachInfo = {0,0,1,2,0,1,1,1,1,1,1};
  vector<int> lionInfo = solution(n, apeachInfo);
  for (int lionScore : lionInfo) {
    cout << lionScore << ' ';
  }
  cout << '\n';
  return 0;
}