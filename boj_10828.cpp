#include <iostream>
#include <stack>
#include <string>

using namespace std;

void boj_10828()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	cin >> N;

	string S;

	stack<int> stk;

	for (int i = 0; i < N; i++) {
		
		cin >> S;

		if (S == "push") {
			int item;
			cin >> item;
			stk.push(item);

		}

		else if (S == "pop") {
			if (stk.empty())
				cout << "-1\n";
			else {
				cout << stk.top() << '\n';
				stk.pop();
			}
		}

		else if (S == "size") {
			cout << stk.size() << '\n';
		}

		else if (S == "empty") {
			cout << stk.empty() << '\n';
		}

		else {
			if (stk.empty())
				cout << "-1\n";
			else
				cout << stk.top() << '\n';
		}
	}

}
