#include <iostream>
using namespace std;

int main() {

    int n, x;
    int cnt = 0;
    cin >> n >> x;
    int* arr = new int[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] < x) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}