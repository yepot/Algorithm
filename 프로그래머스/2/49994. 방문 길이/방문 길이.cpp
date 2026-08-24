#include <string>
#include <set>
using namespace std;

// U(-1, 0) D(+1, 0) R(0, +1) L(0, -1)
int solution(string dirs) {
    int answer = 0;
    
    set<pair<pair<int,int>, pair<int,int>>> vis;
    
    int x = 0;
    int y = 0;
    for(int i=0; i<dirs.size(); i++) {
        int tmpX = x;
        int tmpY = y;
        
        if(dirs[i] == 'U') tmpX--;
        else if(dirs[i] == 'D') tmpX++;
        else if(dirs[i] == 'R') tmpY++;
        else if(dirs[i] == 'L') tmpY--;
        
        if(tmpX<-5 || tmpX>5 || tmpY<-5 || tmpY>5) continue;
        if(vis.find({{x, y}, {tmpX, tmpY}}) == vis.end()) {
            vis.insert({{x, y}, {tmpX, tmpY}});
            vis.insert({{tmpX, tmpY}, {x, y}});
            answer++;
        }
        x = tmpX;
        y = tmpY;
    }
    
    return answer;
}