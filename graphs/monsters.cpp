#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// vector<char> dirChar = {'U', 'R', 'D', 'L'};

bool isValid(int i, int j, vector<string>& map, vector<vector<bool>>& vis) {
    int n = map.size();
    int m = map[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || map[i][j] == '#' || vis[i][j]) {
        return false;
    }
    return true;
}


void trackPath(vector<vector<pair<int,int>>>& parent, int r, int c){
    vector<char> path;
    while(parent[r][c] != make_pair(r, c)){
        int prev_r = parent[r][c].first;
        int prev_c = parent[r][c].second;
        if(r+1 == prev_r && c == prev_c)    path.push_back('U');   
        else if(r-1 == prev_r && c == prev_c)    path.push_back('D');   
        else if(r == prev_r && c+1 == prev_c)    path.push_back('L');   
        else if(r == prev_r && c-1 == prev_c)    path.push_back('R');  

        r = prev_r;
        c = prev_c; 
    }
    reverse(path.begin(), path.end());
    for(auto& ch: path){
        cout<<ch;
    }
    cout<<endl;
}


void monsters(vector<string>& map) {
    int n = map.size();
    int m = map[0].size();

    // for monsters (multisource BFS)
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 'M'){
                q.push({i,j});
                dist[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    while(!q.empty()){
        auto pos = q.front();
        int r=pos.first;
        int c=pos.second;
        q.pop();
        for(auto& dir:directions){
            int new_r = r+dir.first;
            int new_c = c+dir.second;
            if(isValid(new_r, new_c, map, vis)){
                q.push({new_r,new_c});
                vis[new_r][new_c] = true;
                dist[new_r][new_c] = dist[r][c]+1;
            }
        }
    }
    
    // for user(me)
    vector<vector<bool>> visA(n, vector<bool>(m, false));
    vector<vector<int>> distA(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 'A'){
                q.push({i,j});
                distA[i][j] = 0;
                visA[i][j] = true;
                parent[i][j] = {i,j};
            }
        }
    }
    while(!q.empty()){
        auto pos = q.front();
        int r=pos.first;
        int c=pos.second;
        q.pop();
        for(auto& dir:directions){
            int new_r = r+dir.first;
            int new_c = c+dir.second;
            if(isValid(new_r, new_c, map, visA)){
                q.push({new_r,new_c});
                parent[new_r][new_c] = {r, c};
                visA[new_r][new_c] = true;
                distA[new_r][new_c] = distA[r][c]+1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(distA[i][0] < dist[i][0]){
            cout<<"YES"<<endl;
            cout<<distA[i][0]<<endl;
            trackPath(parent, i, 0);
            return;
        }
        if(distA[i][m-1] < dist[i][m-1]){
            cout<<"YES"<<endl;
            cout<<distA[i][m-1]<<endl;
            trackPath(parent, i, m-1);
            return;
        }
    }
    for(int j=0; j<m; j++){
        if(distA[0][j] < dist[0][j]){
            cout<<"YES"<<endl;
            cout<<distA[0][j]<<endl;
            trackPath(parent, 0, j);
            return;
        }
        if(distA[n-1][j] < dist[n-1][j]){
            cout<<"YES"<<endl;
            cout<<distA[n-1][j]<<endl;
            trackPath(parent, n-1, j);
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    monsters(map);
    return 0;
}
