#include <iostream>
#include <queue>
using namespace std;

void BOJ1158() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	for (int i = 0; i < N-1; i++) { //������ 1���� �˻����ʿ� �����Ƿ�
		for (int j = 0; j < K - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front() << ">" << endl;
	
}