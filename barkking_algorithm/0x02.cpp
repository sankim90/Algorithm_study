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

void boj2753()
{
    int tmp = 0;
    int rtn = 0;
    cin >> tmp;

    if(tmp % 400 == 0)
        rtn = 1;
    else if(tmp % 4 == 0 && tmp % 100 != 0)
        rtn = 1;
    
    cout << rtn;
}

void boj2480()
{
    // 3개 입력 배열에 넣기
    // 첫번째 입력부터 탐색하여 cnt++ 
    // cnt 수에 따라 값 계산 후 프린트

    vector <int> v(3);
    int i = 0;
    int rst = 0;
    int cnt = 1;

    for (i=0; i<3; i++)
    {
        cin >> v[i];
    }
        
    
    if(v[0] == v[1] && v[1] == v[2])
        rst = 10000 + (v[0] * 1000);
    else if(v[0] == v[1] || v[0] == v[2]) // 555, 551, 155, 515, 123
        rst = 1000 + (v[0] * 100);
    else if(v[1] == v[2])
        rst = 1000 + (v[1] * 100);
    else
        rst = *max_element(v.begin(), v.end()) * 100;

    // for (auto i = v.begin(); i != v.end(); i++)
    cout << rst;

    /* barking dog solution
    int a[3]; 
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0] == a[2]) cout << 10000 + a[0]*1000; // 세 수가 동일
    else if(a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1]*100; // 두 수가 동일
    else cout << a[2]*100;
    */
}

void boj2490()
{
    //input masking
    int tmp=0;
    int cnt=0;
    int n = 3;

    while (n--)
    {
        cnt = 0;
        for(int i=0; i<4; i++)
        {
            cin >> tmp;
            if(tmp == 0) // barking) 이러면 되는데... result += input;
                cnt++;
        }
        
        //string res = "DCBAE"; barking) 짬바 클라스
        //cout << res[result] << '\n';

        switch (cnt)
        {
        case 1:
            cout << "A\n";
            break;
        case 2:
            cout << "B\n";
            break;
        
        case 3:
            cout << "C\n";
            break;

        case 4:
            cout << "D\n";
            break;

        default:
            cout << "E\n";
            break;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // boj10871();
    // boj10869();
    // boj2752();
    // boj2753();
    // boj2480();
    boj2490();

    return 0;
}

