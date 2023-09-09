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
            JQ.push({nx, ny});                                                                   // dist1[nx][ny] != -1 : 보드에 불이 없는 경우가 있다! 예외처리
            dist2[nx][ny] = dist2[cur.first][cur.second]+1;
        }
    }
    cout << "IMPOSSIBLE\n";
}

// char board_1697[100000];
int dist_1697[100002];
int dx_1697[3] = {-1, 1, 2};

void boj1697()
{
    queue<int> Q;
    int N, K;
    int nx;
    cin >> N >> K;
    if(N >= K) // 순간이동은 양의 방향으로만 가능하므로 이 경우 -1으로만 이동함
    {
        cout << N-K;
        return;
    }

    fill(dist_1697, dist_1697+100002, -1);

    Q.push(N);
    dist_1697[N] = 0;

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<3; dir++)
        {
            if(dir==2)
                nx = cur * dx_1697[dir];
            else
                nx = cur + dx_1697[dir];

            if(nx<0 || nx>100000) continue;
            if(dist_1697[nx]>=0) continue;
            if(nx == K)
            {
                cout << dist_1697[cur]+1;
                return;
            }
            Q.push(nx);
            dist_1697[nx] = dist_1697[cur]+1;
        }
    }
}

void boj1012()
{
    int T, N, M, K;
    int x, y;
    int Piccnt;

    cin >> T;
    
    for(int l=0; l<T; l++)
    {
        queue<pair<int, int>> Q;
        bool board[52][52] = {0, };
        bool vis[52][52] = {0, };
        Piccnt = 0;
        cin >> M >> N >> K; // 열 행

        for(int p=0; p<K; p++)
        {
            cin >> y >> x;
            board[x][y] = 1;
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(board[i][j] && vis[i][j] == 0)
                {
                    Q.push({i, j});
                    vis[i][j] = 1;
                
                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first  + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                            if(vis[nx][ny] || board[nx][ny] == 0) continue;
                            Q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    Piccnt++;
                }
            }
        }

        cout << Piccnt << '\n';
    }
}

void boj10026()
{
    int N;
    char board1[101][101]={0, };
    char board2[101][101]={0, };
    bool vis1[101][101]={0, };
    bool vis2[101][101]={0, };
    int Piccnt1 = 0; // RGB
    int Piccnt2 = 0; // RG+B
    
    queue<pair<int, int>> Q;
    cin >> N;
    // board 2개 만든다 V
    // 2번 보드의 G를 R로 바꾼다

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> board1[i][j];
            board2[i][j] = board1[i][j];
            if(board1[i][j] == 'G')
                board2[i][j] = 'R';
        }
    }

    for(auto k:{'R', 'G', 'B'})
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(board1[i][j] == k && vis1[i][j] == 0) 
                {
                    Q.push({i,j});
                    vis1[i][j]=1;
                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first  + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                            if(vis1[nx][ny] || board1[nx][ny] != board1[cur.first][cur.second])  continue;
                            Q.push({nx, ny});
                            vis1[nx][ny] = 1;
                        }
                    }
                    Piccnt1++;
                }
            }
        }
    }

    for(auto k:{'R', 'B'})
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(board2[i][j] == k && vis2[i][j] == 0) 
                {
                    Q.push({i,j});
                    vis2[i][j]=1;
                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first  + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                            if(vis2[nx][ny] || board2[nx][ny] != board2[cur.first][cur.second])  continue;
                            Q.push({nx, ny});
                            vis2[nx][ny] = 1;
                        }
                    }
                    Piccnt2++;
                }
            }
        }
    }

    cout << Piccnt1 << ' ' << Piccnt2 << '\n';

}

int board_7569[103][103][103];
int dist_7569[103][103][103];
int dx_7569[6] = {1, 0, -1, 0, 0, 0}; // 행
int dy_7569[6] = {0, 1, 0, -1, 0, 0}; // 열
int dz_7569[6] = {0, 0, 0, 0, 1, -1}; // 높이

void boj7569()
{
    int M, N, H;
    int i, j, k;
    int rst = 0;
    queue<tuple<int, int, int>> Q;
    
    cin >> M >> N >> H; //  열 행 높이

    for(k=0; k<H; k++)
        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
            {
                dist_7569[k][i][j] = -1;
                cin >> board_7569[k][i][j];
                if(board_7569[k][i][j] == 1)
                {
                    Q.push({k,i,j});
                    dist_7569[k][i][j] = 0;
                }
            }


    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0; dir<6; dir++)
        {
            int nx = get<1>(cur) + dx_7569[dir];
            int ny = get<2>(cur) + dy_7569[dir];
            int nz = get<0>(cur) + dz_7569[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H) continue;
            if(board_7569[nz][nx][ny] != 0 || dist_7569[nz][nx][ny]>=0) continue;
            Q.push({nz, nx, ny});
            dist_7569[nz][nx][ny] = dist_7569[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            rst = max(dist_7569[nz][nx][ny], rst);
        }
    }
            

    for(k=0; k<H; k++)
        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
            {
                if(board_7569[k][i][j] == 0 && dist_7569[k][i][j] == -1)
                {
                    cout << "-1\n";
                    return;
                }
            }
    
    cout << rst;
}

// int board_7562[305][305];
int dist_7562[305][305];
int dx_7562[8] = {1, 2,  2,  1, -1, -2, -2, -1}; // 행
int dy_7562[8] = {2, 1, -1, -2, -2, -1,  1,  2}; // 열

void boj7562()
{
    int TC, l;
    int x, y;
    int tar_x, tar_y;
    queue<pair<int, int>> Q;
    cin >> TC;

    for(int T=0; T<TC; T++)
    {
        cin >> l;
        cin >> x >> y;
        cin >> tar_x >> tar_y;

        for(int i=0; i<l; i++)
            fill(dist_7562[i], dist_7562[i]+l, -1);

        Q.push({x, y});
        dist_7562[x][y] = 0;
        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<8; dir++)
            {
                int nx = cur.first  + dx_7562[dir];
                int ny = cur.second + dy_7562[dir];
                if(nx<0 || nx>=l || ny<0 || ny>=l) continue;
                if(dist_7562[nx][ny]>=0) continue;
                Q.push({nx, ny});
                dist_7562[nx][ny] = dist_7562[cur.first][cur.second] + 1;
            }
        }
        cout << dist_7562[tar_x][tar_y] << '\n';
    }
}

char board_5427[1002][1002];
int distF_5427[1002][1002];
int distS_5427[1002][1002];

void boj5427()
{
    int TC, w, h;
    int die;
    queue<pair<int, int>> FQ;
    queue<pair<int, int>> SQ;

    cin >> TC;

    for(int T=0; T<TC; T++)
    {
        cin >> w >> h;
        for(int l=0; l<h; l++)
        {
            fill(distF_5427[l], distF_5427[l]+w, -1);
            fill(distS_5427[l], distS_5427[l]+w, -1);
        }
        
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                cin >> board_5427[i][j];
                if(board_5427[i][j] == '@')
                {
                    SQ.push({i,j});
                    distS_5427[i][j] = 0;
                }
                else if(board_5427[i][j] == '*')
                {
                    FQ.push({i,j});
                    distF_5427[i][j] = 0;
                }
            }
        die = 1;
        while(!FQ.empty())
        {
            auto cur = FQ.front(); FQ.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first  + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(distF_5427[nx][ny]>=0 || board_5427[nx][ny]=='#') continue;
                FQ.push({nx,ny});
                distF_5427[nx][ny] = distF_5427[cur.first][cur.second] + 1;
            }
        }

        while(!SQ.empty())
        {
            if(!die)
            {
                while (!SQ.empty())
                    SQ.pop();
                break;
            }
            auto cur = SQ.front(); SQ.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first  + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || nx>=h || ny<0 || ny>=w)
                {
                    cout << distS_5427[cur.first][cur.second]+1 << '\n';
                    die = 0;
                    break;
                }
                if(board_5427[nx][ny] =='#' || distS_5427[nx][ny] >= 0) continue;
                if(distF_5427[nx][ny] != -1 && distF_5427[nx][ny] <= distS_5427[cur.first][cur.second] + 1)  continue;
                SQ.push({nx, ny});              // distF_5427[nx][ny] != -1 : 보드에 불이 없는 경우가 있다! 예외처리
                distS_5427[nx][ny] = distS_5427[cur.first][cur.second] + 1;
            }
        }
        if(die)
            cout << "IMPOSSIBLE\n";
    }
}

char board_2206[1002][1002];
int dist_2206[1002][1002][2];
// dist_2206[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist_2206[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
/*
void boj2206_san() // 내 풀이, 완전 탐색으로 하니까 시간초과남 ㅠㅠ
{
    int M, N;
    int i, j;
    int crash = 1;
    int cnt = 0;
    int rst=-1;
    cin >> M >> N;
    queue<pair<int, int>> Q;
    
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            cin >> board_2206[i][j];
            if(board_2206[i][j] == '1')
                cnt++;
        }

    for(i=0; i<cnt; i++)
    {
        for(j=0; j<M; j++)
            fill(dist_2206[j], dist_2206[j]+N, -1);

        Q.push({0, 0});
        dist_2206[0][0] = 1;
        crash = 1;
        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first  + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
                if(dist_2206[nx][ny]>=0 || board_2206[nx][ny] == '2') continue;
                if(board_2206[nx][ny]=='1')
                {
                    if(crash)
                    {
                        board_2206[nx][ny] = '2';
                        crash = 0;
                    }
                    else 
                        continue;
                }
                Q.push({nx,ny});
                dist_2206[nx][ny] = dist_2206[cur.first][cur.second] + 1;
            }
        }
    }

    rst = max(dist_2206[M-1][N-1], rst);
    cout << rst;

}
*/
void boj2206() // 로직 설명: https://bloodstrawberry.tistory.com/305
{
    int M, N;
    int i, j;
    int rst=-1;
    cin >> N >> M;
    
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            cin >> board_2206[i][j];
            dist_2206[i][j][0] = dist_2206[i][j][1] = -1;
        }

    dist_2206[0][0][0] = dist_2206[0][0][1] = 1;
    queue<tuple<int, int, int>> Q;
    Q.push({0,0,0});

    while(!Q.empty())
    {
        int cur_x, cur_y, crash;
        tie(cur_x, cur_y, crash) = Q.front();
        if(cur_x == N-1 && cur_y == M-1)
        {
            cout << dist_2206[cur_x][cur_y][crash];
            return;
        }
        Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(board_2206[nx][ny] == '0' && dist_2206[nx][ny][crash] == -1) // 깬놈이랑 안깬놈이 crash에 따라 구분되어 들어간다.
            {
                Q.push({nx, ny, crash});    // crash가 0이면서 Q에 들어간 애들은 독립적으로 벽을 한번 깰 수 있다는걸 기억해야한다.
                dist_2206[nx][ny][crash] = dist_2206[cur_x][cur_y][crash]+1; // 모든 crash 값을 고려한 코드
            }
            if(!crash && board_2206[nx][ny] == '1' && dist_2206[nx][ny][1] == -1) // 핵심, 벽 한번도 안깨고, 다음이 벽이면
            {      
                dist_2206[nx][ny][1] = dist_2206[cur_x][cur_y][0]+1; // 벽을 깬 거리는 안깬거리 + 1
                Q.push({nx, ny, 1}); // 벽을 깬 자리라는것을 "1" 알려주고 Q에 넣는다, 애는 for문을 돌때 다시 !crash 조건으로 들어가지 못한다!
            }   // 결국 내가 최초로 생각한 벽 한번도 안깬 BFS, 한번 깬 BFS를 돌리고 난 후, dist[N-1][M-1]을 출력하는것이 맞음, 난 근데 구현을 못했음.
        }
    }
    cout <<-1;
}

// int arr[100005];
// int state[100005];
int arr[10]; // 디버깅용, 이렇게해서 직접 돌려서 코드 복습할것.
int state[10];
int n;


#define NOT_VISITED 0
#define VISITED  1
#ifdef RUN1
#define CYCLE_IN  2
#else
#define CYCLE_IN  -1 // index인 x값과 겹치면 안되므로 -1로 지정
#endif
#define NOT_CYCLE_IN  3

void find_cycle(int start)
{
    int cur = start; // 시작점

    while (1)
    {
        state[cur] = start; // start 도장 쾅쾅
        cur = arr[cur];  // 다음꺼 ㄱㄱ

        if(state[cur] == start) { // 돌다보니 제자리네?
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN; // 사이클이야~
                cur = arr[cur];
            }
            return;
        }
        else if(state[cur] != 0) // 먼저 방문했거나 사이클이면
            return;
    }
    
}

void boj9466()
{
    int T;
    int i;
    int cnt;
    cin >> T;

    while (T--)
    {
        cin >> n;
        fill(state+1, state+1+n, 0);
        cnt = 0;

        for(i=1; i<=n; i++) {
            cin >> arr[i];
        }

        for(i=1; i<=n; i++) {
            if(state[i] == NOT_VISITED)
                find_cycle(i);
        }

        for(i=1; i<=n; i++) {
            if(state[i] != CYCLE_IN)
                cnt++;
        }

        cout << cnt << '\n';
    }
}


bool vis2583[101][101];

void fill_box(int x1, int y1, int x2, int y2)
{
    for(int i=y1; i<y2; i++)
        for(int j=x1; j<x2; j++)
            vis2583[i][j]   = true;
}

void boj2583()
{
    
    int test[100];
    vector <int> V;
    queue<pair<int, int>> Q;

    int M, N, K;
    int i, j;
    int area=0;
    int numb = 0;
    
    cin >> M >> N >> K;
    
    for(i=0; i<M; i++)
        fill(vis2583[i], vis2583[i]+N, 0);
    
    while (K--)
    {
        int x1, y1, x2, y2; // x.y 좌표계
        cin >> x1 >> y1 >> x2 >> y2;
        fill_box(x1, y1, x2, y2);
    }

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            if(!vis2583[i][j])
            {
                Q.push({i, j});
                vis2583[i][j] = true;
                numb = 0;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    numb++;
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
                        if(vis2583[nx][ny]) continue;
                        vis2583[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
                V.push_back(numb);
                area++;
            }
        }
    
    cout << area <<'\n';
    sort(V.begin(), V.end());
    for(auto i : V)
    {
        cout << i;
        if(i != V.back())
            cout <<' ';
    }
}

void boj2667()
{
    int N;
    int i, j;
    cin >> N;
    char board[35][35];
    bool vis[35][35];
    queue<pair<int, int>> Q;
    int cnt = 0;
    int area = 0;
    vector<int> V;

    for(i=0; i<N; i++)
    {
        fill(board[i], board[i]+N, '0');
        fill(vis[i], vis[i]+N, 0);
    }

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            cin >> board[i][j];
    
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            if(board[i][j] == '1' && vis[i][j] == 0)
            {
                Q.push({i, j});
                vis[i][j] = 1;
                area = 0;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    area++;
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first  + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                        if(vis[nx][ny]|| board[nx][ny] == '0') continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                V.push_back(area);
                cnt++;
            }
        }

    cout << cnt <<'\n';
    
    sort(V.begin(), V.end());
    for(auto i : V)
        cout << i <<'\n';
}

int dist5014[1000001];
void boj5014()
{
    int F, S, G, U, D; // 최대 높이, 시작층, 목표층, 위로 이동거리, 아래로 이동거리
    int next;
    queue<int> Q;
    cin >> F >> S >> G >> U >> D;
    // 1차원 bfs
    fill(dist5014, dist5014+1000001, -1);
    Q.push(S);
    dist5014[S] = 0;

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        
        for(auto i : {U, D})
        {

            if(i==U)
                next = cur + i;
            else
                next = cur - i;

            if(next < 1 || next > F) continue;
            if(dist5014[next]>=0) continue;
            Q.push(next);
            dist5014[next] = dist5014[cur] + 1;
        }
    }

    if(dist5014[G] == -1)
        cout << "use the stairs\n";
    else
        cout << dist5014[G] << '\n';
    
}

void boj2468()
{
    int board[102][102];
    bool vis[102][102];

    int N, i, j, k, l;
    int max_val = 0;
    int min_val = 0;
    int area = 0;
    int ans = 0;
    queue<pair<int, int>> Q;
    cin >> N;

    for(i=0; i<N; i++)      //BFS 돌리는데
        for(j=0; j<N; j++)
        {
            cin >> board[i][j];
            max_val = max(max_val, board[i][j]);
            min_val = min(min_val, board[i][j]);
        }
    
    for(i=min_val; i<max_val; i++)
    {
        area = 0;
        for(l=0; l<N; l++)
            fill(vis[l], vis[l]+N, 0);
        
        for(j=0; j<N; j++)
        {
            for(k=0; k<N; k++)
            {
                if((i < board[j][k]) && vis[j][k] == 0)
                {
                    Q.push({j, k});
                    vis[j][k] = 1;

                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first  + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                            if(vis[nx][ny] || board[nx][ny] <= i) continue;
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    area++;
                }
            }
        }
        ans = max(ans, area);
    }

    cout << ans <<'\n';
}

void boj6593()
{
    char board[32][32][32]; // L R C
    int dist[32][32][32];
    int dx[6] = {1, 0, -1, 0, 0, 0}; // 행
    int dy[6] = {0, 1, 0, -1, 0, 0}; // 열
    int dz[6] = {0, 0, 0, 0, 1, -1}; // 높이
    int L, R, C;
    int i, j, k;
    int end_flag;
    queue<tuple<int, int, int>> Q;


    while (1)
    {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) return;
        end_flag = 0;
        for(i=0; i<L; i++)
            for(j=0; j<R; j++)
                for(k=0; k<C; k++)
                {
                    cin >> board[i][j][k];
                    dist[i][j][k] = -1;
                    if(board[i][j][k] == 'S')
                    {
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                }

        while (!Q.empty())
        {
            int curx, cury, curz;
            tie(curz, curx, cury) = Q.front(); Q.pop();

            for(int dir=0; dir<6; dir++)
            {
                int nx = curx + dx[dir];
                int ny = cury + dy[dir];
                int nz = curz + dz[dir];
                if(nx<0 || nx>=R || ny<0 || ny>=C || nz<0 || nz>=L) continue;
                if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] >= 0) continue;
                if(board[nz][nx][ny] == 'E')
                {
                    cout << "Escaped in "<< dist[curz][curx][cury] + 1 << " minute(s).\n";
                    end_flag = 1;
                }
                Q.push({nz,nx,ny});
                dist[nz][nx][ny] = dist[curz][curx][cury] + 1;
            }
        }

        if(!end_flag)
            cout << "Trapped!\n";
    }

}

void boj2573()
{
    int M, N;
    int i, j;
    cin >> N >> M;

    int board[304][304];
    bool vis[304][304];
    int area = 0;
    int year = 0;
    queue<pair<int, int>> Q;

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            cin >> board[i][j];

    while (1)
    {
        area = 0;
        year++;
        for(i=0; i<N; i++)
            fill(vis[i], vis[i]+M, 0);

        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(board[i][j] != 0 && vis[i][j] == 0)
                {
                    Q.push({i, j});
                    vis[i][j] = 1;

                    while (!Q.empty())
                    {
                        auto cur = Q.front();   Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first  + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                            if(vis[nx][ny]) continue; // 서순 유의, visit 먼저 체크해야 된다!
                            if(board[nx][ny] == 0){
                                if(board[cur.first][cur.second]>0) // 요 케이스만 조심하자, 0 이하로 가면 안됨
                                    board[cur.first][cur.second]--;
                                continue;
                            }
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    area++;
                }
            }
        }
        // cout << '\n';
        // for(i=0; i<N; i++) // 디버깅때 이렇게 한번씩 그려보는거 유용한듯
        // {
        //     for(j=0; j<M; j++)
        //         cout << board[i][j] << ' ';
        //
        //     cout << '\n';
        // }
        if(area>1)
        {
            cout << year-1;
            return;
        }
        else if(area == 0)
        {
            cout << 0;
            return;
        }
    }
}

int board_2146[101][101];
int bridge(int i, int j, int N) {

    queue<pair<int, int>> Q;
    int dist[101][101];
	for (int k = 0; k < N; k++)
		fill(dist[k], dist[k] + N, -1); // 매번 -1 초기화를 하지 않으면 이전 시도 때의 dist 값 0 초기화 때문에 continue에 다걸림

    Q.push({i,j});
    dist[i][j] = 0;

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(dist[nx][ny]>=0) continue;
            if(board_2146[i][j] == board_2146[nx][ny]) continue; // cur 값이 아니라 i,j이다, 입력받은 "id"값과 비교해야 한다!
            if(board_2146[nx][ny] != 0) // 다음섬을 찾은거임~
                return dist[cur.first][cur.second]; // 다리의 거리니까 +1 할필요 없음
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    return 1000;
}

void boj2146() 
{
    int N;
    queue<pair<int, int>> Q;
    
    bool vis[101][101];
    int i, j;
    int min_dist=1000;
    int id = 1;
    cin >> N;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            cin >> board_2146[i][j];
            vis[i][j] = 0;
        }
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(board_2146[i][j] && vis[i][j] == 0) // BFS 돌면서 각 섬마다 id 할당
            {
                Q.push({i, j});
                vis[i][j] = 1;

                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    board_2146[cur.first][cur.second] = id;
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                        if(board_2146[nx][ny] == 0 || vis[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                id++;
            }
        }
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(board_2146[i][j] == 0) continue;
            min_dist = min(min_dist, bridge(i,j,N));
        }
    }

    cout << min_dist;

}

#define MX 100001
int dist13549 [MX];
void boj13549()
{
    int N, K;
    deque<int> DQ;
    int dx1[3] = {2, 1, -1};
    cin >> N >> K;
    fill(dist13549, dist13549+MX, -1);

    DQ.push_back(N);
    dist13549[N] = 0;

    while (!DQ.empty())
    {
        auto cur = DQ.front(); DQ.pop_front();
        if(cur == K)
        {
            cout << dist13549[cur];
            return;
        }
        if(2*cur < MX && dist13549[2*cur] == -1)
        {
            DQ.push_front(2*cur);
            dist13549[2*cur] = dist13549[cur];
        }
        for(int nxt : {cur-1,cur+1})
        {
            if(nxt < 0 || nxt >= MX || dist13549[nxt] >= 0) continue;
            dist13549[nxt] = dist13549[cur]+1;
            DQ.push_back(nxt);      
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj1926();
    // boj2178();
    // boj7576();
    // boj4179();
    // boj1697();
    // boj1012();
    // boj10026();
    // boj7569();
    // boj7562();
    // boj5427();
    // boj2206_san();
    // boj2206();
    // boj9466();
    // boj2583();
    // boj2667();
    // boj5014();
    // boj2468();
    // boj6593();
    // boj2573();
    // boj2146();
    boj13549();
}