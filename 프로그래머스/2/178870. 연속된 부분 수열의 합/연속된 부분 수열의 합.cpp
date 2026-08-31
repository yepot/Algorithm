#include <string>
#include <vector>

using namespace std;

// 투 포인터
vector<int> solution(vector<int> sequence, int k) {
    
    vector<int> answer = {0, (int)sequence.size() - 1};
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int length = sequence.size();
    
    for(right=0; right<sequence.size(); right++) {
        sum += sequence[right];
        
        while(sum > k) {
            sum -= sequence[left];
            left++;
        }

        if(sum == k) {
            if(right-left < length) {
                length = right-left;
                answer = {left, right};
            }
        }
    }
    return answer;
}