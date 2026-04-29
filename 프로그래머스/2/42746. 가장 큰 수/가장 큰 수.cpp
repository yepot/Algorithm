#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i=0; i<numbers.size(); i++) {
        string s = to_string(numbers[i]);
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) answer+=v[i];
    
    //반례: 000... -> 0으로 출력
    bool t = true;
    for(auto i : answer) {
        if(i!='0') t = false;
    }
    
    if(t) return "0";
    else return answer;
}