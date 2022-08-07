//T.C & S.C -> O(32 * n * log(m)) & O(1)

int countNumbersLessThanMid(vector<int> row, int mid)
{
  int l = 0, h = row.size() - 1;

  while(l <= h)
  {
    int md = (l + h) >> 1;
    if(row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }

  return l;
}

int Solution::findMedian(vector<vector<int> > &A) {

  int lo = 0, hi = 1e9, n = A.size(), m = A[0].size();

  while(lo <= hi)
  {
    int mid = (lo + hi) >> 1;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
      count += countNumbersLessThanMid(A[i], mid);
    }

    if(count <= (n * m) / 2)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  return lo;
}

