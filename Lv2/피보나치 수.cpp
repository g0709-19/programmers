#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  vector<int> fibo(n+1, 0);
  fibo[1] = 1;
  for (int i=2; i<=n; ++i) {
    fibo[i] = fibo[i-2] + fibo[i-1];
    fibo[i] %= 1234567;
  }
  return fibo[n];
}

int main() {
  if ((solution(3) == 2) && (solution(5) == 5)) {
    cout << "테스트 통과\n";
  } else {
    cout << "테스트 실패\n";
  }
  return 0;
}