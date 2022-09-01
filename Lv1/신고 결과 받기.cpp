#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    set<string> bannedUsers;
    unordered_map<string, set<string>> reportedUsers;
    unordered_map<string, int> reportedCount;
    // 신고 횟수 count
    for (int i=0; i<report.size(); ++i) {
        string reporter, reportedUser;
        stringstream ss(report[i]);
        ss >> reporter >> reportedUser;
        if (reportedUsers[reporter].find(reportedUser) == reportedUsers[reporter].end()) {
            ++reportedCount[reportedUser];
            if (reportedCount[reportedUser] >= k) {
                bannedUsers.insert(reportedUser);
            }
            reportedUsers[reporter].insert(reportedUser);
        }
    }
    
    // 정지 결과 count
    for (int i=0; i<id_list.size(); ++i) {
        string userId = id_list[i];
        for (string bannedUser : bannedUsers) {
            if (reportedUsers[userId].find(bannedUser) != reportedUsers[userId].end()) {
                ++answer[i];
            }
        }
    }
    
    return answer;
}

int main() {
  // vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
  // vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
  vector<string> id_list = {"con", "ryan"};
  vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
  // int k = 2;
  int k = 3;
  vector<int> answer = solution(id_list, report, k);
  for (auto a : answer) {
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}