#include <string>
#include <stack>
#include <iostream>

using namespace std;

void BOJ2504()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack <char> stack;
	string S;

	int result = 0;
	int mul = 1;

	cin >> S;

	for (unsigned int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			mul = mul * 2;
			stack.push(S[i]);

			if (i + 1 < S.length() && S[i + 1] == ')') { // 열린괄호일때 이미 값계산은 끝남
				result = mul + result;
			}
		}
		else if (S[i] == '[') {
			mul = mul * 3;
			stack.push(S[i]);

			if (i + 1 < S.length() && S[i + 1] == ']') {
				result = mul + result;
			}
		}
	
		else if (S[i] == ')') {							// 닫힌괄호일때 다음계산을 위한 준비를 하는 과정, 예외처리 해주고
			if (stack.empty()) {
				stack.push('x');
				break;
			}
			
			else if (stack.top() == '(') {
				stack.pop();
			}
			mul = mul / 2;
		}
			
		else if (S[i] == ']') {
			if (stack.empty()) {
				stack.push('x');
				break;
			}

			else if (stack.top() == '[') {
				stack.pop();
			}
			mul = mul / 3;
		}
	}
	if (stack.empty())
		cout << result;

	else
		cout << '0';

}

