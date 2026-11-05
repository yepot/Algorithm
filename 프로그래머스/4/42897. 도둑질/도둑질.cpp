#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// D[i] : i번째 집까지 돈 최댓값
// D[i] = max(D[i-1], D[i-2] + money)
// 원이라서 배열 맨앞뒤 떄문에 첫번째 출발 두번째 출발 나누어서 생각해!!!!!
int solution(vector<int> money) {
    int answer = 0;
    
    int D[1000005];
    int size = money.size();
    
    // 첫번째 집에서 출발
    D[0] = money[0];
    D[1] = max(money[0], money[1]); // money[1] 아니야~!!
    for(int i=2; i<money.size()-1; i++) {
        D[i] = max(D[i-1], D[i-2] + money[i]);
    }
    
    answer = D[size-2];
    
    // 두번째 집에서 출발
    D[0] = 0; // 첫번째 집은 제외해야돼
    D[1] = money[1];
    for(int i=2; i<money.size(); i++) {
        D[i] = max(D[i-1], D[i-2] + money[i]);
    }
    
    answer = max(answer, D[size-1]);
    
    return answer;
}