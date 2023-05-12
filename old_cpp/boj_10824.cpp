#include<iostream>
#include<string>
#include<vector>

using namespace std;

void boj_10824() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> vec;

	string temp1, temp2;

	for (int i = 0; i < 4; i++) {
		cin >> temp1;
		vec.push_back(temp1);

	}
	int a = 3;
	string temp;

	temp1 = vec[0] + vec[1];
	temp2 = vec[2] + vec[3];

	cout << stoll(temp1) + stoll(temp2);


}