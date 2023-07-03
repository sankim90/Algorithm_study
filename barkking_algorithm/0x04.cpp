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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    boj1406();
}