#include <iostream>
using namespace std;

int boj9095_d[12] = { 0, 1, 2, 4, };

int boj9095_topdown(int n) {


	if (boj9095_d[n] > 0)
		return boj9095_d[n];

	else {
		boj9095_d[n] = boj9095_topdown(n - 1) + boj9095_topdown(n - 2) + boj9095_topdown(n - 3);
		return boj9095_d[n];
	}
}
void boj9095() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << boj9095_topdown(n) <<"\n";
	}

	int d[12] = { 0, 1, 2, 4, }; //점화식좀 잘만들자.. fn = fn-1 + fn-2 + fn-3
								 //문제에서 손계산을 몇가지 케이스에 대해서 해보고, 그에 따른 점화식을 유추하자!
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	//cout << d[n];

}
