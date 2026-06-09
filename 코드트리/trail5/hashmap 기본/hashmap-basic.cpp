#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        
        if(s == "add") {
            int a, b;
            cin >> a >> b;
            m[a] = b;
        }
        else if(s == "find") {
            int a;
            cin >> a;
            if(m.find(a) != m.end()) cout << m[a] << '\n';
            else cout << "None" << '\n';
        }
        else if(s == "remove") {
            int a;
            cin >> a;
            m.erase(a);
        }
    }

    return 0;
}