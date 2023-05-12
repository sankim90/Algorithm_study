#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void boj_10818()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int val;
	vector<int> vec;

	for (int i = 0; i < N; i++) {
		cin >> val;
		vec.push_back(val);
	}
	cout << *min_element(vec.begin(), vec.end()) << ' ';
	cout << *max_element(vec.begin(), vec.end());
}