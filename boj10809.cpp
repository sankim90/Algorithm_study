#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int alphabet[26];
	fill_n(alphabet, 26, -1);

	string S;
	cin >> S;
	
	for (unsigned int i = 0; i < S.length(); i++) {
		int idx = 0;
		for (char a = 'a'; a <= 'z'; a++) {
			if (S[i] == a) {
				if (alphabet[idx] > -1)
					break;
				alphabet[idx] = i;
				break;
			}
			else 
				idx++;
		}
	}

	for (auto i : alphabet) {
		cout << i << " ";
	}
}
