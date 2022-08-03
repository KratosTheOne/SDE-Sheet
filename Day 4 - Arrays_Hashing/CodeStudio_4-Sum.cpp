#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int target2=target-arr[i];
        for(int j=i+1;j<n;j++)
        {
            int target3=target2-arr[j];
            int front=j+1;
            int back=n-1;
            while(front<back)
            {
                int check=arr[front]+arr[back];
                if(target3>check) front++;
                else if(target3<check) back--;
                else return "Yes";
           }
       }
   }
   return "No";
}

