#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> S;
    for(int i=0; i<nums.size(); i++) S.insert(nums[i]);
    if(S.size() >= nums.size()/2) answer = nums.size()/2;
    else answer = S.size();
    return answer;
}