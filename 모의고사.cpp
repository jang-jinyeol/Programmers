#include <string>
#include <vector>
#include <iostream>

using namespace std;




vector<int> solution(vector<int> answers) {
    vector<int> answer;
   
    
    int sum[3] = { 0, };
    int a[5] = { 1,2,3,4,5 };
    int b[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int c[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); i++) {

        if (answers[i] == a[i % 5]) ++sum[0];
        if (answers[i] == b[i % 8]) ++sum[1];
        if (answers[i] == c[i % 10]) ++sum[2];
    }
    int m =max(max(sum[0], sum[1]), sum[2]);

    for (int i = 0; i < 3; i++) {

        if (sum[i] == m) {
            answer.emplace_back(i + 1);
        }
    }

    return answer;
}

int main() {

    vector<int> data={ 1,3,2,4,2 };
    auto k=solution(data);
    
    for (auto q : k) {

        cout << q<<" ";
    }
}

/*
    새로운 방법
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }

*/
