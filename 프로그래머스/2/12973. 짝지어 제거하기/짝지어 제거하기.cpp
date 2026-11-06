#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> st;

    for(char cur : s) {
        if(!st.empty() && st.top() == cur) st.pop();
        else st.push(cur);
    }

    if(st.empty()) return 1;
    else return 0;
}