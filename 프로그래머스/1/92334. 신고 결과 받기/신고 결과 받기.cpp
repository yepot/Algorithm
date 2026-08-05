#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_set<string> re;
    for(auto s : report) {
        re.insert(s);
    }
    
    unordered_map<string, int> reportCnt;
    for(auto s : re) {
        stringstream ss(s);
        string word;
        ss >> word;
        ss >> word;
        
        reportCnt[word]++;
    }
    
    unordered_map<string, int> mailCnt;
    for(auto s : re) {
        stringstream ss(s);
        string word;
        ss >> word;
        string a = word;
        ss >> word;
        if(reportCnt[word] >= k) mailCnt[a]++;
        
    }
    
    for(auto s : id_list) {
        answer.push_back(mailCnt[s]);
    }
    
    return answer;
}