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

// iscycle 함수는 위에서 언급한 것과 같이 N번 이내에 자기 자신으로 돌아오는지 
// 여부를 이용해 idx번째 학생이 사이클에 들어있는지를 판단하는 함수입니다.
bool iscycle_N2(int idx) // O(N^2) 풀이, 시간초과
{
    int cur = idx; // cur, idx 1 2 3 4 5 6 7
    for(int i=0; i<n; i++)
    {                   // idx = 0 1 2 3 4 5 6 7
        cur = arr[cur]; // arr = 0 3 1 4 7 3 4 6
        if(cur == idx) return true;
    }
    return false;
}

void run(int x)
{
    int cur = x; // x에서 시작할때
    while (1)
    {
        state[cur] = VISITED; // x 는 방문 체크!
        cur = arr[cur]; // x가 가르키는 다음 노드

        //1. 사이클에 포함된 학생 혹은 사이클에 포함되지 않은 학생을 재방문했을 경우 x는 사이클에 포함되지 않은 학생이다. 
        //지금까지 방문한 학생들을 사이클에 포함되지 않은 학생으로 분류한다.
        if(state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN)
        {
            cur = x;
            while (state[cur] == VISITED)
            {
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }

        //2. x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고 y는 사이클에 포함되어 있다. 
        //y에서 출발해 이동하며 다시 y에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만들고, x에서 출발해 이동하며 
        //y에 도달할 때 까지 만나는 학생들을 사이클에 포함되지 않은 학생으로 만든다.
        if(state[cur] == VISITED && cur != x)
        {
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            cur = x;
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }

        //3. x를 재방문했을 경우 x는 사이클에 포함된 학생이다. x에서 출발해 이동하며 다시 x에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
        if(state[cur] == VISITED && cur == x)
        {
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
    }
    // 이미 방문한 노드에 또 방문할 경우 탐색이 종료되고 이후 방문 표시를 남기는 작업을 진행하기 때문에 각 노드는 최대 2번 방문되어 O(N)입니다.
}


void run_2(int x){
  int cur = x; // 현재에서 시작
  while(true){
    state[cur] = x; // x값이 진행 됨을 기록
    cur = arr[cur]; // x가 가르키는 다음 노드

    // 이번 방문에서 지나간 학생에 도달했을 경우
    if(state[cur] == x){ // x -> 을 반복하다가 다시 제자리 x값에 도착했을경우
      while(state[cur] != CYCLE_IN){ // 이미 찾은 사이클 이니?
        state[cur] = CYCLE_IN;       // 아니면 사이클이라고 표시하고
        cur = arr[cur];              // 전체 표시를 위해 다음 노드로 반복
      }
      return;
    }
    // 이전 방문에서 지나간 학생에 도달했을 경우
    else if(state[cur] != 0) 
        return; // state에 111 333 444 이런식으로 x의 진행이 표현 또는, 이미 사이클이면 더볼게 없음
  }
}

void boj9466()
{
    //iscycle_N^2 풀이
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     cin >> n;
    //     for(int i=1; i<=n; i++)
    //         cin >> arr[i];
    //     int ans=0;
    //     for(int i=1; i<=n; i++)
    //         if(!iscycle_N2(i))
    //             ans++;
        
    //     cout << ans << '\n';
    // }
    
    int t;
    int i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        fill(state+1, state+n+1, 0);
        for(i=1; i<=n; i++)
            cin >> arr[i];
        int ans = 0;
        for(i=1; i<=n; i++)
        {
            if(state[i] == NOT_VISITED)
                run_2(i);
        }
        int cnt = 0;
        for(i=1; i<=n; i++)
        {
            if(state[i] != CYCLE_IN) //
                cnt++;
        }
        cout << cnt << '\n';
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
    boj9466();
}