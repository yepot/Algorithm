#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 0에서 시작해서 길이가 1,2,3, ... 인 것 넣기
// 1에서 시작해서 ..똑같이
int solution(vector<int> elements) {
    
    unordered_set<int> s;
    int size = elements.size();
    
    for(int start = 0; start<size; start++) {
        int sum = 0;
        for(int length=0; length<size; length++) {
            int idx = (start+length)%size;
            sum += elements[idx];
            s.insert(sum);
        }
    }
    
    return s.size();
}