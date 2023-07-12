#include <bits/stdc++.h>
using namespace std;

void boj10828()
{
    int N;
    cin >> N;
    int tmp;
    stack <int> stk;
    string str;

    while(N--)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> tmp;
            stk.push(tmp);
        }
        else if(str == "pop")
        {
            if(stk.empty())
                cout << "-1\n";
            else
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if(str == "top")
        {
            if(stk.empty())
                cout << "-1\n";
            else
                cout << stk.top() << '\n';
        }
        else if(str == "size")
            cout << stk.size() << '\n';
        else if(str == "empty")
            cout << stk.empty() << '\n';
    }
}

void boj10773()
{
    int K, tmp;
    int rst = 0;
    cin >> K;
    stack <int> stk;

    while(K--)
    {
        cin >> tmp;
        if(tmp)
        {
            rst += tmp;
            stk.push(tmp);
        }
        else
        {
            rst -= stk.top();
            stk.pop();
        }
    }

    cout << rst;    // 1 2 3 4 5 6 7 8 // 4 3 7 2 1
}

void boj1874()
{
    int N;
    int K = 1;
    int J = 0;
    vector <int> v (100001);
    queue <char> rst;
    stack <int> stk;

    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> v[i]; //4 3 6 8 7 5 2 1
    
    stk.push(K);
    rst.push('+');

    while(1)
    {
        if(!stk.empty() && stk.top() == v[J])
        {
            rst.push('-');
            J++;
            stk.pop();
        }
        else if(K<=N)
        {
            K++;
            stk.push(K);
            rst.push('+');
        }
        else
        {
            break;
        }

        if(J == N)
            break;
    }

    //8
    //STK: 1 2 3 4
    //V: 4 3 6 8 7 5 2 1

    if(stk.empty())
    {
        while(!rst.empty())
        {
            cout << rst.front() << '\n';
            rst.pop();
        }
    }
    else
        cout << "NO\n";
}

void boj2493()
{
    // int N;
    // int index=1;
    // int prev; 
    // int tmp;
    
    // // stack <int> stk;
    // queue <int> rst;
    // vector <int> stk(500001);
    // int ptr = 0;
    // int i;
    // // vector <int> rst(500001);
    // cin >> N;

    // for(i=0; i<N; i++)
    //     cin >> stk[i];

    // if(N == 1)
    // {
    //     cout << "0\n";
    //     return;
    // }

    // 2개이상이라고 확정하고 진행  // 시간초과 
    // prev = 1;                      
    // rst.push(0);
    // while(prev<N) // 6 9 5 7 4
    // {// 1 2 3 5
    //     if(stk[ptr] >= stk[prev])
    //     {
    //         rst.push(ptr+1);
    //         ptr = prev;
    //         prev++;
    //     }
    //     else if(stk[ptr] < stk[prev])
    //     {
    //         if(ptr == 0)
    //         {
    //             rst.push(0);
    //             ptr = prev;
    //             prev++;
    //         }
    //         else
    //             ptr--;
    //     }
        
    // }

    // stk_tmp = stk;

    // prev = stk.top();
    
    // while(!stk.empty())   // 6 9 5 7 4 -> 시간초과 again
    // {                          // 
    //     //                     // prev = 4, top = 7 // prev = 7, top = 5 // prev 7, top 9 // prev 5 top 9
    //     stk.pop();

    //     if(stk.empty() || stk.top() >= prev)
    //     {
    //         if(stk.empty())
    //             rst.push(0);
    //         else if(stk.top() >= prev)
    //             rst.push(stk.size());
    //         stk = stk_tmp;

    //         for(int i=0; i<index; i++) // 6 9 5 7  -> 6 9 5  -> 6 9
    //             stk.pop();

    //         if(!stk.empty())
    //             prev = stk.top(); // prev 7 // prev 5 // 9
    //         index++; // 2 // 3
    //     }
    // }

    // while(!rst.empty())
    // {
    //     cout << rst.front() << ' ';
    //     rst.pop();
    // }
    // cout <<'\n';



    //솔루션 https://godsang.tistory.com/entry/C-BOJ-2493-stack-%EA%B3%BC-pair%EC%9D%98-%EC%82%AC%EC%9A%A9
    /*
    K = 6 9 5 7 4

    0. STK[{100만, 0}, }

    for
    1. 100만 < 6 False
    -> cout 0
    -> push STK[{100만, 0}, {6, 1}]

    2. 6 < 9 True
    -> pop STK [{100만, 0}]
    -> cout 0
    -> push STK [{100만, 0}, {9, 2}]

    3. 9 < 5 False
    -> cout 2
    -> push STK [{100만, 0}, {9, 2}, {5, 3}]

    4. 5 < 7 True
    -> pop STK [{100만, 0}, {9, 2}]
    -> cout 2
    -> push STK [{100만, 0}, {9, 2}, {7,4}]

    5. 7 < 4 False
    -> cout 4
    -> push STK [{100만, 0}, {9, 2}, {7,4}, {4,5}]

    done
    */

    int n, k;
    int max = 100000001;
    stack<pair<int, int>> stk;
    cin >> n;
    stk.push({max, 0});
    for(int i = 1; i <= n ; i++) {
        cin >> k;
        while(stk.top().first < k) {
            stk.pop();
        }
        cout << stk.top().second << " ";
        stk.push({k, i});
    }

}

void boj6198()
{
    #define MAX 80001
    int N, i;
    
    int ptr = 1;
    int head = 0;
    unsigned long long rst = 0;
    vector <int> V(MAX);
    cin >> N;

    for(i = 0; i < N; i++)
        cin >> V[i];
    V[N] = 1000000001;

    for(i = 0; i < N; i++)
    {
        while(V[head] > V[ptr])
        {
            rst++;
            ptr++;
        }
        if(V[head] <= V[ptr])
        {
            head++;
            ptr = head + 1;
        }
    }

    cout << rst;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj10828();
    // boj10773();
    // boj1874();
    // boj2493();
    boj6198();
}