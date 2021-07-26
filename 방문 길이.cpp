#include <string>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;



int solution(string dirs) {
    
    set<pair<pair<int,int>,pair<int,int>>>check;//중복으로 들어오는 것을 방지하기 위하여 set 사용 되돌아 오는 길도 체크해야 하므로 2차원으로 pair 만든다.
    unordered_map<char, pair<int, int>>map = { {'U',{0,1}},{'L',{-1,0}},{'R',{1,0}},{'D',{0,-1}} }; //char형으로 받을 것

    int cur_x = 0, cur_y = 0,next_x,next_y;
    
    for (int i = 0; i < dirs.size(); i++) {

        if (abs(cur_x+map[dirs[i]].first) > 5 || abs(cur_y+map[dirs[i]].second) > 5) continue; //좌표를 벗어나면 continue

        next_x = cur_x + map[dirs[i]].first;
        next_y = cur_y + map[dirs[i]].second;

        check.insert({{ cur_x,cur_y }, { next_x,next_y }});
        check.insert({{ next_x,next_y }, { cur_x,cur_y }});


        cur_x = next_x;
        cur_y = next_y;
    }
    

    return check.size()/2;
}

int main() {

    cout << solution("ULURRDLLU");

}
