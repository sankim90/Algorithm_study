#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;



	//소문자 대문자 숫자 공백 카운트
	int m, b, n, s;

	while (getline(cin, S)) { //getline, cin은 올바른 값이 들어왔는지(타입에 맞는 값)를 판별하여 bool값을 리턴한다.

		m = 0;
		b = 0;
		n = 0;
		s = 0;

		for (auto i : S) {
			if (i >= 'a' && i <= 'z')
				m++;
			else if (i >= 'A' && i <= 'Z')
				b++;
			else if (isdigit(i))
				n++;
			else
				s++;
		}
		cout << m << " " << b << " " << n << " " << s << " \n";
	}
}
