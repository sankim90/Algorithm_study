#include <iostream>
#include <algorithm>

using namespace std;

int table[10001];
//int DP_2156[3][10001];
int DP_2156[10001]; // N 번째까지 마신 포도주의 최대값

void boj_2156() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << DP_2156[-1][0] << endl;
	//cout << &DP_2156[0][-1]<<endl;
	//cout << &DP_2156<<endl;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int item;
		cin >> item;
		table[i] = item;

	}
	DP_2156[0] = 0;
	DP_2156[1] = table[1];
	DP_2156[2] = table[1] + table[2];

	for (int i = 3; i <= N; i++) {
		//cout << i << endl;
		//DP_2156[0][i] = max(max(DP_2156[0][i - 1], DP_2156[1][i - 1]), DP_2156[2][i - 1]);
		//DP_2156[1][i] = table[i] + DP_2156[0][i - 1];
		//DP_2156[2][i] = table[i] + DP_2156[1][i - 1];

		DP_2156[i] = DP_2156[i - 1];  // 안마심
		
		DP_2156[i] = max(DP_2156[i], table[i] + DP_2156[i - 2]); // 안마심 vs 지금 1잔만 마심

		DP_2156[i] = max(DP_2156[i], table[i] + table[i - 1] + DP_2156[i - 3]); // 지금 1잔만 마심 vs 2잔 연속 마심

		// 위 3가지 케이스 중 가장 큰 값을 DP[i] 값으로 선정
	}

	long result;
	result = DP_2156[N];
	//result = max(max(DP_2156[0][N], DP_2156[1][N]), DP_2156[2][N]);

	cout << result << "\n";


}