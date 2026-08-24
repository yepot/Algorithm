#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    
    s[0] = toupper(s[0]);
    for(int i=0; i<s.size()-1; i++) {
        if(s[i] == ' ') {
            s[i+1] = toupper(s[i+1]);
        }
        else {
            s[i+1] = tolower(s[i+1]);
        }
    }
    
    return s;
}