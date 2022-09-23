#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toKNotation(int n, int k) {
  string notation;
  while (n != 0) {
    notation += (n % k) + '0';
    n /= k;
  }
  reverse(notation.begin(), notation.end());
  return notation;
}

vector<string> getToken(string s, char delim) {
  vector<string> token;
  string temp;
  for (char c : s) {
    if (c != delim) {
      temp += c;
    } else if (temp.size() != 0) {
      token.push_back(temp);
      temp = "";
    }
  }
  if (temp.size() != 0) {
    token.push_back(temp);
  }
  return token;
}

bool isPrime(int n) {
  if (n == 1) {
    return false;
  }
  for (int i=2; i*i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int solution(int n, int k) {
    int answer = 0;
    auto tokens = getToken(toKNotation(n, k), '0');
    for (auto token : tokens) {
      if (isPrime(stoi(token))) {
        ++answer;
      }
    }
    return answer;
}

int main() {
  cout << solution(437674, 3) << '\n';
  cout << solution(110011, 10) << '\n';
  return 0;
}