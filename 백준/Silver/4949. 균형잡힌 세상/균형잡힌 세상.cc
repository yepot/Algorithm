#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
	while(s!=".") {
		getline(cin, s);
		if(s==".") break;
		string result = "yes";
		stack<char> st;
		for(auto i : s) {
			if(i=='(' || i=='[') st.push(i);
			else if(i==')') {
				if(st.empty() || st.top()!='(') {
					result = "no";
					break;
				}
				st.pop();
			}
			else if(i==']') {
				if(st.empty() || st.top()!='[') {
					result = "no";
					break;
				}
				st.pop();
			}
		}
		if(!st.empty()) result = "no";
		cout << result << '\n';
	}
}