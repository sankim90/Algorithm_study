#include <bits/stdc++.h>
using namespace std;


void boj4949()
{
    string str;
    // getline(cin, str, '('); 구분자 쓸 수 있음, cin.ignore()로 이전 입력에 대한 개행문자 무시도 가능하니 참고

    while(1)
    {
        stack <char> stk;
        getline(cin, str);
        
        if(str[0] == '.')
            break;

        for(auto i:str) //(])
        {
            if(i == '(' || i == '[')
                stk.push(i);
            else
            {
                if(i == ')')
                {
                    if(!stk.empty() && stk.top() == '(')
                        stk.pop();
                    else
                    {
                        stk.push(i);
                        break;
                    }
                }
                else if(i == ']')
                {
                    if(!stk.empty() && stk.top() == '[')
                        stk.pop();
                    else
                    {
                        stk.push(i);
                        break;
                    }
                }
            }
        }
        
        if(stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
        
    }
}

void boj10799() // 내 풀이, 아래와 같에 몽땅 stack에 안넣고 string 값을 인덱싱하여 이전값을 확인 할 수 있다. -str[i-1] <-온라인 솔루션들은 대부분 이렇게 푼듯.
{
    stack <char> stk;
    string str;
    int rst = 0;

    cin >> str;

    for(auto i:str)
    {
        if(!stk.empty() && i == ')')
        {
            if(stk.top() == ')')
            {
                stk.pop();
                stk.pop();
                rst += 1;
            }
            else
            {
                stk.pop();
                rst += stk.size();
            }
        }
        else if(!stk.empty() && i == '(')
        {
            if(stk.top() == ')')
                stk.pop();
        }

        stk.push(i);
    }

    cout << rst << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj4949();
    boj10799();

}