/*#include<iostream>
#include <vector>
using namespace std;

int N, M;
//bool visit[10];
int visit[10];

vector <int> stk;
int i = 0;
void print() {
		for (auto i = stk.begin(); i < stk.end(); i++) cout << *i + 1<< ' ';

		cout << '\n';
		stk.pop_back();
		visit[i] = false;
	
}
void func() {
		
	stk.push_back(0);
	
	while (!stk.empty()) {
		stk.pop_back();
		visit[stk.size()] = false;
		for (i = 0; i < N; i++) {
			if (visit[i] == 0) {
				visit[i] = true;
				stk.push_back(i);
				
			}
			if (stk.size() == M) {
				print();
			}
		}

		
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	func();
	return 0;
}*/

/*#include <iostream>
#include <vector>
using namespace std;

int N, M;
//vector<bool> visit;
bool visit[10];
vector<int> vec;
void dfs() {
	if (vec.size() == M) {
		for (int i = 0; i < M; i++) printf("%d ", vec[i]+1);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true; 
			vec.push_back(i);
			dfs(); //간단히 애 종료되면 다음 꺼... return되서 다음 줄 실행이지
			visit[i] = false; 
			vec.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;
	//visit = vector<bool>(N + 1, false);

	dfs();
}*/

/*#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, r, c;
int result;

void recursion(int x, int y, int len) {

	if (x == r && y == c) {
		cout << result << endl;
		exit(0);
	}

	if (len == 1) {
		result++; return;
	}

	if (!(x <= r && r<x + len && y <= c && c<y + len)) {
		result += len*len;
		return;
	}

	recursion(x, y, len / 2);
	recursion(x, y + len / 2, len / 2);
	recursion(x + len / 2, y, len / 2);
	recursion(x + len / 2, y + len / 2, len / 2);

}



int main() {

	cin >> n >> r >> c;
	recursion(0, 0, pow(2, n));
	
	return 0;

}*/
/*
#include <stdio.h>
#include <math.h>
int N, R, C, cnt = 0;

void func(int n, int r, int c) {
	if (n == 2) {
		if (r == R && c == C) {
			printf("%d\n", cnt++);
			return;
		}
		cnt++;

		if (r == R && c+1 == C) {
			printf("%d\n", cnt++);
			return;
		}
		cnt++;

		if (r+1 == R && c == C) {
			printf("%d\n", cnt++);
			return;
		}
		cnt++;

		if (r+1 == R && c+1 == C) {
			printf("%d\n", cnt++);
			return;
		}
		cnt++;
		return;
	}

	func(n / 2, r, c);
	func(n / 2, r, c+n/2);
	func(n / 2, r+n/2, c);
	func(n / 2, r+n/2, c+n/2);
}

void main() {
	scanf("%d%d%d", &N, &R, &C);
	func(pow(2, N), 0, 0);
}*/