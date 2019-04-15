#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int result=0;
	stack<char> data;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			data.push(S[i]);
		}
		else { //S[i] == ')') String이랑 stack이랑 들어있는거 헷갈리지 말아라......
			data.pop();

			if (S[i - 1] == '(') { // laser를 만나면 bar의 끝이아니라면 바 * 2 만큼 조각이남
				result += data.size();
				
			}
			else if (S[i - 1] == ')') { // bar의 끝을 만나면 시작 부분을 pop 해줘야함
				result += 1;			//마지막 꼬다리 처리
			}
		}
				
	}

	cout << result << '\n';
}
