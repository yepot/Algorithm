#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idxA = 0;
    int idxB = 0;
    
    // 가장 적은 차이로 이기기
    // 진 애는 버리는 카드로 생각
    for(idxB=0; idxB<B.size(); idxB++) {
        if(B[idxB] > A[idxA]) {
            idxA ++;
            answer ++;
        }
    }
    
    return answer;
}