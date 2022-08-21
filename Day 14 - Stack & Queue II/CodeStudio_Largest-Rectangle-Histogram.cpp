#include<bits/stdc++.h>

int largestRectangle(vector < int > & heights) {
     stack<int> st;
     int n = heights.size();
     int maxA = 0;
     for(int i = 0; i <= n; i++)
     {
         while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
         {
             int height = heights[st.top()];
             st.pop();
             int width;

             if(st.empty()) width = i;
             else width = i - st.top() - 1;

             maxA = max(maxA, height * width);
         }

         st.push(i);
     }

     return maxA;
 }
