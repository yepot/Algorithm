#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    // 10 20 : 30 40 -> 30+70 -> 100
    // ㅇㅏ! 두 개 더한 걸 또 다시 큐에 넣자 그러면 큐 사이즈가 1이 될 때까지 반복
    int sum = 0;
    while(pq.size()>1) {
        int tmp = 0;
        for(int i=0; i<2; i++) {
            tmp+=pq.top();
            pq.pop();
        }
        sum+=tmp;
        pq.push(tmp); 
    }

    cout << sum;
}