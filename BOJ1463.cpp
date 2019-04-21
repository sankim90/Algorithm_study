#include <iostream>
using namespace std;

int D[1000002];

//D[N] -> N이 1이 될때까지의 연산 횟수

//내문제는 그럴것이다라고 넘어가질 못하는것이야. 재귀함수 디버깅으로 한줄한줄 다 따라가면 머리터진다!!!!
int topdown(long N) {

	if (N == 1) // 1일때는 그냥 D(횟수)가 0이지
		return 0;

	if (D[N] > 0) // 뭔가 값이 있으면 memo 리턴, 중복된 연산 하기 싫으니 DP는 테이블 보고 끝낸다는거다.
		return D[N];
	
	D[N] = topdown(N - 1) + 1; // N - 1을 이용한 연산 횟수

	if (N % 2 == 0) {
		int temp = topdown(N / 2) + 1;  // N / 2를 이용한 연산 횟수

		if (D[N] > temp) // 앞에 D[N - 1]랑 비교해서  작은놈 D[N]으로
			D[N] = temp;

	}
	
	if (N % 3 == 0) {
		int temp = topdown(N / 3) + 1;

		if (D[N] > temp)
			D[N] = temp;

	}

	return D[N];
	
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long N;
	cin >> N;

	cout<<topdown(N);
	
}
