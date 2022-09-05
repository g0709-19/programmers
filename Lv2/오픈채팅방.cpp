#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> split(string &str) {
    stringstream ss(str);
    string temp;
    vector<string> splited;
    while (ss >> temp) {
        splited.push_back(temp);
    }
    return splited;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nicknames;
    for (string history : record) {
        vector<string> splited = split(history);
        if (splited[0] == "Enter" || splited[0] == "Change") {
            nicknames[splited[1]] = splited[2];
        }
    }
    for (string history : record) {
        vector<string> splited = split(history);
        if (splited[0] == "Enter") {
            answer.push_back(nicknames[splited[1]] + "님이 들어왔습니다.");
        } else if (splited[0] == "Leave") {
            answer.push_back(nicknames[splited[1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}

int main() {
  vector<string> record = {
    "Enter uid1234 Muzi",
    "Enter uid4567 Prodo",
    "Leave uid1234",
    "Enter uid1234 Prodo",
    "Change uid4567 Ryan"
  };
  vector<string> answer = solution(record);
  for (auto s : answer) {
    cout << s << '\n';
  }
  return 0;
}