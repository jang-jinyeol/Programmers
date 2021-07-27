#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <stdlib.h>
#pragma warning (disable:4996)

using namespace std;


bool compare(const pair<int,int>& a,const pair<int,int>& b) {

    if (a.first > b.first)   //a>b 이면 내림차순 주의
        return true;
    else if (a.first == b.first) {
        if (a.second < b.second) //인덱스 번호는 오름차순으로
            true;
    }

    return false;

}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    unordered_map<string, int>map;
    unordered_map<string, vector<pair<int,int>>>map2;//매우중요 순서 정렬을 위한 부분(뒤에 벡터가 핵심)

    vector<pair<int, int>>v;

    for (int i = 0; i < genres.size(); i++) {

        map[genres[i]] += plays[i];
        map2[genres[i]].push_back(make_pair(plays[i],i));//pair<int,int>(plays[i],i)); plays와 index를 저장
    }
    
    //map을 벡터에 넣어서 정렬한다. 편의를 위해 int부터 받는다.
    //삽입시에도 pair 형태로 넣어준다.
    //범위기반 반복문 (range based for)을 사용한다.

    vector<pair<int, string>>Sort;
   
    for (auto x : map) Sort.push_back(make_pair(x.second,x.first));

    sort(Sort.begin(), Sort.end());

    while (Sort.size() > 0) {

        pair<int, string>tmp = Sort.back(); //sort는 default가 오름차순 이므로 가장 큰 값을 tmp에 넣는다.
        Sort.pop_back(); // tmp에 넣었으니 pop_back으로 제거
        vector<pair<int, int>>a = map2[tmp.second];//새로운 벡터를 만들어서 가장 큰(tmp)의 value를 넣어준다.
        sort (a.begin(), a.end(), compare);//문제의 요구대로 plays의 내림차순, 같다면 고유번호 기준으로 오름차순으로 정렬해준다.

        int lastn = 2;
        
        if (a.size() < 2) {  //가장 많이 재생된 노래 2개만 출력해야 하므로 lastn를 2로 설정한다.
            lastn = a.size(); //a벡터에 1개만 있을경우 1개만 출력
        }

        for (int i = 0; i < lastn; i++) {

            answer.push_back(a[i].second);
        }
    }


    return answer;
}
int main() {

    vector<string> a = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> b = { 500, 600, 150, 800, 2500 };
    auto p = solution(a, b);
    for (auto k : p) cout << k << " ";

}


