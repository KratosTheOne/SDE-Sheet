#include<bits/stdc++.h>

int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};

void  dfs(int **arr ,int n , int m , int i , int j){
    if(i< 0|| j<0 || i>=n || j>=m){
        return ;
    }
    if(arr[i][j] !=1 ) return ;
    arr[i][j] = 0;
    for(int k = 0 ;k<8;k++){
        int x  = dx[k] + i;
        int y = dy[k] +j;
        dfs(arr , n ,  m ,x,y);
    }
}


int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int cnt = 0;
    for(int i = 0 ; i<n;i++){
        for(int j = 0 ; j<m ;j++){
            if(arr[i][j] == 1 ){
                dfs(arr,n,m,i,j);
                cnt++;
            }
        }

    }
    return cnt;
}
