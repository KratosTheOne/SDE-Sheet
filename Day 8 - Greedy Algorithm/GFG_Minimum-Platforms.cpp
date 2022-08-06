class Solution{
    //T.C && S.C -> O(nlog) & O(1)

    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);

    	int plat = 1, res = 1;
    	int i = 1, j = 0;

    	while(i < n && j < n)
    	{
    	    if(arr[i] <= dep[j])
    	    {
    	        plat++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j])
    	    {
    	        plat--;
    	        j++;
    	    }
    	    if(plat > res)
    	        res = plat;
    	}

    	return res;
    }
};
