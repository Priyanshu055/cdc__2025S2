#include<bits/stdc++.h>
using namespace std;
int noOfislands(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int island_count=0;
    vector<int> dirX={-1,0,1,0,-1,-1,1,1};
    vector<int> dirY={0,1,0,-1,-1,1,-1,1};
    function<void(int,int)> dfs=[&](int x,int y){
        visited[x][y]=true;
        for(int d=0;d<8;d++){
            int newX=x+dirX[d];
            int newY=y+dirY[d];
            if(newX>=0 && newX<n && newY>=0 && newY<m && 
               grid[newX][newY]=='1' && !visited[newX][newY]){
                dfs(newX,newY);
            }
        }
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                island_count++;
                dfs(i,j);
            }
        }
    }
    cout<<island_count<<endl;
    return island_count;
}
int main(){
    noOfislands();
    return 0;
}