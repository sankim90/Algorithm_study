#include <iostream>
#include <string>
#include <stack>

using namespace std;

void boj_10799()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ( -> push
	// () -> add stk.size()
	// ) -> add +1, pop

	string S;
	cin >> S;

	stack<char> stk;
	int result = 0;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			stk.push(S[i]);
		}
		else if (S[i] == ')') {
			//if (stk.top() == '(') {
			if (S[i - 1] == '(') {
				stk.pop();
				result += stk.size();
			}
			else if (S[i - 1] == ')') {
				stk.pop();
				result += 1;
			}
			else {
				result = 0;
				break;
			}	
		}
	}

	cout << result << "\n";
}