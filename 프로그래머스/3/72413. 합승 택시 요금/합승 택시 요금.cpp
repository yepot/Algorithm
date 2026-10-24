#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// s 출발, a b 도착
// 합승이 끝나는 지점 찾기
// 플로이드 워셜 알고리즘..
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    int dist[205][205] = {0, };
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = 100000000;
            if(i == j) dist[i][j] = 0;
        }
    }
    
    for(int i=0; i<fares.size(); i++) {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    // from -> mid -> to
    for(int mid=1; mid<=n; mid++) {
        for(int from=1; from<=n; from++) {
            for(int to=1; to<=n; to++) {
                dist[from][to] = min(dist[from][mid]+dist[mid][to], dist[from][to]);
            }
        }
    }
    answer = dist[s][a] + dist[s][b];
    for(int mid=1; mid<=n; mid++) {
        int total = dist[s][mid] + dist[mid][a] + dist[mid][b];
        answer = min(answer, total);
    }
    
    return answer;
}