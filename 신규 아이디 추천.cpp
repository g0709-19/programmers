#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAlphabetUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isAlphabetLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

string getRemovedStartEndDot(string new_id) {
    int start = 0;
    int end = new_id.size();
    if (new_id[0] == '.') {
        ++start;
    }
    if (new_id[end-1] == '.') {
        --end;
    }
    return new_id.substr(start, end);
}

string solution(string new_id) {
    // Lv1
    for (int i=0; i<new_id.size(); ++i) {
        if (isAlphabetUpperCase(new_id[i])) {
            new_id[i] -= ('A' - 'a');
        }
    }
    // Lv2
    string temp = "";
    for (int i=0; i<new_id.size(); ++i) {
        if (isAlphabetLowerCase(new_id[i]) || isNumber(new_id[i])
           || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            temp += new_id[i];
        }
    }
    new_id = temp;
    // Lv3
    temp = "";
    bool isDot = false;
    for (int i=0; i<new_id.size(); ++i) {
        if (new_id[i] == '.') {
            if (isDot) {
                continue;
            }
            isDot = true;
        } else {
            isDot = false;
        }
        temp += new_id[i];
    }
    new_id = temp;
    // Lv4
    new_id = getRemovedStartEndDot(new_id);
    // Lv5
    if (new_id.size() == 0) {
        new_id += "a";
    }
    // Lv6
    new_id = new_id.substr(0, 15);
    new_id = getRemovedStartEndDot(new_id);
    // Lv7
    while (new_id.size() <= 2) {
        new_id += new_id[new_id.size()-1];
    }
    return new_id;
}

int main() {
  string new_id = "=.=";
  string answer = solution(new_id);
  cout << answer << '\n';
  return 0;
}