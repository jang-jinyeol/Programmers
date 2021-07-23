#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& d,int target, int& answer,int count=0,int sum=0) {

    if (count == d.size() - 1) {

        if (target == sum + d[count]) answer++;
        if (target == sum - d[count]) answer++;
        
        return;
    }
    
    dfs(d, target,answer, count + 1, sum + d[count]);
    dfs(d, target,answer ,count + 1, sum - d[count]);


}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers,target,answer);
    return answer;
}
