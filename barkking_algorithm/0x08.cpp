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

void boj2504() // 내가 푼것
{
    stack <char> stk;
    string str;
    int rst = 0;
    int tmp = 1;

    cin >> str;
    if(str[str.length() - 1] == '(' || str[str.length() - 1] == '[')
    {
        cout << rst << '\n';
        return;
    }
    for(int i=0; i<str.length(); i++) //  (()[[]])
    {
        if(str[i] == '(')
        {
            tmp *= 2;
            stk.push(str[i]);
        }
        else if(str[i] == '[') // 다 더하고 stk 마지막 값을 분배해서 곱하기
        {
            tmp *= 3;
            stk.push(str[i]);
        }
        else if(str[i] == ')')
        {
            if(!stk.empty() && stk.top() == '(')
            {
                rst += tmp;
                tmp = tmp / 2;
            }
            else if(stk.empty())
                tmp = 1;
            else
            {
                rst = 0;
                break;
            }
            while(!stk.empty())
                stk.pop();
        }
        else if(str[i] == ']') //((()[])[])  2((2(2 + 3)+3)
        {
            if(!stk.empty() && stk.top() == '[')
            {
                rst += tmp;
                tmp = tmp / 3;
            }
            else if(stk.empty())
                tmp = 1;
            else
            {
                rst = 0;
                break;
            }
            while(!stk.empty())
                stk.pop();
        }
        // else
        //     tmp = 1;
        

    }
    
    cout << rst << '\n';
}
/* 과거의 나 이거 어케품?
#include <string>
#include <stack>
#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack <char> stack;
	string S;

	int result = 0;
	int mul = 1;

	cin >> S;

	for (unsigned int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			mul = mul * 2;
			stack.push(S[i]);

			if (S[i + 1] == ')') { // 열린괄호일때 이미 값계산은 끝남
				result = mul + result;
			}
		}
		else if (S[i] == '[') {
			mul = mul * 3;
			stack.push(S[i]);

			if (S[i + 1] == ']') {
				result = mul + result;
			}
		}
	
		else if (S[i] == ')') {							// 닫힌괄호일때 다음계산을 위한 준비를 하는 과정, 예외처리 해주고
			if (stack.empty()) {
				stack.push('x');
				break;
			}
			
			else if (stack.top() == '(') {
				stack.pop();
			}
			mul = mul / 2;
		}
			
		else if (S[i] == ']') {
			if (stack.empty()) {
				stack.push('x');
				break;
			}

			else if (stack.top() == '[') {
				stack.pop();
			}
			mul = mul / 3;
		}
	}
	if (stack.empty())
		cout << result;

	else
		cout << '0';

}
*/
/* 솔루션, 에러케이스만 몇개만 더 보면 됐는데 ㄲㅂ..
#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  int sum = 0; // 누적해서 더해질 값
  int num = 1; // 곱해질 값

  for(int i = 0; i < str.size(); i++){
    if(str[i] == '('){
      num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
      s.push(str[i]);
    }
    else if(str[i] == '['){
      num *= 3; // 대괄호가 나오면 곱해질 값 3배 증가
      s.push(str[i]);
    }
    else if(str[i] == ')'){
      if(s.empty() || s.top() != '('){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '(') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
      s.pop();
      num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔      
    }
    else{ // str[i] == ']'
      if(s.empty() || s.top() != '['){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '[') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
      s.pop();
      num /= 3; // 대괄호 쌍이 사라졌으니 3로 나눔
    }
  }
  if(s.empty()) cout << sum;
  else cout << 0;
}
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // boj4949();
    // boj10799();
    boj2504();

}