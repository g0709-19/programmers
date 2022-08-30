#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
using Point = pair<int, int>;

Point leftHandPos = {3, 0}, rightHandPos = {3, 2};
const Point NUMBER_POSITION[] = {
  {3, 1}, {0, 0}, {0, 1}, {0, 2},
  {1, 0}, {1, 1}, {1, 2},
  {2, 0}, {2, 1}, {2, 2}
};
const int LEFT_NUMBER[] = {1, 4, 7};
const int RIGHT_NUMBER[] = {3, 6, 9};

char getFinger(int toPress, string hand) {
  char finger = 0;
  bool isSelected = false;
  for (int leftNumber : LEFT_NUMBER) {
    if (toPress == leftNumber) {
      finger = 'L';
      isSelected = true;
      break;
    }
  }
  if (!isSelected) {
    for (int rightNumber : RIGHT_NUMBER) {
      if (toPress == rightNumber) {
        finger = 'R';
        isSelected = true;
        break;
      }
    }
  }
  if (!isSelected) {
    int x = NUMBER_POSITION[toPress].first;
    int y = NUMBER_POSITION[toPress].second;
    int leftFingerDistance = abs(x - leftHandPos.first) + abs(y - leftHandPos.second);
    int rightFingerDistance = abs(x - rightHandPos.first) + abs(y - rightHandPos.second);
    if (leftFingerDistance < rightFingerDistance) {
      finger = 'L';
    } else if (leftFingerDistance > rightFingerDistance) {
      finger = 'R';
    } else {
      finger = (hand == "right" ? 'R' : 'L');
    }    
  }
  if (finger == 'R') {
    rightHandPos = NUMBER_POSITION[toPress];
  } else {
    leftHandPos = NUMBER_POSITION[toPress];
  }
  return finger;
}

string solution(vector<int> numbers, string hand) {
  string answer = "";
  for (int toPress : numbers) {
    answer += getFinger(toPress, hand);
  }
  return answer;
}

int main() {
  vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
  string hand = "right";
  cout << solution(numbers, hand) << '\n';
  return 0;
}