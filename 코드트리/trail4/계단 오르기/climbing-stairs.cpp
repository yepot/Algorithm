#include <iostream>
using namespace std;

// D[i] : i번째칸 까지 올라갔을 때 경우의 수
// D[i] = D[i-2] + D[i-3];
// D[2] = 1, D[3] = 1, D[4] = 1
int main() {
    
    int n;
    cin >> n;

    int D[1001];
    D[2] = 1;
    D[3] = 1;
    D[4] = 1;

    for(int i=5; i<=1000; i++) {
        D[i] = (D[i-2] + D[i-3]) % 10007;
    }

    cout << D[n];
    return 0;
}