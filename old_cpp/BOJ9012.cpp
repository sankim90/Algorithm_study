#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
    string S;
	cin >> num;

	for (int i = 0; i < num; i++) {
        stack<char> data;
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '(') 
				data.push(S[j]);
			else {
				if (data.empty()) {
					data.push('x');
					break;
				}

				if (S[j] == ')')
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
