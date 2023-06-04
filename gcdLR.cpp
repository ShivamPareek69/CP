#include <iostream>
using namespace std;
int __gcd(int a, int b)
{
 if (b == 0)
 {
  return a;
 }
 else
 {
  return __gcd(b, a % b);
 }
}

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n, q, l, r;
  cin >> n >> q;
  int a[n];
  int forward[n + 1];
  int backward[n + 1];
  forward[0] = backward[n + 1] = 0;
  for (int i = 1; i <= n; i++)
  {
   cin >> a[i];
  }
  for (int i = 1; i <= n; ++i)
  {
   forward[i] = __gcd(forward[i - 1], a[i]);
  }
  for (int i = n; i >= 1; --i)
  {
   backward[i] = __gcd(backward[i + 1], a[i]);
  }
  while (q--)
  {
   int l, r;
   cin >> l >> r;
   cout << __gcd(forward[l - 1], backward[r + 1]) << endl;
  }
 }
 return 0;
}