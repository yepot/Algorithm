#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

// 대소문자 구분 X
// unordered_multiset으로 관리
int solution(string str1, string str2) {
    int answer = 0;
    
    int cnt = 0;
    int size1 = 0;
    int size2 = 0;
    unordered_multiset<string> ms;
    
    for(int i=0; i<str1.size()-1; i++) {
        if(isalpha(str1[i]) && isalpha(str1[i+1])) {
            string tmp = "";
            tmp += toupper(str1[i]);
            tmp += toupper(str1[i+1]);
            ms.insert(tmp);
            size1 ++;
        }
    }
    
    for(int i=0; i<str2.size()-1; i++) {
        if(isalpha(str2[i]) && isalpha(str2[i+1])) {
            string tmp = "";
            tmp += toupper(str2[i]);
            tmp += toupper(str2[i+1]);
            if(ms.find(tmp) != ms.end()) {
                cnt ++;
                ms.erase(ms.find(tmp));
            }
            size2 ++;
        }
    }
    
    int uni = size1 + size2 -cnt;
    if(uni == 0 && cnt == 0) return 65536;
    else if(uni == 0 || cnt == 0) return 0;
    answer = (double)cnt/uni*65536;
    
    return answer;
}