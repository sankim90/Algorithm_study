#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void boj_11656() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;

	cin >> S;

	vector<string> vec;

	for (int i = 0; i < S.length(); i++) {
		vec.push_back(S.substr(i));
	}
	
	sort(vec.begin(), vec.end());

	for (auto i = vec.begin(); i != vec.end(); i++) {
		cout << *i << "\n";
	}
}