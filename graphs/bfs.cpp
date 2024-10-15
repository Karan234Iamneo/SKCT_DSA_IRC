#include <bits/stdc++.h>
#include<queue>
void bfs(vector <int> bfs(vector<int> g[], int N)) {

queue<int> q;
vector<int> ans;
bool *visited = new bool[N+1]{false};
q.push(0);

while(!q.empty()){
ans.push_back(q.front());
int temp = q.front();
q.pop();

for(auto node : g[temp]){
if(!visited[node]){
q.push(node);
visited[node] = true;
}
}
}
return ans;

}
