#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> getToken(string s, char delim) {
    vector<int> v;
    string temp;
    for (char c : s) {
        if (c != delim) {
            temp += c;
        } else {
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    v.push_back(stoi(temp));
    return v;
}

int getSubbedMinute(string outTime, string inTime) {
    auto out = getToken(outTime, ':');
    auto in = getToken(inTime, ':');
    int sub = 0;
    if (out[1] < in[1]) {
        --out[0];
        sub += 60 - out[1] - in[1];
    } else {
        sub += out[1] - in[1];
    }
    sub += 60 * (out[0] - in[0]);
    return sub;
}

bool compare(const pair<int, int> &front, const pair<int, int> &back) {
    if (front.first < back.first) {
        return true;
    } else {
        return false;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, int> parkingTime;
    vector<pair<int, string>> parkingLot;
    for (string record : records) {
        istringstream is(record);
        string time, type;
        int number;
        is >> time >> number >> type;
        if (type == "IN") {
            parkingLot.push_back({number, time});
        } else {
            for (auto it=parkingLot.begin(); it!=parkingLot.end(); ++it) {
                if (it->first == number) {
                    string inTime = it->second;
                    int minute = getSubbedMinute(time, inTime);
                    parkingTime[number] += minute;
                    parkingLot.erase(it);
                    break;
                }
            }
        }
    }
    if (!parkingLot.empty()) {
        for (auto it=parkingLot.begin(); it!=parkingLot.end(); ++it) {
            string inTime = it->second;
            int minute = getSubbedMinute("23:59", inTime);
            parkingTime[it->first] += minute;
        }
    }
    vector<pair<int, int>> pv(parkingTime.begin(), parkingTime. end());
    sort(pv.begin(), pv.end(), compare);
    for (auto p : pv) {
        int fee = fees[1];
        if (p.second > fees[0]) {
            fee += ceil((p.second - fees[0]) / fees[2]) * fees[3];   
        }
        answer.push_back(fee);
    }
    return answer;
}

int main() {
  vector<vector<int>> fees = {
    {180, 5000, 10, 600}
    // {120, 0, 60, 591},
    // {1, 461, 1, 10}
  };
  vector<vector<string>> records = {
    {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"},
    {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"},
    {"00:00 1234 IN"}
  };
  vector<vector<int>> result = {
    {14600, 34400, 5000},
    {0, 591},
    {14841}
  };
  for (int i=0; i<fees.size(); ++i) {
    auto answer = solution(fees[i], records[i]);
    bool flag = true;
    for (int j=0; j<result[i].size(); ++j) {
      cout << answer[j] << '\t' << result[i][j] << '\n';
      if (answer[j] != result[i][j]) {
        flag = false;
      }
    }
    cout << "Test" << (i+1) << ": " << (flag ? "통과" : "실패") << '\n';
  }
  return 0;
}