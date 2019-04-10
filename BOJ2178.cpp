//#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <queue>

using namespace std;

int x, y;
int paper[100][100];
bool vis[100][100];



void BOJ2178() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S, S_tmp;
	const int dx[4] = { 1, 0, -1, 0 };
	const int dy[4] = { 0, 1, 0, -1 };

	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%1d", &paper[i][j]); // 1d로 받으면 띄어쓰기 안해도 그대로 숫자로 받음, _s에러는 #define _CRT~~~로 해결

		}
	}
	
	queue<pair<int, int>> Q;

	vis[0][0] = 1;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		cout << "(" << cur.first << "," << cur.second << ") ->";
		for (int dir = 0; dir < 4; dir++) {
			auto nx = cur.first + dx[dir];
			auto ny = cur.second + dy[dir];
			if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if(vis[nx][ny] == 1 || paper[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}

	}

	
}