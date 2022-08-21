//T.C && S.C -> O(n) & O(n)

class Solution
{
    private:
    //Function to check if a knows b or vice versa.
    bool knows(vector<vector<int> >& M, int a, int b, int n)
    {
        if(M[a][b] == 1)
            return true;

        return false;
    }

    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        stack<int> st;

        //Step 1 push all elements

        for(int i = 0; i < n; i++)
            st.push(i);

        //Step 2 remove 2 elements till 1 remains and compare

        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if(knows(M, a, b, n))
                st.push(b);

            else
                st.push(a);
        }

        int ans = st.top();

        //Step 3 remaining 1 element can be potential candidate so verify

        int zeroCount = 0;

        for(int i = 0; i < n; i++)
        {
            if(M[ans][i] == 0)
                zeroCount++;
        }

        if(zeroCount != n)
            return -1;

        int oneCount = 0;

        for(int i = 0; i < n; i++)
        {
            if(M[i][ans] == 1)
                oneCount++;
        }

        if(oneCount != n - 1)
            return -1;

        return ans;
    }
};
