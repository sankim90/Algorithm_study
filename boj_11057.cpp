#include<iostream>

using namespace std;

long long D_11057[101][10];
long long mod_11057 = 10007;


//D[N][M] = M으로 끝나는 N자리 오르막수의 갯수
void boj_11057() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		D_11057[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				D_11057[i][j] += D_11057[i-1][k];
				D_11057[i][j] = D_11057[i][j] % mod_11057;
			}
		}
	}//

	long long sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum = sum + D_11057[N][j];
	}

	sum = sum % mod_11057;

	cout << sum;

}
