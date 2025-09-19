#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
	cin >> k;
	stack<int> S;
	int x;
	for(int i=0; i<k; i++) {
		cin >> x;
		if(x==0) S.pop();
		else S.push(x);
	}
	int sum=0;
	while(!S.empty()) {
		sum+=S.top();
		S.pop();
	}
	cout << sum <<'\n';
}   