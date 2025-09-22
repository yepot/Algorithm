#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
	cin >> n >> m;
	deque<int> DQ;
	for(int i=1; i<=n; i++) DQ.push_back(i);

	int k;
	int cnt = 0;
	for(int i=0; i<m; i++) {
		cin >> k;
		int idx = find(DQ.begin(), DQ.end(), k) - DQ.begin();
		while(DQ.front()!=k) { //맨앞을 k로 고정시킨다고 생각. 수들을 움직이면서 k를 찾는다고 생각!
			if(idx < DQ.size()-idx) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
			else {
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
			cnt++;
		}
		DQ.pop_front();
	}
	cout << cnt << '\n';
}