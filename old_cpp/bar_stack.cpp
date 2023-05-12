#include <iostream>
#include <stack>
#include <string>

using namespace std;

void bar_stack() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int result=0;
	stack<char> data;

	for (unsigned int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			data.push(S[i]);
		}
		else { //S[i] == ')') String�̶� stack�̶� ����ִ°� �򰥸��� ���ƶ�......
			data.pop();

			if (S[i - 1] == '(') { // laser�� ������ bar�� ���̾ƴ϶�� �� * 2 ��ŭ �����̳�
				result += data.size();
				
			}
			else if (S[i - 1] == ')') { // bar�� ���� ������ ���� �κ��� pop �������
				result += 1;			//������ ���ٸ� ó��
			}
		}
				
	}

	cout << result << '\n';
}
