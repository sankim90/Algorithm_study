#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

//          위  오 아래 왼
int dx[4] = {1, 0, -1, 0}; // 행
int dy[4] = {0, 1, 0, -1}; // 열

void boj1926()
{
    int board[502][502] = {0, }; // 배열의 크기는 여유롭게 최댓값으로 잡음
    bool vis[502][502] = {0, };

    int n, m;
    int i, j;
    int Picnt = 0;
    int Maxcnt = 0;
    int rst = 0;
    queue<pair<int, int>> Q;

    cin >> n >> m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin >> board[i][j];

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(board[i][j] && vis[i][j] == 0)
            {
                Maxcnt = 0;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    Maxcnt++;
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first  + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                Picnt++;
                if(rst < Maxcnt) rst = Maxcnt;
            }
        }
    }
    
    cout << Picnt <<'\n' << rst << '\n';
}

void boj2178()
{
    int n, m;
    int i, j;
    int nx, ny;
    char board[102][102] = {0, };
    int  dist [102][102];
    queue <pair<int, int>> Q;
    cin >> n >> m;
    int cnt = 0;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin >> board[i][j];

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            dist[i][j] = -1;

    Q.push({0, 0});
    dist[0][0] = 0;

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            nx = cur.first  + dx[dir];
            ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});    
        }
    }

    cout << dist[n-1][m-1]+1;
}

int board[1002][1002];
int dist[1002][1002];

void boj7576()
{
    int n, m;
    int i, j;
    int rst=0;
    queue <pair<int, int>> Q;

    cin >> n >> m; // 열 행
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1)
                Q.push({i,j});
            else if(board[i][j] == 0)
                dist[i][j] = -1;
        }
    }

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first  + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(dist[nx][ny]>=0) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            rst = max(dist[nx][ny], rst);
            Q.push({nx,ny});
        }
    }

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(dist[i][j] == -1)
            {
                cout << "-1\n";
                return;
            }
    cout << rst;
}

char board_4179[1002][1002];
int dist1[1002][1002]; // 불
int dist2[1002][1002]; // 지훈
void boj4179()
{
    int n, m;
    int i, j;
    int rst = 0;

    cin >> n >> m;
    queue<pair<int, int>> FQ; // 불
    queue<pair<int, int>> JQ; // 지훈이
    
    for(i=0; i<n; i++)
    {
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
        cin >> board_4179[i];
    }

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(board_4179[i][j]=='F')
            {
                FQ.push({i,j});
                dist1[i][j] = 0;
            }
            else if(board_4179[i][j]=='J')
            {
                JQ.push({i,j});
                dist2[i][j] = 0;
            }
        }

    
    while (!FQ.empty()) // 불에 대한 BFS 먼저 돌림
    {
        auto cur = FQ.front(); 
        FQ.pop();

        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first  + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist1[nx][ny]>=0 || board_4179[nx][ny] == '#') continue;
            FQ.push({nx, ny});
            dist1[nx][ny] = dist1[cur.first][cur.second]+1;
        }
    }

    while (!JQ.empty()) // 지훈이 BFS
    {
        auto cur = JQ.front(); 
        JQ.pop();

        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first  + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) //m,n 밖이면 즉 탈출이다~
            {
                cout << dist2[cur.first][cur.second]+1;
                return;
            }
            if(dist2[nx][ny]>=0 || board_4179[nx][ny] == '#') continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second]+1) continue; // dist1(불) <= dist2(지훈)는 지훈이가 더 늦었다는 것임(값이 클수록 늦게 도착)
            JQ.push({nx, ny});                                                                   // #(벽)은 계산에 포함되면 안되므로 != -1 조건 추가
            dist2[nx][ny] = dist2[cur.first][cur.second]+1;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj1926();
    // boj2178();
    // boj7576();
    boj4179();
}