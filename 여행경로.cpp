#include <string>
#include <vector>

using namespace std;
int visited[1000000];
string ans_string = "a";

void dfs(vector<vector<string>>& tickets, string cur, string path, int depth) {
    if (depth == tickets.size()) {
        string p = path;
        if (path < ans_string) {
            ans_string = path;
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (cur == tickets[i][0] && !visited[i]) {
            visited[i] = 1;
            dfs(tickets, tickets[i][1], path + tickets[i][1], depth + 1);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    dfs(tickets, "ICN", "ICN", 0);
    for (int i = 0; i < ans_string.size(); i += 3) {
        answer.push_back(ans_string.substr(i, 3));
    }
    return answer;
}
