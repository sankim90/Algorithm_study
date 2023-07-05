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
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj10828();
    boj10773();
}