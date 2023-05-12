#include <bits/stdc++.h>

using namespace std;

void boj10871()
{
    int a, b, c;

    cin >> a >> b;

    for(int i=0; i<a; i++)
    {
        cin >> c;
        if(c < b)
            cout << c << '\n';
    }
}

void boj10869()
{
    int a, b;

    cin >> a >> b;

    cout << a + b << '\n';
    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a / b << '\n';
    cout << a % b << '\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // boj10871();
    boj10869();

    return 0;
}

