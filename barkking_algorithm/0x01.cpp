#include <bits/stdc++.h>

using namespace std;

int func1(int n);
int func2(int arr[], int n);
int func3(int n);
int func4(int n);

int main()
{
    // cout << "Answer " << func1(16);
    // int arr[3] = {1, 77, 2};
    // cout << "Answer " << func2(arr, 3);
    // cout << "Answer " << func3(756580036);
    cout << "Answer " << func4(67108864);
    
}

int func1(int n) // 3 or 5 의 배수 
{
    //16 -> 3, 5, 6, 9, 10, 12, 15
    int sum = 0;
    for (int i=3; i<=n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

int func2(int arr[], int n)
{   
    if (n < 1)
        return 0;
    else if (n == 2)
        return ((arr[0] + arr[1]) == 100) ? 1 : 0;

    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            {
                if((arr[i] + arr[j]) == 100)
                    return 1;
            }

    return 0;
}

int func3(int n)
{
    int num = (int)sqrt(n); // 123
    double diff = sqrt(n);  // 123.456
    int rtn = 0;

    if((diff - num) == 0)
        rtn = 1;

    return rtn;
}
/* bark sol
int func3(int N){
  for(int i = 1; i * i <= N; i++){
    if(i*i == N) return 1;
  }
  return 0;
}
*/

int func4(int n) // 5 => 1, 2, 4 (2^0, 1, 2)
{
    int max = 1;
    // for(int i = 1; i * 2 <= n; i = i * 2)  // San
    //     max  = i * 2;

    while(2 * max <= n) // bark sol
        max *= 2;

    return max;
}