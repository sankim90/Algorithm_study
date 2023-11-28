#include <bits/stdc++.h>
using namespace std;

int N, M;
//          위  오 아래 왼
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[10][10];
int vis[10][10];
int cctv_num;
int rst = 100;
vector<pair<int, int>> vec;

int count_vis() {
    int cnt = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(board[i][j] == 0 && vis[i][j] == 0) cnt++;

    return cnt;
}

void cctv_vis(int cur_r, int cur_c, int nxt, bool remove) {
    int nx = cur_r;
    int ny = cur_c;
    while (1)
    {
        nx = nx + dx[nxt];
        ny = ny + dy[nxt];
        if(nx<0 || nx>=N || ny<0 || ny>=M) break;
        if(board[nx][ny] == 6) break;
        if(board[nx][ny] == 0) {
            if(remove) 
                vis[nx][ny]--;
            else 
                vis[nx][ny]++;
        }
    }
}
void cctv_work(int cur_r, int cur_c, int dir, int type, bool remove) {
    int nxt;
    switch (type)
    {
        case 1:
            nxt = dir;
            cctv_vis(cur_r, cur_c, nxt, remove);
            break;

        case 2:
            for(int i=0; i<2; i++) { // 2줄 그림
                if(dir == 0) {  // 상 하
                    nxt = i ? 0 : 2;
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else if(dir == 1) { // 좌 우
                    nxt = i ? 1 : 3;
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else break;
            }
            break;

        case 3: 
            for(int i=0; i<2; i++) {
                if(dir == 0) {
                    nxt = i ? 2 : 1; // 상, 우
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else if(dir == 1) {
                    nxt = i ? 0 : 1; // 하, 우
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else if(dir == 2) { // 하, 좌
                    nxt = i ? 0 : 3;
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else {
                    nxt = i ? 2 : 3; // 좌, 상
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
            }
            break;
        
        case 4: 
            for(int i=0; i<3; i++) {
                if(dir == 0) {
                    nxt = (i == 0) ? 3 : (i == 1) ? 1 : 0; // 좌 우 하
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else if(dir == 1) {
                    nxt = (i == 0) ? 3 : (i == 1) ? 1 : 2; // 좌 우 상
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else if(dir == 2) {
                    nxt = (i == 0) ? 2 : (i == 1) ? 0 : 1; // 상 하 우
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
                else {
                    nxt = (i == 0) ? 2 : (i == 1) ? 0 : 3; // 상 하 좌
                    cctv_vis(cur_r, cur_c, nxt, remove);
                }
            }
            break;
        
        case 5: /////  위 0  오 1 아래 2 왼 3
            for(int i=0; i<4; i++) {
                if(dir == 0) {
                    cctv_vis(cur_r, cur_c, i, remove);
                }
                else break;
            }
            break;
    }
}

void boj15683(int k) {
    if(k==cctv_num) {
        int tmp = count_vis();
        rst = min(tmp, rst);
        return;
    }
    
    auto cur = vec[k];
    for(int dir=0; dir<4; dir++) {
        int type = board[cur.first][cur.second];

        cctv_work(cur.first, cur.second, dir, type, 0);
        boj15683(k+1);
        cctv_work(cur.first, cur.second, dir, type, 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                vec.push_back({i,j});
                cctv_num++;
            }
        }

    boj15683(0);
    cout << rst;
}
