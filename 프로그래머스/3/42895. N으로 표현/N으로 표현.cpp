#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

//1. D[i]: n을 i개 가지고 만들 수 있는 수들의 집합
//2. D[i] = (D[k]+D[i-k]) + (N이 i번 있음) 
//  -> S[i] = {NNN...N} ∪ (S[j] op S[i-j])
//3. D[1]=n, D[2]={n+n, n-n, n/n, n*n}
    
int solution(int N, int number) {
    vector<unordered_set<int>> S(9); //8로했다가 자꾸 오류남 벡터범위 주의!!

    for(int i=1; i<=8; i++) {
        S[i].insert((pow(10,i)-1)/9*N);
        for(int j=1; j<i; j++) {
            for(auto a : S[j]) {
                for(auto b : S[i-j]) {
                    S[i].insert(a+b);
                    if(a-b>0) S[i].insert(a-b);
                    if(a/b>0 && b!=0) S[i].insert(a/b);
                    S[i].insert(a*b);
                }
            }
        }
        if(S[i].find(number)!=S[i].end()) return i;
    }
    
    return -1;
}