1060.Are They Equal (25)...to be continued...

pat-al-1060

2017-03-01

- 不能眼高手低……
- string的使用
- 大坑：对于多个前置位是0的处理：s.erase()
- 对于数据本身是0的特殊处理，要将指数e置为0
- 先一边求e，一边处理数据（对于前置位是0的处理）；然后利用string把经过初始处理的数据转变成最终需要的数据

```c++
/**
 * pat-al-1060
 * 2017-03-01
 * Cpp version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
string deal(string s, int& e)
{
  int k = 0;
  while(s.length() > 0 && s[0] == '0')
    s.erase(s.begin());
  if(s[0] == '.')
  {
    s.erase(s.begin());
    while(s.length() > 0 && s[0] == '0')
    {
      s.erase(s.begin());
      e--;
    }
  }
  else
  {
    while(k < s.length() && s[k] != '.')
    {
      k++;
      e++;
    }
    if(k < s.length())
      s.erase(s.begin()+k);
  }
  if(s.length() == 0)
    e = 0;
  string res;
  int num = 0;
  k = 0;
  while(num < n)
  {
    if(k < s.length())
      res += s[k++];
    else
      res += '0';
    num++;
  }
  return res;
}
int main()
{
  freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  string s1, s2;
  cin >> s1 >> s2;
  int e1 = 0, e2 = 0;
  string s3 = deal(s1, e1);
  string s4 = deal(s2, e2);
  if(s3 == s4 && e1 == e2)
  {
    printf("YES 0.");
    cout << s3;
    printf("*10^%d\n", e1);
  }
  else
  {
    printf("NO 0.");
    cout << s3;
    printf("*10^%d 0.", e1);
    cout << s4;
    printf("*10^%d\n", e2);
  }
}
```
-TBC-
