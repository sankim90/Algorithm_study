#include <iostream>
#include <stack>
#include <string>

using namespace std;

void VPS() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		stack<char> data;
		cin >> S;
		for (auto c : S) {
			if (c == '(') 
				data.push(c);
			else {
				if (data.empty()) {
					data.push('x');
					break;
				}

				if (c == ')')
					if (data.top() != '(') 
						break;

				data.pop();
			}
		}
		if (data.empty())
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	
}