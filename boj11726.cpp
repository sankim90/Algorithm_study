#include <iostream>
using namespace std;


int boj11726_d[1006];
int mod = 10007;
int topdown(int n) {

	if (n == 1)
		return 1;

	else if (n == 2)  // base n= 1, 2 경우를 memo 해줘야 이를 이용해서 다음 문제(n >=3)를 풀수있지!
		return 2;

	else if (boj11726_d[n] > 0)
		return boj11726_d[n];

	else {
		boj11726_d[n] = topdown(n - 1) + topdown(n - 2);
		boj11726_d[n] = boj11726_d[n] % mod;
		return boj11726_d[n];
	}
}
void boj11726() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	//cout <<topdown(n);

	int d[1006] = { 0, };
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2]; // 이전 값들을 모아서 다음값을 만듦
		d[i] = d[i] % mod;
	}

	cout << d[n];
	

}
