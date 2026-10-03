#include <string>
#include <vector>

using namespace std;

int arr[21];
bool isused[21] = {0, };

long long factorial(int n) {
    if(n == 0) return 1;
    return n*factorial(n-1);
}

// 탐색범위 점점 줄이기
void func(int cnt, int n, long long k) {
    if(cnt == n) return;

    long long size = factorial(n-cnt-1); 
    long long idx = k/size;

    for(int i=1; i<=n; i++) {
        if(isused[i] == 0) {
            if(idx > 0) { // 사용하지 않은 숫자 중에 idx 번째 숫자를 선택해야하므로 그 전은 건너뛰기 하기
                idx--;
                continue;
            }

            arr[cnt] = i;
            isused[i] = 1;
            func(cnt+1, n, k%size);
            return;
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    func(0, n, k-1);

    for(int i=0; i<n; i++) {
        answer.push_back(arr[i]);
    }

    return answer;
}