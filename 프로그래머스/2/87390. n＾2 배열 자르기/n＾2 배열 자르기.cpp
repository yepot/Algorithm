#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1 2 3 4
// 2 2 3 4
// 3 3 3 4
// 4 4 4 4
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
        
    for(long long i=left; i<=right; i++) {
        int a = i/n;
        int b = i%n;
        answer.push_back(max(a,b)+1);
    }
    
    
    return answer;
}