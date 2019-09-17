#include<iostream>

using namespace std;

int D_11727[1000002]; // init 0

int DP_11727(long n) {

	if (n == 1)
		return 1;

	else if (n == 2)
		return 3;

	else if (D_11727[n] > 0)
		return D_11727[n];


	D_11727[n] = (DP_11727(n - 1) + DP_11727(n - 2) * 2) % 10007;

	return D_11727[n];

}

void boj_11727() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long N;

	cin >> N;

	cout << DP_11727(N);
}