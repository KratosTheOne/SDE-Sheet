//T.C & S.C -> O(n * logn) & O(1)

int isPossible(vector<int> &A, int mid, int students)
{
    int count = 0;
    int allocatedPages = 0;

    for(int i = 0; i < A.size(); i++)
    {
        if(allocatedPages + A[i] > mid)
        {
            count++;
            allocatedPages = A[i];
            if(allocatedPages > mid) return false;
        }
        else
        {
            allocatedPages += A[i];
        }
    }

    if(count < students)
        return true;

    return false;
}

int Solution::books(vector<int> &A, int B) {

    int n = A.size();

    if(B > n) return -1;

    int low = A[0];
    int high = 0;

    for(int i = 0; i < n; i++)
    {
        high += A[i];
        low = min(low, A[i]);
    }

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        if(isPossible(A, mid, B))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return low;
}

