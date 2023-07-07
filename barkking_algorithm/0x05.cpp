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
    int N;
    int index=1;
    int prev; 
    int tmp;
    cin >> N;

    stack <int> stk;
    stack <int> rst;
    // vector <int> rst(500001);

    cin >> tmp;
    stk.push(tmp);

    for(int i=1; i<N; i++)
    {
        
        cin >> tmp;

        if(stk.empty())
        {
            rst.push(0);
        }
        else if(stk.top() < tmp)
        {
            stk.pop();
        }
        else if(stk.top() >= tmp)
        {
            rst.push(stk.size());
        }
            // stk.push(tmp);
    }


    // stk_tmp = stk;

    // prev = stk.top();
    
    // while(!stk.empty())   // 6 9 5 7 4 -> 시간초과
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

    while(!rst.empty())
    {
        cout << rst.top() << ' ';
        rst.pop();
    }
    cout <<'\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj10828();
    // boj10773();
    // boj1874();
    boj2493();
}