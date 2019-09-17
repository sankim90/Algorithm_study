#include <iostream>
#include <algorithm>

using namespace std;

int table[10001];
//int DP_2156[3][10001];
int DP_2156[10001]; // N ��°���� ���� �������� �ִ밪

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

		DP_2156[i] = DP_2156[i - 1];  // �ȸ���
		
		DP_2156[i] = max(DP_2156[i], table[i] + DP_2156[i - 2]); // �ȸ��� vs ���� 1�ܸ� ����

		DP_2156[i] = max(DP_2156[i], table[i] + table[i - 1] + DP_2156[i - 3]); // ���� 1�ܸ� ���� vs 2�� ���� ����

		// �� 3���� ���̽� �� ���� ū ���� DP[i] ������ ����
	}

	long result;
	result = DP_2156[N];
	//result = max(max(DP_2156[0][N], DP_2156[1][N]), DP_2156[2][N]);

	cout << result << "\n";


}