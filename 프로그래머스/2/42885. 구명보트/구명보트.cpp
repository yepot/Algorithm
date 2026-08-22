#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 무거운 사람 + 가장 가벼운 사람 가능한 지
// 인덱스로 접근!!
int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int r = people.size()-1;
    int l = 0;

    while(l <= r) {
        int cur = people[r];
        if(cur+people[l] <= limit) {
            l ++;
            cur += people[l];
        }
        r--;
        answer++;
    }
    
    return answer;
}