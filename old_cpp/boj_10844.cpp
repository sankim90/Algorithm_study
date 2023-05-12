#include<iostream>

using namespace std;

//int D_10844[10000002]; // init 0

long long D_10844[101][10];
long long mod = 1000000000;



void boj_10844() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		D_10844[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				D_10844[i][j] = D_10844[i - 1][j + 1] % mod;
			else if(j == 9)
				D_10844[i][j] = D_10844[i - 1][j - 1] % mod;
			else
				D_10844[i][j] = (D_10844[i - 1][j - 1] + D_10844[i - 1][j + 1]) % mod;
		}
	}

	long long sum = 0;
	for (int j = 0; j <= 9; j++)
		sum = sum + D_10844[N][j];
	
	cout << sum % mod << endl;
}