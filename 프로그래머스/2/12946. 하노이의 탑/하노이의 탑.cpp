#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

// 재귀 문제임!!
// [(n-1)개 1->2] + [1->3] + [(n-1)개 2->3]
// from -> to, tmp: 경유지
void func(int from, int to, int tmp, int k) {
    if(k == 1) {
        answer.push_back({from, to});
        return;
    }
    
    func(from, tmp, to, k-1);
    answer.push_back({from,to});
    func(tmp, to, from, k-1);
    
}
vector<vector<int>> solution(int n) {

    func(1, 3, 2, n);
    return answer;
}