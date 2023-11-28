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
/////          위  오 아래 왼
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
void cctv_work(int cur_r, int cur_c, int dir, int type, bool remove) {
    int nx = cur_r;
    int ny = cur_c;
    switch (type)
    {
        case 1:
            while (1)
            {
                nx = nx + dx[dir];
                ny = ny + dy[dir];
                if(nx<0 || nx>=N || ny<0 || ny>=M) break;
                if(board[nx][ny] == 6) break;
                if(board[nx][ny] == 0) {
                    if(remove) 
                        vis[nx][ny]--;
                    else 
                        vis[nx][ny]++;
                }
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
        // vis[cur.first][cur.second] = 10;
        int type = board[cur.first][cur.second];

        switch (type)
        {
            case 1:
                cctv_work(cur.first, cur.second, dir, type, 0);
                break;
        }
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
