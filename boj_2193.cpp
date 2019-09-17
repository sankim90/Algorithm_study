#include<iostream>

using namespace std;


long D_2193[91];

//D[N] = N자리 이친수의 개수
//D[N] = D[N-1] + D[N-2];

void boj_2193() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;


	D_2193[1] = 1;
	D_2193[2] = 1;
	for (int i = 3; i <= N; i++) {
		D_2193[i] = D_2193[i-1] + D_2193[i-2];
	}

	cout << D_2193[N];

}