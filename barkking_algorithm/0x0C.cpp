#include <bits/stdc++.h>
using namespace std;

int N, M;
int cnt;
bool isused[35];
bool isused1[35];
bool isused2[35];
int arr[10];
vector <int> V;

//두 수열에서 같은 위치에 다른 값이 있는 경우가 하나라도 있으면 다른 수열이라고 말합니다.
// An = a1 + 2(n-1)
// -> 1 3 5 7 9
// Bn = a1 - 2(n-1)
// -> 9 7 5 3 1
// A5와 B5의 값이 다르므로, 두 개는 다른 수열이다. 즉 순서를 인정한다.
// "수열"은 순서가 있는 나열이다.

// next_permutation은 오름차순을 내림차순으로 정렬 하는 과정에서 모든 순열을 알 수 있는 함수다.
bool next_permutation_san(int a[], int size) { //next_permutation의 정의, 과정을 잘 알아두자 ref: https://charles098.tistory.com/8
    int k = size - 1;
    int m = size - 1;
    //1. find max(k), a[k] < a[k+1]
    while (k > 0 && a[k-1] >= a[k])
        k--;
    
    if(k==0) {
        reverse(a, a+size);
        return false;
    }
    else {
        //2. find max(m), a[k] < a[m] && k < m
        while (a[k-1] >= a[m])
            m--;
        
        //3. swap a[k], a[m]
        swap(a[k-1], a[m]);
        //4. reverse a[k+1: ]
        reverse(a+k, a+size);

        return true;
    }
}

// 백트래킹 기본형 외우자!
// 1부터 N까지 숫자 중 K개를 선택하여 순서 있는 수열 만들기
void boj15649(int k) {  // K개 선택함
    //#1 백트래킹을 이용한 풀이                        
    // if(k == M) { // M개 충족시
    //     for(int i=0; i<M; i++) 
    //         cout << arr[i] << " "; // arr에 기록한 M개값 출력
    //     cout << "\n";
    //     return;
    // }

    // for(int i=1; i<=N; i++) { // 1부터 N까지 숫자중에
    //     if(!isused[i]) {    // 수열 만들기에 i가 사용되지 않았다면
    //         arr[k] = i;     // k번째 수를 i값으로 정하고
    //         isused[i] = true; // i 값 사용했다고 표시
    //         boj15649(k+1);   // k정했으니 다음 수를 정하러 한 단계 더 들어감
    //         isused[i] = false; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    //     }
    // }

    //#2 next_permutation 이용한 풀이
    
    do{
        for(int i=0; i<M; i++) 
            cout << V[i] << " ";
        
        cout << "\n";
        reverse(V.begin() + M, V.end()); // next_permutation의 동작을 잘 알아야 쓸 수 있는 스킬
    }while(next_permutation(V.begin(), V.end())); //next_permutation은 오름차순을 내림차순으로 정렬 하는 과정에서 모든 순열을 알수 있는 함수다.
                                                  //이때 각 요소를 크기 비교 하기때문에 위와 같은 트릭이 가능하다.
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


void boj1182(int cur, int total) { // 상태 트리로 그림을 그려보면 좋다, 부분 수열은 2^N 개이다.
    if(cur == N) {              //트리의 맨 마지막값이 총합이다. 
        if(total == M) cnt++;
        return;
    }

    boj1182(cur+1, total); // 현재값을 더하지 않음 EX) N 3일때, 0-> 3-> 0 == {3} 의 total 값 3 비교! 
    boj1182(cur+1, total+V[cur]); // 현재값을 더함 EX2) N 3일때, 0-> 3 -> 5 == {3, 5} 의 total 값 8 비교! 

    return;
}

void next_permutation_train() {
    // 1. next_permutation 사용법
    // 2. N개의 수열을 오름차순에서 내림차순으로 정렬하는 과정이 곧 모든 순열이 된다.
    // 3. 단 여기서 N개중 M개를 뽑으려면 reverse(V.begin() + M, V.end()) 등의 트릭이 필요함

    // for(int i=0; i<N; i++) {
    //     int tmp;
    //     cin >> tmp;
    //     V.push_back(tmp);
    // }
    
    //순열
    // do {
    //     for(int i=0; i<M; i++) {
    //             cout << V[i] << " ";
    //         }
    //     cout << "\n";
    //     reverse(V.begin()+M, V.end());
    // } while (next_permutation(V.begin(), V.end()));

    //조합
    // vector <int> npn;
    // for(int i=0; i<N; i++) {
    //     if(i<M)
    //         npn.push_back(0);
    //     else
    //         npn.push_back(1);
    // }
    
    // do {
    //     for(int i=0; i<N; i++) {
    //             if(npn[i] == 0)
    //                 cout << V[i] << " ";
    //         }
    //     cout << "\n";
    // } while (next_permutation(npn.begin(), npn.end()));
}

void boj15650(int k, int start) {  // 조합 구현 문제
    //#1 백트래킹 풀이

    // if(k==M) {
    //     for(int i=0; i<M; i++)
    //         cout << arr[i] << " ";
    //     cout <<"\n";
    //     return;
    // }

    // for(int i=start; i<=N; i++) {
    //     if(!isused[i]) {
    //         isused[i] = true;
    //         arr[k] = i;
    //         boj15650(k+1, i);
    //         isused[i] = false;
    //     }
    // }

    //#2 next_permutation 이용한 풀이
    vector <int> npn;
    for(int i=0; i<N; i++) {
        if(i<M)
            npn.push_back(0);
        else
            npn.push_back(1);
    }
    
    do {
        for(int i=0; i<N; i++) {
                if(npn[i] == 0)
                    cout << V[i] << " ";
            }
        cout << "\n";
    } while (next_permutation(npn.begin(), npn.end()));
}

void boj15651(int k) {  // K개 선택함
    //#1 백트래킹을 이용한 풀이                        
    if(k == M) { // M개 충족시
        for(int i=0; i<M; i++) {
                cout << arr[i] << " "; // arr에 기록한 M개값 출력
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++) { // 1부터 N까지 숫자중에
            arr[k] = i;     // k번째 수를 i값으로 정하고
            boj15651(k+1);   // k정했으니 다음 수를 정하러 한 단계 더 들어감
    }
}

void boj15652(int k) {  // K개 선택함
    //#1 백트래킹을 이용한 풀이                        
    if(k == M) { // M개 충족시
        for(int i=0; i<M; i++) {
                cout << arr[i] << " "; // arr에 기록한 M개값 출력
        }
        cout << "\n";
        return;
    }
    int start = 1;
    if(k>0) 
        start = arr[k-1];  // 시작점 컨트롤
    for(int i=start; i<=N; i++) { // 1부터 N까지 숫자중에
            arr[k] = i;     // k번째 수를 i값으로 정하고
            boj15652(k+1);   // k정했으니 다음 수를 정하러 한 단계 더 들어감
    }
}

void boj15654(int k) {  // K개 선택함
    
    //#1 백트랙킹 풀이
    if(k == M) {
        for(int i=0; i<M; i++)
            cout << arr[i] << " ";
        
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++) {
        if(!isused[i]) {
            arr[k] = V[i];
            isused[i] = true;
            boj15654(k+1);
            isused[i] = false;
        }
    }

    //#2 next_permutation 풀이

    // do {
    //     for(int i=0; i<M; i++) {
    //         cout << V[i] << " ";
    //     }
    //     cout << "\n";
    //     reverse(V.begin()+M, V.end());
    // } while (next_permutation(V.begin(), V.end()));
    
}

void boj15655(int k, int start) {  // K개 선택함
    
    //#1 백트랙킹 풀이
    // if(k==M) {
    //     for(int i=0; i<M; i++)
    //         cout << arr[i] << ' ';
    //     cout << "\n";
    //     return;
    // }
    // for(int i=start; i<N; i++) {
    //     if(!isused[i]) {
    //         isused[i] = true;
    //         arr[k] = V[i];
    //         boj15655(k+1, i);
    //         isused[i] = false;
    //     }
    // }

    //#2 next_permutation 풀이
    vector <int> npn;
    for(int i=0; i<N; i++) {
        if(i<M)
            npn.push_back(0);
        else
            npn.push_back(1);
    }
    
    do {
        for(int i=0; i<N; i++) {
            if(npn[i] == 0)
            cout << V[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(npn.begin(), npn.end()));
}

void boj15656(int k) {  // K개 선택함
    
    //#1 백트랙킹 풀이
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++) {
            arr[k] = V[i];
            boj15656(k+1);
    }
    
}

void boj15657(int k, int start) {  // K개 선택함
    
    //#1 백트랙킹 풀이
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<N; i++) {
        arr[k] = V[i];
        boj15657(k+1, i);
    }
}


//set은 유일한 원소만을 갖을 수 있는 구조로서 수학적으로 집합을 의미하는 것을 알 수 있다.
//set은 특정 기준에 의하여 원소들이 자동 정렬되는 노드 기반 컨테이너이다.
//set은 기본적으로 오름차순(less) 정렬이고 greater 조건자를 줌으로써 내림차순으로 정렬할 수도 있다.
//또한, 균형 이진 트리로 구현되어 빠른 시간으로 원소를 탐색할 수 있으며 이에 따라 탐색할 수 있도록 여러가지 탐색 함수를 제공해 준다.
// https://notepad96.tistory.com/25
set <vector<int>> s; 
void boj15663(int k, int start) {  // K개 선택함
    if(k == M) {
        vector<int> res;
        for(int i=0; i<M; i++)
            res.push_back(arr[i]);
        s.insert(res); // 벡터 자체를 넣으면 되는데 왜 생각 못했을까...
        res.clear();
        return;
    }
    for(int i=0; i<N; i++) {
        if(!isused[i]) {
            isused[i] = true;
            arr[k] = V[i];
            boj15663(k+1, i);
            isused[i] = false;
        }
    }
}

//1, 2, 5, 6번과 같은 상황에서는 next_permutation을 통해 구현
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    sort(V.begin(), V.end());

    // next_permutation_train();
    // boj15649(0);
    // boj9663(0);
    // cout << cnt;

    // boj1182(0, 0);
    // if(M==0) cnt--; // 공집합 제거
    // cout << cnt;
    // for(int i=1; i<=N; i++)
    //     V.push_back(i);
    // boj15650(0, 1);
    // boj15651(0);
    // boj15652(0);
    // boj15654(0);
    // boj15655(0, 0);
    // boj15656(0);
    // boj15657(0, 0);
    boj15663(0, 0);

    for(auto vec:s) {
        for(auto i:vec)
            cout << i << " ";
        cout <<"\n";
    }
        
    
}