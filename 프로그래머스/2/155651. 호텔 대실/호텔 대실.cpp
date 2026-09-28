#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<string>> book_time) {
    int answer = 1;
    
    vector<vector<int>> v(book_time.size(), vector<int>(2, 0));
    
    for(int i=0; i<book_time.size(); i++) {
        for(int j=0; j<2; j++) {
            int h = stoi(book_time[i][j].substr(0,2));
            int m = stoi(book_time[i][j].substr(3,2));
            
            v[i][j] = h*60 + m;
        }
    }
    
    sort(v.begin(), v.end());
    
    vector<int> room;
    room.push_back(v[0][1]);
    int min = v[0][1]; // 가장 빨리 끝나는 시간
    
    for(int i=1; i<v.size(); i++) {
        
        if(v[i][0] >= min+10) {
            sort(room.begin(), room.end());
            room[0] = v[i][1];
            min = *min_element(room.begin(), room.end());
        }
        else {
            answer ++;
            room.push_back(v[i][1]);
            if(v[i][1] < min) min = v[i][1];
        }
        
    }
    
    return answer;
}