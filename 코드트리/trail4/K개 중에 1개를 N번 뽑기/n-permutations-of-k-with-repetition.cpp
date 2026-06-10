#include <iostream>
using namespace std;

int k, n;
int arr[10];

void func(int cnt) { // cnt번째 수까지 선택
    if(cnt == n) {
        for(int i=0; i<n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=k; i++) {
        arr[cnt] = i;
        func(cnt+1);
    }

}

int main() {
    // Please write your code here.
    cin >> k >> n;
    
    func(0);
    return 0;
}