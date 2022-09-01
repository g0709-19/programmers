#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int charToScore(char c) {
    return c - '0';
}

int charToBonus(char c) {
    if (c == 'S') {
        return 1;
    } else if (c == 'D') {
        return 2;
    } else if (c == 'T') {
        return 3;
    } else {
        return 0;
    }
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> scoreList;
    for (int pivot=0; pivot<dartResult.size();) {
        int score = 0;
        if (dartResult[pivot+1] >= '0' && dartResult[pivot+1] <= '9') {
            score = pow(charToScore(dartResult[pivot])*10+charToScore(dartResult[pivot+1]), charToBonus(dartResult[pivot+2]));
            ++pivot;
        } else {
            score = pow(charToScore(dartResult[pivot]), charToBonus(dartResult[pivot+1]));
        }
        if (dartResult[pivot+2] == '*') {
            if (!scoreList.empty()) {
                scoreList[scoreList.size()-1] *= 2;
            }
            score *= 2;
            pivot += 3;
        } else if (dartResult[pivot+2] == '#') {
            score *= -1;
            pivot += 3;
        } else {
            pivot += 2;
        }
        scoreList.push_back(score);
    }
    for (int score : scoreList) {
        answer += score;
    }
    return answer;
}

int main() {
    string dartResult = "1D2S#10S";
    int answer = solution(dartResult);
    cout << answer << '\n';
    return 0;
}