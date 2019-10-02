//#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <queue>

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
string board[102]; // '1'이 파란 칸, '0'이 빨간 칸에 대응
int dist[102][102]; // 해당 칸을 방문했는지 여부를 저장
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	queue<pair<int, int> > Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue; // 범위 밖일 경우 넘어감
			if (dist[nx][ny] >= 0 or board[nx][ny] != '1') continue; // 이미 방문한 칸이거나 이동할 수 없는 칸일 경우
			dist[nx][ny] = dist[cur.X][cur.Y] + 1; // (nx, ny)의 거리는 현재 보고 있는 위치의 거리 + 1
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1; // 문제의 특성상 거리+1이 정답
}
