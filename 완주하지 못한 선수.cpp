#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//
//정렬로 푸는 방법
//O(nlogn) + O(nlogn) + O(n) = O(nlogn) 시간복잡도
//string solution(vector<string> participant, vector<string> completion)
//{
//    sort(participant.begin(), participant.end());
//    sort(completion.begin(), completion.end());
//
//    for (int i = 0; i < completion.size(); ++i)
//    {
//        if (participant[i] != completion[i])
//        {
//            return participant[i];
//        }
//    }
//
//    return participant[participant.size() - 1];
//}



//
//이중 반복문 O(n) = O(n ^ 2)
//string solution(vector<string> participant, vector<string> completion)
//{
//    for (string name : completion)
//    {
//        auto it = find(participant.begin(), participant.end(), name);
//        if (it != participant.end())
//        {
//            participant.erase(it);
//        }
//    }
//
//    return participant[0];
//}


//unordered_map O(n) + O(n) + O(n) = O(n) 
string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int>map;

    for (string i : participant) {
        
        ++map[i];
    }
    for (string i : completion) {

        --map[i];
    }
    for (auto i : map) {

        if (i.second > 0)
            return i.first;
    }


}
int main(void) {
    vector<string> completion = { "eden", "kiki" };
    vector<string> participant = { "leo", "kiki", "eden" };
    solution(participant, completion);

    return 0;
}
