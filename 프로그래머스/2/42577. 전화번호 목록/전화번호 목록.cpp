#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> M;
    for(int i=0; i<phone_book.size(); i++) {
        M[phone_book[i]] = 1;
    }
    
    // 반대로도 생각하는 방법 좀!!길러
    // vector를 보고 각 string을 앞에서부터 1개,2개,... 잘라가면서 그게 map에 존재하는 지 확인
    for(int i=0; i<phone_book.size(); i++) {
        for(int j=1; j<phone_book[i].size(); j++) {
            string num = phone_book[i].substr(0, j);
            if(M[num]) return false;
        }
    }
    
    return answer;
    
}