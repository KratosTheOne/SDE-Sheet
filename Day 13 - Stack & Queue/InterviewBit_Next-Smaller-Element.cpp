vector<int> Solution::prevSmaller(vector<int> &arr) {

    int n = arr.size();

    vector<int> nse(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top() >= arr[i])
            s.pop();

        if(i < n)
            if(!s.empty())
                nse[i] = s.top();

        s.push(arr[i]);
    }

    return nse;
}

