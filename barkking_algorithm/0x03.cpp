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

void boj3273()
{
  vector <int> v(2000001);
  vector <int> index_(100001);
  int N;
  int cnt = 0;
  int X = 0;
  int tmp = 0;
  int i;
  cin >> N;

  // for(i=0; i<N; i++) //바킹독 솔루션
  // {
  //   cin >> v[i];
  // }

  // cin >> X;

  // for(i=0; i<N; i++)
  // {
  //   if(X-v[i] > 0 && index_[X-v[i]]) // index가 -값이면 안되니까 X-v[i] > 0 검사
  //     cnt++;
  //   else
  //     index_[v[i]] = true;
  // }


  // 내 코드
  for(i=0; i<N; i++)
  {
    cin >> tmp;
    index_[i] = tmp;
    v[tmp] = tmp;
  }

  cin >> X;

  for(i=0; i<N; i++)
  {
    if(X-index_[i] > 0 && (v[X-index_[i]] + v[index_[i]]) == X) 
      cnt++;
  }

  cout <<cnt/2;

}
/*바킹독 솔루션
 // -100 <= v && v <= 100 이므로 음수도 저장할 수 있는 공간을 배열에 추가
  int N, v, a[201] = {};
  cin >> N;

  // 입력값을 배열에 저장
  while(N--){
    int t;
    cin >> t;
    // 음수도 인덱스로 접근하기 위해 기존 인덱스+100으로 배열에 저장 <- 이생각 했었는데 굳이 싶었음
    a[t+100]++;
  }

  // v의 개수를 배열에서 확인
  cin >> v;
  cout << a[v+100];
*/
void boj10807()
{
  // arr[], V 의 범위는 -100 <= X <= 100
  int N, X;
  int cnt = 0;
  vector <int> v(101);
  cin >> N;

  for(int i=0; i<N; i++)
    cin >> v[i];

  cin >> X;

  for(int j=0; j<N; j++)
  {
    if(v[j] == X)
      cnt++;
  }

  cout << cnt;
}

void boj13300() // N 전교생 숫자 K 방의 최대 수용인원, 0 여자 1 남자 / 학년
{
  int N, K;
  int S, Grad;
  int room1 = 0;
  int room2 = 0;
  vector <int> M_Grad(7);
  vector <int> W_Grad(7);

  cin >> N >> K;

  for(int i=0; i<N; i++)
  {
    cin >> S >> Grad;
    if(S)
      M_Grad[Grad]++;
    else
      W_Grad[Grad]++;
  }
  
  for(int j=1; j<7; j++)
  {
    if(M_Grad[j])
    {
      if(M_Grad[j]%K)
        room1 += (M_Grad[j]/K)+1;
      else
        room1 += (M_Grad[j]/K);
    }
    
    if(W_Grad[j])
    {
      if(W_Grad[j]%K)
        room2 += (W_Grad[j]/K)+1;
      else
        room2 += (W_Grad[j]/K);
    }
  }

  cout << room1 + room2;
}

void boj11328()
{
  int N;
  char tmp1 = 0, tmp2 = 0;
  
  cin >> N;

  string Str1, Str2;

  // while(N--) 내코드 28ms 
  // {
  //   cin >> Str1 >> Str2;
  //   sort(Str1.begin(), Str1.end());
  //   sort(Str2.begin(), Str2.end());

  //   if(Str1 == Str2)
  //     cout << "Possible\n";
  //   else
  //     cout << "Impossible\n";
  // }

  while(N--) // 바킹독 8ms 
  {
    vector <int> V(30);
    cin >> Str1 >> Str2;

    for(auto i : Str1)
      V[i-'a']++; // 배열 하나로 처리 하는게 아이디어
    for(auto i : Str2)
      V[i-'a']--; // 위와 같은 값이면 0으로 초기화, 아에 다른 값이면 -가 될것임

    // 0이 아닌 배열의 요소가 있을 경우, 개수가 다른 문자가 존재하므로 false
    bool isPossible = true;

    for (int i : V){
      if (i != 0) 
      {
        isPossible = false;
        break;
      }
    }
    if(isPossible) cout << "Possible\n";
    else cout << "Impossible\n";
  }

}

void boj1919()
{
  vector <int> v(26);
  string str1, str2;
  int rst = 0;
  cin >> str1 >> str2;

  for(auto i : str1) //중복된 문자수
    v[i-'a']++;
  for(auto i : str2) // a bb ccc dddd eeeee (15) / e dd ccc bbbb aaaaa (15) a = 4, b = 2, c = 0, d = 2, e = 4  --> 12
    v[i-'a']--;
  
  for(auto i : v)
    rst += abs(i);
  
  cout << rst;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // boj2577();
  // boj1475();
  // boj3273();
  // boj10807();
  // boj13300();
  // boj11328();
  boj1919();

  // insert_test();
  // erase_test();

  // boj10808();
  // int arr[3] = {1, 77, 23};
  // cout << "Answer " << func2(arr, 3);
}