#include<iostream>
#include<string>
#include<deque>

using namespace std;


void boj_10866() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string S;
	deque<int> dq;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S == "push_front") {
			int item;
			cin >> item;

			dq.push_front(item);
		}
		else if (S == "push_back") {
			int item;
			cin >> item;

			dq.push_back(item);
		}
		else if (S == "pop_front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}

		else if (S == "pop_back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}

		else if (S == "size") {
			cout << dq.size()<<endl;
		}

		else if (S == "empty") {
			if (dq.empty()) {
				cout << "1" << endl;
			}
			else
				cout << "0" << endl;
		}

		else if (S == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else 
				cout << dq.front() << endl;
		}

		else if (S == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else
				cout << dq.back() << endl;
		}

	}
}