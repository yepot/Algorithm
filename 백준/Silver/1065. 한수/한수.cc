#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    int cnt = 0;

    for (int i=1; i<=n; i++) {
        if (i < 100) cnt++;
		else { 
            int a = i/100;       
            int b = (i/10)%10; 
            int c = i%10;        
            if (a+c==b*2) cnt++;
        }
    }
    cout << cnt << '\n';
}
