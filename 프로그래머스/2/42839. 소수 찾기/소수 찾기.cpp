#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> nums;
bool visited[7];

bool isPrime(int n) {
    
    if (n < 2) return false;

    for (int i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }

    return true;
}

void dfs(string numbers, string cur) {
    // 현재까지 만든 문자열이 비어 있지 않으면 숫자로 저장
    if (!cur.empty()) {
        nums.insert(stoi(cur));
    }

    // 다음 숫자 하나 선택
    for (int i=0; i<numbers.length(); i++) {
        if (visited[i]) continue;

        visited[i] = true;
        dfs(numbers, cur+numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    // 먼저 string으로 모든 경우 구하고, 정수로 바꾸기
    dfs(numbers, "");
    for(auto i : nums) {
        if(isPrime(i)) answer++;
    }
    
    return answer;
}