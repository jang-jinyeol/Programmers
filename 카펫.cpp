#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {


	vector<int> answer;

	int sum = brown + yellow;
	for (int height = 3;; height++) {
		if (!(sum % height)) {

			int width = sum / height;
			if ((height - 2) * (width - 2) == yellow) {
				answer.emplace_back(width);
				answer.emplace_back(height);
				break;
			}
		
		}
	}


	return answer;
}

int main() {

	auto k =solution(10, 2);


	for (auto i : k) cout << i << " ";
}
