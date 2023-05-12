#include<iostream>
#include<algorithm>

using namespace std;

int D_11053[1001];
int A_11053[1001];
//D[N] = N���� ���� �� ������ ����
// A[N] ���� ���� ��� ������ D[N]���� ���� ū�� + 1 �ϸ� �� ���̰� ���´�

/*
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

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
