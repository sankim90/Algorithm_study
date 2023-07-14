#include <bits/stdc++.h>
using namespace std;


void boj10845()
{
    int N;
    cin >> N;
    int tmp;
    queue <int> Q;
    string str;

    while(N--)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> tmp;
            Q.push(tmp);
        }
        else if(str == "pop")
        {
            if(Q.empty())
                cout << "-1\n";
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(str == "front")
        {
            if(Q.empty())
                cout << "-1\n";
            else
                cout << Q.front() << '\n';
        }
        else if(str == "back")
        {
            if(Q.empty())
                cout << "-1\n";
            else
                cout << Q.back() << '\n';
        }
        else if(str == "size")
            cout << Q.size() << '\n';
        else if(str == "empty")
            cout << Q.empty() << '\n';
    }
}
void boj18258()
{
    queue <int> Q;
    int N, i;
    cin >> N;

    for(i=1; i<=N; i++)
        Q.push(i);
    
    while(Q.size()!=1)
    {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj10845();
    boj18258();
}