#include <iostream>
using namespace std;

int memo[100]; //global variable로 0으로 초기화된 상태
int recursion(int n) { //top down
	if (n <= 1)
		return n;
	else {
		if (memo[n] > 0) { // 0 이상의 무언가 값이 있단는 것은 먼저 계산한 값이 memo 되어 있다는 뜻
			return memo[n];
		}
		memo[n] = recursion(n - 1) + recursion(n - 2);
		return memo[n];
	}

}

int d[100];
int bottom_up_fibo(int n) {
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) { // 문제를 크기가 작은 문제부터 차례대로 푼다, i++ 문제의 크기를 점진적으로 키우면서 푼다.
		d[i] = d[i - 1] + d[i - 2]; // 작은 문제들을 풀면서 왔기에 큰 문제는 항상 해결된다.
	}

	return d[n]; // 결국 원하는 d[n]을 구할 수 있다.
}
void fibo_DP() {

	int n;
	cin >> n;
	cout << recursion(n);
	cout << bottom_up_fibo(n);
}
/*
전략:
문제에서 구하려고 하는 답을 문장으로 나타낸다.
ex)
피보나치 수를 구하는 문제
-> N 번째 피보나치 수

이제 그문장에 나와있는 변수의 개수만큼 메모하는 배열을 만든다.

*Top-down 인 경우에는 재귀 호출의 인자의 개수만큼
문제를 작은 문제로 나누고, 수식을 이용해서 문제를 표현해야 한다.
*/
