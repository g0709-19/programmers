#include <string>
#include <vector>

using namespace std;

typedef struct {
    string name;
    int number;
} Number;

int solution(string s) {
    int answer = 0;

    vector<vector<Number>> numbers(6, vector<Number>());
    numbers[3].push_back({ "one", 1 });
    numbers[3].push_back({ "two", 2 });
    numbers[3].push_back({ "six", 6 });
    numbers[4].push_back({ "zero", 0 });
    numbers[4].push_back({ "four", 4 });
    numbers[4].push_back({ "five", 5 });
    numbers[4].push_back({ "nine", 9 });
    numbers[5].push_back({ "three", 3 });
    numbers[5].push_back({ "seven", 7 });
    numbers[5].push_back({ "eight", 8 });

    string result = "";
    bool isEnd = false;
    for (int first = 0; first < s.length(); ++first) {
        if (s[first] >= '0' && s[first] <= '9') {
            result += s[first];
        }
        else {
            for (int i = 3; i <= 5; ++i) {
                for (Number number : numbers[i]) {
                    string toCompare = number.name;
                    bool isAllEqual = true;
                    for (int j = 0; j < i; ++j) {
                        if (s[first + j] != toCompare[j]) {
                            isAllEqual = false;
                            break;
                        }
                    }
                    if (isAllEqual) {
                        result += to_string(number.number);
                        first += i - 1;
                        isEnd = true;
                        break;
                    }
                }
                if (isEnd) {
                    break;
                }
            }
        }
    }

    answer = stoi(result);

    return answer;
}
