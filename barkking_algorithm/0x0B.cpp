#include <bits/stdc++.h>

using namespace std;
using ll = long long; // typedef, define 대신에 모던 C++에서 추천됨

void ex1(int n) {
    if(n == 0) return; // base condition
    cout << n << '\n'; 
    ex1(n-1);   // k+1이 k에 영향을 받는 "축소개념"의 귀납적 사고를 해야한다, 절차적으로 따라가지 말자
}

int recur1629(int a, int b, int c) {
    if(b <= 1) return a % c; // base condition으로 재귀함수는 수렴한다.
    ll val = recur1629(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val; //짝수
    return val * a % c; //홀수
}

void boj1629() {
    int a, b, c;
    cin >> a >> b >> c; // (a^b) % c;
    cout << recur1629(a, b, c);
}

void recur11729(int a, int b, int n) { // n개의 원판을 a기둥에서 b기둥으로 옮기는 점화식 유도
    if(n <= 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    
    recur11729(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    recur11729(6-a-b, b, n-1);
}

void boj11729() {
    int N;
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    recur11729(1, 3, N);
}

int recur1074(int N, int R, int C) {
   if(N < 1) return 0;
   int half = 1<<(N-1);

   if(R < half && C < half) return recur1074(N-1, R, C);
   if(R < half && C >= half) return half*half + recur1074(N-1, R, C-half);
   if(R >= half && C < half) return 2*half*half + recur1074(N-1, R-half, C);
   else return 3*half*half + recur1074(N-1, R-half, C-half);
}

void boj1074() {

    int N, R, C;
    cin >> N >> R >> C;
    cout << recur1074(N, R, C);
}

string str17478;
void boj17478(int n) {
    cout << str17478 << "\"재귀함수가 뭔가요?\"\n";
    if(n==0) {
        cout << str17478 << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        return;
    } 
    cout << str17478 << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout << str17478 << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout << str17478 << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    str17478.append("____");
    boj17478(n-1);
    cout << str17478 << "라고 답변하였지.\n";
    str17478.erase(0, 4);
}

int board1780[2200][2200];
int Cnt1780[3]; // -1 0 1
int N;
bool isSame(int n, int r, int c) { // 3^n을 다이나믹하게 처리할 수 있는 함수를 만들어야함, N 81 에서 분할되는 TC를 상상해보자.

    for(int i=r; i<r+n; i++)
        for(int j=c; j<c+n; j++) {
            if(board1780[r][c] != board1780[i][j])
                return false;
        }

    return true;
}

void boj1780(int n, int r, int c) {
    
    if(isSame(n, r, c)) {
        if(board1780[r][c] == -1)
            Cnt1780[0]++;
        else if(board1780[r][c] == 0)
            Cnt1780[1]++;
        else
            Cnt1780[2]++;
        return;             // base condition
    }
    else {
        int div = n/3;      // else의 경우 분할해야 하므로
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)             
                boj1780(div, r + i*div, c + j*div); // 핵심이 되는 부분인듯, r + i*div 이런 수식을 만들어 낼 수 있어야 함
    }                                               // 81, 9, 3 TC를 두고 코드를 보자 분할정복의 의미를 알 수 있다.
}

void recur_input() {
    
    int i, j;
    cin >> N;
    // cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    // boj17478(N);
    // cout << "라고 답변하였지.\n";

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            cin >> board1780[i][j];

    boj1780(N, 0, 0);
    for (int i = 0; i < 3; i++) cout << Cnt1780[i] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    // ex1(5);
    // boj1629();
    // boj11729();
    // boj1074();
    recur_input();

}