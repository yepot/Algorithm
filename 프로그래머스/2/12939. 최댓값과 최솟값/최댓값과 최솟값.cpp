#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    vector<int> v;
    int temp;
    while (ss >> temp) {
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v.back());
    
    return answer; 
} 