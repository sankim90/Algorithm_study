#include <iostream>
//#include <algorithm>
#include <queue>

using namespace std;

short board_2146[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int island_name = 2;
int N;

int bridge(int, int);
void boj_2146() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool item;
			cin >> item;
			board_2146[i][j] = item;
		}
	}

	queue <pair<int, int>> q;

	//global distance
	//local distance
	//일단 이동후

	for(int step_Y = 0; step_Y < N; step_Y++) {
		for (int step_X = 0; step_X < N; step_X++) {
			if (board_2146[step_Y][step_X] == 1) {
				q.push({ step_Y, step_X }); //Q.push({ nx,ny })
				board_2146[step_Y][step_X] = island_name;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					//cout << "(" << cur.first << ", " << cur.second << ")->";

					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];  // 열
						int ny = cur.second + dy[i]; // 행
						if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
						if (board_2146[nx][ny] != 1) continue;
						board_2146[nx][ny] = island_name;
						q.push({ nx, ny });
					}

				}
				// 0을 count해서 현재 id가 아닌 섬을 만날때 까지 distance++
				island_name++;
			}
			else
				continue;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board_2146[i][j];
		}
		cout << endl;
	}

	

	int ans = 199999;

	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board_2146[i][j] == 0) continue;
			ans = min(ans, bridge(i, j));
		}
	}

	cout << ans;
}

int bridge(int x, int y) {

	int dist[101][101];
	for (int i = 0; i < N; i++)
		fill(dist[i], dist[i] + N, -1);

	queue <pair<int, int>> Q;
	Q.push({ x, y });
	dist[x][y] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];  // 열
			int ny = cur.second + dy[i]; // 행
			if (nx >= N || ny >= N || nx < 0 || ny < 0 || dist[nx][ny] >= 0) continue;
			if (board_2146[nx][ny] == board_2146[x][y]) continue;
			if (board_2146[nx][ny] != 0)
				return dist[cur.first][cur.second];
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}

	}

	return 99999;
}
