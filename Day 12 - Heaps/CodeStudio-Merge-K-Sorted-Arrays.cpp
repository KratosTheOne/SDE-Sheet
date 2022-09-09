#include<bits/stdc++.h>

//T.C & S.C ->O((N * K)log K) & O(K)

class node{
    public:
        int data;
        int i;
        int j;

    node(int data, int row, int col)
    {
        this -> data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b)
        {
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    //Step 1: put the first element of every array in minHeap
    for(int i = 0; i < k; i++)
    {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //Step 2: check if minHeap.size() > 0 & do the algo steps
    while(!minHeap.empty())
    {
        node* temp = minHeap.top();
        ans.push_back(temp -> data);
        minHeap.pop();

        int i = temp -> i;
        int j = temp -> j;

        //Check if we are node exceeding the boundary of the array
        if(j + 1 < kArrays[i].size())
        {
            node* next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

