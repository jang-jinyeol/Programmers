#include <string>
#include <set>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dirs)
{
    set<pair<pair<int, int>, pair<int, int>>> s;
    map<char, pair<int, int>> m = { {'U', {1, 0}},{ 'R',{ 0, 1 } },{ 'D',{ -1, 0 } },{ 'L',{ 0, -1 } } };
    int cur_row = 0, cur_col = 0, next_row, next_col;

    for (int i = 0; i < dirs.size(); i++)
    {
        if (abs(cur_row + m[dirs[i]].first) > 5 || abs(cur_col + m[dirs[i]].second) > 5)
            continue;
        next_row = cur_row + m[dirs[i]].first;
        next_col = cur_col + m[dirs[i]].second;
        s.insert({ { cur_row, cur_col }, { next_row, next_col } });
        s.insert({ { next_row, next_col }, { cur_row, cur_col } });
        cur_row = next_row;
        cur_col = next_col;
    }

    return s.size() / 2;
}

int main() {

  cout << solution("ULURRDLLL");
}
