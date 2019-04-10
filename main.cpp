#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stl_test.h"

using namespace std;


int main()
{
	//vector_test();
	//list_test();
	//set_test();
	//map_test();
	//mutiset_test();
	//mutimap_test();
	//lower_test();
	//graph();
	//coding_test();
	//DQ_test();
	//VPS();
	//bar_stack();
	//BOJ2504();
	//BFS();
	//BOJ1926();
	//BOJ2178();
	//DFS();

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N-i; j++) {
			cout << " ";
		}
		for (int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << endl;
	}
}
