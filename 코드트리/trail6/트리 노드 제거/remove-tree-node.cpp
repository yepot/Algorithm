#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, k, root;
int answer = 0;
vector<int> adj[51];

void dfs() {
    
    if(root == k) return;

    stack<int> s;
    s.push(root);

    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        int child = 0;
        for(auto next : adj[cur]) {
            if(next == k) continue;
            s.push(next);
            child ++;
        }

        if(child == 0) answer ++;
    }
}

int main() {
    // Please write your code here.
    cin >> N;

    for(int i=0; i<N; i++) {
        int parent;
        cin >> parent;

        if(parent == -1) root = i;
        else adj[parent].push_back(i);
    }

    cin >> k;

    dfs();
    cout << answer;

    return 0;
}