#include <string>
#include <vector>

using namespace std;

int cnt1(int n) {
    int cnt = 0;
    while(n > 0) {
        if(n%2 == 1) cnt ++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    
    int cnt = cnt1(n);
    
    while(1) {
        n++;
        if(cnt1(n) == cnt) return n;
    }
}