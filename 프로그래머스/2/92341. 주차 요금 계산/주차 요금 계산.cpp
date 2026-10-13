#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, vector<int>> m;
    
    for(int i=0; i<records.size(); i++) {
        stringstream ss(records[i]);
        string time, car, status;
        ss >> time >> car >> status;
        
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        
        int total_time = 0;
        int total_fee = fees[1];
        
        m[car].push_back(hour*60 + min);
        
    }
    
    for(auto& pair : m) {
        if(pair.second.size() % 2 == 0) continue;
        pair.second.push_back(23 * 60 + 59);
    }
    
    vector<pair<string, int>> v;
    for(auto pair : m) {
        int total_time = 0;
        int total_fee = fees[1];
        
        for(int i=0; i<pair.second.size(); i+=2) {
            total_time += (pair.second[i+1] - pair.second[i]);
        }

        if(total_time > fees[0]) {
            total_fee += ceil((double)(total_time - fees[0]) / fees[2]) * fees[3];
        }
    
        v.push_back({pair.first, total_fee});
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        answer.push_back(v[i].second);
    }
    
    return answer;
}