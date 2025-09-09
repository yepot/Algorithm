#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int k = a*b*c;
    int arr[10] = {0};
    while(k>0) {
        arr[k%10]++;
        k/=10;
    }
    for(int i=0; i<10; i++){
        cout << arr[i] << '\n';
    }
}