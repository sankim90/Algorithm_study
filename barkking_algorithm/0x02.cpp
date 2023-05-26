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

void boj2576()
{
    int tmp;
    int j = 0;
    int i = 0;
    int sum = 0;
    int min = 100; // max input

    for(i=0; i<7; i++)
    {
        cin >> tmp;
        if((tmp % 2) == 1)
        {
            sum += tmp;
            if(min > tmp)
                min = tmp;
            j++;
        }
    }

    if(j)
        cout << sum << "\n" << min;
    else
        cout << "-1";
}

void boj2587()
{
    int sum = 0;
    int arr[5];
    int tmp;

    for(int i=0; i<5; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
        sum += tmp; 
    }

    sort(arr, arr+5);

    cout << sum / 5 << '\n' << arr[2] << '\n';
    
}

int boj2309() // 9P7 오름차순으로 결과내기
{
    int n = 0;
    int tmp[9] = {1, 1, 1, 1, 1, 1, 1, 0, 0};
    int sum = 0;

    vector <int> v(9);
    
    for (n=0; n<9; n++)
        cin >> v[n];

    sort(v.begin(), v.end());

    do {
        for (int i=0; i<v.size(); i++)
        {
            if(tmp[i] == 1)
            {
                sum += v[i];
                if(sum == 100)
                {
                    cout << '\n';
                    for(int j = 0; j < 7; j++)
                        cout << v[j] << '\n';
                    return 0;
                }
            }
        }
        sum = 0;
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}

void boj10093()
{
    unsigned long long a, b;
    unsigned long long tmp;

    cin >> a >> b;

    if(a > b) //swap(a,b)로 대체가능
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    if(a==b)
    {
        cout << '0';
    }
    else
    {
        cout << b - a - 1 <<'\n';
        for(unsigned long long i=a+1; i<b; i++)
        {
            cout << i << " ";
        }    
    }
}

void boj1267()
{
    int N, tmp;
    int sumY = 0;
    int sumM = 0;
    // vector <int> v(20);

    cin >> N;

    //Y: 30초마다 10원씩 청구, 60초마다 20원
    //M: 60초마다 15원씩 청구 
    
    //barking dog sol: 
    //Y += ((phone[n] / 30) + 1) * 10;
    //M += ((phone[n] / 60) + 1) * 15;
    for(int i=0; i<N; i++) // 60 65
    {
        cin >> tmp; // 둘다 계산 다해야함
        if(tmp%29)
            sumY += (tmp/30) * 10 + 10;
        else
            sumY += (tmp/30) * 10;
        
        if(tmp%59)
            sumM += (tmp/60) * 15 + 15;
        else
            sumM += (tmp/60) * 15;
    }

    if(sumY > sumM)
        cout << "M " << sumM;
    else if(sumY < sumM)
        cout << "Y "<< sumY;
    else
        cout << "Y M "<< sumY;

}

void boj10804()
{
    vector <int> v(20);
    int i, a, b;

    // reverse(v.begin()+1, v.begin()+5);  //이상 미만

    for(i=0; i<20; i++) v[i] = i+1;

    for(i=0; i<10; i++)
    {
        cin >> a >> b;
        reverse(v.begin()+a-1, v.begin()+b);
    }

    for(auto j:v)
        cout << j << ' ';
}

void boj15552()
{
    int i, N;
    int a, b;

    cin >> N;

    for(i=0; i<N; i++)
    {
        cin >> a >> b;
        cout << a + b <<'\n';
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
    // boj2490();
    // boj2576();
    // boj2587();
    // boj2309();
    // boj10093();
    // boj1267();
    // boj10804();
    boj15552();

    return 0;
}

