#include <bits/stdc++.h>
using namespace std;

void boj1406()
{
    list <char> node; // data node
    string str;
    int N;

    cin >> str;
    for(auto i : str)
        node.push_back(i);

    auto ptr = node.end(); //iterator pointer
    // ptr--;
    // cout << *ptr; // abcd 기준 NULL
    // ptr++;
    // cout << *ptr; // a
    
    cin >> N;
    while(N--)
    {
        char cmd;

        cin >> cmd;

        switch (cmd)
        {
        case 'L':
            if(ptr != node.begin())
                ptr--;
            break;
        
        case 'D':
            if(ptr != node.end())
                ptr++;
            break;
        
        case 'B':
            if(ptr != node.begin())
            {
                ptr--;
                ptr = node.erase(ptr);
            }
            break;
        
        case 'P':
            if(node.size() <= 600000)
            {
                char ch;
                cin >> ch;
                node.insert(ptr, ch);
            }
            break;

        default:
            break;
        }
    }

    for(auto i : node)
        cout << i;

}

void boj5397()
{
    int N;
    cin >> N;

    while (N--)
    {
        list <char> inpwd;
        string str;
        cin >> str;

        auto ptr = inpwd.begin();

        for(auto cmd : str)
        {
            switch (cmd)
            {
            case '<':
                if(ptr != inpwd.begin())
                    ptr--;                
                break;

            case '>':
            if(ptr != inpwd.end())
                ptr++;
            break;

            case '-':
            if(ptr != inpwd.begin())
            {
                ptr--;
                ptr = inpwd.erase(ptr);
            }
            break;

            default:
                if(inpwd.size() < 1000001)
                    inpwd.insert(ptr, cmd);
                break;
            }
        }

        for(auto i : inpwd)
            cout << i;

        cout << '\n';
    }
}

void boj1158() // 7,3 // 1 2 3 4 5 6 7 -> 3 // 1 2 4 5 6 7 -> 6 // 1 2 4 5 7 -> 2
{
    int N, K;
    list <int> circle;
    list <int> rst;

    cin >> N >> K;

    for(int i=1; i<=N; i++)
        circle.push_back(i);
    
    auto ptr = circle.begin();


    while(!circle.empty())
    {
        for(int j=1; j<K; j++)
        {
            ptr++;

            if(ptr == circle.end())
                ptr = circle.begin();
        }

        // cout << *ptr << " ";
        rst.push_back(*ptr);
        ptr = circle.erase(ptr);
        if(ptr == circle.end())
            ptr = circle.begin();
    }

    cout << "<";
    for(auto i : rst)
    {
        cout << i;
        if(i != rst.back())
            cout <<", ";
    }
    cout << ">\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj1406();
    // boj5397();
    boj1158();
}