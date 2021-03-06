/**
 * pat-bl-1050
 * 2017-01-22
 * C version
 * Author: fengLian_s
 */
#include<stdio.h>
#include<math.h>
int tmpArr[100002];
void Merge(int num[], int low, int mid, int high)
{
  int i, j, k;
  for(i = low;i <= high;i++)
    tmpArr[i] = num[i];
  i = low, j = mid+1, k = low;
  while(i <= mid && j <= high)
  {
    if(tmpArr[i] >= tmpArr[j])
      num[k++] = tmpArr[i++];
    else
      num[k++] = tmpArr[j++];
  }
  while(i <= mid)
    num[k++] = tmpArr[i++];
  while(j <= high)
    num[k++] = tmpArr[j++];
}
void MergeSort(int num[], int low, int high)
{
  if(low < high)
  {
    int mid = (low + high) / 2;
    MergeSort(num, low, mid);
    MergeSort(num, mid+1, high);
    Merge(num, low, mid, high);
  }
}
int main()
{
  //先排序以及求出m和n，然后再往里填
  freopen("in.txt", "r", stdin);
  int N, m, n;
  scanf("%d", &N);
  int num[N];
  for(int i = sqrt(N);i > 0;i--)//求出m和n
  {
    if(N % i == 0)
    {
      n = i;
      m = N / n;
      break;
    }
  }
  int resultArr[m][n];//创建数组
  //printf("m = %d, n = %d\n", m , n);
  for(int i = 0;i < N;i++)
  {
    scanf("%d", &num[i]);
  }
  MergeSort(num, 0, N-1);
  // for(int i = 0;i < N;i++)
  //   printf("%d ", num[i]);
  // putchar('\n');
  if(n == 1)//坑：一列的情况
  {
    for(int i = 0;i < N;i++)
      printf("%d\n", num[i]);
  }
  else
  {
    int mMin = 0, mMax = m, nMin = 0, nMax = n;
    int i = 0, j = 0, k = 0;
    while(i < mMax && i >= mMin && j < nMax && j >= nMin)//按顺时针依次填空
    {
      while(j < nMax)//从左向右
      {
        resultArr[i][j++] = num[k++];
        //printf("resultArr[%d][%d] = %d\n", i, j-1, resultArr[i][j-1]);
      }
      if(k == N)//坑：比如数据是6*3的，不加这个判断就会有问题，所以要每次循环后加一个判断，及时跳出避免覆盖了正确的数
        break;
      j--;i++;mMin++;
      while(i < mMax)//从上到下
      {
        //printf("num[%d] = %d\n", k, num[k]);
        resultArr[i++][j] = num[k++];
        //printf("resultArr[%d][%d] = %d\n", i-1, j, resultArr[i-1][j]);
      }
      if(k == N)
        break;
      i--;j--;nMax--;
      while(j >= nMin)//从右向左
      {
        resultArr[i][j--] = num[k++];
        //printf("resultArr[%d][%d] = %d\n", i, j+1, resultArr[i][j+1]);
      }
      if(k == N)
        break;
      j++;i--;mMax--;
      while(i >= mMin)//从下到上
      {
        resultArr[i--][j] = num[k++];
        //printf("resultArr[%d][%d] = %d\n", i+1, j, resultArr[i+1][j]);
      }
      if(k == N)
        break;
      i++;j++;nMin++;
    }
    //output:
    for(int i = 0;i < m;i++)
    {
      printf("%d", resultArr[i][0]);
      for(int j = 1;j < n;j++)
      {
        printf(" %d", resultArr[i][j]);
      }
      putchar('\n');
    }
  }
}
