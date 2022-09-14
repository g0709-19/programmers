#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getLowerCase(string s) {
  for (auto i=s.begin(); i!=s.end(); ++i) {
    if (*i >= 'A' && *i <= 'Z') {
      *i -= ('A'-'a');
    }
  }
  return s;
}

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  vector<string> cache;
  for (string city : cities) {
    auto begin = cache.begin();
    auto iter = cache.end();
    if (cache.size() > 3) {
      begin = cache.end() - 3;
    }
    city = getLowerCase(city);
    if ((iter = find(begin, cache.end(), city)) != cache.end()) {
      answer += 1;
      cache.erase(iter);
      cache.push_back(city);
    } else {
      answer += 5;
      cache.push_back(city);
    }
  }
  return answer;
}

int main () {
  int cacheSize = 5;
  vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
  int answer = solution(cacheSize, cities);
  cout << answer << " " << (answer == 52 ? "O" : "X") << '\n';
  return 0;
}