#include <bits/stdc++.h>
using namespace std;

void boj10866()
{
    deque <int> dq;
    int N;
    cin >> N;

    while(N--)
    {
        string str;
        int tmp;
        cin >> str;

        if(str == "push_front")
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if(str == "push_back")
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if(str == "pop_front")
        {
            if(dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() <<"\n";
                dq.pop_front();
            }
        }
        else if(str == "pop_back")
        {
            if(dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() <<"\n";
                dq.pop_back();
            }
        }
        else if(str == "size")
            cout << dq.size() << "\n";
        else if(str == "empty")
            cout << dq.empty() << "\n";
        else if(str == "front")
        {
            if(dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << "\n";
        }
        else if(str == "back")
        {
            if(dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << "\n";
        }
    }
}

void boj1021()
{
    int N, M;
    int i;
    int cnt1 = 0;
    int cnt2 = 0;
    deque <int> dq, dq2;
    cin >> N >> M;

    for(i=1; i<=N; i++)
        dq.push_back(i);
    dq2 = dq;
    while(M--)
    {
        int tmp;
        cin >> tmp;

        while(dq.front() != tmp)
        {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt1++;
        }
        dq.pop_front();

        while(dq2.front() != tmp)
        {
            dq2.push_front(dq2.back());
            dq2.pop_back();
            cnt2++;
        }
        dq2.pop_front();

        if(cnt1 < cnt2)
        {
            dq2 = dq;
            cnt2 = cnt1;
        }
        else if(cnt1 > cnt2)
        {
            dq = dq2;
            cnt1 = cnt2;
        }
    }
    
    cout << cnt1;
}

void boj5430()
{
    int T;
    cin >> T;
    

    while(T--)
    {
        string str;
        deque <int> dq;
        int rev=0;
        int err=0;
        int N;

        cin >> str;
        cin >> N;

        for(int i=0; i<N; i++)
        {
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        }
        
        for(auto i : str)
        {
            if(i == 'R')
            {
                if(rev)
                    rev = 0; // front
                else 
                    rev = 1; // back
            }
            else if(!dq.empty() && i == 'D')
            {
                if(!rev)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
            else
            {
                err=1;
                cout << "error\n";
                break;
            }
        }

        if(err)
            continue;
        // if(dq.empty())
        //     continue;

        if(!rev)
        {
            cout << '[';
            while(!dq.empty())
            {
                cout << dq.front();
                dq.pop_front();
                if(!dq.empty())
                    cout << ',';
            }
            cout << "]\n";
        }
        else
        {
            cout << '[';
            while(!dq.empty())
            {
                cout << dq.back();
                dq.pop_back();
                if(!dq.empty())
                    cout << ',';
            }
            cout << "]\n";
        }
        
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj10866();
    // boj1021();
    boj5430();

    // deque <int> dq;
    // int i;

    // for(i=1; i<5; i++)
    //     dq.push_back(i);
    
    // auto itr = dq.end();
    
    // while(i--)
    //     cout << *itr--;
}