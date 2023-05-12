#include<iostream>
#include<algorithm>

using namespace std;

int D_11053[1001];
int A_11053[1001];
//D[N] = N까지 가장 긴 수열의 길이
// A[N] 보다 작은 모든 수에서 D[N]값이 가장 큰거 + 1 하면 내 길이가 나온다

/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

*/
void boj_11053() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	
	cin >> N;
	
	int result = 0;

	for (int i = 1; i <= N; i++) {
		int item;
		int temp = 0;

		cin >> item;
		A_11053[i] = item;

		for (int j = 1; j < i; j++) {
			if (A_11053[j] < A_11053[i]) {
				if (D_11053[j] > temp) {
					temp = D_11053[j];
				}
			}
		}

		D_11053[i] = temp + 1;

		if (D_11053[i] > result)
			result = D_11053[i];

	}
	
	cout << result;

}
