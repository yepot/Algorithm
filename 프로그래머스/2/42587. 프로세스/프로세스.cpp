#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max = *max_element(priorities.begin(), priorities.end());

    while(!priorities.empty()) {
        if(location==0) {
            if(priorities.front()==max) return answer+1;
            else {
                int tmp = priorities.front();
                priorities.erase(priorities.begin());
                priorities.push_back(tmp);
                location = priorities.size()-1;
            }
        }
        else {
            if(priorities.front()==max) {
                priorities.erase(priorities.begin());
                answer++;
                location--;
                max = *max_element(priorities.begin(), priorities.end());
            }
            else {
                int tmp = priorities.front();
                priorities.erase(priorities.begin());
                priorities.push_back(tmp);
                location--;
            }
        }
    }
    
}