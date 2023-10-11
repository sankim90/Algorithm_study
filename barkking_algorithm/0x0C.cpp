#include <bits/stdc++.h>
using namespace std;

int N, M;
int cnt;
bool isused[35];
bool isused1[35];
bool isused2[35];
int arr[10];

// 백트래킹 기본형 외우자!
// 1부터 N까지 숫자 중 K개를 선택하여 순서 있는 수열 만들기
void boj15649(int k) {  // K개 선택함
                        
    if(k == M) { // M개 충족시
        for(int i=0; i<M; i++) 
            cout << arr[i] << " "; // arr에 기록한 M개값 출력
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++) { // 1부터 N까지 숫자중에
        if(!isused[i]) {    // 수열 만들기에 i가 사용되지 않았다면
            arr[k] = i;     // k번째 수를 i값으로 정하고
            isused[i] = true; // i 값 사용했다고 표시
            boj15649(k+1);   // k정했으니 다음 수를 정하러 한 단계 더 들어감
            isused[i] = false; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
        }
    }
}

void boj9663(int cur_row) { // 매 행마다 체크하는데
    if(N==cur_row) {
        cnt++;
        return;
    }
    for(int col=0; col<N; col++) { // 열을 하나씩 바꿔서 백트랙킹
        if(isused[col] || isused1[cur_row+col] || isused2[cur_row-col+N]) continue; // 행, 양대각선, 음대각선, 문제를 통해 수식을 도출해낸다. 물론 난 해설 봄 ㅇㅇ
        isused[col] = true;                                                           // 음대각선은 0 - 14 = -14가 나올수 있으므로 N을 더해준다.
        isused1[cur_row+col] = true;                                                  // N을 더하면 값이 달라지지 않나? 싶었지만 체크만 하기위함이니 상관없다.
        isused2[cur_row-col+N] = true;
        boj9663(cur_row+1);                                                           // N과 M 문제와 비슷한 패턴
        isused[col] = false;
        isused1[cur_row+col] = false;
        isused2[cur_row-col+N] = false;
    }
}

vector <int> V;
void boj1182(int cur, int total) {
    if(cur == N) {
        if(total == M) cnt++;
        return;
    }

    boj1182(cur+1, total); // 현재값을 더하지 않음
    boj1182(cur+1, total+V[cur]); // 현재값을 더함
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    // boj15649(0);
    // boj9663(0);
    // cout << cnt;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }

    boj1182(0, 0);
    if(M==0) cnt--; // 공집합 제거
    cout << cnt;
}