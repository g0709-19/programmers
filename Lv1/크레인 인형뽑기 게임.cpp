#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  const int BOARD_HEIGHT = board.size();
  const int MOVE_LENGTH = moves.size();
  stack<int> basket;

  for (int i=0; i<MOVE_LENGTH; ++i) {
    int toSelect = moves[i] - 1;
    for (int row=0; row<BOARD_HEIGHT; ++row) {
      int doll = board[row][toSelect];
      // 가장 위에 있는 인형 선택
      if (doll != 0) {
        // 바구니에 가장 나중에 들어온 인형과 같다면 제거
        if (!basket.empty() && basket.top() == doll) {
          answer += 2;
          basket.pop();
        } else {
          basket.push(doll);
        }
        board[row][toSelect] = 0;
        break;
      }
    }
  }

  return answer;
}

int main() {
  vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  vector<int> moves = {1,5,3,5,1,2,1,4};
  int answer = solution(board, moves);
  cout << "answer: " << answer << '\n';
  return 0;
}