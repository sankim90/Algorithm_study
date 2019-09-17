#include<iostream>
#include<string>
#include<queue>

using namespace std;


void boj_10845() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	queue <int> qu;

	cin >> N;

	string S;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S == "push") {
			int item;
			cin >> item;
			qu.push(item);
		}

		else if (S == "size") {
			cout << qu.size() << "\n";
		}

		else if (S == "empty") {
			cout << qu.empty() << "\n";
		}

		else if (S == "pop") {
			if (!qu.empty()) {
				cout << qu.front() << "\n";
				qu.pop();
			}
			else
				cout << "-1\n";
		}
		else if (S == "front") {
			if (!qu.empty()) {
				cout << qu.front() << "\n";
			}
			else
				cout << "-1\n";
		}
		else if (S == "back") {
			if (!qu.empty()) {
				cout << qu.back() << "\n";
			}
			else
				cout << "-1\n";
		}
	}
	

}