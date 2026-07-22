#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int maxX = 0;
    int maxY = 0;
    
    for(auto &i : sizes) { // &붙여서 원본참조해!!
        if(i[0] < i[1]) {
            swap(i[0], i[1]);
        }
    }
    
    for(auto i : sizes) {
        maxX = max(maxX, i[0]);
        maxY = max(maxY, i[1]);
    }
    
    return maxX*maxY;
}