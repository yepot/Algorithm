#include <iostream>
using namespace std;

int n;
int cnt = 0;
int arr[20];

void func(int k) {
    if(k == n) {
        cnt++;
        return;
    }
    else if(k > n) {
        return ;
    }
    for(int i=1; i<=4; i++) {
        for(int j=0; j<i; j++) {
            arr[k+j] = i;
        }
        func(k+i);
    }

}

int main() {
    // Please write your code here.
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}