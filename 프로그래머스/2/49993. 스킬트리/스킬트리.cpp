#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<string> v;
    for(int i=0; i<skill_trees.size(); i++) {
        string str = "";
        for(int j=0; j<skill_trees[i].size(); j++) {
            string tmp = "";
            tmp += skill_trees[i][j];
            if(skill.find(tmp) == string::npos) continue;
            str += tmp;
        }
        v.push_back(str);
    }
    
    for(int i=0; i<v.size(); i++) {
        if(skill.find(v[i]) == 0) answer ++;
    }
    
    return answer;
}