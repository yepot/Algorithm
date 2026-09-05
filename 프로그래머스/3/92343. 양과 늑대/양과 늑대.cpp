#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20];
vector<int> node;
int answer; // 양 최대 몇 마리
vector<int> can;

void dfs(int sheep, int wolf, vector<int> can) {
    if(sheep <= wolf) return;

    answer = max(answer, sheep);

    for(int i=0; i<can.size(); i++) {
        int next = can[i];
        vector<int> nextCan = can;

        // 이번에 방문할 노드는 후보에서 제거
        nextCan.erase(nextCan.begin()+i);

        // 방문한 노드의 자식들을 새로운 후보로 추가
        for(int child : adj[next]) {
            nextCan.push_back(child);
        }

        if(node[next] == 0) dfs(sheep+1, wolf, nextCan);
        else if(node[next] == 1) dfs(sheep, wolf+1, nextCan);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    answer = 0;
    
    for(int i=0; i<edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        if(edges[i][0] == 0) {
            can.push_back(edges[i][1]);
        }
    }
    
    node = info;
    
    dfs(1, 0, can);
    
    return answer;
}