#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool isValid(int i, int j, vector<string>& map, vector<vector<bool>>& vis){
    int n=map.size();
    int m=map[0].size();
    if(i<0 || i>=n || j<0 || j>=m || map[i][j] == '#' || vis[i][j]){
        return false;
    }
    return true;
}

void DFS(vector<string>& map, vector<vector<bool>>& vis, int i, int j){
    vis[i][j] = true;
    for(auto& dir:directions){
        int new_i = i+dir.first;
        int new_j = j+dir.second;
        if(isValid(new_i, new_j, map, vis)){
            DFS(map, vis, new_i, new_j);
        }
    }
}

void countingRooms(vector<string>& map){
    int n=map.size();
    int m=map[0].size();
    int cnt=0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && map[i][j] == '.'){
                DFS(map, vis, i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> map(n);
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        map[i]=s;
    }
    countingRooms(map);
}