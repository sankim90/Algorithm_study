
#include <bits/stdc++.h>
using namespace std;

//for(int i = len; i > idx; i--) // 뒤에서부터 옮기면 아래처럼 안해도 됌..
//  arr[i] = arr[i-1];
//arr[idx] = num;
//len++;

void insert(int idx, int num, int arr[], int& len){

    int tmp;
    if(idx >= 10 || idx < 0)
    {
        cout << "Index Out of range \n";
        return;
    }
    else if(idx < len)
    {
        for(int i=idx; i<=len; i++)
        {
            tmp = arr[i];
            arr[i] = num;
            num = tmp;
        }
    }
    else
        arr[idx] = num;
    
    len++;
}

void erase(int idx, int arr[], int& len){

    int tmp;
    if((idx >= 10 || idx < 0) || (idx >= len))
    {
        cout << "Index Out of range \n";
        return;
    }
    
    if(arr[idx + 1] != NULL)
    {
      for(int i=idx; i<len; i++)
      {
        arr[i] = arr[i+1];
        arr[i+1] = NULL;
      }

    }
    else
    {
      arr[idx] = NULL;
    }
    len--;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  // int arr[10] = {10, 50, 40, 30, 70, 20};
  // int len = 6;
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

void boj10808()
{
  vector <int> v(26);
  string s;
  cin >> s;

  for(auto c : s)
    v[c-'a']++; // a의 아스키 코드 97 이므로, 현재 알파벳 - 'a'값은 곧 index가 된다.
  for(auto i : v)
    cout << i << ' ';
  
  // 26개 벡터 만들고
  // c == 'a' idx_0 ++ 이런식으로 출력
}
int func2(int arr[], int n)
{
  vector <int> v(101);
  
  for(int i=0; i<n; i++)
  {
    if(v[100-arr[i]])
      return 1;
    
    v[arr[i]] = 1;
  }
  return 0;
}

void boj2577()
{
  vector <int> v(10);

  int a, b, c;
  int rst = 0;
  string s;
  cin >> a >> b >> c;

  rst = a * b * c; 
  
  s = to_string(rst);
  //stoi도 있음

/* 바킹독 솔루션
  int t=A*B*C;
  int d[10] = {};
// 계산 결과를 자릿수별로 확인하여 저장
  while (t>0) {
    d[t%10]++;
    t/=10;
  }
*/

  for(auto i : s)
  {
    v[i - '0']++;
  }

  for(auto i : v)
    cout << i <<'\n';

}

void boj1475()
{
  vector <int> v(10);
  int n;
  int cnt = 0;
  int rcnt = 0;
  int rst;
  string str;

  cin >> n;
  str = to_string(n);

  for(auto i : str) // 666 7777
    v[i - '0']++;
  
  for(int i=0; i<10; i++) // 123669966 -> cnt 3, rcnt = 6
  {
    if(i == 6 || i == 9) 
    {
      rcnt += v[i]; // 669966 -> 6
      continue;
    }
    else if(cnt < v[i])
      cnt = v[i];
  }
  
  rst = max(cnt, (rcnt + 1) / 2);
  cout <<rst;  
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // boj2577();
  boj1475();
  // insert_test();
  // erase_test();

  // boj10808();
  // int arr[3] = {1, 77, 23};
  // cout << "Answer " << func2(arr, 3);
}