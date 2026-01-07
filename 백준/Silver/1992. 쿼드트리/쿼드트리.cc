#include <iostream>
using namespace std;

int n;
int arr[65][65];

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
    if(check(a, b, n)) {
        cout << arr[a][b];
    }
    else {
        int k = n/2;
        cout << '(';
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                func(a+i*k, b+j*k, k);
            }
        }
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<n; j++) {
            arr[i][j] = tmp[j]-'0';
        }
    }

    func(0, 0, n);
}