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

void boj2752()
{
    int tmp = 0;
    int i;
    vector <int> v(3);

    for (i=0; i<3; i++)
    {
        cin >> tmp;
        v[i] = tmp;
    }

    sort(v.begin(), v.end());

    for(i=0; i<3; i++)
    {
        cout << v[i] <<'\n';
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // boj10871();
    // boj10869();
    boj2752();

    return 0;
}

