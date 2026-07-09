#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    int arr[5001];
    unordered_map<int, int> m;
    int answer = 0;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
        
    }

    // j < i < third 라고 생각
    for(int i=0; i<n; i++) {
        m[arr[i]]--; //사용
        for(int j=0; j<i; j++) {
            if(m.count(k-arr[i]-arr[j]) > 0) {
                answer += m[k-arr[i]-arr[j]]; //주의!!
            }
        }
    }

    cout << answer;
    return 0;
}