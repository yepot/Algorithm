#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for(auto i : s) {
        if(st.empty()) st.push(i);
        else {
            if(i=='(') st.push(i);
            else {
                if(st.top()=='(') st.pop();
            }
        }
    }

    return st.empty();
}