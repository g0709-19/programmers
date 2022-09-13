#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothTypeNameMap;
    for (auto cloth : clothes) {
        ++clothTypeNameMap[cloth[1]];
    }
    for (auto iter=clothTypeNameMap.begin(); iter!=clothTypeNameMap.end(); ++iter) {
        answer *= iter->second + 1;
    }
    return answer - 1;
}

int main() {
  vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
  int answer = solution(clothes);
  cout << answer << " " << (answer == 5 ? "O" : "X") << '\n';
  return 0;
}