#include <iostream>
using namespace std;

int n;
int arr[129][129];
int cnt[2];

bool check(int a, int b, int n) {
    for(int i=a; i<a+n; i++) {
        for(int j=b; j<b+n; j++) {
            if(arr[i][j]!=arr[a][b]) {
                return 0;
            }
        }
    }
    return 1;
}

void func(int a, int b, int n) {
    int k = n/2;
    if(check(a, b, n)) cnt[arr[a][b]]++;
    else {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                func(a+i*k, b+j*k, k);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    func(0, 0, n);
    cout << cnt[0] << '\n' << cnt[1];
}