#include<bits/stdc++.h>
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};
*/
//T.C & S.C -> O(v+e) & O(v)
    graphNode* dfs(graphNode* curr, unordered_map<graphNode*, graphNode*>& mp)
    {
        vector<graphNode*> adj;
        graphNode* clone = new graphNode(curr -> data);
        mp[curr] = clone;

        for(auto it : curr -> neighbours)
        {
            if(mp.find(it) != mp.end())
            {
                adj.push_back(mp[it]);
            }
            else
                adj.push_back(dfs(it, mp));
        }
        clone -> neighbours = adj;
        return clone;
    }
    graphNode* cloneGraph(graphNode* node) {

        unordered_map<graphNode*, graphNode*> mp;

        if(node == NULL)
            return NULL;

        if(node -> neighbours.size() == 0)
        {
            graphNode* clone = new graphNode(node -> data);
            return clone;
        }

        return dfs(node, mp);
    }
