#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur = 0;
    int idx = 0;

    queue<int> bridge;

    // 처음 다리는 비어 있음
    for (int i=0; i<bridge_length; i++) {
        bridge.push(0);
    }

    while (idx < truck_weights.size()) {
        answer++;

        // 다리 맨 앞 칸이 빠져나감
        cur -= bridge.front();
        bridge.pop();

        // 다음 트럭을 올릴 수 있으면 올림
        if (cur+truck_weights[idx] <= weight) {
            bridge.push(truck_weights[idx]);
            cur += truck_weights[idx];
            idx++;
        } 
        // 못 올리면 빈 칸 이동
        else {
            bridge.push(0);
        }
    }

    // 마지막 트럭
    answer+=bridge_length;

    return answer;
}