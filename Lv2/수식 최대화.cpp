#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long getResultByOperator(long long a, long long b, char op) {
  if (op == '+') return a + b;
  else if (op == '-') return a - b;
  else if (op == '*') return a * b;
  else return 0;
}

long long getResult(vector<long long> numbers, vector<char> ops, const vector<char> &opOrder) {
  for (auto op : opOrder) {
    for (int i=0; i<ops.size(); ++i) {
      if (ops[i] == op) {
        long long temp = getResultByOperator(numbers[i], numbers[i+1], op);
        numbers[i] = temp;
        numbers.erase(numbers.begin() + i + 1);
        ops.erase(ops.begin()+i);
        --i;
      }
    }
  }
  return numbers[0];
}

long long answer = 0;
vector<bool> visited;
vector<char> ops = {'+', '-', '*'};
vector<long long> numberVector;
vector<char> opVector;
void dfs(int count, vector<char> &v, const string &exp) {
  if (count == 0) {
    long long result = getResult(numberVector, opVector, v);
    result = (result < 0 ? result * -1 : result);
    answer = (answer < result ? result : answer);
  } else {
    for (int i=0; i<ops.size(); ++i) {
      if (!visited[i]) {
        visited[i] = true;
        v.push_back(ops[i]);
        dfs(count-1, v, exp);
        v.pop_back();
        visited[i] = false;
      }
    }
  }
}

long long solution(string exp) {
  string number;
  for (char c : exp) {
    if (c >= '0' && c<= '9') {
      number += c;
    } else {
      numberVector.push_back(stoi(number));
      number = "";
      opVector.push_back(c);
    }
  }
  numberVector.push_back(stoll(number));
  for (auto it=ops.begin(); it!=ops.end(); ++it) {
    if (exp.find(*it, 0) == string::npos) {
      ops.erase(it);
      --it;
    }
  }
  int opAmount = ops.size();
  visited = vector<bool>(opAmount);
  vector<char> v;
  dfs(opAmount, v, exp);
  return answer;
}

int main() {
  cout << (solution("100-200*300-500+20") == 60420 ? "통과" : "실패") << '\n';
  return 0;
}