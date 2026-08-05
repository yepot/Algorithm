#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    unordered_map<string, list<string>::iterator> m;
    
    // front: 가장 오래 사용하지 않은 도시
    // back: 가장 최근에 사용한 도시
    list<string> cache;
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    for(auto city : cities) {
        // 대소문자 통일
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        // cache hit
        if(m.find(city) != m.end()) {
            answer++;
            cache.erase(m[city]);
            cache.push_back(city);
            m[city] = prev(cache.end());
        }
        
        // cache miss
        if(m.find(city) == m.end()) {
            answer += 5;
            if(cache.size() == cacheSize) {
                m.erase(cache.front());
                cache.pop_front();
            }
            cache.push_back(city);
            m[city] = prev(cache.end());
        }
    }
    
    return answer;
}