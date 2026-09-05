#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lc[10001] = {0, };
int rc[10001] = {0, };
vector<vector<int>> answer(2);
vector<vector<int>> node;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] > b[1];
}

// 트리 만들기
void insertNode(int parent, int child) {
    // 현재 x좌표가 부모보다 작으면 왼쪽
    if(node[child-1][0] < node[parent-1][0]) {
        if(lc[parent] == 0) {
            lc[parent] = child;
        }
        else {
            insertNode(lc[parent], child);
        }
    }
    
    // 현재 x좌표가 부모보다 크면 오른쪽
    else{
        if(rc[parent] == 0) {
            rc[parent] = child;
        } 
        else {
            insertNode(rc[parent], child);
        }
    }
}

void preorder(int cur) {
    answer[0].push_back(cur);
	if(lc[cur] != 0) preorder(lc[cur]);
	if(rc[cur] != 0) preorder(rc[cur]);
}

void postorder(int cur) {
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    answer[1].push_back(cur);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    node = nodeinfo;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i+1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    // 루트를 제외한 모든 노드를 삽입
    int root = nodeinfo[0][2];
    for (int i=1; i<nodeinfo.size(); i++) {
        int child = nodeinfo[i][2];
        insertNode(root, child);
    }
    
    preorder(root);
    postorder(root);
    
    return answer;
}