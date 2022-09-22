#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

string getPostfixNotation(string infix, unordered_map<char, int> priority) {
  string postfix = "";
  string number = "";
  stack<char> op;
  for (char c : infix) {
    if (c >= '0' && c <= '9') {
      number += c;
    } else {
      postfix += number + ";";
      number = "";
      if (!op.empty() && priority[op.top()] < priority[c]) {
        op.push(c);
      } else if (!op.empty() && priority[op.top()] >= priority[c]) {
        while (!op.empty()) {
          postfix += op.top();
          op.pop();
        }
        op.push(c);
      } else if (op.empty()) {
        op.push(c);
      }
    }
  }
  postfix += number + ";";
  while (!op.empty()) {
    postfix += op.top();
    op.pop();
  }
  return postfix;
}

long long getResultFromPostfix(string postfix) {
  string number = "";
  stack<long long> result;
  for (char c : postfix) {
    if (c >= '0' && c <= '9') {
      number += c;
    } else if (c == ';') {
      result.push(stoi(number));
      number = "";
    } else {
      long long second = result.top();
      result.pop();
      long long first = result.top();
      result.pop();
      long long temp = 0;
      switch (c) {
        case '+': temp = first + second; break;
        case '-': temp = first - second; break;
        case '*': temp = first * second; break;
      }
      result.push(temp);
    }
  }
  return result.top();
}

long long solution(string expression) {
  long long answer = 0;
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      for (int k=0; k<3; ++k) {
        if (i == j || i == k || j == k) continue;
        unordered_map<char, int> priority;
        priority['+'] = i;
        priority['-'] = j;
        priority['*'] = k;
        string postfix = getPostfixNotation(expression, priority);
        int result = getResultFromPostfix(postfix);
        result = (result < 0 ? result * -1 : result);
        answer = (answer < result ? result : answer);
      }
    }
  }
  return answer;
}

int main() {
  long long first = solution("100-200*300-500+20");
  long long second = solution("50*6-3*2");
  cout << first << " " << 60420 << " " << (first == 60420 ? "O" : "X") << '\n';
  cout << second << " " << 300 << " " << (second == 300 ? "O" : "X") << '\n';
  return 0;
}