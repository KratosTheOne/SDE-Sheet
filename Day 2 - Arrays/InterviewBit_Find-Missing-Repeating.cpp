//Both the solutions are O(n) & O(1) space;
//Sol-1 will give overflow for constraint > 1e5;
//Sol-2 will not give overflow

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;

    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }

    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;

    /*
    // Will hold xor of all elements and numbers from 1 to n
    int xor1;

    // Will have only single set bit of xor1
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = A.size();

    xor1 = A[0];

    // Get the xor of all array elements
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ A[i];

    // XOR the previous result with numbers from 1 to n
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    // Get the rightmost set bit in set_bit_no
    set_bit_no = xor1 & ~(xor1 - 1);

    // Now divide elements into two sets by comparing a rightmost set bit
    // of xor1 with the bit at the same position in each element.
    // Also, get XORs of two sets. The two XORs are the output elements.
    // The following two for loops serve the purpose

    for (i = 0; i < n; i++) {
        if (A[i] & set_bit_no)
            // arr[i] belongs to first set
            x = x ^ A[i];

        else
            // arr[i] belongs to second set
            y = y ^ A[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            // i belongs to first set
            x = x ^ i;

        else
            // i belongs to second set
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (A[i]==x)
            x_count++;
    }

    if (x_count==0)
        return {y, x};

    return {x, y};
    */
}
