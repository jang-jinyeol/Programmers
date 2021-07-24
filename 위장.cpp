#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;



int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int>map;

    for (int i = 0; i < clothes.size(); i++) {

        map[clothes[i][1]]++;
    }  
    
    for (auto it : map) {

        answer *= it.second + 1;
      
    }

  /*  for (auto it = map.begin(); it != map.end(); it++) {
        
        answer *= (*it).second + 1;
    }*/

    answer--;

    
    return answer;
}


int main() {

    vector<vector<string>> data = { {"yellowhat", "headgear"
}, { "bluesunglasses", "eyewear"
}, { "green_turban", "headgear"
} };
    cout << solution(data);

}
