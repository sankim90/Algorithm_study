#include <iostream>
#include <queue>

using namespace std;


int paper[500][500];
bool vis[500][500];
int x, y;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int info;
	int dx[4] = { -1,0,1,0 }; // 상 하
	int dy[4] = { 0,-1,0,1 }; // 좌 우



	cin >> x >> y; // 행 렬

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> info;
			paper[i][j] = info;
			//cout << paper[i][j] << " ";
		}
		//cout << endl;
	}

	queue<pair<int, int>> q;
	int img_cnt = 0;
	int b_cnt = 0;
	int top_area = 0;;



	 //int a = q.front().first;
	//int b = q.front().second;

	for (int j = 0; j < x; j++) {
		for (int k = 0; k < y; k++) {

			if (vis[j][k] == 0 && paper[j][k] == 1) { //2 ny 2에서 큐가 빔
				q.push({ j, k });
				vis[j][k] = 1;
				img_cnt++;
				b_cnt = 0;
				
			}
			
			
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				//cout << '(' << cur.first << ", " << cur.second << ") -> ";
				b_cnt++;

				if (b_cnt > top_area) {
					top_area = b_cnt;
				}

				for (int i = 0; i < 4; i++) { //cur.first = x, cur.second = y 
					int nx = cur.first + dx[i]; // 행
					int ny = cur.second + dy[i]; // 열 
					if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue; //cin >> row >> col; // x, y
					if (vis[nx][ny] == 1 || paper[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	cout << img_cnt << '\n';
	cout << top_area;

}
