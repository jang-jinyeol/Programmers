#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  int day;
  int max_day = 0;

  for (int i = 0; i < progresses.size(); ++i) {
    day = (99 - progresses[i]) / speeds[i] + 1;//작업 진도는 100 미만 자연수 진도-작업률 / 속도 +1 은 총 걸리는 기간
    if (answer.empty() || max_day < day) { //현재 값 보다 걸리는 기간이 더 길면
      answer.push_back(1); max_day = day; //완료되는 작업 추가
    } else answer.back()++;//걸리는 기간이 더 짧을 경우 더해줌
  } return answer;
}
