#include <string>
#include <vector>
#include <algorithm>
#include <iostream>;
using namespace std;

bool compare(const string& a, const string& b) {

    if (a + b > b + a)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string>v;
    for (int i = 0; i < numbers.size(); i++)
    v.push_back((to_string(numbers[i])));

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        answer += v[i];

    if (answer[0] == '0')
        return "0";
    return answer;
}

int main(void) {

    vector<int>test = { 3,30,34,5,9 };
    cout << solution(test);

    return 0;
}